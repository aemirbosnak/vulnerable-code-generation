//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_LENGTH 100

int main(int argc, char *argv[]) {
    char *binary_num = "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010";
    char *decimal_num = "42";
    int decimal_int = 0;
    int binary_int = 0;
    int num_length = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    int remainder = 0;
    int power = 0;
    char *decimal_binary = malloc(MAX_NUM_LENGTH * sizeof(char));
    char *binary_decimal = malloc(MAX_NUM_LENGTH * sizeof(char));

    // Convert decimal to binary
    while (decimal_num[i]!= '\0') {
        decimal_int = decimal_int * 10 + (decimal_num[i] - '0');
        i++;
        num_length++;
    }

    // Reverse decimal integer
    temp = decimal_int;
    while (temp!= 0) {
        remainder = temp % 2;
        decimal_binary[j] = remainder + '0';
        temp = temp / 2;
        j++;
    }
    for (k = 0; k < num_length; k++) {
        if (decimal_binary[k] == '0') {
            printf("0");
        } else {
            printf("%d", decimal_binary[k] - '0');
        }
    }
    printf("\n");

    // Convert binary to decimal
    while (binary_num[i]!= '\0') {
        binary_int = binary_int * 2 + (binary_num[i] - '0');
        i++;
        num_length++;
    }

    // Reverse binary integer
    temp = binary_int;
    while (temp!= 0) {
        remainder = temp % 10;
        binary_decimal[j] = remainder + '0';
        temp = temp / 10;
        j++;
    }
    for (k = 0; k < num_length; k++) {
        if (binary_decimal[k] == '0') {
            printf("0");
        } else {
            printf("%d", binary_decimal[k] - '0');
        }
    }
    printf("\n");

    free(decimal_binary);
    free(binary_decimal);

    return 0;
}