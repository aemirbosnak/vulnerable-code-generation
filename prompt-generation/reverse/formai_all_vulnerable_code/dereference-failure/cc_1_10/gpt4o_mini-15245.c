//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate a word from English to Cat Language
char* translateToCatLanguage(const char* word) {
    // Allocate memory for the translated word
    size_t wordLen = strlen(word);
    // Adjust size and allocate space for the new Cat language word
    // +4 for '-meow' and '\0' null terminator
    char* catWord = (char*)malloc((wordLen + 5) * sizeof(char)); 
    if (catWord == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    
    // Construct the Cat Language word
    strcpy(catWord, word);
    strcat(catWord, "-meow");
    
    return catWord; 
}

// Function to translate a sentence to Cat Language
void translateSentence(const char* sentence) {
    char* tempSentence = strdup(sentence); // Duplicate the input sentence
    if (tempSentence == NULL) {
        perror("Failed to allocate memory for sentence");
        exit(EXIT_FAILURE);
    }

    const char delim[2] = " ";
    char* token = strtok(tempSentence, delim); // Tokenize the sentence

    printf("Translated to Cat Language: ");
    
    while (token != NULL) {
        char* translatedWord = translateToCatLanguage(token); // Translate each word
        printf("%s ", translatedWord); // Print the translated word
        free(translatedWord); // Free allocated memory
        token = strtok(NULL, delim); // Get the next token
    }

    printf("\n");
    free(tempSentence); // Free the duplicated sentence
}

int main() {
    char input[256]; // Buffer for user input

    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter a sentence in English (or 'exit' to quit):\n");

    while (1) {
        printf("> "); // Prompt
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // If input fails, exit loop
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check for exit condition
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the Cat Language Translator. Meow!\n");
            break;
        }

        // Translate the entered sentence to Cat Language
        translateSentence(input);
    }

    return 0;
}