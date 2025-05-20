//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// Function prototypes
void menu();
void translatePhrase(char *phrase);
void translateWord(char *word);
void displayHelp();
char* alienLanguage(char *str);

int main() {
    char phrase[MAX_LENGTH];
    int choice;

    do {
        menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // consume newline character left by scanf

        switch(choice) {
            case 1:
                printf("Enter the phrase to translate: ");
                fgets(phrase, sizeof(phrase), stdin);
                phrase[strcspn(phrase, "\n")] = 0; // remove newline character
                translatePhrase(phrase);
                break;
            case 2:
                printf("Enter a word to translate: ");
                fgets(phrase, sizeof(phrase), stdin);
                phrase[strcspn(phrase, "\n")] = 0; // remove newline character
                translateWord(phrase);
                break;
            case 3:
                displayHelp();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to display menu options
void menu() {
    printf("\n--- Alien Language Translator ---\n");
    printf("1. Translate a Phrase\n");
    printf("2. Translate a Word\n");
    printf("3. Help\n");
    printf("4. Exit\n");
}

// Function to translate a given phrase
void translatePhrase(char *phrase) {
    printf("Translating phrase: '%s'\n", phrase);
    char *translatedPhrase = alienLanguage(phrase);
    printf("Translated Phrase: '%s'\n", translatedPhrase);
    free(translatedPhrase); // Free memory allocated by alienLanguage
}

// Function to translate a single word
void translateWord(char *word) {
    printf("Translating word: '%s'\n", word);
    char *translatedWord = alienLanguage(word);
    printf("Translated Word: '%s'\n", translatedWord);
    free(translatedWord); // Free memory allocated by alienLanguage
}

// Function to display help information
void displayHelp() {
    printf("\n--- Help ---\n");
    printf("This program translates phrases and words into an alien language.\n");
    printf("1. Select 'Translate a Phrase' to enter a phrase.\n");
    printf("2. Select 'Translate a Word' to enter a single word.\n");
    printf("3. The alien language is a simple transformation of characters.\n");
    printf("4. Select 'Exit' to close the program.\n");
}

// Function to convert regular text to alien language
char* alienLanguage(char *str) {
    int length = strlen(str);
    char *alienText = (char *)malloc(length * 2); // allocate max space for alien string
    int index = 0;

    for(int i = 0; i < length; i++) {
        switch(str[i]) {
            case 'a': alienText[index++] = 'z'; break;
            case 'e': alienText[index++] = 'y'; break;
            case 'i': alienText[index++] = 'x'; break;
            case 'o': alienText[index++] = 'w'; break;
            case 'u': alienText[index++] = 'v'; break;
            case 'A': alienText[index++] = 'Z'; break;
            case 'E': alienText[index++] = 'Y'; break;
            case 'I': alienText[index++] = 'X'; break;
            case 'O': alienText[index++] = 'W'; break;
            case 'U': alienText[index++] = 'V'; break;
            default: alienText[index++] = str[i]; break; // for all other characters
        }
    }
    alienText[index] = '\0'; // null-terminate the string
    return alienText;
}