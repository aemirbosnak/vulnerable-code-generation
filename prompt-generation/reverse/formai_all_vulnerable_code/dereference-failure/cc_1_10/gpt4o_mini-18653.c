//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct WordNode {
    char *word;
    int count;
    struct WordNode *next;
} WordNode;

typedef struct HashTable {
    WordNode **table;
} HashTable;

unsigned int hash(const char *word) {
    unsigned long int hashval = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hashval = hashval * 31 + word[i];
    }
    return hashval % TABLE_SIZE;
}

HashTable *create_table() {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->table = malloc(sizeof(WordNode *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void insert_word(HashTable *ht, const char *word) {
    unsigned int idx = hash(word);
    WordNode *current = ht->table[idx];

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    WordNode *new_node = malloc(sizeof(WordNode));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = ht->table[idx];
    ht->table[idx] = new_node;
}

void free_table(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        WordNode *current = ht->table[i];
        while (current != NULL) {
            WordNode *temp = current;
            current = current->next;
            free(temp->word);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

void print_table(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        WordNode *current = ht->table[i];
        while (current != NULL) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

void count_words_in_file(const char *filename, HashTable *ht) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    char buffer[256];
    while (fscanf(file, "%255s", buffer) == 1) {
        // Remove punctuation from the word
        for (int i = 0; buffer[i]; i++) {
            if (ispunct(buffer[i])) {
                buffer[i] = '\0';
            }
        }
        insert_word(ht, buffer);
    }

    fclose(file);
}

int main() {
    HashTable *ht = create_table();
    const char *filename = "text.txt"; // Change to your desired file name

    count_words_in_file(filename, ht);
    print_table(ht);
    free_table(ht);

    return 0;
}