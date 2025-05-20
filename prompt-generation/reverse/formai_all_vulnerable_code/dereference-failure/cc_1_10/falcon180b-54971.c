//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *word_counts;
    int num_words;
} Index;

void init_index(Index *index) {
    index->word_counts = (WordCount *)malloc(MAX_NUM_WORDS * sizeof(WordCount));
    index->num_words = 0;
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        index->word_counts[i].word = NULL;
        index->word_counts[i].count = 0;
    }
}

void add_word(Index *index, char *word) {
    int word_len = strlen(word);
    if (word_len > MAX_WORD_LENGTH) {
        return;
    }
    for (int i = 0; i < index->num_words; i++) {
        if (strcmp(index->word_counts[i].word, word) == 0) {
            index->word_counts[i].count++;
            return;
        }
    }
    if (index->num_words >= MAX_NUM_WORDS) {
        return;
    }
    index->word_counts[index->num_words].word = strdup(word);
    index->word_counts[index->num_words].count = 1;
    index->num_words++;
}

void print_index(Index *index) {
    for (int i = 0; i < index->num_words; i++) {
        printf("%s: %d\n", index->word_counts[i].word, index->word_counts[i].count);
    }
}

int main() {
    char input_text[1000000];
    printf("Enter the text to be indexed:\n");
    fgets(input_text, sizeof(input_text), stdin);

    Index index;
    init_index(&index);

    char *word = strtok(input_text, " ");
    while (word!= NULL) {
        add_word(&index, word);
        word = strtok(NULL, " ");
    }

    print_index(&index);

    return 0;
}