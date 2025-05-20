//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256
#define MAX_OUTPUT_LENGTH (MAX_INPUT_LENGTH * 2)

void translateToCatLanguage(const char *input, char *output) {
    char *token;
    char translatedWord[MAX_INPUT_LENGTH];
    
    // Initialize output
    output[0] = '\0';

    // Copy input to a mutable string
    char *mutableInput = strdup(input);
    if (!mutableInput) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Tokenize the input string
    token = strtok(mutableInput, " ");
    while (token != NULL) {
        // Translate each word
        if (isalpha(token[0])) { // Ignore punctuation
            sprintf(translatedWord, "%cat, ", tolower(token[0])); // Cat Language Conversion
            strcat(output, translatedWord);
        }
        token = strtok(NULL, " ");
    }

    // Replace last comma and space with " meow"
    if (strlen(output) > 0) {
        output[strlen(output)-2] = ' '; // Replace last ", " with space
        strcat(output, "meow");
    }

    // Clean up
    free(mutableInput);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter a sentence in English (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            perror("Error reading input");
            continue;
        }

        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Translate to Cat Language
        translateToCatLanguage(input, output);
        printf("In Cat Language: %s\n", output);
    }

    printf("Thanks for using the Cat Language Translator!\n");
    return 0;
}