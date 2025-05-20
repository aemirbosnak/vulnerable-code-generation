//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#pragma pack(push, 1)
typedef struct BinaryTag {
    char name[32];
    unsigned int value;
} Binary;
#pragma pack(pop)

void binToDec(const char* bin, int* dec) {
    int i = 0, j = 0, power = 0;
    for (; bin[i] != '\0'; ++i) {
        if (bin[i] == '1') {
            dec[j] += pow(2, power);
        }
        ++power;
        if (power == 8) {
            power = 0;
            ++j;
        }
    }
}

void printDecToBin(int dec, int size) {
    int* decBin = malloc(sizeof(int) * size);
    int i = 0;
    for (; dec != 0; dec /= 10) {
        decBin[i++] = dec % 10;
    }

    for (i = size - 1; i >= 0; --i) {
        printf("%d", decBin[i]);
    }
    printf("\n");
    free(decBin);
}

void printBinaryStruct(const char* name, const Binary* binary) {
    printf("%s: 0x%08x -> ", name, binary->value);
    printDecToBin(binary->value, 32);
}

int main() {
    const char* binaryStr = "1110110010111111110110111011011011";
    Binary binary[1];

    sscanf(binaryStr, "%31s %x", binary[0].name, &binary[0].value);

    printBinaryStruct(binary[0].name, binary);

    int dec[4];
    binToDec(binaryStr, dec);

    for (int i = 0; i < 4; ++i) {
        printf("%s: 0x%08x -> 0x%08x\n", binary[0].name, binary[0].value, dec[i]);
    }

    return 0;
}