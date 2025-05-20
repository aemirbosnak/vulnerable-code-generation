//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

void spell_checker(char *word);

int main() {
    char word[MAX_LENGTH];
    char corrected_word[MAX_LENGTH];

    printf("Welcome to the Spell Checking Program! \n");

    // Generate a random word for the user to spell
    srand(time(NULL));
    int word_length = rand() % MAX_LENGTH + 1;
    char *word_generated = malloc(word_length * sizeof(char));
    for (int i = 0; i < word_length; i++) {
        word_generated[i] = 'a' + (rand() % 26);
    }

    printf("The word you need to spell is: %s\n", word_generated);

    // Get the user's response
    printf("Please enter the word you want to spell: ");
    fgets(word, MAX_LENGTH, stdin);

    // Call the spell checker function
    spell_checker(word);

    // Generate the corrected word
    strcpy(corrected_word, word);
    int index = 0;
    while (index < strlen(corrected_word)) {
        if (isalpha(corrected_word[index])) {
            corrected_word[index] = tolower(corrected_word[index]);
        }
        index++;
    }

    // Print the corrected word
    printf("The correct spelling of the word is: %s\n", corrected_word);

    return 0;
}

void spell_checker(char *word) {
    int i, j, k;
    char c;

    // Loop through each character in the word
    for (i = 0; i < strlen(word); i++) {
        c = word[i];

        // Check if the character is a letter
        if (isalpha(c)) {
            // Loop through each letter in the word
            for (j = i + 1; j < strlen(word); j++) {
                if (word[j] == c) {
                    // If the letter appears more than once, flag it
                    word[j] = '*';
                }
            }
        }
    }
}