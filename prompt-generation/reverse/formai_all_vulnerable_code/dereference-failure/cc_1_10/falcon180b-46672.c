//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *binary;
    int decimal;
} BinaryConverter;

void initialize(BinaryConverter *bc) {
    bc->binary = malloc(MAX_SIZE * sizeof(char));
    bc->decimal = 0;
}

void destroy(BinaryConverter *bc) {
    free(bc->binary);
    bc->binary = NULL;
}

void convert(BinaryConverter *bc, int decimal) {
    int i = 0;
    int remainder = decimal;

    while (remainder > 0) {
        if (remainder % 2 == 0) {
            bc->binary[i] = '0';
        } else {
            bc->binary[i] = '1';
        }
        i++;
        remainder /= 2;
    }
    bc->binary[i] = '\0';
    bc->decimal = decimal;
}

void print(BinaryConverter *bc) {
    printf("Binary: %s\nDecimal: %d\n", bc->binary, bc->decimal);
}

int main() {
    BinaryConverter bc;
    initialize(&bc);
    int decimal = 42;
    convert(&bc, decimal);
    print(&bc);
    destroy(&bc);
    return 0;
}