//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 80
#define HEX_CHARS "0123456789abcdef"

int main() {
    char line[MAX_LINE_LEN];
    char *hex_str = NULL;
    size_t hex_len = 0;

    // Read input from user
    printf("Enter hexadecimal string: ");
    fgets(line, MAX_LINE_LEN, stdin);

    // Remove newline character from input
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }

    // Convert input string to uppercase
    for (int i = 0; i < strlen(line); i++) {
        line[i] = toupper(line[i]);
    }

    // Convert hexadecimal string to binary string
    hex_str = malloc(strlen(line) * 2 + 1); // Allocate memory for binary string
    hex_len = 0;

    for (int i = 0; i < strlen(line); i++) {
        char c = line[i];

        if (isxdigit(c)) {
            if (isdigit(c)) {
                hex_str[hex_len++] = c;
            } else {
                int val = toupper(c) - 'A' + 10;
                hex_str[hex_len++] = val % 16 + '0';
            }
        } else {
            printf("Invalid character: %c\n", c);
            exit(1);
        }
    }

    hex_str[hex_len] = '\0';

    // Print binary string
    printf("Binary string: %s\n", hex_str);

    free(hex_str);

    return 0;
}