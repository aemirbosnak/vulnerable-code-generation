//FormAI DATASET v1.0 Category: Spell checking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 50
#define DICTIONARY_SIZE 47500

// Function to convert a word to lowercase
void to_lowercase(char *word) {
    int i = 0;
    while (word[i] != '\0') {
        word[i] = tolower(word[i]);
        i++;
    }
}

// Function to check the spelling of a word
int check_spelling(char *word, char **dictionary) {
    int i = 0;
    while (dictionary[i] != NULL) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found in dictionary
        }
        i++;
    }
    return 0; // Word not found in dictionary
}

int main() {
    // Load the dictionary into memory
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error loading dictionary file.\n");
        return 1;
    }
    char **dictionary = malloc(DICTIONARY_SIZE * sizeof(char *));
    char temp_word[WORD_LENGTH];
    int word_count = 0;
    while (fgets(temp_word, WORD_LENGTH, dictionary_file)) {
        // Allocate memory for word
        dictionary[word_count] = malloc(WORD_LENGTH * sizeof(char));
        // Copy word to dictionary
        strcpy(dictionary[word_count], temp_word);
        // Remove newline character
        dictionary[word_count][strlen(dictionary[word_count])-1] = '\0';
        // Convert word to lowercase
        to_lowercase(dictionary[word_count]);
        word_count++;
    }
    // Close dictionary file
    fclose(dictionary_file);

    // Get input word from user
    char input_word[WORD_LENGTH];
    printf("Enter a word to check its spelling: ");
    scanf("%s", input_word);

    // Convert input word to lowercase
    to_lowercase(input_word);

    // Check spelling of input word
    if (check_spelling(input_word, dictionary)) {
        printf("The word '%s' is spelled correctly!\n", input_word);
    }
    else {
        printf("The word '%s' is spelled incorrectly.\n", input_word);
        // Suggest corrections
        printf("Did you mean: ");
        int i, j, k, l;
        char c;
        char temp_word[WORD_LENGTH];
        for (i = 0; input_word[i] != '\0'; i++) {
            // Delete one character
            for (j = 0, k = 0; input_word[j] != '\0'; j++) {
                if (j != i) {
                    temp_word[k++] = input_word[j];
                }
            }
            temp_word[k] = '\0';
            if (check_spelling(temp_word, dictionary)) {
                printf("%s ", temp_word);
            }
            // Replace one character at a time with a-z
            for (c = 'a'; c <= 'z'; c++) {
                for (j = 0, k = 0; input_word[j] != '\0'; j++) {
                    if (j == i) {
                        temp_word[k++] = c;
                    }
                    temp_word[k++] = input_word[j];
                }
                temp_word[k] = '\0';
                if (check_spelling(temp_word, dictionary)) {
                    printf("%s ", temp_word);
                }
            }
            // Insert one character at a time from a-z
            for (c = 'a'; c <= 'z'; c++) {
                for (j = 0, k = 0; input_word[j] != '\0'; j++) {
                    temp_word[k++] = input_word[j];
                    if (j == i) {
                        temp_word[k++] = c;
                    }
                }
                temp_word[k] = '\0';
                if (check_spelling(temp_word, dictionary)) {
                    printf("%s ", temp_word);
                }
            }
            // Swap adjacent characters
            for (j = 0; input_word[j+1] != '\0'; j++) {
                temp_word[j] = input_word[j+1];
                temp_word[j+1] = input_word[j];
                temp_word[j+2] = '\0';
                if (check_spelling(temp_word, dictionary)) {
                    printf("%s ", temp_word);
                }
            }
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < word_count; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}