//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MIN_WORD_LEN 3
#define HASH_TABLE_SIZE 1000000

typedef struct {
    char word[MAX_WORDS];
    int count;
} WordCount;

typedef struct {
    WordCount *table;
    int size;
} HashTable;

int hash(char *word) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(word); i++) {
        sum += word[i];
    }
    return sum % HASH_TABLE_SIZE;
}

void init_table(HashTable *table) {
    table->table = (WordCount *)malloc(sizeof(WordCount) * HASH_TABLE_SIZE);
    table->size = HASH_TABLE_SIZE;
    int i;
    for (i = 0; i < table->size; i++) {
        table->table[i].count = 0;
    }
}

void add_word(HashTable *table, char *word) {
    int index = hash(word);
    table->table[index].word[table->table[index].count] = word;
    table->table[index].count++;
}

void print_table(HashTable *table) {
    int i;
    for (i = 0; i < table->size; i++) {
        if (table->table[i].count > 0) {
            printf("%d: ", i);
            int j;
            for (j = 0; j < table->table[i].count; j++) {
                printf("%s ", table->table[i].word[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    char word[MAX_WORDS];
    int i;
    HashTable table;
    init_table(&table);
    while (fscanf(stdin, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LEN) {
            add_word(&table, word);
        }
    }
    print_table(&table);
    return 0;
}