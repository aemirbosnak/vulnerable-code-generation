//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    // The magic spell checker!
    char* spell_checker = "ZAP_THE_SPELLS";

    // Ask the user for a word to check
    printf("Enter a word to check: ");
    char word[100];
    fgets(word, 100, stdin);

    // Check the word for spelling errors
    int errors = check_spelling(word, spell_checker);

    // Print the results
    if (errors == 0) {
        printf("The word %s is spelled correctly!\n", word);
    } else {
        printf("OOPS! The word %s has %d spelling errors!\n", word, errors);
    }

    return 0;
}

int check_spelling(char* word, char* spell_checker) {
    // The magic spell checker!
    int errors = 0;

    // Check for missing letters
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == '\0') {
            errors++;
        }
    }

    // Check for extra letters
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == 'x') {
            errors++;
        }
    }

    // Check for wrong letters
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] != spell_checker[i]) {
            errors++;
        }
    }

    return errors;
}