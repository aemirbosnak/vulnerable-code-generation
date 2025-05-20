//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function prototypes
void convert_hex(char *input);
bool is_hex(char c);

int main() {
    char input[100];

    printf("Enter a hexadecimal number: ");
    fgets(input, 100, stdin);

    convert_hex(input);

    return 0;
}

// Function to convert hexadecimal to decimal
void convert_hex(char *input) {
    char *output = calloc(strlen(input) * 2, sizeof(char));
    int i = 0, j = 0;

    // Loop through the input string
    for (i = 0; input[i]!= '\0'; i++) {
        // Check if the character is a hexadecimal digit
        if (is_hex(input[i])) {
            // Convert the hexadecimal digit to decimal and add to the output string
            if (isupper(input[i])) {
                output[j] = input[i] - 'A' + 10;
            } else {
                output[j] = input[i] - 'a' + 10;
            }
            j++;
        }
    }

    printf("Decimal equivalent: %s\n", output);
}

// Function to check if a character is a hexadecimal digit
bool is_hex(char c) {
    if (isdigit(c)) {
        return true;
    } else if (isalpha(c)) {
        if (isupper(c)) {
            return true;
        } else if (islower(c)) {
            return true;
        }
    }

    return false;
}