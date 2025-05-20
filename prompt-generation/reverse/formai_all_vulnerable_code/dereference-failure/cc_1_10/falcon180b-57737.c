//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int num_words;
    int size;
} WordFrequency;

void initialize_word_frequency(WordFrequency *frequency) {
    frequency->words = (WordCount *)malloc(MAX_SIZE * sizeof(WordCount));
    frequency->num_words = 0;
    frequency->size = MAX_SIZE;
}

void add_word(WordFrequency *frequency, char *word) {
    WordCount *current_word = NULL;
    for (int i = 0; i < frequency->num_words; i++) {
        if (strcmp(frequency->words[i].word, word) == 0) {
            current_word = &frequency->words[i];
            break;
        }
    }
    if (current_word == NULL) {
        if (frequency->num_words == frequency->size) {
            frequency->size *= 2;
            frequency->words = (WordCount *)realloc(frequency->words, frequency->size * sizeof(WordCount));
        }
        current_word = &frequency->words[frequency->num_words];
        strcpy(current_word->word, word);
        current_word->count = 0;
        frequency->num_words++;
    }
    current_word->count++;
}

void print_word_frequency(WordFrequency *frequency) {
    for (int i = 0; i < frequency->num_words; i++) {
        printf("%s: %d\n", frequency->words[i].word, frequency->words[i].count);
    }
}

int main() {
    char *words[] = {"Cyberpunk", "Data", "Structures", "Visualization", "Program"};
    int num_words = sizeof(words) / sizeof(char *);

    WordFrequency frequency;
    initialize_word_frequency(&frequency);

    for (int i = 0; i < num_words; i++) {
        add_word(&frequency, words[i]);
    }

    print_word_frequency(&frequency);

    return 0;
}