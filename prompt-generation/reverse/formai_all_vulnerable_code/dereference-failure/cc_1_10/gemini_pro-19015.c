//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char *alien_dictionary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", "A", "B", "C", "D",
    "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",
    "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", "!", "@", "#", "$", "%", "^", "&", "*",
    "(", ")", "-", "_", "=", "+", "[", "]", "{", "}",
    "\\", "|", ";", ":", "'", "\"", ",", ".", "/", "<",
    ">", "?", "`", "~"
};

// Define the English language dictionary
char *english_dictionary[] = {
    "apple", "banana", "cherry", "dog", "elephant", "fish",
    "grape", "horse", "ice cream", "juice", "kiwi", "lemon",
    "mango", "nut", "orange", "peach", "pear", "pineapple",
    "queen", "rabbit", "strawberry", "tiger", "umbrella",
    "violin", "watermelon", "x-ray", "yacht", "zebra"
};

// Translate an Alien word to English
char *alien_to_english(char *alien_word) {
    int i;
    for (i = 0; i < sizeof(alien_dictionary) / sizeof(char *); i++) {
        if (strcmp(alien_word, alien_dictionary[i]) == 0) {
            return english_dictionary[i];
        }
    }
    return NULL;
}

// Translate an English word to Alien
char *english_to_alien(char *english_word) {
    int i;
    for (i = 0; i < sizeof(english_dictionary) / sizeof(char *); i++) {
        if (strcmp(english_word, english_dictionary[i]) == 0) {
            return alien_dictionary[i];
        }
    }
    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <alien_word> <english_word>\n", argv[0]);
        return 1;
    }

    char *alien_word = argv[1];
    char *english_word = argv[2];

    char *english_translation = alien_to_english(alien_word);
    if (english_translation == NULL) {
        printf("Alien word '%s' not found in dictionary.\n", alien_word);
        return 1;
    }

    char *alien_translation = english_to_alien(english_word);
    if (alien_translation == NULL) {
        printf("English word '%s' not found in dictionary.\n", english_word);
        return 1;
    }

    printf("Alien word '%s' translates to English '%s'.\n", alien_word, english_translation);
    printf("English word '%s' translates to Alien '%s'.\n", english_word, alien_translation);

    return 0;
}