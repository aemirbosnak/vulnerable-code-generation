//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 20
#define MAX_POEM_LENGTH 50

// Function to generate a random word based on the input phrase
void generate_word(char* phrase, char** word) {
    int i, j;
    for (i = 0; i < strlen(phrase); i++) {
        for (j = 0; j < strlen(phrase); j++) {
            if (phrase[i] == phrase[j]) {
                *word = phrase + i;
                return;
            }
        }
    }
    *word = phrase + strlen(phrase) - 1;
}

// Function to generate a poem based on the input phrase
void generate_poem(char* phrase) {
    char word[MAX_LINE_LENGTH];
    char* current_word = word;
    int line_count = 0;

    // Generate a random word based on the input phrase
    generate_word(phrase, &current_word);

    // Loop until the current word is null
    while (current_word != NULL) {
        // Check if the current word is a proper noun
        if (ispropernoun(current_word)) {
            // If it is, generate a new word based on the input phrase
            generate_word(phrase, &current_word);
        } else {
            // If it's not, add it to the current line of the poem
            *current_word = '\0';
            printf("%s\n", word);
            line_count++;

            // Generate a new word based on the input phrase
            generate_word(phrase, &current_word);
        }
    }

    // Print the final line of the poem
    printf("%s\n", word);
}

// Function to check if a word is a proper noun
int ispropernoun(char* word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (word[i] == ' ' || word[i] == '\t') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char phrase[MAX_LINE_LENGTH];

    // Ask the user for the input phrase
    printf("Enter a phrase: ");
    fgets(phrase, MAX_LINE_LENGTH, stdin);

    // Generate the poem based on the input phrase
    generate_poem(phrase);

    return 0;
}