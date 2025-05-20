//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *input;
    char *output;
    int i, j;
    int len;
    int hex;

    if (argc!= 3) {
        printf("Usage: %s [input_string] [output_string]\n", argv[0]);
        exit(1);
    }

    input = argv[1];
    output = argv[2];

    len = strlen(input);
    hex = 0;

    // Check if input string contains non-hexadecimal characters
    for (i = 0; i < len; i++) {
        if (!isxdigit(input[i])) {
            printf("Error: Input string contains non-hexadecimal characters.\n");
            exit(1);
        }
    }

    // Convert input string to hexadecimal
    for (i = 0, j = 0; i < len; i += 2, j++) {
        if (isxdigit(input[i]) && isxdigit(input[i + 1])) {
            sprintf(&output[j], "%02X", (unsigned char)input[i]);
        } else {
            sprintf(&output[j], "%c", input[i]);
        }
    }

    // Check if output string is empty
    if (strlen(output) == 0) {
        printf("Error: Input string is empty.\n");
        exit(1);
    }

    printf("Input string: %s\n", input);
    printf("Hexadecimal string: %s\n", output);

    return 0;
}