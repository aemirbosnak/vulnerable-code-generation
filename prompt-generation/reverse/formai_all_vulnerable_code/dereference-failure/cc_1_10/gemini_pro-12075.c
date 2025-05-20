//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Define the reset code
#define RESET "\033[0m"

// Define the main function
int main() {
    // Print a welcome message
    printf("Welcome to the Color Code Converter!\n");

    // Get the user's input
    char *input = NULL;
    size_t len = 0;
    printf("Enter your text: ");
    getline(&input, &len, stdin);

    // Convert the user's input to color codes
    char *output = malloc(strlen(input) + 1);
    int i;
    for (i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'a':
                output[i] = RED;
                break;
            case 'e':
                output[i] = GREEN;
                break;
            case 'i':
                output[i] = YELLOW;
                break;
            case 'o':
                output[i] = BLUE;
                break;
            case 'u':
                output[i] = MAGENTA;
                break;
            case 'y':
                output[i] = CYAN;
                break;
            default:
                output[i] = WHITE;
        }
    }

    // Print the converted text
    printf("Your text in color codes: ");
    printf("%s", output);
    printf(RESET);

    // Free the allocated memory
    free(input);
    free(output);

    return 0;
}