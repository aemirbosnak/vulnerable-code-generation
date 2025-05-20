//FormAI DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100

// Function to check if a character is a digit
bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to compress a string using our custom algorithm
void compress(char *input, char *output) {
    int count = 1;
    char current_char = input[0];
    int output_index = 0;
    for (int i = 1; input[i] != '\0' && output_index < MAX_LENGTH; i++) {
        if (input[i] == current_char) {
            count++;
        } else {
            // Add the current character and count to the output string
            output[output_index++] = current_char;
            if (count > 1) {
                for (int j = 0; j < count && output_index < MAX_LENGTH; j++) {
                    // Convert the digit to a character and add it to the output string
                    output[output_index++] = count / (10^j) % 10 + '0';
                }
            }
            // Reset the count and current character
            count = 1;
            current_char = input[i];
        }
    }
    // Add the last character and count to the output string
    output[output_index++] = current_char;
    if (count > 1) {
        for (int j = 0; j < count && output_index < MAX_LENGTH; j++) {
            // Convert the digit to a character and add it to the output string
            output[output_index++] = count / (10^j) % 10 + '0';
        }
    }
    // Add the null termination character to the output string
    output[output_index] = '\0';
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);

    char output[MAX_LENGTH];
    compress(input, output);

    printf("Compressed string: %s\n", output);

    return 0;
}