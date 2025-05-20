//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 32

void convert_binary_to_decimal(char* binary, int binary_length, char* decimal) {
    int decimal_value = 0;
    int power = 0;

    for (int i = binary_length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal_value += pow(2, power);
        }
        power++;
    }

    sprintf(decimal, "%d", decimal_value);
}

void convert_decimal_to_binary(int decimal, char* binary) {
    int binary_value = 0;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binary_value = remainder + binary_value * 10;
        decimal /= 2;
    }

    int binary_length = strlen(binary_value);
    for (int i = binary_length - 1; i >= 0; i--) {
        binary[i] = binary_value % 10 + '0';
        binary_value /= 10;
    }
}

int main() {
    char binary[MAX_NUM_LENGTH];
    char decimal[MAX_NUM_LENGTH];

    printf("Enter a binary number: ");
    scanf("%s", binary);

    convert_binary_to_decimal(binary, strlen(binary), decimal);

    printf("The decimal equivalent of %s is %s.\n", binary, decimal);

    convert_decimal_to_binary(atoi(decimal), binary);

    printf("The binary equivalent of %s is %s.\n", decimal, binary);

    return 0;
}