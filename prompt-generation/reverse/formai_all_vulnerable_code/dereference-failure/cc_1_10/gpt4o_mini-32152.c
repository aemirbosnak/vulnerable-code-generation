//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256
#define MAX_TRANSLATIONS 10

// Structure to hold the Alien language mappings
typedef struct {
    char english[50];
    char alien[50];
} Translation;

// Function prototypes
void loadTranslations(Translation translations[], int *count);
void translateToAlien(char *input, Translation translations[], int count);
void displayTranslations(Translation translations[], int count);

int main() {
    Translation translations[MAX_TRANSLATIONS];
    int translationCount = 0;

    // Load the translations
    loadTranslations(translations, &translationCount);

    // Display available translations
    displayTranslations(translations, translationCount);

    char input[MAX_INPUT];
    printf("\nEnter a sentence in English to translate into Alien Language:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character
    
    translateToAlien(input, translations, translationCount);

    return 0;
}

void loadTranslations(Translation translations[], int *count) {
    // Sample translations for the Alien Language
    strcpy(translations[(*count)++].english, "hello");
    strcpy(translations[(*count)++].alien, "xylop");
    
    strcpy(translations[(*count)++].english, "world");
    strcpy(translations[(*count)++].alien, "glorp");

    strcpy(translations[(*count)++].english, "goodbye");
    strcpy(translations[(*count)++].alien, "zappo");

    strcpy(translations[(*count)++].english, "friend");
    strcpy(translations[(*count)++].alien, "venka");

    strcpy(translations[(*count)++].english, "alien");
    strcpy(translations[(*count)++].alien, "blorpt");

    strcpy(translations[(*count)++].english, "love");
    strcpy(translations[(*count)++].alien, "hezzik");

    strcpy(translations[(*count)++].english, "peace");
    strcpy(translations[(*count)++].alien, "dormax");

    strcpy(translations[(*count)++].english, "star");
    strcpy(translations[(*count)++].alien, "zaral");

    strcpy(translations[(*count)++].english, "space");
    strcpy(translations[(*count)++].alien, "biol");

    strcpy(translations[(*count)++].english, "universe");
    strcpy(translations[(*count)++].alien, "glumbra");
}

void translateToAlien(char *input, Translation translations[], int count) {
    char *token = strtok(input, " ");
    char alienTranslation[MAX_INPUT] = "";

    while(token != NULL) {
        int found = 0;

        for (int i = 0; i < count; i++) {
            if (strcmp(token, translations[i].english) == 0) {
                strcat(alienTranslation, translations[i].alien);
                strcat(alienTranslation, " "); // Add space after the translation
                found = 1;
                break;
            }
        }

        if (!found) {
            strcat(alienTranslation, token); // If no translation, keep the word
            strcat(alienTranslation, " ");
        }
        
        token = strtok(NULL, " ");
    }

    printf("\nTranslated Alien Language:\n%s\n", alienTranslation);
}

void displayTranslations(Translation translations[], int count) {
    printf("Available translations:\n");
    for(int i = 0; i < count; i++) {
        printf("- %s => %s\n", translations[i].english, translations[i].alien);
    }
}