//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the Alien language dictionary
const char *alien_dict[] = {
    "aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj",
    "kk", "ll", "mm", "nn", "oo", "pp", "qq", "rr", "ss", "tt",
    "uu", "vv", "ww", "xx", "yy", "zz"
};

// Define the English language dictionary
const char *english_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z"
};

// Function to translate Alien language to English
char *translate_alien_to_english(char *alien_text) {
    char *english_text = malloc(strlen(alien_text) + 1);
    int i;

    for (i = 0; i < strlen(alien_text); i++) {
        int index = -1;
        for (int j = 0; j < 26; j++) {
            if (strcmp(alien_text + i, alien_dict[j]) == 0) {
                index = j;
                break;
            }
        }

        if (index == -1) {
            english_text[i] = '?';
        } else {
            english_text[i] = english_dict[index];
        }
    }

    english_text[strlen(alien_text)] = '\0';
    return english_text;
}

// Function to translate English language to Alien
char *translate_english_to_alien(char *english_text) {
    char *alien_text = malloc(strlen(english_text) + 1);
    int i;

    for (i = 0; i < strlen(english_text); i++) {
        int index = -1;
        for (int j = 0; j < 26; j++) {
            if (english_text[i] == english_dict[j]) {
                index = j;
                break;
            }
        }

        if (index == -1) {
            alien_text[i] = '?';
        } else {
            alien_text[i] = alien_dict[index];
        }
    }

    alien_text[strlen(english_text)] = '\0';
    return alien_text;
}

int main() {
    char alien_text[] = "aaddbbcc";
    char english_text[] = "abcd";
    char *translated_alien_text;
    char *translated_english_text;

    // Translate Alien language to English
    translated_alien_text = translate_alien_to_english(alien_text);
    printf("Alien text: %s\n", alien_text);
    printf("Translated English text: %s\n", translated_alien_text);
    free(translated_alien_text);

    // Translate English language to Alien
    translated_english_text = translate_english_to_alien(english_text);
    printf("English text: %s\n", english_text);
    printf("Translated Alien text: %s\n", translated_english_text);
    free(translated_english_text);

    return 0;
}