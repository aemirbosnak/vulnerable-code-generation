//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter {
    int bufferSize;
    char *buffer;
    int currentPosition;
    int isFinished;
} HexadecimalConverter;

HexadecimalConverter *initializeHexadecimalConverter(int bufferSize) {
    HexadecimalConverter *converter = malloc(sizeof(HexadecimalConverter));
    converter->bufferSize = bufferSize;
    converter->buffer = malloc(bufferSize);
    converter->currentPosition = 0;
    converter->isFinished = 0;

    return converter;
}

void convertHexadecimal(HexadecimalConverter *converter, int number) {
    int i = 0;
    char hex[MAX_BUFFER_SIZE];

    converter->buffer[converter->currentPosition++] = number & 0xf0;
    converter->buffer[converter->currentPosition++] = (number & 0x0f) << 4;

    for (i = 0; converter->buffer[i] != 0; i++) {
        hex[i] = converter->buffer[i] + 0x30;
    }

    printf("Hexadecimal: ");
    for (i = 0; hex[i] != 0; i++) {
        printf("%c ", hex[i]);
    }

    printf("\n");
}

int main() {
    HexadecimalConverter *converter = initializeHexadecimalConverter(MAX_BUFFER_SIZE);

    convertHexadecimal(converter, 0x12);
    convertHexadecimal(converter, 0x3f);
    convertHexadecimal(converter, 0x8a);

    return 0;
}