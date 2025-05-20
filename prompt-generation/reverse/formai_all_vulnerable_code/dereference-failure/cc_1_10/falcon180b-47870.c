//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define HEX_CHARS "0123456789ABCDEF"

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char hex_buffer[MAX_LINE_LENGTH];
    char *hex_output = NULL;
    size_t hex_output_size = 0;
    size_t input_buffer_size = 0;
    int i = 0;
    int j = 0;

    // Prompt the user for input
    printf("Enter a string to convert to hexadecimal: ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    // Remove newline character from input buffer
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    // Convert input buffer to hexadecimal
    for (i = 0; input_buffer[i]!= '\0'; i++) {
        if (isprint(input_buffer[i])) {
            hex_buffer[j] = input_buffer[i];
            j++;
        } else {
            sprintf(&hex_buffer[j], "\\x%02X", input_buffer[i]);
            j += 3;
        }
    }

    // Allocate memory for hex_output
    hex_output_size = j + 1;
    hex_output = malloc(hex_output_size);

    // Convert hex_buffer to uppercase
    for (i = 0; i < j; i++) {
        hex_output[i] = toupper(hex_buffer[i]);
    }

    // Print hexadecimal output
    printf("Hexadecimal output:\n%s\n", hex_output);

    // Free memory
    free(hex_output);

    return 0;
}