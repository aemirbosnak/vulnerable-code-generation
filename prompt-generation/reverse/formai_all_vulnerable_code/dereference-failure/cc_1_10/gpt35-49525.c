//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_LENGTH 20

// Function to generate random word
char* generate_word() {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char* word = malloc(MAX_LENGTH * sizeof(char));
    int i;

    for (i = 0; i < MAX_LENGTH - 1; i++) {
        word[i] = letters[rand() % 26];
    }

    word[MAX_LENGTH - 1] = '\0';

    return word;
}

// Function to print the randomly generated words
void print_words(char** words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    char* words[MAX_WORDS];
    int i, j;
    for (i = 0; i < MAX_WORDS; i++) {
        words[i] = generate_word(); // Generate the words
    }

    printf("Type the following words as fast as possible:\n");
    print_words(words);

    char input[MAX_WORDS * MAX_LENGTH];
    fgets(input, MAX_WORDS * MAX_LENGTH, stdin); // Get user input

    // Tokenize user input
    char* token;
    int word_count = 0;
    char* words_input[MAX_WORDS];
    token = strtok(input, " ");
    while (token != NULL && word_count < MAX_WORDS) {
        words_input[word_count++] = token;
        token = strtok(NULL, " ");
    }

    // Compare user input with generated words
    int correct_count = 0;
    for (i = 0; i < MAX_WORDS && i < word_count; i++) {
        if (strcmp(words[i], words_input[i]) == 0) {
            correct_count++;
        }
    }

    printf("You typed %d words correctly out of %d.\n", correct_count, MAX_WORDS);

    // Free allocated memory
    for (i = 0; i < MAX_WORDS; i++) {
        free(words[i]);
    }

    return 0;
}