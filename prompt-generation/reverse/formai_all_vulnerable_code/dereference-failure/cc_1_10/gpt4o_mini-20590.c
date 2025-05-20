//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 256

// Function declarations
void printInstructions();
char* alienTranslate(const char* text);
char* reverseString(const char* str);
int isVowel(char c);
void freeTranslatedString(char* translated);

int main() {
    printInstructions();

    char inputText[MAX_LENGTH];
    printf("Enter text to translate into Alien Language (type 'exit' to quit):\n");

    while (1) {
        fgets(inputText, MAX_LENGTH, stdin);
        // Remove the newline character from fgets
        inputText[strcspn(inputText, "\n")] = 0;

        if (strcmp(inputText, "exit") == 0) {
            break; // Exit the loop if the user types 'exit'
        }

        char* translatedText = alienTranslate(inputText);
        printf("Translated to Alien Language: %s\n", translatedText);
        freeTranslatedString(translatedText); // Free the memory allocated for the translated string
    }

    printf("Goodbye!\n");
    return 0;
}

// Print instructions for the user
void printInstructions() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("In the Alien Language:\n");
    printf("- Each vowel (a, e, i, o, u) is replaced with its position in the alphabet (1-5)\n");
    printf("- Each consonant is reversed in the output string.\n");
    printf("Type your text and see how it transforms!\n");
}

// Translate the given text into Alien Language
char* alienTranslate(const char* text) {
    int length = strlen(text);
    char* translated = (char*)malloc((length * 3) + 1); // Allocate enough space for the translation
    if (translated == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    
    int pos = 0;
    for (int i = 0; i < length; i++) {
        char c = text[i];
        if (isVowel(c)) {
            switch (c) {
                case 'a': translated[pos++] = '1'; break;
                case 'e': translated[pos++] = '2'; break;
                case 'i': translated[pos++] = '3'; break;
                case 'o': translated[pos++] = '4'; break;
                case 'u': translated[pos++] = '5'; break;
                default: break; // Just in case
            }
        } else if (c >= 'a' && c <= 'z') {
            // Reverse consonant
            char* reversed = reverseString((char[]){c, '\0'});
            strcpy(&translated[pos], reversed);
            pos += strlen(reversed);
            free(reversed);
        } else if (c >= 'A' && c <= 'Z') {
            // Handle uppercase consonants by converting to lowercase
            char lowerC = c + ('a' - 'A');
            char* reversed = reverseString((char[]){lowerC, '\0'});
            strcpy(&translated[pos], reversed);
            pos += strlen(reversed);
            free(reversed);
        } else {
            // Just copy non-alphabetical characters as they are
            translated[pos++] = c;
        }
    }
    translated[pos] = '\0';
    return translated;
}

// Reverse the input character string
char* reverseString(const char* str) {
    int n = strlen(str);
    char* reversed = (char*)malloc(n + 1);
    if (reversed == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        reversed[i] = str[n - i - 1];
    }
    reversed[n] = '\0'; // Null-terminate the reversed string
    return reversed;
}

// Check if the given character is a vowel
int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Free the translated string memory
void freeTranslatedString(char* translated) {
    free(translated);
}