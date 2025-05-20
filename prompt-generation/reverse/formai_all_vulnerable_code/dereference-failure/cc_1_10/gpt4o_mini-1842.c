//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATION_LENGTH 200
#define MAX_WORDS_IN_INPUT 50

// Function to transform a single character into its alien equivalent
char transformChar(char c) {
    if (isalpha(c)) {
        // Simple transformation based on ASCII values
        return (c + 3) % 128; // Shift character by 3 in ASCII
    }
    return c; // Non-alphabetical characters remain unchanged
}

// Function to translate an English word into an alien language
void translateWord(const char *word, char *translation) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        translation[i] = transformChar(word[i]);
    }
    translation[length] = '\0'; // Null-terminate the translated string
}

// Function to process an input sentence into multiple words
void processInput(const char *input, char words[MAX_WORDS_IN_INPUT][MAX_WORD_LENGTH], int *wordCount) {
    char *token = strtok(strdup(input), " ");
    *wordCount = 0;

    while (token != NULL) {
        strcpy(words[*wordCount], token);
        (*wordCount)++;
        token = strtok(NULL, " ");
    }
}

// Function to translate a sentence into alien language
void translateSentence(const char *input, char *output) {
    char words[MAX_WORDS_IN_INPUT][MAX_WORD_LENGTH];
    int wordCount;
    processInput(input, words, &wordCount);

    output[0] = '\0'; // Initialize the output string

    for (int i = 0; i < wordCount; i++) {
        char translated[MAX_TRANSLATION_LENGTH];
        translateWord(words[i], translated);
        
        strcat(output, translated);
        if (i < wordCount - 1) {
            strcat(output, " "); // Add space between words
        }
    }
}

// Main function to get user input and display translation
int main() {
    char input[MAX_TRANSLATION_LENGTH];
    char output[MAX_TRANSLATION_LENGTH];

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter a sentence in English (max 200 characters): \n");
    fgets(input, MAX_TRANSLATION_LENGTH, stdin);

    // Remove newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    translateSentence(input, output);
    printf("Translated into Alien Language: %s\n", output);

    return 0;
}