//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Alien Language Struct
typedef struct AlienLanguage {
    char *symbol;
    char *translation;
} AlienWord;

// Initialize Alien Language Translation Table
AlienWord alienTranslateTable[] = {
    {"ZORK", "Hello, Earthling!"},
    {"XLRT", "How are you?"},
    {"BLAT", "What is your name?"},
    {"SQUX", "Nice to meet you"},
    {"GRKT", "Where is the bathroom?"},
    {"KLON", "Goodbye"},
    {NULL, NULL}
};

// Function to translate Alien Language
void translateAlienLanguage(char *alienMessage) {
    char alienWord[20];
    int i;

    strcpy(alienWord, strtok(alienMessage, " ")); // Get first alien word

    for (i = 0; alienTranslateTable[i].symbol != NULL; i++) {
        if (strcasecmp(alienWord, alienTranslateTable[i].symbol) == 0) { // Match found
            printf("%s: %s\n", alienWord, alienTranslateTable[i].translation);
            strcpy(alienWord, strtok(NULL, " ")); // Get next alien word
            break;
        }
    }

    if (alienTranslateTable[i].symbol == NULL) { // Unknown word
        printf("Unknown alien word: %s\n", alienWord);
    }
}

int main() {
    char alienMessage[100];

    printf("Greetings, Earthling! Enter alien message: ");
    fgets(alienMessage, sizeof(alienMessage), stdin);

    // Remove newline character from fgets input
    alienMessage[strcspn(alienMessage, "\n")] = '\0';

    printf("\nAlien Message: %s\n", alienMessage);
    translateAlienLanguage(alienMessage);

    return 0;
}