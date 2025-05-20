//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_INPUT_LENGTH 500
#define MAX_ALIEN_WORDS 100

// Function prototypes
void translateWord(const char *input, char *output);
void translateSentence(const char *input, char *output);
void readInput(char *input);
void trimWhitespace(char *str);

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];

    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a sentence in English and I will translate it into Alien Language.\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        readInput(input);
        // Check for quitting the program
        if (strcmp(input, "quit") == 0) {
            printf("Exiting the translator. Goodbye!\n");
            break;
        }

        // Translate the input sentence
        translateSentence(input, output);
        printf("Translated to Alien Language: %s\n", output);
    }
    
    return 0;
}

// Function that reads input from the user
void readInput(char *input) {
    printf("> ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    trimWhitespace(input);
}

// Function that translates a single word into Alien Language
void translateWord(const char *input, char *output) {
    int length = strlen(input);
    // Simple transformation rule: reverse the word and append "zap"
    for (int i = 0; i < length; i++) {
        output[length - 1 - i] = input[i];
    }
    output[length] = '\0'; // Null-terminate the string
    strcat(output, " zap"); // Append " zap" to the translated word
}

// Function that translates a full sentence into Alien Language
void translateSentence(const char *input, char *output) {
    const char delimiters[] = " "; // Delimiters for words
    char *token;
    char word[MAX_WORD_LENGTH];
    char translatedWord[MAX_WORD_LENGTH];
    int firstWord = 1;

    output[0] = '\0'; // Initialize output

    // Make a copy of the input string to avoid modifying it
    char *inputCopy = malloc(strlen(input) + 1);
    if (inputCopy == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strcpy(inputCopy, input);

    // Tokenize the input string
    token = strtok(inputCopy, delimiters);
    while (token != NULL) {
        translateWord(token, translatedWord);
        if (firstWord) {
            firstWord = 0; // Not the first word anymore
        } else {
            strcat(output, " "); // Add space between words
        }
        strcat(output, translatedWord);
        token = strtok(NULL, delimiters);
    }

    free(inputCopy); // Free allocated memory
}

// Function to trim whitespace from the start and end of a string
void trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;
    
    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    
    end[1] = '\0'; // Null-terminate
}