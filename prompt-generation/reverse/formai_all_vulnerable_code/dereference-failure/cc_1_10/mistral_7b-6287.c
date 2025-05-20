//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LEN 1000
#define BIN_LEN (sizeof(unsigned long long)*8)

typedef unsigned long long binary_t;

void itob(binary_t bin, char* str, int len) {
    int i = 0;
    for (; i < len; i++) {
        str[len - i - 1] = '0' + (bin >> (i * 3) & 7);
        bin <<= 3;
    }
}

void convert(char* str, binary_t* bin) {
    int len = strlen(str);
    int i = 0, j = 0;
    binary_t base = 1;
    binary_t value = 0;
    for (; i < len; i++) {
        if (str[i] == '1')
            value += base;
        base *= 2;
    }
    *bin = value;
}

int main(int argc, char** argv) {
    char input[MAX_LEN];
    char output[BIN_LEN + 1];
    binary_t binary;

    if (argc != 2) {
        printf("Usage: %s <decimal number>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);

    // Shift input string to the left and remove leading zeros
    for (int i = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            for (int j = i; j < strlen(input); j++)
                input[j] = input[j + 1];
            break;
        }
    }

    if (strlen(input) > MAX_LEN - BIN_LEN) {
        printf("Error: Number too large.\n");
        return 1;
    }

    convert(input, &binary);

    itob(binary, output, BIN_LEN);

    printf("%s -> %s\n", input, output);

    return 0;
}