//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_LENGTH 64
#define BINARY_DIGITS "0123456789ABCDEF"

int main(int argc, char *argv[]) {
    char input_num[MAX_NUM_LENGTH];
    char binary_num[MAX_NUM_LENGTH];
    int i = 0, j = 0;
    int decimal_num = 0;
    int binary_length = 0;
    int is_negative = 0;
    char *endptr;

    // Check if the user has entered a valid decimal number
    if (argc!= 2) {
        printf("Invalid input. Please enter a decimal number.\n");
        return 1;
    }

    // Convert the input string to lowercase
    strcpy(input_num, argv[1]);
    for (i = 0; i < strlen(input_num); i++) {
        input_num[i] = tolower(input_num[i]);
    }

    // Check if the input string contains a negative sign
    if (input_num[0] == '-') {
        is_negative = 1;
        strcpy(input_num, input_num + 1);
    }

    // Convert the input string to binary
    decimal_num = strtol(input_num, &endptr, 10);
    if (endptr == input_num || decimal_num == 0) {
        printf("Invalid input. Please enter a valid decimal number.\n");
        return 1;
    }
    binary_length = sprintf(binary_num, "%b", decimal_num);

    // Add leading zeros if necessary
    while (binary_length < MAX_NUM_LENGTH) {
        binary_num[binary_length++] = '0';
    }

    // Add negative sign if necessary
    if (is_negative) {
        binary_num[0] = '-';
        binary_length++;
    }

    // Print the binary number
    printf("Binary number: %s\n", binary_num);

    return 0;
}