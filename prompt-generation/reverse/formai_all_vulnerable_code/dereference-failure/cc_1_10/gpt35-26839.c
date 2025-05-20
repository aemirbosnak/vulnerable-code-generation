//FormAI DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024

char* compress(char *input) {

    // Initializing variables
    int length = strlen(input);
    int count = 1;
    int index = 0;
    char current_char;
    char *output = (char *) malloc(sizeof(char) * MAX_SIZE);

    // Error handling
    if (output == NULL) {
        printf("Memory allocation unsuccessful!\n");
        exit(EXIT_FAILURE);
    }

    // Compressing the input string
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            current_char = input[i];
            output[index] = current_char;
            index++;
        }
        else {
            if (input[i] == current_char) {
                count++;
                if (count > 9) {
                    output[index] = count / 10 + '0';
                    index++;
                }
                output[index] = count % 10 + '0';
                index++;
            }
            else {
                current_char = input[i];
                count = 1;
                output[index] = current_char;
                index++;
            }
        }
    }

    // Adding null character to end of output string
    output[index] = '\0';

    return output;
}


int main() {

    char input[MAX_SIZE];
    printf("Enter a string to compress: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;

    // Compressing the input string
    char *compressed_string = compress(input);

    // Printing the original and compressed strings
    printf("Original String: %s\n", input);
    printf("Compressed String: %s\n", compressed_string);

    return 0;
}