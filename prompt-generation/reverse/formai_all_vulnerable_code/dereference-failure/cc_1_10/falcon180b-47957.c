//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20
#define INITIAL_HASH_SIZE 10

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int size;
    int num_words;
} HashTable;

void init_hash_table(HashTable *table) {
    table->size = INITIAL_HASH_SIZE;
    table->words = (WordCount *)malloc(table->size * sizeof(WordCount));
    table->num_words = 0;
}

int hash(char *word) {
    int sum = 0;
    while (*word) {
        sum += tolower(*word++);
    }
    return sum % INITIAL_HASH_SIZE;
}

void add_word(HashTable *table, char *word) {
    int index = hash(word);
    while (table->words[index].word[0]!= '\0') {
        index = (index + 1) % table->size;
    }
    table->words[index].word[0] = tolower(word[0]);
    strcpy(table->words[index].word + 1, word + 1);
    table->words[index].count = 1;
    table->num_words++;
    if (table->num_words > table->size * 0.75) {
        int new_size = table->size * 2;
        WordCount *new_words = (WordCount *)malloc(new_size * sizeof(WordCount));
        memcpy(new_words, table->words, table->size * sizeof(WordCount));
        table->size = new_size;
        table->words = new_words;
    }
}

void print_hash_table(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        if (table->words[i].word[0]!= '\0') {
            printf("%s: %d\n", table->words[i].word, table->words[i].count);
        }
    }
}

void main() {
    HashTable table;
    init_hash_table(&table);
    char word[MAX_WORD_LEN + 1];
    while (scanf("%s", word)!= EOF) {
        add_word(&table, word);
    }
    print_hash_table(&table);
}