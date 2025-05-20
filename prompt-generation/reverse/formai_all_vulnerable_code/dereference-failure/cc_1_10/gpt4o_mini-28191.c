//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024
#define ALIEN_SIZE 26

// Function to translate English letters to Alien language
void translateToAlien(const char *input, char *output) {
    char alienAlphabet[ALIEN_SIZE] = {'@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '+', '{', '}', '[', ']', ':', ';', '"', '\'', '<', '>', '?', '/', '~', '`'};
    
    while (*input) {
        if (*input >= 'a' && *input <= 'z') {
            *output = alienAlphabet[*input - 'a'];
        } else if (*input >= 'A' && *input <= 'Z') {
            *output = alienAlphabet[*input - 'A'];
        } else {
            *output = *input; // non-alphabetic characters stay the same
        }
        input++;
        output++;
    }
    *output = '\0'; // null-terminate the output string
}

// Function to display the menu
void displayMenu() {
    printf("=== Alien Language Translator ===\n");
    printf("1. Translate Text\n");
    printf("2. Exit\n");
    printf("=================================\n");
}

// Main program function
int main() {
    char *inputText = (char *)malloc(MAX_INPUT * sizeof(char));
    char *outputText = (char *)malloc(MAX_INPUT * sizeof(char));

    if (inputText == NULL || outputText == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character left in the input buffer

        switch (choice) {
            case 1:
                printf("Enter text to translate: ");
                fgets(inputText, MAX_INPUT, stdin);
                inputText[strcspn(inputText, "\n")] = 0; // remove newline character

                translateToAlien(inputText, outputText);
                printf("Translated Text: %s\n", outputText);
                break;
            case 2:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 2);

    // Free allocated memory
    free(inputText);
    free(outputText);

    return 0;
}