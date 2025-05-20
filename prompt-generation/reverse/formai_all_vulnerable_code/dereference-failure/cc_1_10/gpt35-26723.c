//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

/*
 * A structure to hold a word and its frequency count.
 */
typedef struct word_frequency {
    char *word;
    unsigned int freq;
} word_frequency;

/*
 * A function that counts the number of times
 * a given word appears in the input string.
 */
unsigned int count_word(const char *input, const char *word) {
    unsigned int count = 0;
    char *pos = strstr(input, word);
    while (pos != NULL) {
        count++;
        pos = strstr(pos + 1, word);
    }
    return count;
}

/*
 * A function that splits a string into words and populates
 * the provided word_frequency array with each word and its
 * corresponding frequency count.
 */
void count_words(const char *input, word_frequency *words, unsigned int *num_words) {
    char *cur_word = malloc(sizeof(char) * MAX_WORD_LENGTH);
    unsigned int word_index = 0;
    unsigned int i;
    for (i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            cur_word[strlen(cur_word)] = input[i];
        } else if (strlen(cur_word) > 0) {
            cur_word[strlen(cur_word)] = '\0';
            // check if the word is already in the words array
            unsigned int j;
            for (j = 0; j < word_index; j++) {
                if (strcmp(cur_word, words[j].word) == 0) {
                    words[j].freq++;
                    break;
                }
            }
            // if the word is not in the words array, add it
            if (j == word_index) {
                words[word_index].word = malloc(sizeof(char) * MAX_WORD_LENGTH);
                strcpy(words[word_index].word, cur_word);
                words[word_index].freq = 1;
                word_index++;
            }
            cur_word = malloc(sizeof(char) * MAX_WORD_LENGTH);
        }
    }
    // handle the final word if one exists
    if (strlen(cur_word) > 0) {
        cur_word[strlen(cur_word)] = '\0';
        // check if the word is already in the words array
        unsigned int j;
        for (j = 0; j < word_index; j++) {
            if (strcmp(cur_word, words[j].word) == 0) {
                words[j].freq++;
                break;
            }
        }
        // if the word is not in the words array, add it
        if (j == word_index) {
            words[word_index].word = malloc(sizeof(char) * MAX_WORD_LENGTH);
            strcpy(words[word_index].word, cur_word);
            words[word_index].freq = 1;
            word_index++;
        }
    }
    free(cur_word);
    *num_words = word_index;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: usage is \"./word_counter <input_string> [word1] [word2] ... [wordn]\"\n");
        return 1;
    }
    char *input = argv[1];
    unsigned int num_words = 0;
    word_frequency *words = malloc(sizeof(word_frequency) * strlen(input));
    memset(words, 0, sizeof(word_frequency) * strlen(input));
    count_words(input, words, &num_words);
    if (argc == 2) {
        // print out the frequency of all words
        unsigned int i;
        for (i = 0; i < num_words; i++) {
            printf("%s: %u\n", words[i].word, words[i].freq);
        }
    } else {
        // print out the frequency of the given words
        unsigned int i;
        for (i = 2; i < argc; i++) {
            printf("%s: %u\n", argv[i], count_word(input, argv[i]));
        }
    }
    // free memory
    unsigned int i;
    for (i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(words);
    return 0;
}