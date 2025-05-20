//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LENGTH 1000
#define MIN_LENGTH 3

// Structure to store spell check data
struct spell_check {
    char word[MAX_LENGTH];
    int frequency;
};

// Function to check if a word is misspelled
int is_misspelled(char word[MAX_LENGTH]) {
    int i, j;
    for (i = 0; i < strlen(word); i++) {
        for (j = i + 1; j < strlen(word); j++) {
            if (word[i] == word[j]) {
                // Check if the word has a repeated letter
                if (i != j) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to check the spell of a word
int check_spell(char word[MAX_LENGTH]) {
    int i, j;
    struct spell_check *sc;
    sc = (struct spell_check *)calloc(1, sizeof(struct spell_check));
    strcpy(sc->word, word);
    sc->frequency = 1;
    for (i = 0; i < strlen(word); i++) {
        for (j = 0; j < strlen(word); j++) {
            if (word[i] == word[j]) {
                // Check if the word has a repeated letter
                if (i != j) {
                    sc->frequency++;
                }
            }
        }
    }
    return sc->frequency;
}

// Function to display the spell check results
void display_results(struct spell_check *sc) {
    int i;
    printf("Word: %s\n", sc->word);
    printf("Frequency: %d\n", sc->frequency);
    for (i = 0; i < strlen(sc->word); i++) {
        printf("Letter %c appears %d times\n", sc->word[i], sc->frequency - (i == 0));
    }
}

int main() {
    char word[MAX_LENGTH];
    struct spell_check sc;

    // Ask the user for a word to check
    printf("Enter a word to check the spell: ");
    fgets(word, MAX_LENGTH, stdin);

    // Check if the word is misspelled
    if (is_misspelled(word)) {
        // If the word is misspelled, display the corrected spelling
        printf("Corrected spelling: ");
        check_spell(word);
        display_results(&sc);
    } else {
        // If the word is spelled correctly, display the word and its frequency
        printf("Word is spelled correctly: ");
        check_spell(word);
        display_results(&sc);
    }

    return 0;
}