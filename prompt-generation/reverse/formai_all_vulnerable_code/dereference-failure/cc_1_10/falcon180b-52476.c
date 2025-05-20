//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *binary;
    int decimal;
} BinaryConverter;

BinaryConverter *create_binary_converter(int decimal) {
    BinaryConverter *converter = malloc(sizeof(BinaryConverter));
    converter->binary = calloc(33, sizeof(char));
    converter->decimal = decimal;
    return converter;
}

void destroy_binary_converter(BinaryConverter *converter) {
    free(converter->binary);
    free(converter);
}

char *binary_to_string(int decimal) {
    char *binary_string = calloc(33, sizeof(char));
    int i = 0;
    while (decimal > 0) {
        int remainder = decimal % 2;
        strcat(binary_string, remainder == 0? "0" : "1");
        decimal /= 2;
        i++;
    }
    for (; i < 32; i++) {
        strcat(binary_string, "0");
    }
    return binary_string;
}

int main() {
    BinaryConverter *converter;
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    converter = create_binary_converter(decimal);
    printf("Binary representation: %s\n", converter->binary);

    destroy_binary_converter(converter);

    return 0;
}