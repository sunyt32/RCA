#include <cstdio>
#include "rca.hpp"

int main() {
    char input[2048];
    unsigned char output[10];
    scanf("%s", input);
    rca(input, strlen(input), output);
    for(int i = 0; i < 10; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");
    return 0;
}

