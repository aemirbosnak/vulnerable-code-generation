//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Structure to store a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

// Create a new word
Word* new_word(char* word) {
    Word* new_word = malloc(sizeof(Word));
    strcpy(new_word->word, word);
    new_word->frequency = 1;
    return new_word;
}

// Compare two words
int compare_words(const void* a, const void* b) {
    Word* word1 = (Word*)a;
    Word* word2 = (Word*)b;
    return strcmp(word1->word, word2->word);
}

// Load the dictionary into an array of words
Word** load_dictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the array of words
    Word** dictionary = malloc(sizeof(Word*) * MAX_WORDS);

    // Read the words from the dictionary
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(fp, "%s", word) != EOF) {
        dictionary[i++] = new_word(word);
    }

    fclose(fp);

    // Sort the dictionary
    qsort(dictionary, i, sizeof(Word*), compare_words);

    return dictionary;
}

// Check if a word is in the dictionary
int is_word_in_dictionary(Word** dictionary, int num_words, char* word) {
    int low = 0;
    int high = num_words - 1;

    // Perform a binary search for the word
    while (low <= high) {
        int mid = (low + high) / 2;
        int comparison = strcmp(dictionary[mid]->word, word);

        if (comparison == 0) {
            return 1;
        } else if (comparison < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return 0;
}

// Check the spelling of a word
int check_spelling(Word** dictionary, int num_words, char* word) {
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word is in the dictionary
    if (is_word_in_dictionary(dictionary, num_words, word)) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Load the dictionary
    Word** dictionary = load_dictionary("dictionary.txt");
    int num_words = 10000;

    // Get the input word from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check the spelling: ");
    scanf("%s", word);

    // Check the spelling of the word
    int is_correct = check_spelling(dictionary, num_words, word);

    // Print the result
    if (is_correct) {
        printf("The spelling of '%s' is correct.\n", word);
    } else {
        printf("The spelling of '%s' is incorrect.\n", word);
    }

    return 0;
}