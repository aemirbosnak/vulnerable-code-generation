//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char alien_dict[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char english_dict[] = "etaoinshrdlucmfwypvbgkjqxzETAOINSRHDLUMCFWYPVBGKJQXZ 0123456789";

// Function to translate an Alien word into English
char *alien_to_english(char *alien_word) {
    int i, len;
    char *english_word;

    len = strlen(alien_word);
    english_word = malloc(len + 1);

    for (i = 0; i < len; i++) {
        english_word[i] = strchr(alien_dict, alien_word[i]) - alien_dict;
    }

    english_word[len] = '\0';

    return english_word;
}

// Function to translate an English word into Alien
char *english_to_alien(char *english_word) {
    int i, len;
    char *alien_word;

    len = strlen(english_word);
    alien_word = malloc(len + 1);

    for (i = 0; i < len; i++) {
        alien_word[i] = strchr(english_dict, english_word[i]) - english_dict;
    }

    alien_word[len] = '\0';

    return alien_word;
}

// Main function
int main() {
    char *alien_word = "etaoi";
    char *english_word = "hello";

    // Translate the Alien word into English
    char *translated_english_word = alien_to_english(alien_word);

    // Print the translated English word
    printf("Alien word: %s\n", alien_word);
    printf("Translated English word: %s\n", translated_english_word);

    // Translate the English word into Alien
    char *translated_alien_word = english_to_alien(english_word);

    // Print the translated Alien word
    printf("English word: %s\n", english_word);
    printf("Translated Alien word: %s\n", translated_alien_word);

    return 0;
}