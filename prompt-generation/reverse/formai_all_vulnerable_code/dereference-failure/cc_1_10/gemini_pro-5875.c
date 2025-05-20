//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define the alien language dictionary
typedef struct {
    char alien_word[50];
    char english_word[50];
} AlienDictEntry;

AlienDictEntry alien_dict[] = {
    {"ploog", "hello"},
    {"fleem", "goodbye"},
    {"grack", "thank you"},
    {"wazoo", "you're welcome"},
    {"bleep", "please"},
    {"bloop", "excuse me"},
    {"zork", "I don't understand"},
    {"quux", "help me"},
    {"bar", "yes"},
    {"foo", "no"}
};

// Get a line of input from the user
char *get_input(void) {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
}

// Translate an alien word to English
char *translate_alien_to_english(char *alien_word) {
    for (int i = 0; i < sizeof(alien_dict) / sizeof(AlienDictEntry); i++) {
        if (strcmp(alien_word, alien_dict[i].alien_word) == 0) {
            return alien_dict[i].english_word;
        }
    }
    return "Unknown word";
}

// Translate an English word to alien
char *translate_english_to_alien(char *english_word) {
    for (int i = 0; i < sizeof(alien_dict) / sizeof(AlienDictEntry); i++) {
        if (strcmp(english_word, alien_dict[i].english_word) == 0) {
            return alien_dict[i].alien_word;
        }
    }
    return "Unknown word";
}

// Print a message in both alien and English
void print_message(char *alien_message, char *english_message) {
    printf("Alien: %s\n", alien_message);
    printf("English: %s\n", english_message);
}

int main(void) {
    // Get the user's input
    char *input = get_input();

    // Check if the user wants to translate from alien to English or from English to alien
    if (input[0] == 'a') {
        // Translate from alien to English
        char *english_message = translate_alien_to_english(input + 1);
        print_message(input + 1, english_message);
    } else if (input[0] == 'e') {
        // Translate from English to alien
        char *alien_message = translate_english_to_alien(input + 1);
        print_message(alien_message, input + 1);
    } else {
        // Invalid input
        printf("Invalid input. Please enter 'a' to translate from alien to English or 'e' to translate from English to alien.\n");
    }

    // Free the input string
    free(input);

    return 0;
}