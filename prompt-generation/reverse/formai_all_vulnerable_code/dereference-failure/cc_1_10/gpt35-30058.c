//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Turing-style function headers
void compress(char *input, char *output);
void decompress(char *input, char *output);

int main() {
    char input[1000], output[1000];
    printf("Enter input string: ");
    fgets(input, 1000, stdin);

    // Compress the string
    compress(input, output);
    printf("Compressed string: %s\n", output);

    // Decompress the string
    decompress(output, input);
    printf("Decompressed string: %s\n", input);

    return 0;
}

void compress(char *input, char *output) {
    int len = strlen(input);
    int i = 0, j = 0, count = 1;

    // Iterate through input string
    while (i < len) {
        // Check for repeating characters
        while (input[i] == input[i+1]) {
            count++;
            i++;
        }

        // Write compressed data to output string
        output[j++] = input[i];
        if (count > 1) {
            char count_str[5];
            sprintf(count_str, "%d", count);
            strcat(output, count_str);
            j += strlen(count_str);
        }

        count = 1;
        i++;
    }

    // Null-terminate the output string
    output[j] = '\0';
}

void decompress(char *input, char *output) {
    int len = strlen(input);
    int i = 0, j = 0, count = 0;

    // Iterate through input string
    while (i < len) {
        // Check for repeating characters
        if (input[i+1] >= '0' && input[i+1] <= '9') {
            count = input[i+1] - '0';
            if (input[i+2] >= '0' && input[i+2] <= '9') {
                count = count * 10 + input[i+2] - '0';
                i++;
            }
            for (int k = 0; k < count-1; k++) {
                output[j++] = input[i];
            }
        } else {
            output[j++] = input[i];
        }
        i++;
    }

    // Null-terminate the output string
    output[j] = '\0';
}