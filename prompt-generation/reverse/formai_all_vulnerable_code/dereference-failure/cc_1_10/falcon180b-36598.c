//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000000
#define MAX_OUTPUT_SIZE (MAX_INPUT_SIZE * 8)

int main(int argc, char **argv) {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    int input_size, output_size;
    int i;

    // Check if the user provided a binary input
    if (argc < 2) {
        printf("Usage: %s <binary input>\n", argv[0]);
        return 1;
    }

    // Copy the input to a buffer
    strncpy(input, argv[1], MAX_INPUT_SIZE);
    input_size = strlen(input);

    // Convert the binary input to decimal
    for (i = 0; i < input_size; i++) {
        if (input[i] == '1') {
            output_size++;
        }
    }

    // Allocate memory for the decimal output
    output_size = MAX_OUTPUT_SIZE - 1;
    output[output_size--] = '\0';
    for (i = 0; i < output_size; i++) {
        output[i] = '0';
    }

    // Convert the binary input to decimal
    for (i = input_size - 1; i >= 0; i--) {
        if (input[i] == '1') {
            output[output_size--] = '1';
        } else {
            output[output_size--] = '0';
        }
    }

    // Print the decimal output
    printf("Decimal output: %s\n", output);

    return 0;
}