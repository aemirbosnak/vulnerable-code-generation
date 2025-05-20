//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PHRASE_LENGTH 256
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

// Function prototypes
void toCatLanguage(char phrase[], char translatedPhrase[]);
void translateWord(char *word, char *translatedWord);
void appendCatSounds(char *word, char *translatedWord);
void convertToUpperCase(char *word);
void processInput(char *phrase);

int main() {
    char phrase[MAX_PHRASE_LENGTH];
    char translatedPhrase[MAX_PHRASE_LENGTH];

    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter an English phrase (type 'exit' to quit):\n");

    while (1) {
        processInput(phrase);
        if (strcmp(phrase, "exit") == 0) break; // Exit condition
        toCatLanguage(phrase, translatedPhrase);
        printf("Cat Language Translation: %s\n\n", translatedPhrase);
    }

    printf("Thank you for using the Cat Language Translator. Goodbye!\n");
    return 0;
}

void processInput(char *phrase) {
    printf(">> ");
    fgets(phrase, MAX_PHRASE_LENGTH, stdin);
    phrase[strcspn(phrase, "\n")] = 0; // Remove trailing newline character
}

void toCatLanguage(char phrase[], char translatedPhrase[]) {
    char *word;
    char translatedWord[MAX_WORD_LENGTH];
    translatedPhrase[0] = '\0'; // Initialize translatedPhrase as empty

    word = strtok(phrase, " ");
    while (word != NULL) {
        translateWord(word, translatedWord);
        strcat(translatedPhrase, translatedWord);
        strcat(translatedPhrase, " "); // Add space between words
        word = strtok(NULL, " ");
    }

    // Remove the trailing space
    if (translatedPhrase[strlen(translatedPhrase) - 1] == ' ') {
        translatedPhrase[strlen(translatedPhrase) - 1] = '\0';
    }
}

void translateWord(char *word, char *translatedWord) {
    // Start with a basic modification that simulates "Cat Language"
    appendCatSounds(word, translatedWord);
}

void appendCatSounds(char *word, char *translatedWord) {
    // Basic rules for translating to "Cat Language"
    int len = strlen(word);

    // Transform first letter to upper case, if not already
    char upperCaseWord[MAX_WORD_LENGTH];
    convertToUpperCase(word);
    strcpy(upperCaseWord, word);

    // Append "meow" for a whimsical cat effect
    snprintf(translatedWord, MAX_WORD_LENGTH, "%s-meow", upperCaseWord);
}

void convertToUpperCase(char *word) {
    if (word[0] != '\0') {
        word[0] = toupper(word[0]); // Capitalize the first letter
    }
}