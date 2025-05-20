//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BINARY_LENGTH 1024

typedef struct {
    char name[50];
    unsigned char binary[MAX_BINARY_LENGTH];
    int length;
} File;

void binary_from_decimal(int decimal, unsigned char *binary, int *length) {
    int i = 0;
    unsigned char bit;

    *length = 0;

    do {
        bit = decimal % 2;
        decimal /= 2;
        binary[i] = bit;
        (*length)++;
    } while (decimal > 0);
}

void decimal_from_binary(unsigned char *binary, int length, int *decimal) {
    int i = 0, power = 0;
    int sum = 0;

    *decimal = 0;

    for (; i < length; i++) {
        sum += (binary[i] & 0x01) << power;
        power += 1;
    }

    *decimal = sum;
}

void print_binary(unsigned char *binary, int length) {
    int i = 0;

    printf("The binary representation of the decimal number is:\n");
    printf("0b");

    for (; i < length; i++) {
        printf("%d", binary[i]);
    }

    printf("\n");
}

void print_decimal(int decimal) {
    printf("The decimal representation of the binary number is: %d\n", decimal);
}

File read_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    File file_info;
    int ch;

    strcpy(file_info.name, filename);

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    file_info.length = 0;

    while ((ch = fgetc(file)) != EOF) {
        file_info.binary[file_info.length++] = (unsigned char) ch;
    }

    fclose(file);

    return file_info;
}

int main(int argc, char **argv) {
    File input_file;
    unsigned char binary[MAX_BINARY_LENGTH];
    int decimal;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    input_file = read_file(argv[1]);

    binary_from_decimal(0b10110110, binary, &input_file.length);

    printf("The binary number %s represents the decimal number:\n", input_file.name);
    print_binary(binary, input_file.length);

    decimal_from_binary(binary, input_file.length, &decimal);
    print_decimal(decimal);

    return EXIT_SUCCESS;
}