//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the alien language dictionary.
char *alien_dictionary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", "A", "B", "C", "D",
    "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",
    "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", "!", "@", "#", "$", "%", "^", "&", "*",
    "(", ")", "-", "_", "+", "=", "[", "]"
};

// Define the English language dictionary.
char *english_dictionary[] = {
    "alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india", "juliet",
    "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo", "sierra", "tango",
    "uniform", "victor", "whiskey", "xray", "yankee", "zulu", "ALPHA", "BRAVO", "CHARLIE", "DELTA",
    "ECHO", "FOXTROT", "GOLF", "HOTEL", "INDIA", "JULIET", "KILO", "LIMA", "MIKE", "NOVEMBER",
    "OSCAR", "PAPA", "QUEBEC", "ROMEO", "SIERRA", "TANGO", "UNIFORM", "VICTOR", "WHISKEY", "XRAY",
    "YANKEE", "ZULU", "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN",
    "EIGHT", "NINE", "EXCLAMATION", "AT", "HASH", "DOLLAR", "PERCENT", "CARET", "AMPERSAND", "ASTERISK",
    "LEFT_PAREN", "RIGHT_PAREN", "HYPHEN", "UNDERSCORE", "PLUS", "EQUALS", "LEFT_BRACKET", "RIGHT_BRACKET"
};

// Translate an alien word to English.
char *alien_to_english(char *alien_word) {
    int i;

    // Find the alien word in the alien dictionary.
    for (i = 0; i < sizeof(alien_dictionary) / sizeof(char *); i++) {
        if (strcmp(alien_word, alien_dictionary[i]) == 0) {
            return english_dictionary[i];
        }
    }

    // The alien word was not found in the dictionary.
    return NULL;
}

// Translate an English word to alien.
char *english_to_alien(char *english_word) {
    int i;

    // Find the English word in the English dictionary.
    for (i = 0; i < sizeof(english_dictionary) / sizeof(char *); i++) {
        if (strcmp(english_word, english_dictionary[i]) == 0) {
            return alien_dictionary[i];
        }
    }

    // The English word was not found in the dictionary.
    return NULL;
}

// Print the usage information.
void usage() {
    printf("Usage: alien_language_translator <mode> <word>\n");
    printf("Modes:\n");
    printf("  -e: English to alien\n");
    printf("  -a: Alien to English\n");
}

int main(int argc, char **argv) {
    char *mode;
    char *word;
    char *translation;

    // Check the command line arguments.
    if (argc != 3) {
        usage();
        return 1;
    }

    mode = argv[1];
    word = argv[2];

    // Translate the word.
    if (strcmp(mode, "-e") == 0) {
        translation = english_to_alien(word);
    } else if (strcmp(mode, "-a") == 0) {
        translation = alien_to_english(word);
    } else {
        usage();
        return 1;
    }

    // Print the translation.
    if (translation != NULL) {
        printf("%s\n", translation);
    } else {
        printf("The word '%s' was not found in the dictionary.\n", word);
    }

    return 0;
}