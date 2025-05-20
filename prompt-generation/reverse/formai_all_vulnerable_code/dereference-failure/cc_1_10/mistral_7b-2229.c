//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define HEX_ARRAY_SIZE 16

void print_hex(unsigned char hex[]) {
    int i;
    char hex_string[HEX_ARRAY_SIZE * 2 + 1];

    for (i = 0; i < HEX_ARRAY_SIZE; i++) {
        sprintf(hex_string + (i * 2), "%02X", hex[i]);
    }
    printf("%s\n", hex_string);
}

int is_hex_character(char c) {
    if (isdigit(c) || (isalpha(c) && isalpha(c) <= 'F') || (isalpha(c) && isalpha(c) >= 'A')) {
        return 1;
    }
    return 0;
}

int hex_string_to_array(char *input, unsigned char output[MAX_INPUT_LENGTH / 2]) {
    int i = 0, j = 0;
    char c;

    while ((c = input[i]) != '\0') {
        if (is_hex_character(c)) {
            if (isdigit(c)) {
                output[j++] = (unsigned char) (isdigit(c) ? c - '0' : c - 'A' + 10);
            } else {
                output[j++] = (unsigned char) (isalpha(c) ? c - 'A' : c - '0' - 10);
            }
            if (is_hex_character(input[i + 1])) {
                i++;
            }
        } else if (j > 0) {
            i++;
            j--;
        } else {
            printf("Invalid hexadecimal string.\n");
            return 0;
        }
        i++;
    }

    output[MAX_INPUT_LENGTH / 2] = '\0';
    return j + 1;
}

int main() {
    unsigned char hex_array[MAX_INPUT_LENGTH / 2];
    char hex_string[MAX_INPUT_LENGTH];

    printf("Enter a hexadecimal string: ");
    fgets(hex_string, MAX_INPUT_LENGTH, stdin);
    hex_string[strcspn(hex_string, "\n")] = '\0';

    if (hex_string_to_array(hex_string, hex_array) > 0) {
        print_hex(hex_array);
    }

    return 0;
}