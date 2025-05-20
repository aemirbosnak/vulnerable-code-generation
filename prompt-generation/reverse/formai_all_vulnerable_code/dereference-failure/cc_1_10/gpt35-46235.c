//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

// Maximum character count (upper-bound)
#define MAX_CHARACTERS 128

/**
 * Function to compress the input string.
 *
 * @param input the input string.
 * @return a compressed string.
 */
char *compress(char input[]) {
    int count = 0, index = 0;
    char *output = malloc(sizeof(char) * BUFFER_SIZE);
    char ch = input[0];

    for (int i = 0; input[i] != '\0'; i++) {
        // count the number of occurrences of character 'ch'
        if (input[i] == ch) {
            count++;
        } else {
            // encode the count of character 'ch'
            output[index++] = ch;
            output[index++] = count + '0';

            // set the new character and reset the count
            ch = input[i];
            count = 1;
        }
    }

    // encode the last character and its count
    output[index++] = ch;
    output[index++] = count + '0';
    output[index] = '\0';

    return output;
}

/**
 * Function to decompress the input string.
 *
 * @param input the compressed input string.
 * @return a decompressed string.
 */
char *decompress(char input[]) {
    int count = 0, index = 0;
    char *output = malloc(sizeof(char) * BUFFER_SIZE);

    for (int i = 0; input[i] != '\0'; i += 2) {
        // get the character and its count
        char ch = input[i];
        count = input[i + 1] - '0';

        // add the character to the output string
        for (int j = 0; j < count; j++) {
            output[index++] = ch;
        }
    }

    output[index] = '\0';

    return output;
}

int main() {
    char input[BUFFER_SIZE], *compressed, *decompressed;

    // read the input from the user
    printf("Enter a string to compress: ");
    fgets(input, BUFFER_SIZE, stdin);

    // remove the newline character at the end
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // ensure the input contains only ASCII characters
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] > MAX_CHARACTERS) {
            printf("Error: only ASCII characters are supported.\n");
            return 1;
        }
    }

    // compress the input string and print the output
    compressed = compress(input);
    printf("Compressed string: %s\n", compressed);

    // decompress the compressed string and print the output
    decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);

    // free the memory allocated for the compressed and decompressed strings
    free(compressed);
    free(decompressed);

    return 0;
}