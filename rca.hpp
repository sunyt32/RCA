#pragma once

#include <cstring>
#include <cstdlib>
#include "prng.hpp"

static const unsigned int init[4] = {0xd76aa478, 0xf61e2562, 0xfffa3942, 0xf4292244};


inline unsigned int rotl(unsigned int a, unsigned int b) {
    b &= 0x1f;
    return (a << b) | (a >> (32 - b));
}

inline unsigned int rotr(unsigned int a, unsigned int b) {
    b &= 0x1f;
    return (a >> b) | (a << (32 - b));
}

typedef unsigned char ST;

ST next(ST st, unsigned int input) {
    ST res = 0;
    bool st_0, st_1, st_2, st_3, in_0, in_1, in_2, in_3;
    st_0 = st == 0;
    st_1 = st == 1;
    st_2 = st == 2;
    st_3 = st == 3;
    in_0 = input == 0;
    in_1 = input == 1;
    in_2 = input == 2;
    in_3 = input == 3;
    res |= 1 & -((st_0 && in_0) || (st_1 && in_3) || (st_2 && in_1) || (st_3 && in_1));
    res |= 2 & -((st_0 && in_3) || (st_1 && in_0) || (st_2 && in_3) || (st_3 && in_3));
    res |= 3 & -((st_0 && in_2) || (st_1 && in_2) || (st_2 && in_2) || (st_3 && in_2));
    return res;
}


void mapping(unsigned int *b, ST st_in, ST st_out) {
    unsigned int encode = 0;
    switch (st_in)
    {
    case 0:
        encode = (b[1] & b[2]) | (~b[1] & b[3]);
        break;
    
    case 1:
        encode = (b[1] & b[3]) | (b[2] & ~b[3]);
        break;
    
    case 2:
        encode = b[1] ^ b[2] ^ b[3];
        break;

    case 3:
        encode = b[2] ^ (b[1] | ~b[3]);
        break;
    
    default:
        break;
    }
    encode ^= b[0];
    switch (st_out)
    {
    case 0:
        b[0] = rotl(encode, b[0]);
        b[1] = rotr(encode, b[1]);
        b[2] = encode ^ b[2];
        b[3] = encode * b[3];
        break;
    
    case 1:
        b[1] = rotl(encode, b[1]);
        b[2] = rotr(encode, b[2]);
        b[3] = encode ^ b[3];
        b[0] = encode * b[0];
        break;
    
    case 2:
        b[2] = rotl(encode, b[2]);
        b[3] = rotr(encode, b[3]);
        b[0] = encode ^ b[0];
        b[1] = encode * b[1];
        break;

    case 3:
        b[3] = rotl(encode, b[3]);
        b[0] = rotr(encode, b[0]);
        b[1] = encode ^ b[1];
        b[2] = encode * b[2];
        break;
    
    default:
        break;
    }
}

void print_memory(unsigned int *memory) {
    for(int i = 0; i < 4; i++) {
        printf("%08x", memory[i]);
    }
    printf("\n");
}

void rca(char *message, int len, unsigned char *output) {
    unsigned int memory[4];
    unsigned int block[3];
    unsigned int ptr = 0, arg;
    ST in = 1, out = 3;
    memcpy(memory, init, 4 * sizeof(unsigned int));
    memory[0] ^= len;
    while(ptr < len) {
        if(ptr + 12 <= len) {
            memory[0] ^= *((unsigned int*)(message + ptr));
            memory[1] ^= *((unsigned int*)(message + ptr + 4));
            memory[2] ^= *((unsigned int*)(message + ptr + 8));
            ptr += 12;
        } else {
            memcpy(block, message, len - ptr);
            memset((unsigned char*)block + len - ptr, 0, 12 - (len - ptr));
            memory[0] ^= block[0];
            memory[1] ^= block[1];
            memory[2] ^= block[2];
            ptr = len;
        }
        arg = prng(block, 12);
        // arg = rand();
        for(int i = 0; i < 4; i++) {
            mapping(memory, in, out);
            in = next(in, arg & 0x3);
            out = next(out, (arg >> 2) & 0x3);
            arg >>= 4;
        }
    }
    mapping(memory, in, out);
    memcpy(output, memory, 10);
}

