//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
/**********************
* Hexadecimal Converter *
***********************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define HEX_BASE 16 /* hexadecimal base */

/* function prototypes */
void clear_input_buffer();
void print_binary(int hex_digit);
void print_octal(int hex_digit);
void print_decimal(int hex_digit);
void print_hex_digit(int hex_digit);
void convert_hex_string(char* hex_string);

/* main function */
int main() {
    char hex_string[17]; /* hold 16 hex digits and null terminator */
    
    printf("Enter a hexadecimal number (up to 16 digits): ");
    scanf("%16s", hex_string);
    convert_hex_string(hex_string);
    
    return 0;
}

/* Function to clear the input buffer */
void clear_input_buffer() {
    while (getchar() != '\n');
}

/* Function to print a binary representation of a hexadecimal digit */
void print_binary(int hex_digit) {
    printf("0b"); /* print binary prefix */

    /* print each binary bit */
    for (int i = 3; i >= 0; --i) {
        if (hex_digit & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }

    printf(" ");
}

/* Function to print an octal representation of a hexadecimal digit */
void print_octal(int hex_digit) {
    printf("%o ", hex_digit);
}

/* Function to print a decimal representation of a hexadecimal digit */
void print_decimal(int hex_digit) {
    printf("%d ", hex_digit);
}

/* Function to print a hexadecimal digit */
void print_hex_digit(int hex_digit) {
    if (hex_digit < 10) {
        printf("%d ", hex_digit);
    } else {
        printf("%c ", hex_digit + 55);
    }
}

/* Function to convert a hexadecimal string to binary, octal, decimal, and hexadecimal */
void convert_hex_string(char* hex_string) {
    int hex_digit; /* holds the current hex digit being converted */
    
    /* loop through each character in the hex string */
    for (int i = 0; hex_string[i] != '\0'; ++i) {
        hex_digit = toupper(hex_string[i]);
        /* check if character is a valid hexadecimal digit */
        if (isdigit(hex_digit) || (hex_digit >= 'A' && hex_digit <= 'F')) {
            hex_digit = (hex_digit >= 'A') ? hex_digit - 'A' + 10 : hex_digit - '0';

            /* print the various representations of the current hex digit */
            printf("Hex digit %d: ", i + 1);
            print_binary(hex_digit);
            print_octal(hex_digit);
            print_decimal(hex_digit);
            print_hex_digit(hex_digit);
            printf("\n");
        } else {
            printf("Invalid hexadecimal digit %c\n", hex_string[i]);
            clear_input_buffer();
            return;
        }
    }
}