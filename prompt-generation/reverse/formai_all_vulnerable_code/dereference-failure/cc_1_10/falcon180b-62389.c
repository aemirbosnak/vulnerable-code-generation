//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM_CHARS 32

typedef struct {
    char* binary;
    int decimal;
} BinaryConverter;

void initialize_binary_converter(BinaryConverter* bc) {
    bc->binary = (char*)malloc(MAX_NUM_CHARS*sizeof(char));
    bc->decimal = 0;
    bc->binary[0] = '\0';
}

void destroy_binary_converter(BinaryConverter* bc) {
    free(bc->binary);
}

void convert_decimal_to_binary(int decimal, BinaryConverter* bc) {
    char* binary = bc->binary;
    int i = 0;

    while (decimal!= 0) {
        int remainder = decimal % 2;
        binary[i++] = remainder + '0';
        decimal /= 2;
    }

    binary[i] = '\0';
    bc->decimal = atoi(binary);
}

void convert_binary_to_decimal(BinaryConverter* bc) {
    int decimal = 0;
    int power = 0;
    int i = strlen(bc->binary) - 1;

    while (i >= 0) {
        int digit = bc->binary[i] - '0';
        decimal += digit * pow(2, power);
        power++;
        i--;
    }

    bc->decimal = decimal;
}

int main() {
    BinaryConverter bc;
    initialize_binary_converter(&bc);

    int choice;
    do {
        printf("\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &bc.decimal);
                convert_decimal_to_binary(bc.decimal, &bc);
                printf("Binary representation: %s\n", bc.binary);
                break;
            case 2:
                convert_binary_to_decimal(&bc);
                printf("Decimal representation: %d\n", bc.decimal);
                break;
            case 3:
                destroy_binary_converter(&bc);
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}