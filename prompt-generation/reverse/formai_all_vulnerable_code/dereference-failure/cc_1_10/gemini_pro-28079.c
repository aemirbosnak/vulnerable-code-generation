//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} word_count_pair;

int compare_word_count_pairs(const void *a, const void *b) {
    const word_count_pair *aa = a;
    const word_count_pair *bb = b;
    return strcmp(aa->word, bb->word);
}

int main() {
    char *input = "This is a simple example of a word frequency counter. The program reads a text file and counts the number of occurrences of each word in the file. The output of the program is a list of the words and their counts, sorted in descending order of count.";

    // Split the input into words
    char *words[MAX_WORDS];
    int num_words = 0;
    char *word = strtok(input, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Count the occurrences of each word
    word_count_pair word_counts[MAX_WORDS];
    for (int i = 0; i < num_words; i++) {
        bool found = false;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[i], word_counts[j].word) == 0) {
                word_counts[j].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            word_counts[num_words].word = words[i];
            word_counts[num_words].count = 1;
            num_words++;
        }
    }

    // Sort the word counts in descending order of count
    qsort(word_counts, num_words, sizeof(word_count_pair), compare_word_count_pairs);

    // Print the word counts
    for (int i = 0; i < num_words; i++) {
        printf("%s %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}