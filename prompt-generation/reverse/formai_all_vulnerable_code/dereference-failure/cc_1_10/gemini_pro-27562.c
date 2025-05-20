//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the hexadecimal digits
static const char *hex_digits = "0123456789ABCDEF";

// Convert a decimal number to hexadecimal
char *decimal_to_hexadecimal(int decimal) {
    // Allocate memory for the hexadecimal string
    char *hexadecimal = malloc(100);

    // Initialize the hexadecimal string to empty
    hexadecimal[0] = '\0';

    // Convert the decimal number to hexadecimal
    while (decimal > 0) {
        int remainder = decimal % 16;
        decimal /= 16;
        hexadecimal[0] = hex_digits[remainder];
        hexadecimal++;
    }

    // Reverse the hexadecimal string
    char *start = hexadecimal;
    char *end = hexadecimal + strlen(hexadecimal) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    // Return the hexadecimal string
    return hexadecimal;
}

// Convert a hexadecimal number to decimal
int hexadecimal_to_decimal(char *hexadecimal) {
    // Initialize the decimal number to 0
    int decimal = 0;

    // Convert the hexadecimal number to decimal
    while (*hexadecimal != '\0') {
        int digit = *hexadecimal;
        if (digit >= '0' && digit <= '9') {
            digit -= '0';
        } else if (digit >= 'A' && digit <= 'F') {
            digit -= 'A' + 10;
        } else if (digit >= 'a' && digit <= 'f') {
            digit -= 'a' + 10;
        } else {
            // Invalid hexadecimal digit
            return -1;
        }
        decimal = 16 * decimal + digit;
        hexadecimal++;
    }

    // Return the decimal number
    return decimal;
}

// Print the usage information
void print_usage() {
    printf("Usage: hexadecimal_converter <decimal number> | <hexadecimal number>\n");
    printf("Example: hexadecimal_converter 100 | hexadecimal_converter FF\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is valid
    if (argc != 2) {
        print_usage();
        return 1;
    }

    // Get the input number
    char *input = argv[1];

    // Check if the input number is a decimal number
    if (input[0] >= '0' && input[0] <= '9') {
        // Convert the decimal number to hexadecimal
        char *hexadecimal = decimal_to_hexadecimal(atoi(input));
        printf("%s\n", hexadecimal);
        free(hexadecimal);
    } else {
        // Convert the hexadecimal number to decimal
        int decimal = hexadecimal_to_decimal(input);
        if (decimal == -1) {
            printf("Invalid hexadecimal number\n");
            return 1;
        }
        printf("%d\n", decimal);
    }

    return 0;
}