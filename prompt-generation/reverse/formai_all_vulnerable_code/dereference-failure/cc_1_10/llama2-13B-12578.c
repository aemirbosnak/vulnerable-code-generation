//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 10

// Function to generate a random word
char *generate_word(void) {
    char *word = malloc(MAX_LENGTH * sizeof(char));
    int i;

    for (i = 0; i < MAX_LENGTH; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    return word;
}

// Function to check if a word is valid
int is_valid(char *word) {
    int i;

    for (i = 0; i < MAX_LENGTH; i++) {
        if (word[i] < 'a' || word[i] > 'z') {
            return 0;
        }
    }

    return 1;
}

int main() {
    char *word;

    // Generate a random word
    word = generate_word();

    // Check if the word is valid
    if (!is_valid(word)) {
        printf("The word %s is not valid\n", word);
        free(word);
        return 1;
    }

    // Print the word
    printf("The word is %s\n", word);

    // Free the memory
    free(word);

    return 0;
}