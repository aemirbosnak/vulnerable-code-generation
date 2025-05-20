//FormAI DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 32

char *decimal_to_binary(int decimal) {
    char *binary = malloc(sizeof(char) * MAX_BINARY_LENGTH);
    memset(binary, 0, sizeof(char) * MAX_BINARY_LENGTH);
    int index = 0;
    while (decimal > 0) {
        binary[index++] = decimal % 2 + '0';
        decimal /= 2;
    }
    int len = strlen(binary);
    for (int i = 0; i < len / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }
    return binary;
}

void binary_to_decimal(char *binary) {
    int decimal = 0;
    int index = 0;
    int len = strlen(binary);
    for (int i = len - 1; i >= 0; i--) {
        int bit = binary[i] == '1' ? 1 : 0;
        decimal += bit << index++;
    }
    printf("Decimal: %d\n", decimal);
}

int main() {
    int option, decimal;
    char *binary;
    do {
        printf("1. Decimal to binary\n");
        printf("2. Binary to decimal\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter decimal: ");
                scanf("%d", &decimal);
                binary = decimal_to_binary(decimal);
                printf("Binary: %s\n", binary);
                free(binary);
                break;
            case 2:
                printf("Enter binary: ");
                scanf("%s", binary);
                binary_to_decimal(binary);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 3);
    return 0;
}