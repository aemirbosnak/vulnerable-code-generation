//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHTABLE_SIZE 26
#define MAX_WORD_LENGTH 32

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

typedef struct hashtable {
    node_t **table;
} hashtable_t;

hashtable_t *create_hashtable() {
    hashtable_t *hashtable = malloc(sizeof(hashtable_t));
    hashtable->table = calloc(HASHTABLE_SIZE, sizeof(node_t *));
    return hashtable;
}

void destroy_hashtable(hashtable_t *hashtable) {
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        node_t *node = hashtable->table[i];
        while (node) {
            node_t *next = node->next;
            free(node->word);
            free(node);
            node = next;
        }
    }
    free(hashtable->table);
    free(hashtable);
}

int hash(char *word) {
    int hash = 0;
    for (int i = 0; word[i]; i++) {
        hash += word[i];
    }
    return hash % HASHTABLE_SIZE;
}

node_t *find_node(hashtable_t *hashtable, char *word) {
    int index = hash(word);
    node_t *node = hashtable->table[index];
    while (node) {
        if (!strcmp(node->word, word)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void insert_word(hashtable_t *hashtable, char *word) {
    int index = hash(word);
    node_t *node = find_node(hashtable, word);

    if (node) {
        node->count++;
    } else {
        node = malloc(sizeof(node_t));
        node->word = strdup(word);
        node->count = 1;
        node->next = hashtable->table[index];
        hashtable->table[index] = node;
    }
}

void print_hashtable(hashtable_t *hashtable) {
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        node_t *node = hashtable->table[i];
        while (node) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }
}

int main() {
    hashtable_t *hashtable = create_hashtable();
    char buffer[MAX_WORD_LENGTH];
    
    printf("Enter words (enter an empty word to quit)\n");
    while (scanf("%s", buffer) != EOF) {
        insert_word(hashtable, buffer);
    }

    print_hashtable(hashtable);
    destroy_hashtable(hashtable);
    return 0;
}