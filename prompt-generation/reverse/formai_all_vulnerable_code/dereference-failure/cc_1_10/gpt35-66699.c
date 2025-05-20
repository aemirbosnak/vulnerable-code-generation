//FormAI DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_FILE "dictionary.txt"
#define MAX_MISSPELLED_WORDS 1000
#define MAX_WORD_LENGTH 30

// Function prototypes
int check_word(char *word, char **dictionary, int size);
void str_lower(char *str);

int main(int argc, char *argv[]) {
	// Check for command line arguments
    if (argc != 2) {
        printf("Usage: spell_check <text_file>\n");
        return 1;
    }

    // Open the dictionary file and read in the words
    FILE *dictionary_file = fopen(DICTIONARY_FILE, "r");

    if (dictionary_file == NULL) {
        printf("Could not open dictionary file.\n");
        return 1;
    }

    // Allocate memory for the dictionary
    char **dictionary = (char**) malloc(sizeof(char*) * MAX_MISSPELLED_WORDS);
    int dictionary_size = 0;

    char line[MAX_WORD_LENGTH];

    while (fgets(line, MAX_WORD_LENGTH, dictionary_file) != NULL) {
        dictionary[dictionary_size] = (char*) malloc(sizeof(char) * strlen(line) + 1);
        line[strlen(line) - 1] = '\0';
        strcpy(dictionary[dictionary_size], line);
        dictionary_size++;
    }

    // Close the dictionary file
    fclose(dictionary_file);

    // Open the input file and read in the words
    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL) {
        printf("Could not open input file.\n");
        return 1;
    }

    // Allocate memory for the misspelled words and counters
    char **misspelled_words = (char**) malloc(sizeof(char*) * MAX_MISSPELLED_WORDS);
    int num_misspelled_words = 0;
    int num_words_checked = 0;

    // Check each word in the input file
    char word[MAX_WORD_LENGTH];

    while (fscanf(input_file, "%s", word) == 1 && num_misspelled_words < MAX_MISSPELLED_WORDS) {
        num_words_checked++;

        // Lowercase the word
        str_lower(word);

        if (check_word(word, dictionary, dictionary_size) == 0) {
            misspelled_words[num_misspelled_words] = (char*) malloc(sizeof(char) * strlen(word) + 1);
            strcpy(misspelled_words[num_misspelled_words], word);
            num_misspelled_words++;
        }
    }

    // Close the input file
    fclose(input_file);

    // Print out the misspelled words
    printf("Misspelled Words:\n");

    for (int i = 0; i < num_misspelled_words; i++) {
        printf("%s\n", misspelled_words[i]);
    }

    printf("\nTotal Words Checked: %d\n", num_words_checked);
    printf("Misspelled Words Found: %d\n", num_misspelled_words);

    // Free memory
    for (int i = 0; i < dictionary_size; i++) {
        free(dictionary[i]);
    }

    free(dictionary);

    for (int i = 0; i < num_misspelled_words; i++) {
        free(misspelled_words[i]);
    }

    free(misspelled_words);

    return 0;
}

/**
 * Checks whether a word is in the dictionary.
 * 
 * @param word The word to check.
 * @param dictionary An array of strings representing the dictionary.
 * @param size The size of the dictionary.
 * @return 1 if the word is in the dictionary, 0 otherwise.
 */
int check_word(char *word, char **dictionary, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

/**
 * Converts a string to lowercase.
 * 
 * @param str The string to convert.
 */
void str_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}