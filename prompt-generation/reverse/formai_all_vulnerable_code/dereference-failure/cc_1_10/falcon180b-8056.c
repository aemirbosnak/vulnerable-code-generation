//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *word_frequencies;
    int num_words;
} Index;

Index *create_index() {
    Index *index = (Index *)malloc(sizeof(Index));
    index->word_frequencies = (WordFrequency *)malloc(sizeof(WordFrequency));
    index->num_words = 0;
    return index;
}

void add_word_to_index(Index *index, char *word) {
    int word_length = strlen(word);
    if (word_length > MAX_WORD_SIZE) {
        printf("Error: Word length exceeds maximum limit.\n");
        return;
    }
    WordFrequency *word_frequency = (WordFrequency *)malloc(sizeof(WordFrequency));
    strcpy(word_frequency->word, word);
    word_frequency->frequency = 1;
    index->num_words++;
    index->word_frequencies = (WordFrequency *)realloc(index->word_frequencies, index->num_words * sizeof(WordFrequency));
    index->word_frequencies[index->num_words - 1] = *word_frequency;
    free(word_frequency);
}

void print_index(Index *index) {
    printf("Index:\n");
    for (int i = 0; i < index->num_words; i++) {
        printf("%s: %d\n", index->word_frequencies[i].word, index->word_frequencies[i].frequency);
    }
}

int main() {
    Index *index = create_index();
    add_word_to_index(index, "hello");
    add_word_to_index(index, "world");
    print_index(index);
    return 0;
}