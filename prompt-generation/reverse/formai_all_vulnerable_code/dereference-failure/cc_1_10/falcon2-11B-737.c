//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000000

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} Word;

typedef struct {
    Word words[MAX_NUM_WORDS];
    int num_words;
} HashTable;

HashTable *create_hash_table(void) {
    HashTable *table = (HashTable *) malloc(sizeof(HashTable));
    table->num_words = 0;
    return table;
}

void add_word_to_table(HashTable *table, const char *word) {
    int index = hash_word(word);
    if (table->words[index].count == 0) {
        table->words[index].count = 1;
        table->num_words++;
    } else {
        table->words[index].count++;
    }
}

void free_hash_table(HashTable *table) {
    free(table);
}

int hash_word(const char *word) {
    int hash = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        hash += word[i];
    }
    return hash % MAX_NUM_WORDS;
}

void print_top_words(const HashTable *table, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", table->words[i].word, table->words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    HashTable *table = create_hash_table();
    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word)!= EOF) {
        add_word_to_table(table, word);
    }
    fclose(file);

    print_top_words(table, 10);
    free_hash_table(table);

    return 0;
}