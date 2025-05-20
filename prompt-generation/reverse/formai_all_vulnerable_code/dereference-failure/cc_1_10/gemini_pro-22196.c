//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORD_LENGTH 256
#define MAX_WORDS 10000

// Define the data structure for a word
typedef struct word {
    char *spelling;
    int frequency;
} word_t;

// Define the data structure for the dictionary
typedef struct dictionary {
    word_t *words;
    int size;
} dictionary_t;

// Create a new dictionary
dictionary_t *new_dictionary() {
    dictionary_t *dict = malloc(sizeof(dictionary_t));
    dict->words = malloc(MAX_WORDS * sizeof(word_t));
    dict->size = 0;
    return dict;
}

// Add a word to the dictionary
void add_word(dictionary_t *dict, char *spelling) {
    // Check if the word is already in the dictionary
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].spelling, spelling) == 0) {
            dict->words[i].frequency++;
            return;
        }
    }

    // Add the word to the dictionary
    dict->words[dict->size].spelling = strdup(spelling);
    dict->words[dict->size].frequency = 1;
    dict->size++;
}

// Load the dictionary from a file
void load_dictionary(dictionary_t *dict, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)) {
        char *spelling = strtok(line, "\n");
        add_word(dict, spelling);
    }

    fclose(file);
}

// Check if a word is spelled correctly
int is_spelled_correctly(dictionary_t *dict, char *spelling) {
    // Check if the word is in the dictionary
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].spelling, spelling) == 0) {
            return 1;
        }
    }

    // The word is not in the dictionary
    return 0;
}

// Suggest a correction for a misspelled word
char *suggest_correction(dictionary_t *dict, char *spelling) {
    // Calculate the edit distance between the misspelled word and each word in the dictionary
    int min_distance = MAX_WORD_LENGTH;
    char *best_correction = NULL;
    for (int i = 0; i < dict->size; i++) {
        int distance = edit_distance(spelling, dict->words[i].spelling);
        if (distance < min_distance) {
            min_distance = distance;
            best_correction = dict->words[i].spelling;
        }
    }

    // Return the best correction
    return best_correction;
}

// Calculate the edit distance between two strings
int edit_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a matrix to store the edit distances
    int matrix[len1 + 1][len2 + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate the edit distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, // Deletion
                                 matrix[i][j - 1] + 1, // Insertion
                                 matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Return the edit distance
    return matrix[len1][len2];
}

// Find the minimum of three numbers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Print the dictionary
void print_dictionary(dictionary_t *dict) {
    for (int i = 0; i < dict->size; i++) {
        printf("%s: %d\n", dict->words[i].spelling, dict->words[i].frequency);
    }
}

// Free the memory allocated for the dictionary
void free_dictionary(dictionary_t *dict) {
    for (int i = 0; i < dict->size; i++) {
        free(dict->words[i].spelling);
    }
    free(dict->words);
    free(dict);
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s dictionary_file text_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Load the dictionary
    dictionary_t *dict = new_dictionary();
    load_dictionary(dict, argv[1]);

    // Open the text file
    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        perror("Error opening text file");
        exit(EXIT_FAILURE);
    }

    // Check the spelling of each word in the text file
    char line[MAX_WORD_LENGTH];
    int misspelled_words = 0;
    while (fgets(line, MAX_WORD_LENGTH, file)) {
        char *word = strtok(line, " \n");
        while (word != NULL) {
            if (!is_spelled_correctly(dict, word)) {
                printf("Misspelled word: %s\n", word);
                char *correction = suggest_correction(dict, word);
                printf("Suggested correction: %s\n", correction);
                misspelled_words++;
            }
            word = strtok(NULL, " \n");
        }
    }

    fclose(file);

    // Print the number of misspelled words
    printf("%d misspelled words found.\n", misspelled_words);

    // Free the memory allocated for the dictionary
    free_dictionary(dict);

    return EXIT_SUCCESS;
}