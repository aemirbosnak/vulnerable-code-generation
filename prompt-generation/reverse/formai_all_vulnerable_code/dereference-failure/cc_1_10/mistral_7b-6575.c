//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BINARY_SIZE 1024

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to convert binary to decimal
long long binary_to_decimal(const char* binary) {
    int length = strlen(binary);
    long long result = 0;
    int power = 0;

    for (int i = length - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            result += pow(2, power);
        }
        ++power;
    }

    return result;
}

// Function to validate binary number
int is_valid_binary(const char* binary) {
    int length = strlen(binary);

    for (int i = 0; i < length; ++i) {
        if (binary[i] != '0' && binary[i] != '1') {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <binary_number>\n", argv[0]);
        return 1;
    }

    char binary_number[MAX_BINARY_SIZE];
    strcpy(binary_number, argv[1]);

    if (!is_valid_binary(binary_number)) {
        printf("Error: Invalid binary number.\n");
        return 1;
    }

    reverse_string(binary_number);
    long long decimal_number = binary_to_decimal(binary_number);

    printf("Binary number: %s\n", binary_number);
    printf("Decimal number: %lld\n", decimal_number);

    return 0;
}