//FormAI DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a word in the dictionary

#define DICT_FILE "dictionary.txt" // The file path containing the dictionary

/**
 * This function checks if the given word is spelled correctly
 * Params: 
 *      word - The word to be checked for spelling
 * Returns:
 *      1 - If the word is spelled correctly
 *      0 - If the word is not spelled correctly
 */
int check_spelling(char *word) {
    FILE *fp;
    char dict_word[MAX_WORD_LENGTH];

    fp = fopen(DICT_FILE, "r");

    while (fgets(dict_word, MAX_WORD_LENGTH, fp) != NULL) {
        dict_word[strcspn(dict_word, "\n")] = 0; // Removing newline character from end of string

        if (strcmp(word, dict_word) == 0) {
            fclose(fp);
            return 1; // Word found in dictionary
        }
    }

    fclose(fp);
    return 0; // Word not found in dictionary
}

int main() {
    char input[MAX_WORD_LENGTH];
    int num_of_words = 0, num_of_misspelled_words = 0;

    printf("Enter a sentence: ");

    fgets(input, MAX_WORD_LENGTH, stdin);

    // Parsing sentence word by word
    char *word = strtok(input, " ");
    while (word != NULL) {
        num_of_words++;

        if (!check_spelling(word)) {
            num_of_misspelled_words++;
            printf("Misspelled word: %s\n", word);
        }

        word = strtok(NULL, " ");
    }

    if (num_of_misspelled_words == 0) {
        printf("All words spelled correctly.\n");
    } else {
        printf("Total words checked: %d\n", num_of_words);
        printf("Misspelled words found: %d\n", num_of_misspelled_words);
    }

    return 0;
}