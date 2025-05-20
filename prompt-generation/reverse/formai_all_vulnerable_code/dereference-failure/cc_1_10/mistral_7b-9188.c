//MISTRAL-7B DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct HashNode {
    char *word;
    struct HashNode *next;
} HashNode;

unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

HashNode *create_node(const char *word) {
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));

    new_node->word = strdup(word);
    new_node->next = NULL;

    return new_node;
}

void insert_word(HashNode **hash_table, const char *word) {
    unsigned long index = hash(word);

    if (!hash_table[index]) {
        hash_table[index] = create_node(word);
    } else {
        HashNode *current = hash_table[index];

        while (current->next) {
            current = current->next;
        }

        current->next = create_node(word);
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    HashNode *hash_table[TABLE_SIZE] = {NULL};
    char word[50];
    int num_unique_words = 0;

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(file, "%s%*[^\n]", word) != EOF) {
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        insert_word(hash_table, word);
    }

    fclose(file);

    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *current = hash_table[i];

        while (current) {
            num_unique_words++;
            current = current->next;
        }
    }

    printf("Number of unique words: %d\n", num_unique_words);

    return 0;
}