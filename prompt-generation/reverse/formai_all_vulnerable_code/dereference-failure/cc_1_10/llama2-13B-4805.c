//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_WORD_LIST_SIZE 1000
#define MIN_WORD_LENGTH 3

// Structure to store words and their frequencies
typedef struct {
    char *word;
    int freq;
} word_t;

// Function to generate a list of random words
void generate_word_list(word_t **word_list, int *word_count) {
    int i, j, k;
    for (i = 0; i < MAGIC_WORD_LIST_SIZE; i++) {
        // Generate a random word
        char *word = malloc(MIN_WORD_LENGTH + 1);
        for (j = 0; j < MIN_WORD_LENGTH; j++) {
            word[j] = 'a' + (rand() % 26);
        }
        word[MIN_WORD_LENGTH] = '\0';

        // Check if the word is already in the list
        for (k = 0; k < *word_count; k++) {
            if (strcmp(word, word_list[k]->word) == 0) {
                free(word);
                break;
            }
        }

        // Add the word to the list if it's not already there
        if (k == *word_count) {
            word_list[*word_count] = (word_t *) malloc(sizeof(word_t));
            word_list[*word_count]->word = word;
            word_list[*word_count]->freq = 1;
            (*word_count)++;
        }
    }
}

// Function to check the spelling of a given word
int check_spelling(char *word) {
    int i, j;
    for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            for (j = i + 1; j < strlen(word); j++) {
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u') {
                    word[i] = 'y';
                    break;
                }
            }
        }
    }
    return strlen(word) == strlen(word);
}

// Function to print the list of words and their frequencies
void print_word_list(word_t *word_list, int word_count) {
    int i;
    for (i = 0; i < word_count; i++) {
        printf("%d. %s\n", i + 1, word_list[i].word);
    }
}

int main() {
    word_t *word_list;
    int word_count;

    // Generate a list of random words
    generate_word_list(&word_list, &word_count);

    // Check the spelling of each word in the list
    for (int i = 0; i < word_count; i++) {
        if (!check_spelling(word_list[i].word)) {
            printf("Error: %s is not a valid word\n", word_list[i].word);
        }
    }

    // Print the list of words and their frequencies
    print_word_list(word_list, word_count);

    return 0;
}