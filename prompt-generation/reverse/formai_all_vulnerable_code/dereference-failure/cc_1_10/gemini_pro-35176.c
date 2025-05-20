//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input hexadecimal string
#define MAX_HEX_LENGTH 100

// Define the hexadecimal digits
char hex_digits[] = "0123456789ABCDEF";

// Function to convert a hexadecimal digit to its decimal equivalent
int hex_to_decimal(char hex) {
    // Check if the hex digit is valid
    if (strchr(hex_digits, hex) == NULL) {
        fprintf(stderr, "Error: Invalid hexadecimal digit '%c'\n", hex);
        exit(EXIT_FAILURE);
    }

    // Convert the hex digit to its decimal equivalent
    int decimal = 0;
    for (int i = 0; i < 16; i++) {
        if (hex_digits[i] == hex) {
            decimal = i;
            break;
        }
    }

    return decimal;
}

// Function to convert a hexadecimal string to its decimal equivalent
int hex_to_decimal_string(char *hex_string) {
    // Check if the hex string is valid
    if (strlen(hex_string) > MAX_HEX_LENGTH) {
        fprintf(stderr, "Error: Hexadecimal string too long\n");
        exit(EXIT_FAILURE);
    }

    // Convert the hex string to its decimal equivalent
    int decimal = 0;
    int length = strlen(hex_string);
    for (int i = 0; i < length; i++) {
        // Get the decimal equivalent of the current hex digit
        int digit_decimal = hex_to_decimal(hex_string[i]);

        // Shift the decimal value left by 4 bits to make room for the next digit
        decimal <<= 4;

        // Add the decimal equivalent of the current hex digit to the total decimal value
        decimal += digit_decimal;
    }

    return decimal;
}

// Function to convert a decimal number to its hexadecimal equivalent
char *decimal_to_hex(int decimal) {
    // Allocate memory for the hexadecimal string
    char *hex_string = malloc(MAX_HEX_LENGTH + 1);
    if (hex_string == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }

    // Convert the decimal number to its hexadecimal equivalent
    int i = 0;
    while (decimal > 0) {
        // Get the remainder of the division by 16
        int remainder = decimal % 16;

        // Convert the remainder to its hexadecimal digit
        hex_string[i++] = hex_digits[remainder];

        // Divide the decimal number by 16
        decimal /= 16;
    }

    // Reverse the hexadecimal string
    int length = strlen(hex_string);
    for (int j = 0; j < length / 2; j++) {
        char temp = hex_string[j];
        hex_string[j] = hex_string[length - j - 1];
        hex_string[length - j - 1] = temp;
    }

    // Terminate the hexadecimal string with a null character
    hex_string[i] = '\0';

    return hex_string;
}

// Function to print the usage of the program
void print_usage() {
    printf("Usage: hexconv [options] [arguments]\n");
    printf("Options:\n");
    printf("  -h, --help  Print this help message and exit\n");
    printf("  -d, --decimal  Convert a hexadecimal string to its decimal equivalent\n");
    printf("  -x, --hexadecimal  Convert a decimal number to its hexadecimal equivalent\n");
    printf("Arguments:\n");
    printf("  hex_string  The hexadecimal string to convert (for -d option)\n");
    printf("  decimal_number  The decimal number to convert (for -x option)\n");
}

// Main function
int main(int argc, char **argv) {
    // Check if the program was called with the correct number of arguments
    if (argc != 2 && argc != 3) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    // Check if the program was called with the -h or --help option
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_usage();
        exit(EXIT_SUCCESS);
    }

    // Check if the program was called with the -d or --decimal option
    if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--decimal") == 0) {
        // Check if the program was called with the correct number of arguments
        if (argc != 3) {
            print_usage();
            exit(EXIT_FAILURE);
        }

        // Convert the hexadecimal string to its decimal equivalent
        int decimal = hex_to_decimal_string(argv[2]);

        // Print the decimal equivalent
        printf("Decimal: %d\n", decimal);
    }

    // Check if the program was called with the -x or --hexadecimal option
    else if (strcmp(argv[1], "-x") == 0 || strcmp(argv[1], "--hexadecimal") == 0) {
        // Check if the program was called with the correct number of arguments
        if (argc != 3) {
            print_usage();
            exit(EXIT_FAILURE);
        }

        // Convert the decimal number to its hexadecimal equivalent
        char *hex_string = decimal_to_hex(atoi(argv[2]));

        // Print the hexadecimal equivalent
        printf("Hexadecimal: %s\n", hex_string);

        // Free the memory allocated for the hexadecimal string
        free(hex_string);
    }

    // Check if the program was called with an invalid option
    else {
        fprintf(stderr, "Error: Invalid option '%s'\n", argv[1]);
        print_usage();
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}