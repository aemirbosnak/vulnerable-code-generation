//FormAI DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

// Function to check if a char is a punctuation mark
int is_punc(char c) {
    return c == '.' || c == ',' || c == '?' || c == '!' || c == ':' || c == ';' || c == '-';
}

// Function to check if a word is spelled correctly
int is_spell_correct(char *word, char **dictionary, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to remove punctuation marks from a word
char *remove_punc(char *word) {
    char *new_word = calloc(MAX_WORD_LENGTH, sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (!is_punc(word[i])) {
            new_word[j++] = word[i];
        }
    }
    return new_word;
}

int main() {
    // Load dictionary into memory
    char **dictionary = calloc(100000, sizeof(char *));
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error loading dictionary\n");
        exit(1);
    }
    char buffer[MAX_WORD_LENGTH];
    int i = 0;
    while (fgets(buffer, sizeof buffer, fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        dictionary[i++] = strdup(buffer);
    }
    int dict_size = i;

    // Open input file
    FILE *ifp = fopen("input.txt", "r");
    if (ifp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Open output file
    FILE *ofp = fopen("output.txt", "w");
    if (ofp == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Loop through input file one word at a time
    char word[MAX_WORD_LENGTH];
    while (fscanf(ifp, "%s", word) != EOF) {
        // Remove punctuation from word
        char *new_word = remove_punc(word);

        // Check if word is spelled correctly
        if (!is_spell_correct(new_word, dictionary, dict_size)) {
            printf("Possible spelling mistake: %s\n", word);
            fprintf(ofp, "%c%s%c ", '\"', word, '\"');
        } else {
            fprintf(ofp, "%s ", word);
        }

        // Free memory
        free(new_word);
    }

    // Close files
    fclose(fp);
    fclose(ifp);
    fclose(ofp);

    // Free memory
    for (int i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}