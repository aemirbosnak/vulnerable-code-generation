//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(void) {
    // Get the input from the user.
    char *input = malloc(MAX_LINE_LENGTH);
    printf("Enter your Cat Language code:\n");
    if (fgets(input, MAX_LINE_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for the output.
    char *output = malloc(MAX_LINE_LENGTH);

    // Translate the Cat Language code to English.
    int i = 0;
    int j = 0;
    while (input[i] != '\0') {
        switch (input[i]) {
            case 'm':
                output[j++] = 'M';
                break;
            case 'e':
                output[j++] = 'E';
                break;
            case 'o':
                output[j++] = 'W';
                break;
            case 'w':
                output[j++] = 'O';
                break;
            default:
                output[j++] = input[i];
                break;
        }
        i++;
    }
    output[j] = '\0';

    // Print the output.
    printf("English translation:\n");
    printf("%s\n", output);

    // Free the memory.
    free(input);
    free(output);

    return EXIT_SUCCESS;
}