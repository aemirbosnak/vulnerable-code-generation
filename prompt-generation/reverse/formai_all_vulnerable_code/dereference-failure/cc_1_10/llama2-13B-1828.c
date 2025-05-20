//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

// Function to check if a word is misspelled
int is_misspelled(char *word) {
    int i, j;
    for (i = 0; i < strlen(word); i++) {
        for (j = i + 1; j < strlen(word); j++) {
            if (word[i] == word[j]) {
                // If the word contains a duplicate letter, it's misspelled
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a sentence is grammatically correct
int is_grammar_correct(char *sentence) {
    int i, j;
    for (i = 0; i < strlen(sentence); i++) {
        for (j = i + 1; j < strlen(sentence); j++) {
            if (sentence[i] == sentence[j]) {
                // If the sentence contains a duplicate word, it's not grammatically correct
                return 0;
            }
        }
    }
    return 1;
}

// Function to generate a random word
char *generate_random_word() {
    int length = rand() % MAX_LENGTH + 1;
    char word[length];
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + (rand() % 26);
    }
    return word;
}

// Main function
int main() {
    // Create a random word
    char *word = generate_random_word();

    // Check if the word is misspelled
    if (is_misspelled(word)) {
        printf("Oops, it looks like you've got a misspelled word! %s\n", word);
    } else {
        // Check if the sentence is grammatically correct
        char *sentence = "The quick brown fox jumps over the lazy dog.";
        if (!is_grammar_correct(sentence)) {
            printf("Whoa, it looks like you've got a grammatical error! %s\n", sentence);
        } else {
            // Print a success message
            printf("Congratulations, you've got a correctly spelled sentence and a grammatically correct sentence! %s\n", sentence);
        }
    }

    // Print a magic number
    printf("Magic number: %d\n", MAGIC_NUMBER);

    return 0;
}