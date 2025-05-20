//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 10000

/* The structure that holds the information about a word */
typedef struct {
    char* word;
    int frequency;
} Word;

/* Function prototypes */
void add_word(Word* words, int* num_words, const char* new_word);
void print_words(const Word* words, const int num_words);

int main() {
    char input_string[MAX_WORD_LENGTH * MAX_NUM_WORDS];
    Word words[MAX_NUM_WORDS];
    int num_words = 0;
    char* token;
    
    /* Get the input string */
    printf("Enter a string (max %d words): ", MAX_NUM_WORDS);
    fgets(input_string, sizeof(input_string), stdin);
    
    /* Tokenize the input string */
    token = strtok(input_string, " \n");
    while (token != NULL) {
        add_word(words, &num_words, token);
        token = strtok(NULL, " \n");
    }
    
    /* Print the word frequency table */
    print_words(words, num_words);
    
    return 0;
}

/**
 * Adds a new word to the list of words, or increments the frequency of an existing word.
 */
void add_word(Word* words, int* num_words, const char* new_word) {
    int i;
    char* lowercase_word;
    
    /* Convert the word to lowercase */
    lowercase_word = (char*) malloc(strlen(new_word) + 1);
    for (i = 0; i < strlen(new_word); i++) {
        lowercase_word[i] = tolower(new_word[i]);
    }
    lowercase_word[i] = '\0';
    
    /* Check if the word already exists */
    for (i = 0; i < *num_words; i++) {
        if (strcmp(words[i].word, lowercase_word) == 0) {
            words[i].frequency++;
            free(lowercase_word);
            return;
        }
    }
    
    /* Add the new word */
    words[*num_words].word = lowercase_word;
    words[*num_words].frequency = 1;
    (*num_words)++;
}

/**
 * Prints the list of words and their frequencies.
 */
void print_words(const Word* words, const int num_words) {
    int i;
    
    printf("Word Frequency\n");
    printf("--------------\n");
    
    for (i = 0; i < num_words; i++) {
        printf("%-15s %d\n", words[i].word, words[i].frequency);
    }
}