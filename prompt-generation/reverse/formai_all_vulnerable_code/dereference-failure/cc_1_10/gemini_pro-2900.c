//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input hexadecimal string
#define MAX_HEX_LEN 100

// Define the mapping between hexadecimal digits and their decimal equivalents
int hex_to_dec_map[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
};

// Function to convert a hexadecimal digit to its decimal equivalent
int hex_to_dec(char hex_digit) {
    // Check if the hexadecimal digit is valid
    if (hex_digit < '0' || hex_digit > 'f') {
        fprintf(stderr, "Invalid hexadecimal digit: %c\n", hex_digit);
        exit(EXIT_FAILURE);
    }

    // Convert the hexadecimal digit to its decimal equivalent
    int dec_value = hex_to_dec_map[hex_digit - '0'];
    return dec_value;
}

// Function to convert a hexadecimal string to its decimal equivalent
int hex_to_dec_str(char *hex_str) {
    // Check if the hexadecimal string is valid
    if (strlen(hex_str) > MAX_HEX_LEN) {
        fprintf(stderr, "Invalid hexadecimal string: %s\n", hex_str);
        exit(EXIT_FAILURE);
    }

    // Convert the hexadecimal string to its decimal equivalent
    int dec_value = 0;
    for (int i = 0; i < strlen(hex_str); i++) {
        dec_value *= 16;
        dec_value += hex_to_dec(hex_str[i]);
    }

    return dec_value;
}

// Function to convert a decimal number to its hexadecimal equivalent
char *dec_to_hex(int dec_num) {
    // Allocate memory for the hexadecimal string
    char *hex_str = malloc(MAX_HEX_LEN + 1);

    // Convert the decimal number to its hexadecimal equivalent
    int i = 0;
    while (dec_num > 0) {
        int hex_digit = dec_num % 16;
        hex_str[i] = hex_digit < 10 ? '0' + hex_digit : 'a' + hex_digit - 10;
        dec_num /= 16;
        i++;
    }

    // Reverse the hexadecimal string
    for (int j = 0; j < i / 2; j++) {
        char temp = hex_str[j];
        hex_str[j] = hex_str[i - j - 1];
        hex_str[i - j - 1] = temp;
    }

    // Terminate the hexadecimal string
    hex_str[i] = '\0';

    return hex_str;
}

int main(int argc, char *argv[]) {
    // Check if the user has provided a hexadecimal string
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert the hexadecimal string to its decimal equivalent
    int dec_num = hex_to_dec_str(argv[1]);

    // Print the decimal equivalent of the hexadecimal string
    printf("%d\n", dec_num);

    // Convert the decimal number to its hexadecimal equivalent
    char *hex_str = dec_to_hex(dec_num);

    // Print the hexadecimal equivalent of the decimal number
    printf("%s\n", hex_str);

    // Free the allocated memory
    free(hex_str);

    return 0;
}