//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char *alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z"
};

// Define the English language dictionary
char *english_dict[] = {
    "ant", "bee", "cat", "dog", "elephant", "fish", "goat", "horse", "iguana", "jaguar",
    "kangaroo", "lion", "monkey", " والنمر", "octopus", "pig", "queen", "rabbit", "snake", "tiger",
    "umbrella", "violin", "whale", "x-ray", "yacht", "zebra"
};

// Function to translate an Alien word to English
char *translate_alien_to_english(char *alien_word) {
    int len = strlen(alien_word);
    char *english_word = (char *)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        char alien_char = alien_word[i];
        int index = alien_char - 'a';
        if (index >= 0 && index < 26) {
            english_word[i] = english_dict[index][0];
        } else {
            english_word[i] = '?';
        }
    }

    english_word[len] = '\0';
    return english_word;
}

// Function to translate an English word to Alien
char *translate_english_to_alien(char *english_word) {
    int len = strlen(english_word);
    char *alien_word = (char *)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        char english_char = english_word[i];
        int index = -1;

        for (int j = 0; j < 26; j++) {
            if (english_char == english_dict[j][0]) {
                index = j;
                break;
            }
        }

        if (index >= 0) {
            alien_word[i] = alien_dict[index] + 'a';
        } else {
            alien_word[i] = '?';
        }
    }

    alien_word[len] = '\0';
    return alien_word;
}

int main() {
    // Get the Alien word from the user
    char alien_word[100];
    printf("Enter an Alien word: ");
    scanf("%s", alien_word);

    // Translate the Alien word to English
    char *english_word = translate_alien_to_english(alien_word);

    // Print the English translation
    printf("English translation: %s\n", english_word);

    // Get the English word from the user
    char english_word2[100];
    printf("Enter an English word: ");
    scanf("%s", english_word2);

    // Translate the English word to Alien
    char *alien_word2 = translate_english_to_alien(english_word2);

    // Print the Alien translation
    printf("Alien translation: %s\n", alien_word2);

    return 0;
}