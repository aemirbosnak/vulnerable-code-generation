//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    char *value;
    struct node *next;
} node_t;

typedef struct hashtable {
    int size;
    node_t **table;
} hashtable_t;

hashtable_t *create_hashtable(int size) {
    hashtable_t *hashtable = (hashtable_t *)malloc(sizeof(hashtable_t));
    hashtable->size = size;
    hashtable->table = (node_t **)malloc(sizeof(node_t *) * size);
    for (int i = 0; i < size; i++) {
        hashtable->table[i] = NULL;
    }
    return hashtable;
}

int hash_function(char *key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % size;
}

void insert_into_hashtable(hashtable_t *hashtable, char *key, char *value) {
    int index = hash_function(key, hashtable->size);
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->key = key;
    new_node->value = value;
    new_node->next = hashtable->table[index];
    hashtable->table[index] = new_node;
}

char *get_from_hashtable(hashtable_t *hashtable, char *key) {
    int index = hash_function(key, hashtable->size);
    node_t *current_node = hashtable->table[index];
    while (current_node != NULL) {
        if (strcmp(current_node->key, key) == 0) {
            return current_node->value;
        }
        current_node = current_node->next;
    }
    return NULL;
}

void print_hashtable(hashtable_t *hashtable) {
    for (int i = 0; i < hashtable->size; i++) {
        node_t *current_node = hashtable->table[i];
        while (current_node != NULL) {
            printf("%s: %s\n", current_node->key, current_node->value);
            current_node = current_node->next;
        }
    }
}

void free_hashtable(hashtable_t *hashtable) {
    for (int i = 0; i < hashtable->size; i++) {
        node_t *current_node = hashtable->table[i];
        while (current_node != NULL) {
            node_t *next_node = current_node->next;
            free(current_node->key);
            free(current_node->value);
            free(current_node);
            current_node = next_node;
        }
    }
    free(hashtable->table);
    free(hashtable);
}

int main() {
    hashtable_t *hashtable = create_hashtable(10);
    insert_into_hashtable(hashtable, "name", "John Doe");
    insert_into_hashtable(hashtable, "age", "25");
    insert_into_hashtable(hashtable, "city", "New York");
    printf("Name: %s\n", get_from_hashtable(hashtable, "name"));
    printf("Age: %s\n", get_from_hashtable(hashtable, "age"));
    printf("City: %s\n", get_from_hashtable(hashtable, "city"));
    print_hashtable(hashtable);
    free_hashtable(hashtable);
    return 0;
}