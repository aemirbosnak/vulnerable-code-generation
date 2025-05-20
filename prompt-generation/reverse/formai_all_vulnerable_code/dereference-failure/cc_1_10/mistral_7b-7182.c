//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

// Function to read words from a file and store them in a dynamically allocated array
char** load_dictionary(const char* filename) {
    FILE* fp = fopen(filename, "r");
    int num_words = 0;
    char** words = NULL;

    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s", words[num_words]) != EOF) {
        num_words++;

        if (num_words >= MAX_WORDS) {
            fprintf(stderr, "Error: Dictionary file too large\n");
            exit(EXIT_FAILURE);
        }

        words = realloc(words, sizeof(char*) * (num_words + 1));
    }

    fclose(fp);

    words[num_words] = NULL;
    return words;
}

// Function to check if a word is in the dictionary
int is_valid_word(const char* word, const char** dictionary) {
    int i;

    for (i = 0; dictionary[i] != NULL; i++) {
        if (strcmp(dictionary[i], word) == 0)
            return 1;
    }

    return 0;
}

// Main function
int main() {
    const char* dictionary_filename = "dictionary.txt";
    char** dictionary;

    // Load dictionary
    dictionary = load_dictionary(dictionary_filename);

    // Spell checking loop
    char user_input[WORD_LENGTH];
    while (1) {
        printf("Enter a word: ");
        scanf("%s", user_input);

        // Check if word is valid
        if (!is_valid_word(user_input, dictionary)) {
            printf("Error: %s is not a valid word\n", user_input);
        }

        // Ask for next word or exit
        char exit_input;
        scanf(" %c", &exit_input);
        if (exit_input == 'q' || exit_input == 'Q')
            break;
    }

    // Free memory
    int i;
    for (i = 0; dictionary[i] != NULL; i++)
        free(dictionary[i]);
    free(dictionary);

    return 0;
}