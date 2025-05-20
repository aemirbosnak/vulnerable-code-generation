//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256
#define ALIEN_LANGUAGE_SIZE 5

// Structures for the Alien language translation
typedef struct {
    char english[20];
    char alien[20];
} Translation;

// Sample vocabulary of English to Alien translations
Translation glossary[] = {
    {"hello", "zort"},
    {"world", "blon"},
    {"friend", "gretch"},
    {"alien", "krath"},
    {"language", "fuurn"},
};

int glossarySize = sizeof(glossary) / sizeof(glossary[0]);

// Function to translate a word from English to Alien
const char* translate(const char* word) {
    for (int i = 0; i < glossarySize; i++) {
        if (strcmp(glossary[i].english, word) == 0) {
            return glossary[i].alien;
        }
    }
    return NULL;
}

// Function to read a sentence and translate it to Alien language
void translateSentence(const char* sentence) {
    char* token;
    char* inputCopy = strdup(sentence);
    char* rest = inputCopy;

    printf("Translating to Alien language:\n");
    
    while ((token = strtok_r(rest, " ", &rest))) {
        const char* alienWord = translate(token);
        if (alienWord) {
            printf("%s ", alienWord);
        } else {
            printf("%s ", token); // unchanged if not found in glossary
        }
    }
    printf("\n");
    free(inputCopy);
}

int main() {
    char inputBuffer[MAX_BUFFER];
    
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a sentence in English to translate (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(inputBuffer, MAX_BUFFER, stdin);
        
        // Removing the newline character at the end
        inputBuffer[strcspn(inputBuffer, "\n")] = 0;

        if (strcmp(inputBuffer, "exit") == 0) {
            break;
        }

        translateSentence(inputBuffer);
    }

    printf("Thank you for using the Alien Language Translator! Goodbye!\n");
    return 0;
}