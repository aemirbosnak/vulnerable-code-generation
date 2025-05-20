//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define DICTIONARY_SIZE 100

// Structure to hold a Cat language translation entry
typedef struct {
    char* english;
    char* catLang;
} Translation;

// Global dictionary to store translations
Translation dictionary[DICTIONARY_SIZE];
int translationCount = 0;

// Function declarations
void loadTranslations();
void translateToCatLang(const char* input);
void toUpper(const char* input, char* output);
void toCatLang(const char* word, char* translated);
void printTranslations();
void freeTranslations();

int main() {
    char input[MAX_WORD_LEN];

    // Load the cat language translations into the dictionary
    loadTranslations();

    printf("Welcome to the Cat Language Translator!\n");
    printf("Type 'exit' to quit.\n\n");

    // Main translation loop
    while (1) {
        printf("Enter English word to translate: ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check for exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Translate to Cat language
        translateToCatLang(input);
    }

    // Clean up and free allocated memory
    freeTranslations();

    return 0;
}

void loadTranslations() {
    // Add translations to the dictionary (this could be expanded)
    dictionary[translationCount++] = (Translation){strdup("hello"), strdup("meow")};
    dictionary[translationCount++] = (Translation){strdup("cat"), strdup("purr")};
    dictionary[translationCount++] = (Translation){strdup("dog"), strdup("hiss")};
    dictionary[translationCount++] = (Translation){strdup("food"), strdup("munch")};
    dictionary[translationCount++] = (Translation){strdup("play"), strdup("paw")};
    // Add more translations as needed
}

void translateToCatLang(const char* input) {
    char translated[MAX_WORD_LEN] = {0};
    char upperWord[MAX_WORD_LEN] = {0};
    
    // Convert input to upper case for better matching
    toUpper(input, upperWord);

    // Attempt to find translation in the dictionary
    int found = 0;
    for (int i = 0; i < translationCount; i++) {
        if (strcasecmp(upperWord, dictionary[i].english) == 0) {
            strcpy(translated, dictionary[i].catLang);
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Cat Language Translation: %s\n", translated);
    } else {
        printf("No translation found for '%s'.\n", input);
    }
}

void toUpper(const char* input, char* output) {
    for (int i = 0; input[i] != '\0' && i < MAX_WORD_LEN; i++) {
        output[i] = toupper(input[i]);
    }
    output[strlen(input)] = '\0'; // Null-terminate the string
}

void freeTranslations() {
    for (int i = 0; i < translationCount; i++) {
        free(dictionary[i].english);
        free(dictionary[i].catLang);
    }
}

void printTranslations() {
    printf("Current Translations:\n");
    for (int i = 0; i < translationCount; i++) {
        printf("English: %s -> Cat: %s\n", dictionary[i].english, dictionary[i].catLang);
    }
}