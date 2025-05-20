//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate a word from English to Alien language
char *translateToAlien(char *word) {
    // Create a new string to store the translated word
    char *alienWord = malloc(strlen(word) + 1);

    // Iterate over the characters in the word
    for (int i = 0; i < strlen(word); i++) {
        // Replace each character with its Alien language equivalent
        switch (word[i]) {
            case 'A':
                alienWord[i] = 'X';
                break;
            case 'B':
                alienWord[i] = 'Y';
                break;
            case 'C':
                alienWord[i] = 'Z';
                break;
            default:
                // If the character is not a letter, copy it as is
                alienWord[i] = word[i];
        }
    }

    // Add the null-terminator to the end of the string
    alienWord[strlen(word)] = '\0';

    // Return the translated word
    return alienWord;
}

// Function to print the Alien language translation of a sentence
void printAlienTranslation(char *sentence) {
    // Tokenize the sentence into words
    char *token = strtok(sentence, " ");

    // Iterate over the words in the sentence
    while (token != NULL) {
        // Translate the word to Alien language
        char *alienWord = translateToAlien(token);

        // Print the translated word
        printf("%s ", alienWord);

        // Free the memory allocated for the translated word
        free(alienWord);

        // Get the next word in the sentence
        token = strtok(NULL, " ");
    }

    // Print a newline at the end of the sentence
    printf("\n");
}

int main() {
    // Get the sentence to be translated from the user
    char sentence[100];
    printf("Enter the sentence to be translated: ");
    fgets(sentence, 100, stdin);

    // Print the Alien language translation of the sentence
    printf("Alien language translation: ");
    printAlienTranslation(sentence);

    return 0;
}