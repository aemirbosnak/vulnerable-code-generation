//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BINARY_LENGTH 32

int binaryToInt(char binary[]) {
    int length, result = 0;
    length = strlen(binary);
    for (int i = 0; i < length; i++) {
        result += ((binary[i] - '0') * pow(2, length - i - 1));
    }
    return result;
}

char* intToBinary(int decimal) {
    char* binary = (char*)malloc(sizeof(char) * (MAX_BINARY_LENGTH + 1));
    for (int i = 0; i < MAX_BINARY_LENGTH; i++) {
        binary[i] = '0';
    }
    binary[MAX_BINARY_LENGTH] = '\0';
    
    int pointer = MAX_BINARY_LENGTH - 1;
    while (decimal > 0) {
        binary[pointer] = (decimal % 2 == 0) ? '0' : '1';
        decimal /= 2;
        pointer--;
    }
    
    return binary;
}

int main() {
    int choice;
    printf("\nBINARY CONVERTER\n\n");
    printf("1. Convert binary to decimal\n");
    printf("2. Convert decimal to binary\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        char binary[MAX_BINARY_LENGTH + 1];
        printf("\nEnter a binary number (up to 32 bits): ");
        scanf("%s", binary);
        int decimal = binaryToInt(binary);
        printf("Decimal equivalent: %d\n", decimal);
    }
    else if (choice == 2) {
        int decimal;
        printf("\nEnter a decimal number: ");
        scanf("%d", &decimal);
        char* binary = intToBinary(decimal);
        printf("Binary equivalent: %s\n", binary);
        free(binary);
    }
    else {
        printf("\nInvalid choice!");
    }
    
    return 0;
}