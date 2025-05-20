//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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
    hashtable->size = size;
    hashtable->table = malloc(sizeof(node_t *) * size);
    for (int i = 0; i < size; i++) {
        hashtable->table[i] = NULL;
    }
    return hashtable;
}

void destroy_hashtable(hashtable_t *hashtable) {
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

int hash_function(const char *word, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += tolower(word[i]);
    }
    return hash % size;
}

void insert_word(hashtable_t *hashtable, const char *word) {
    int index = hash_function(word, hashtable->size);
    node_t *node = hashtable->table[index];
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            node->count++;
            return;
        }
        node = node->next;
    }
    node = malloc(sizeof(node_t));
    node->word = strdup(word);
    node->count = 1;
    node->next = hashtable->table[index];
    hashtable->table[index] = node;
}

void print_hashtable(hashtable_t *hashtable) {
    for (int i = 0; i < hashtable->size; i++) {
        node_t *node = hashtable->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    hashtable_t *hashtable = create_hashtable(1000);

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *word = strtok(buffer, " ,.-!?\n");
        while (word != NULL) {
            insert_word(hashtable, word);
            word = strtok(NULL, " ,.-!?\n");
        }
    }

    fclose(file);

    print_hashtable(hashtable);

    destroy_hashtable(hashtable);

    return EXIT_SUCCESS;
}