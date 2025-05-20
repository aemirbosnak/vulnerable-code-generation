//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

typedef struct hashtable {
    node_t **table;
    int size;
} hashtable_t;

hashtable_t *create_hashtable(int size) {
    hashtable_t *hashtable = malloc(sizeof(hashtable_t));
    hashtable->table = malloc(sizeof(node_t *) * size);
    hashtable->size = size;

    for (int i = 0; i < size; i++) {
        hashtable->table[i] = NULL;
    }

    return hashtable;
}

void free_hashtable(hashtable_t *hashtable) {
    for (int i = 0; i < hashtable->size; i++) {
        node_t *node = hashtable->table[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node->word);
            free(node);
            node = next;
        }
    }

    free(hashtable->table);
    free(hashtable);
}

int hash(char *word, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += word[i];
    }

    return hash % size;
}

void insert_word(hashtable_t *hashtable, char *word) {
    int index = hash(word, hashtable->size);
    node_t *node = hashtable->table[index];

    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            node->count++;
            return;
        }

        node = node->next;
    }

    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = hashtable->table[index];
    hashtable->table[index] = new_node;
}

int get_word_count(hashtable_t *hashtable, char *word) {
    int index = hash(word, hashtable->size);
    node_t *node = hashtable->table[index];

    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            return node->count;
        }

        node = node->next;
    }

    return 0;
}

int main() {
    hashtable_t *hashtable = create_hashtable(100);

    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int num_words = sizeof(words) / sizeof(char *);

    for (int i = 0; i < num_words; i++) {
        insert_word(hashtable, words[i]);
    }

    for (int i = 0; i < num_words; i++) {
        int count = get_word_count(hashtable, words[i]);
        printf("%s: %d\n", words[i], count);
    }

    free_hashtable(hashtable);

    return 0;
}