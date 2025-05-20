//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold translations
typedef struct {
    char *english;
    char *alien;
} Translation;

// Function to display the menu
void displayMenu() {
    printf("\n--- Alien Language Translator ---\n");
    printf("1. Translate English to Alien\n");
    printf("2. Translate Alien to English\n");
    printf("3. Add new translation\n");
    printf("4. Exit\n");
}

// Function to add new translations to the list
void addTranslation(Translation **translations, int *count) {
    *translations = realloc(*translations, (*count + 1) * sizeof(Translation));

    char *eng = malloc(100);
    char *ali = malloc(100);

    printf("Enter English phrase: ");
    scanf(" %[^\n]", eng);
    printf("Enter corresponding Alien phrase: ");
    scanf(" %[^\n]", ali);

    (*translations)[*count].english = eng;
    (*translations)[*count].alien = ali;
    (*count)++;

    printf("Translation added successfully!\n");
}

// Function to translate from English to Alien
void translateToAlien(Translation *translations, int count) {
    char input[100];
    printf("Enter English phrase to translate: ");
    scanf(" %[^\n]", input);

    for (int i = 0; i < count; i++) {
        if (strcmp(translations[i].english, input) == 0) {
            printf("Alien Translation: %s\n", translations[i].alien);
            return;
        }
    }

    printf("Translation not found!\n");
}

// Function to translate from Alien to English
void translateToEnglish(Translation *translations, int count) {
    char input[100];
    printf("Enter Alien phrase to translate: ");
    scanf(" %[^\n]", input);

    for (int i = 0; i < count; i++) {
        if (strcmp(translations[i].alien, input) == 0) {
            printf("English Translation: %s\n", translations[i].english);
            return;
        }
    }

    printf("Translation not found!\n");
}

// Function to free memory used by translations
void freeTranslations(Translation *translations, int count) {
    for (int i = 0; i < count; i++) {
        free(translations[i].english);
        free(translations[i].alien);
    }
    free(translations);
}

int main() {
    Translation *translations = NULL;
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                translateToAlien(translations, count);
                break;
            case 2:
                translateToEnglish(translations, count);
                break;
            case 3:
                addTranslation(&translations, &count);
                break;
            case 4:
                printf("Exiting the translator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeTranslations(translations, count);
    return 0;
}