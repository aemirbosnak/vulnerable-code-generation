//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
char alien_dict[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-:";

// English language dictionary
char english_dict[] = "etaoinshrdlcumwfgypbvkjxqzETAOINSHRDLUMWFGYPBVKJXQZ0123456789!@#$%^&*()_+=-:";

// Function to translate alien language to English
char *alien_to_english(char *alien_text) {
    char *english_text = malloc(strlen(alien_text) + 1);
    for (int i = 0; i < strlen(alien_text); i++) {
        for (int j = 0; j < strlen(alien_dict); j++) {
            if (alien_text[i] == alien_dict[j]) {
                english_text[i] = english_dict[j];
                break;
            }
        }
    }
    english_text[strlen(alien_text)] = '\0';
    return english_text;
}

// Function to translate English to alien language
char *english_to_alien(char *english_text) {
    char *alien_text = malloc(strlen(english_text) + 1);
    for (int i = 0; i < strlen(english_text); i++) {
        for (int j = 0; j < strlen(english_dict); j++) {
            if (english_text[i] == english_dict[j]) {
                alien_text[i] = alien_dict[j];
                break;
            }
        }
    }
    alien_text[strlen(english_text)] = '\0';
    return alien_text;
}

int main() {
    // Get alien text from user
    char alien_text[100];
    printf("Enter alien text: ");
    scanf("%s", alien_text);

    // Translate alien text to English
    char *english_text = alien_to_english(alien_text);

    // Print English translation
    printf("English translation: %s\n", english_text);

    // Translate English text back to alien
    char *alien_text2 = english_to_alien(english_text);

    // Print alien translation
    printf("Alien translation: %s\n", alien_text2);

    // Free memory
    free(english_text);
    free(alien_text2);

    return 0;
}