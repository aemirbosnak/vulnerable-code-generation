//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MAX_WORDS 100000

typedef struct {
    char *word;
    int count;
} WordCount;

WordCount *word_counts;
int num_words;

void init() {
    word_counts = (WordCount *)malloc(MAX_WORDS * sizeof(WordCount));
    memset(word_counts, 0, MAX_WORDS * sizeof(WordCount));
    num_words = 0;
}

void add_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            word_counts[i].count++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words\n");
        exit(1);
    }
    word_counts[num_words].word = strdup(word);
    word_counts[num_words].count = 1;
    num_words++;
}

void print_counts() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

void free_memory() {
    int i;
    for (i = 0; i < num_words; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);
}

int main() {
    char word[MAX_SIZE];
    while (fgets(word, MAX_SIZE, stdin)!= NULL) {
        add_word(word);
    }
    print_counts();
    free_memory();
    return 0;
}