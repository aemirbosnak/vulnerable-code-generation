//Falcon2-11B DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Hash function to compute the hash value of a word
// Use a simple modulo operation for simplicity
int hash(const char *word) {
    int hash_value = 0;
    for (int i = 0; word[i]!= '\0'; i++) {
        hash_value = (hash_value << 2) ^ word[i];
    }
    return hash_value;
}

// Hash table to store the word counts
struct HashTable {
    int capacity;
    int size;
    char **table;
};

// Initialize the hash table with the given capacity
void init_hash_table(struct HashTable *table, int capacity) {
    table->capacity = capacity;
    table->size = 0;
    table->table = (char **) malloc(capacity * sizeof(char *));
    for (int i = 0; i < capacity; i++) {
        table->table[i] = NULL;
    }
}

// Add a word to the hash table
void insert(struct HashTable *table, const char *word) {
    int index = hash(word) % table->capacity;
    if (table->table[index] == NULL) {
        table->table[index] = (char *) malloc(strlen(word) + 1);
        strcpy(table->table[index], word);
        table->size++;
    } else {
        int i;
        for (i = 0; table->table[index][i]!= '\0'; i++) {
            if (strcmp(table->table[index], word) == 0) {
                break;
            }
        }
        if (table->table[index][i] == '\0') {
            strcat(table->table[index], " ");
            strcat(table->table[index], word);
            table->size++;
        }
    }
}

// Remove all words from the hash table
void clear_hash_table(struct HashTable *table) {
    for (int i = 0; i < table->capacity; i++) {
        if (table->table[i]!= NULL) {
            free(table->table[i]);
            table->table[i] = NULL;
        }
    }
    table->size = 0;
}

// Print the word counts in the hash table
void print_word_counts(struct HashTable *table) {
    for (int i = 0; i < table->capacity; i++) {
        if (table->table[i]!= NULL) {
            printf("%s: %d\n", table->table[i], table->table[i]? table->size : 0);
        }
    }
}

int main() {
    char *input = "Hello world hello world hello world";
    struct HashTable hash_table;
    init_hash_table(&hash_table, 4);

    insert(&hash_table, "Hello");
    insert(&hash_table, "world");

    print_word_counts(&hash_table);

    clear_hash_table(&hash_table);

    return 0;
}