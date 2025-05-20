//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

// Function prototypes
void print_usage();
void convert_to_hexadecimal(const char *input);
int is_valid_number(const char *input);
void append_char(char *output, char ch);
void convert_integer_to_hex(int number, char *output);

int main(int argc, char *argv[]) {
    char input[MAX_INPUT];

    if (argc < 2) {
        print_usage();
        return 1;
    }

    strcpy(input, argv[1]);

    if (is_valid_number(input)) {
        convert_to_hexadecimal(input);
    } else {
        printf("Error: Invalid input. Please enter a valid integer.\n");
        print_usage();
    }

    return 0;
}

void print_usage() {
    printf("Usage: ./hex_converter <integer>\n");
    printf("Converts a decimal integer to its hexadecimal representation.\n");
}

void convert_to_hexadecimal(const char *input) {
    int number = atoi(input);
    char hex_output[9]; // 8 digits for hex + null terminator
    convert_integer_to_hex(number, hex_output);
    printf("Decimal: %d\n", number);
    printf("Hexadecimal: %s\n", hex_output);
}

int is_valid_number(const char *input) {
    // Allow plus or minus sign at the beginning
    if (*input == '+' || *input == '-') {
        input++;
    }

    // Ensure the remaining characters are digits
    while (*input) {
        if (*input < '0' || *input > '9') {
            return 0; // Not a valid number
        }
        input++;
    }
  
    return 1; // Valid number
}

void convert_integer_to_hex(int number, char *output) {
    const char hex_chars[] = "0123456789ABCDEF";
    int i = 0;
    
    if (number == 0) {
        strcpy(output, "0");
        return;
    }
    
    // Handle negative number
    unsigned int num = (number < 0) ? -number : number;

    while (num != 0) {
        int remainder = num % 16;
        output[i++] = hex_chars[remainder];
        num /= 16;
    }
    
    // Add null terminator
    output[i] = '\0';

    // Reverse the string to get the correct hexadecimal representation
    for (int j = 0; j < i / 2; j++) {
        char temp = output[j];
        output[j] = output[i - j - 1];
        output[i - j - 1] = temp;
    }
}