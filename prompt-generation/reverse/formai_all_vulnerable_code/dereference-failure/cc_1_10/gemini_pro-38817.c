//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>

// Alien language dictionary
typedef struct {
    char alien_char;
    char english_char;
} alien_dict_entry;

alien_dict_entry alien_dict[] = {
    {'A', 'a'},
    {'B', 'b'},
    {'C', 'c'},
    {'D', 'd'},
    {'E', 'e'},
    {'F', 'f'},
    {'G', 'g'},
    {'H', 'h'},
    {'I', 'i'},
    {'J', 'j'},
    {'K', 'k'},
    {'L', 'l'},
    {'M', 'm'},
    {'N', 'n'},
    {'O', 'o'},
    {'P', 'p'},
    {'Q', 'q'},
    {'R', 'r'},
    {'S', 's'},
    {'T', 't'},
    {'U', 'u'},
    {'V', 'v'},
    {'W', 'w'},
    {'X', 'x'},
    {'Y', 'y'},
    {'Z', 'z'},
    {'a', 'A'},
    {'b', 'B'},
    {'c', 'C'},
    {'d', 'D'},
    {'e', 'E'},
    {'f', 'F'},
    {'g', 'G'},
    {'h', 'H'},
    {'i', 'I'},
    {'j', 'J'},
    {'k', 'K'},
    {'l', 'L'},
    {'m', 'M'},
    {'n', 'N'},
    {'o', 'O'},
    {'p', 'P'},
    {'q', 'Q'},
    {'r', 'R'},
    {'s', 'S'},
    {'t', 'T'},
    {'u', 'U'},
    {'v', 'V'},
    {'w', 'W'},
    {'x', 'X'},
    {'y', 'Y'},
    {'z', 'Z'}
};

// Function to translate an alien word to English
char *alien_to_english(char *alien_word) {
    char *english_word = malloc(strlen(alien_word) + 1);

    for (int i = 0; i < strlen(alien_word); i++) {
        for (int j = 0; j < sizeof(alien_dict) / sizeof(alien_dict_entry); j++) {
            if (alien_word[i] == alien_dict[j].alien_char) {
                english_word[i] = alien_dict[j].english_char;
                break;
            }
        }
    }

    english_word[strlen(alien_word)] = '\0';

    return english_word;
}

// Function to translate an English word to Alien
char *english_to_alien(char *english_word) {
    char *alien_word = malloc(strlen(english_word) + 1);

    for (int i = 0; i < strlen(english_word); i++) {
        for (int j = 0; j < sizeof(alien_dict) / sizeof(alien_dict_entry); j++) {
            if (english_word[i] == alien_dict[j].english_char) {
                alien_word[i] = alien_dict[j].alien_char;
                break;
            }
        }
    }

    alien_word[strlen(english_word)] = '\0';

    return alien_word;
}

// Main function
int main() {
    // Get the alien word from the user
    char *alien_word = malloc(100);
    printf("Enter an alien word: ");
    scanf("%s", alien_word);

    // Translate the alien word to English
    char *english_word = alien_to_english(alien_word);
    printf("English translation: %s\n", english_word);

    // Translate the English word to Alien
    char *new_alien_word = english_to_alien(english_word);
    printf("Alien translation: %s\n", new_alien_word);

    return 0;
}