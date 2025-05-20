//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compress the input string
char* compress(char* input) {
    int i, j;
    char* output = NULL;
    int output_size = 0;

    // iterate through the input string
    for (i = 0; input[i]!= '\0'; i++) {
        // check if the current character is already in the output string
        for (j = 0; j < output_size; j++) {
            if (output[j] == input[i]) {
                // if yes, increase the frequency counter
                output[j]++;
                break;
            }
        }
        // if no, add the character to the output string
        if (j == output_size) {
            output_size++;
            output = realloc(output, output_size * sizeof(char));
            output[output_size - 1] = input[i];
        }
    }
    // add null terminator to the output string
    output_size++;
    output = realloc(output, output_size * sizeof(char));
    output[output_size - 1] = '\0';

    return output;
}

// function to decompress the input string
char* decompress(char* input) {
    int i, j;
    char* output = NULL;
    int output_size = 0;

    // iterate through the input string
    for (i = 0; input[i]!= '\0'; i++) {
        // check if the current character is a frequency counter
        if (input[i] >= '0' && input[i] <= '9') {
            // if yes, add the character to the output string and update the frequency counter
            output_size++;
            output = realloc(output, output_size * sizeof(char));
            output[output_size - 1] = input[i];
        } else {
            // if no, add the character to the output string and update the frequency counter
            int frequency = input[i] - 'a' + 1;
            for (j = 0; j < frequency; j++) {
                output_size++;
                output = realloc(output, output_size * sizeof(char));
                output[output_size - 1] = input[i];
            }
        }
    }
    // add null terminator to the output string
    output_size++;
    output = realloc(output, output_size * sizeof(char));
    output[output_size - 1] = '\0';

    return output;
}

int main() {
    char* input = "aabbbcccdddeeeefffgggg";
    char* compressed = compress(input);
    char* decompressed = decompress(compressed);

    printf("Input string: %s\n", input);
    printf("Compressed string: %s\n", compressed);
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}