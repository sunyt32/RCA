#include <cstdio>
#include <ctime>
#include "rca.hpp"

int bps() {
    char input[2048];
    unsigned char output[10];
    time_t begin = time(0);
    int count = 0;
    while(time(0) - begin < 1) {
        rca(input, 128, output);
        count++;
    }
    return count;
}

int main() {
    char input[2048];
    unsigned char output[10];
    scanf("%s", input);
    rca(input, strlen(input), output);
    printf("Encrypt speed: %d bps\n", bps());
    for(int i = 0; i < 10; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");
    return 0;
}

