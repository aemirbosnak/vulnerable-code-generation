//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORD_COUNT 20
#define MAX_WORD_LENGTH 15

void translate_to_cat_language(char *input, char *output) {
    char *token;
    char delimiter[2] = " ";
    output[0] = '\0'; // Initialize output string to empty

    token = strtok(input, delimiter);
    while (token != NULL) {
        strcat(output, token);      // Append the word
        strcat(output, " meow");    // Append " meow"
        strcat(output, " ");         // Add space between words
        token = strtok(NULL, delimiter); // Get the next word
    }

    // Remove the trailing space at the end of the output string
    if (output[strlen(output) - 1] == ' ') {
        output[strlen(output) - 1] = '\0';
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    char output[MAX_LINE_LENGTH];

    printf("Welcome to the Retro Cat Language Translator!\n");
    printf("Type a sentence and watch it transform into Cat Language!\n");
    printf("Enter 'exit' to close the translator.\n\n");

    while (1) {
        printf("Please enter a sentence: ");
        fgets(input, MAX_LINE_LENGTH, stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the translator. Have a purr-fect day!\n");
            break;
        }

        translate_to_cat_language(input, output);

        printf("In Cat Language: %s\n\n", output);
    }

    return 0;
}