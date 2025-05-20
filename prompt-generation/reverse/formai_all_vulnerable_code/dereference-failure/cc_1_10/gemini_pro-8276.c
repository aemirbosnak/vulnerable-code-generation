//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Initialize the alien language dictionary
char alien_dictionary[26][26] = {
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
    {'B', 'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
    {'C', 'D', 'A', 'B', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
    // ... continue for all 26 letters
    {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'}
};

// Generate a random alien word
char *generate_alien_word(int length) {
    char *word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int random_index = rand() % 26;
        word[i] = alien_dictionary[0][random_index];
    }
    word[length] = '\0';
    return word;
}

// Translate an alien word to English
char *translate_alien_word(char *alien_word) {
    int length = strlen(alien_word);
    char *english_word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int alien_index = alien_word[i] - 'A';
        english_word[i] = alien_dictionary[alien_index][0];
    }
    english_word[length] = '\0';
    return english_word;
}

// Print the alien language dictionary
void print_alien_dictionary() {
    printf("Alien Language Dictionary:\n");
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            printf("%c ", alien_dictionary[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random alien word
    char *alien_word = generate_alien_word(10);

    // Translate the alien word to English
    char *english_word = translate_alien_word(alien_word);

    // Print the alien word, its English translation, and the alien language dictionary
    printf("Alien Word: %s\n", alien_word);
    printf("English Translation: %s\n", english_word);
    print_alien_dictionary();

    // Free the allocated memory
    free(alien_word);
    free(english_word);

    return 0;
}