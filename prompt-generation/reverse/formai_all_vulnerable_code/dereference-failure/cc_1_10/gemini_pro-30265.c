//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *input;
    int input_len;
    char *output;
    int output_len;
} compression_result;

compression_result compress(char *input, int input_len) {
    compression_result result;
    result.input = input;
    result.input_len = input_len;

    // Allocate a buffer for the compressed output.
    result.output = malloc(input_len + 1);
    if (result.output == NULL) {
        perror("malloc");
        exit(1);
    }

    // Compress the input string.
    int output_len = 0;
    int i;
    for (i = 0; i < input_len; i++) {
        // If the current character is the same as the previous character,
        // increment the count.
        if (i > 0 && input[i] == input[i - 1]) {
            result.output[output_len - 1]++;
        } else {
            // Otherwise, add the character and a count of 1 to the output
            // buffer.
            result.output[output_len++] = input[i];
            result.output[output_len++] = 1;
        }
    }

    // Add a null terminator to the output buffer.
    result.output[output_len] = '\0';
    result.output_len = output_len;

    return result;
}

void decompress(compression_result result) {
    // Allocate a buffer for the decompressed output.
    char *output = malloc(result.input_len + 1);
    if (output == NULL) {
        perror("malloc");
        exit(1);
    }

    // Decompress the input string.
    int output_len = 0;
    int i;
    for (i = 0; i < result.input_len; i++) {
        // If the current character is a digit, add that many copies of the
        // previous character to the output buffer.
        if (isdigit(result.input[i])) {
            int count = result.input[i] - '0';
            while (count--) {
                output[output_len++] = result.input[i - 1];
            }
        } else {
            // Otherwise, add the current character to the output buffer.
            output[output_len++] = result.input[i];
        }
    }

    // Add a null terminator to the output buffer.
    output[output_len] = '\0';

    // Print the decompressed string.
    printf("%s\n", output);

    // Free the allocated buffers.
    free(result.output);
    free(output);
}

int main(int argc, char **argv) {
    // Check if the user provided an input string.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input string>\n", argv[0]);
        exit(1);
    }

    // Get the input string from the user.
    char *input = argv[1];
    int input_len = strlen(input);

    // Compress the input string.
    compression_result result = compress(input, input_len);

    // Print the compressed string.
    printf("Compressed string: %s\n", result.output);

    // Decompress the compressed string.
    decompress(result);

    return 0;
}