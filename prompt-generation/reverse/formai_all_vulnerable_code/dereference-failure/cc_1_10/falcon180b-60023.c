//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 1000
#define MAX_NUM_INDEXES 100

typedef struct {
    char word[MAX_WORD_LEN];
    int index;
} Word;

typedef struct {
    Word *words;
    int num_words;
    int *indexes;
    int num_indexes;
} Index;

void init_index(Index *index) {
    index->num_words = 0;
    index->num_indexes = 0;
    index->words = malloc(MAX_NUM_WORDS * sizeof(Word));
    index->indexes = malloc(MAX_NUM_INDEXES * sizeof(int));
}

void add_word(Index *index, char *word) {
    Word *w = &index->words[index->num_words++];
    strcpy(w->word, word);
    w->index = index->num_indexes++;
}

void build_index(Index *index) {
    int i;
    for (i = 0; i < index->num_words; i++) {
        char *word = index->words[i].word;
        int len = strlen(word);
        while (len > 0) {
            int c = tolower(word[len - 1]);
            if (c >= 'a' && c <= 'z') {
                add_word(index, word);
            }
            len--;
        }
    }
}

void search_index(Index *index, char *query) {
    int i;
    for (i = 0; i < index->num_indexes; i++) {
        Word *w = &index->words[index->indexes[i]];
        if (strcmp(w->word, query) == 0) {
            printf("Found: %s\n", query);
        }
    }
}

int main() {
    Index index;
    init_index(&index);
    char *words[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int num_words = sizeof(words) / sizeof(words[0]);
    int i;
    for (i = 0; i < num_words; i++) {
        add_word(&index, words[i]);
    }
    build_index(&index);
    char query[MAX_WORD_LEN];
    while (1) {
        printf("Enter a query: ");
        scanf("%s", query);
        search_index(&index, query);
    }
    return 0;
}