#include <cstdio>
#include <ctime>
#include "rca.hpp"

int bps(char* input) {
    unsigned char output[10];
    int count = 0;
    printf("size: %d Bytes\n",strlen(input) );
    time_t begin = time(0);
    while(time(0) - begin < 5) {
        rca(input,strlen(input), output);
        count++;
    }
    return 8*strlen(input)*count/5;
}

int main() {
    char input[1024*1024];
    unsigned char output[10];
    FILE *fp = fopen("output.bin", "wb");
    int count = 0;
    while(true) {
        if(scanf("%s", input) == -1) {
            break;
        }
        rca(input, strlen(input), output);
        printf("Encrypt speed: %d bps\n",bps(input));
        printf("hash value: ");
        for(int i = 0; i < 10; i++) {
            printf("%02x", output[i]);
        }
        printf("\n");
        fwrite(output, 10, sizeof(unsigned char), fp);
        count++;
    }
    printf("Encode %d sequences.\n", count);
    return 0;
}

