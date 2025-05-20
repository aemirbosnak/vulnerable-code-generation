//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Brave Binary Converter v1.0 - Convert text to binary and binary to text

typedef struct BinaryData {
    unsigned char* binary;
    size_t size;
} BinaryData;

void binaryPrint(unsigned char* binary, size_t size) {
    printf("Binary: ");
    for (size_t i = 0; i < size; i++) {
        printf("%c", (binary[i] > 0) ? '1' : '0');
    }
    printf("\n");
}

BinaryData textToBinary(const char* text) {
    BinaryData binaryData;
    size_t binarySize = 0;
    for (size_t i = 0; text[i]; i++) {
        if (text[i] == '.' || text[i] == '-') {
            binarySize++;
            continue;
        }
        unsigned char byte = 0;
        for (size_t j = 0; text[i] || (j < 8); j++) {
            byte <<= 1;
            byte |= (text[i] == '1') ? 1 : 0;
            i++;
            if (!text[i]) break;
        }
        binarySize += 8;
        binaryData.binary = realloc(binaryData.binary, binarySize * sizeof(unsigned char));
        binaryData.binary[binarySize - 8] = byte;
    }
    binaryData.size = binarySize;
    return binaryData;
}

void binaryToText(const BinaryData binaryData) {
    printf("Text: ");
    for (size_t i = 0; i < binaryData.size; i++) {
        for (size_t j = 7; j >= 0; j--) {
            putchar((binaryData.binary[i] >> j) & 1 ? '1' : '0');
        }
    }
    printf("\n");
    free(binaryData.binary);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s [text|binary] [convert|print]\n", argv[0]);
        return 1;
    }

    const char* mode = argv[1];
    const char* data = argv[2];

    if (strcmp(mode, "text") == 0) {
        if (strcmp(argv[3], "print") == 0) {
            puts("Text to print:");
            puts(data);
            puts("--------------------\n");
            binaryPrint((unsigned char*)data, strlen(data));
            return 0;
        }

        BinaryData binaryData = textToBinary(data);
        printf("Text: %s\n", data);
        printf("Binary data size: %zu bytes\n", binaryData.size);
        binaryToText(binaryData);
        free(binaryData.binary);
    } else if (strcmp(mode, "binary") == 0) {
        if (strcmp(argv[3], "convert") == 0) {
            BinaryData binaryData = {NULL, 0};
            size_t binarySize = strlen(data) / 8;
            binaryData.binary = calloc(binarySize, 1);
            memcpy(binaryData.binary, data, binarySize);
            printf("Binary data size: %zu bytes\n", binarySize);
            binaryToText(binaryData);
            free(binaryData.binary);
            return 0;
        }

        binaryPrint((unsigned char*)data, strlen(data) / 8);
    }

    puts("Invalid mode or data.");
    return 1;
}