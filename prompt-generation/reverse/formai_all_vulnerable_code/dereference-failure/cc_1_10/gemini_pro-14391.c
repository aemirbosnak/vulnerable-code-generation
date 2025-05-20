//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a sentence
#define MAX_WORDS_IN_SENTENCE 100

// Define the maximum number of characters in a sentence
#define MAX_SENTENCE_LENGTH 1000

// Create a struct to store a word and its count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count;

// Create a function to compare two words
int compare_words(const void *a, const void *b) {
    return strcmp(((word_count *)a)->word, ((word_count *)b)->word);
}

// Create a function to count the words in a sentence
int count_words(char *sentence, word_count *words) {
    // Initialize the word count
    int word_count = 0;

    // Get the first word in the sentence
    char *word = strtok(sentence, " ");

    // While there are more words in the sentence
    while (word != NULL) {
        // Check if the word is already in the word list
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(word, words[i].word) == 0) {
                // If the word is already in the list, increment its count
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not already in the list, add it to the list
        if (!found) {
            strcpy(words[word_count].word, word);
            words[word_count].count = 1;
            word_count++;
        }

        // Get the next word in the sentence
        word = strtok(NULL, " ");
    }

    return word_count;
}

// Create a function to print the word count
void print_word_count(word_count *words, int word_count) {
    // Sort the words by count
    qsort(words, word_count, sizeof(word_count), compare_words);

    // Print the word count
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

// Create a function to get a sentence from the user
char *get_sentence() {
    // Declare the sentence buffer
    char *sentence = malloc(MAX_SENTENCE_LENGTH);

    // Get the sentence from the user
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Remove the newline character from the sentence
    sentence[strlen(sentence) - 1] = '\0';

    return sentence;
}

// Create a function to main
int main() {
    // Declare the word list
    word_count words[MAX_WORDS_IN_SENTENCE];

    // Get a sentence from the user
    char *sentence = get_sentence();

    // Count the words in the sentence
    int word_count = count_words(sentence, words);

    // Print the word count
    print_word_count(words, word_count);

    // Free the sentence buffer
    free(sentence);

    return 0;
}