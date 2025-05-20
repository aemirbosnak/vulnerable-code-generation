//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

bool is_hex(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    if (c >= 'A' && c <= 'F') {
        return true;
    }
    if (c >= 'a' && c <= 'f') {
        return true;
    }
    return false;
}

int get_hex_value(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return -1;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    char input_line[MAX_LINE_LENGTH];
    while (fgets(input_line, MAX_LINE_LENGTH, input_file)!= NULL) {
        int hex_value = 0;
        int i = 0;
        while (input_line[i]!= '\0') {
            char c = tolower(input_line[i]);
            if (!is_hex(c)) {
                printf("Error: invalid character '%c' at position %d.\n", c, i);
                return 2;
            }
            int hex_digit = get_hex_value(c);
            if (hex_digit == -1) {
                printf("Error: invalid character '%c' at position %d.\n", c, i);
                return 3;
            }
            hex_value = (hex_value << 4) | hex_digit;
            i++;
        }

        printf("Hexadecimal value: %X\n", hex_value);
    }

    fclose(input_file);
    return 0;
}