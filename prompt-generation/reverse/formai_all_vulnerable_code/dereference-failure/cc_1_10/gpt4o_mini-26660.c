//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_TRANSLATIONS 128

// Struct for Alien Language translations
typedef struct {
    char *englishWord;
    char *alienWord;
} Translation;

// Array to hold translations
Translation translations[MAX_TRANSLATIONS];
int translationCount = 0;

// Function prototypes
void loadTranslations(const char *filename);
char* translateToAlien(const char *english);
void addTranslation(const char *english, const char *alien);
void displayTranslations();
void saveTranslationsToFile(const char *filename);

int main() {
    loadTranslations("translations.txt");

    char input[MAX_LINE_LENGTH];
    printf("Welcome to the Alien Language Translator!\n");
    printf("Type 'exit' to quit or 'show' to display translations.\n");

    while (1) {
        printf("Enter a word to translate: ");
        fgets(input, MAX_LINE_LENGTH, stdin);

        // Remove newline character from the input
        input[strcspn(input, "\n")] = 0;

        if (strcasecmp(input, "exit") == 0) {
            break;
        } else if (strcasecmp(input, "show") == 0) {
            displayTranslations();
            continue;
        }

        char *translation = translateToAlien(input);
        if (translation) {
            printf("Alien Translation: %s\n", translation);
        } else {
            printf("Translation not found! Would you like to add it? (yes/no): ");
            fgets(input, MAX_LINE_LENGTH, stdin);
            input[strcspn(input, "\n")] = 0;
            if (strcasecmp(input, "yes") == 0) {
                char alien[MAX_LINE_LENGTH];
                printf("Enter the Alien Translation: ");
                fgets(alien, MAX_LINE_LENGTH, stdin);
                alien[strcspn(alien, "\n")] = 0;
                addTranslation(input, alien);
                printf("Translation added!\n");
            }
        }
    }

    saveTranslationsToFile("translations.txt");
    printf("Translations saved. Goodbye!\n");
    return 0;
}

// Function to load translations from a file
void loadTranslations(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s for reading, starting with an empty translation list.\n", filename);
        return;
    }
    
    while (!feof(file) && translationCount < MAX_TRANSLATIONS) {
        char line[MAX_LINE_LENGTH];
        if (fgets(line, sizeof(line), file)) {
            char *english = strtok(line, "=");
            char *alien = strtok(NULL, "\n");
            if (english && alien) {
                addTranslation(english, alien);
            }
        }
    }
    fclose(file);
}

// Function to translate English word to Alien language
char* translateToAlien(const char *english) {
    for (int i = 0; i < translationCount; i++) {
        if (strcasecmp(translations[i].englishWord, english) == 0) {
            return translations[i].alienWord;
        }
    }
    return NULL;
}

// Function to add a translation
void addTranslation(const char *english, const char *alien) {
    if (translationCount < MAX_TRANSLATIONS) {
        translations[translationCount].englishWord = strdup(english);
        translations[translationCount].alienWord = strdup(alien);
        translationCount++;
    } else {
        printf("Translation array is full. Cannot add more translations.\n");
    }
}

// Function to display all translations
void displayTranslations() {
    printf("Current Translations:\n");
    for (int i = 0; i < translationCount; i++) {
        printf("%s = %s\n", translations[i].englishWord, translations[i].alienWord);
    }
}

// Function to save translations to a file
void saveTranslationsToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < translationCount; i++) {
        fprintf(file, "%s=%s\n", translations[i].englishWord, translations[i].alienWord);
    }
    fclose(file);
}