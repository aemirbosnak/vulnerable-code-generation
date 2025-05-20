//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100000
#define DEF_WIDTH 10

struct word {
    char *text;
    int len;
};

typedef struct word Word;

void sort_words(Word *words, int num_words);
void print_words(Word *words, int num_words);
int word_frequency(Word *words, int num_words, char *word);

int main() {
    int i, j, k;
    Word *words = malloc(MAX_LENGTH * sizeof(Word));
    int num_words = 0;

    // Read input from standard input
    for (i = 0; i < MAX_LENGTH; i++) {
        words[i].text = malloc(DEF_WIDTH * sizeof(char));
        fgets(words[i].text, DEF_WIDTH, stdin);
        words[i].len = strlen(words[i].text);
        num_words++;
    }

    // Sort the words
    sort_words(words, num_words);

    // Print the words
    print_words(words, num_words);

    // Count the frequency of each word
    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].text, words[j].text) == 0) {
                words[i].len += words[j].len;
                words[j].len = 0;
                break;
            }
        }
    }

    // Print the frequency of each word
    for (i = 0; i < num_words; i++) {
        printf("%d: %s (%d)\n", i, words[i].text, words[i].len);
    }

    return 0;
}

// Function to sort the words
void sort_words(Word *words, int num_words) {
    int i, j, min_idx;

    // Bubble sort
    for (i = 0; i < num_words - 1; i++) {
        for (j = 0; j < num_words - i - 1; j++) {
            if (strcmp(words[j].text, words[j + 1].text) < 0) {
                min_idx = j;
                while (min_idx < num_words - 1 && strcmp(words[min_idx].text, words[min_idx + 1].text) < 0) {
                    words[j].text = words[min_idx].text;
                    words[j].len = words[min_idx].len;
                    min_idx++;
                }
            }
        }
    }
}

// Function to print the words
void print_words(Word *words, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%d: %s\n", i, words[i].text);
    }
}

// Function to count the frequency of a word
int word_frequency(Word *words, int num_words, char *word) {
    int i, j, freq = 0;

    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].text, word) == 0) {
            freq++;
            break;
        }
    }

    for (j = i + 1; j < num_words; j++) {
        if (strcmp(words[j].text, word) == 0) {
            freq++;
            break;
        }
    }

    return freq;
}