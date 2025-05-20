//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hexadecimal digits
char hex_digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// Convert a hexadecimal digit to its decimal value
int hex_to_dec(char hex) {
    for (int i = 0; i < 16; i++) {
        if (hex == hex_digits[i]) {
            return i;
        }
    }
    return -1;
}

// Convert a hexadecimal string to its decimal value
int hex_to_dec_str(char *hex_str) {
    int dec = 0;
    int len = strlen(hex_str);
    for (int i = 0; i < len; i++) {
        int digit = hex_to_dec(hex_str[i]);
        if (digit == -1) {
            return -1;
        }
        dec += digit * pow(16, len - i - 1);
    }
    return dec;
}

// Convert a decimal value to its hexadecimal string representation
char *dec_to_hex_str(int dec) {
    char *hex_str = malloc(sizeof(char) * 10);
    int i = 0;
    while (dec > 0) {
        int digit = dec % 16;
        hex_str[i++] = hex_digits[digit];
        dec /= 16;
    }
    hex_str[i] = '\0';
    return hex_str;
}

// Print the usage information
void print_usage() {
    printf("Usage: hex_converter [--hex-to-dec | --dec-to-hex] [value]\n");
    printf("Options:\n");
    printf("  --hex-to-dec: Convert a hexadecimal string to its decimal value\n");
    printf("  --dec-to-hex: Convert a decimal value to its hexadecimal string representation\n");
    printf("Value:\n");
    printf("  For --hex-to-dec: The hexadecimal string to convert\n");
    printf("  For --dec-to-hex: The decimal value to convert\n");
}

// Parse the command-line arguments
int parse_args(int argc, char **argv, char **hex_str, int *dec) {
    if (argc != 3) {
        print_usage();
        return -1;
    }

    if (strcmp(argv[1], "--hex-to-dec") == 0) {
        *hex_str = argv[2];
        return 0;
    } else if (strcmp(argv[1], "--dec-to-hex") == 0) {
        *dec = atoi(argv[2]);
        return 0;
    } else {
        print_usage();
        return -1;
    }
}

// Main function
int main(int argc, char **argv) {
    char *hex_str = NULL;
    int dec = -1;

    if (parse_args(argc, argv, &hex_str, &dec) == -1) {
        return -1;
    }

    if (hex_str != NULL) {
        int dec_value = hex_to_dec_str(hex_str);
        if (dec_value == -1) {
            printf("Invalid hexadecimal string: %s\n", hex_str);
            return -1;
        }
        printf("Decimal value: %d\n", dec_value);
    } else {
        char *hex_str = dec_to_hex_str(dec);
        printf("Hexadecimal string: %s\n", hex_str);
        free(hex_str);
    }

    return 0;
}