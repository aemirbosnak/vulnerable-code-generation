//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHTABLE_SIZE 1000
#define INDEX_SIZE 1000

struct index_node {
    char *key;
    int value;
    struct index_node *next;
};

struct index {
    struct index_node *table[INDEX_SIZE];
};

struct hashtable {
    struct index_node *table[HASHTABLE_SIZE];
};

struct hashtable *create_hashtable() {
    struct hashtable *hashtable = malloc(sizeof(struct hashtable));
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        hashtable->table[i] = NULL;
    }
    return hashtable;
}

int hash(char *key) {
    int hash_value = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash_value += key[i];
    }
    return hash_value % HASHTABLE_SIZE;
}

void insert_hashtable(struct hashtable *hashtable, char *key, int value) {
    int hash_value = hash(key);
    struct index_node *node = malloc(sizeof(struct index_node));
    node->key = key;
    node->value = value;
    node->next = hashtable->table[hash_value];
    hashtable->table[hash_value] = node;
}

int get_hashtable(struct hashtable *hashtable, char *key) {
    int hash_value = hash(key);
    struct index_node *node = hashtable->table[hash_value];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

struct index *create_index() {
    struct index *index = malloc(sizeof(struct index));
    for (int i = 0; i < INDEX_SIZE; i++) {
        index->table[i] = NULL;
    }
    return index;
}

void insert_index(struct index *index, char *key, int value) {
    int index_value = hash(key) % INDEX_SIZE;
    struct index_node *node = malloc(sizeof(struct index_node));
    node->key = key;
    node->value = value;
    node->next = index->table[index_value];
    index->table[index_value] = node;
}

int get_index(struct index *index, char *key) {
    int index_value = hash(key) % INDEX_SIZE;
    struct index_node *node = index->table[index_value];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

int main() {
    struct hashtable *hashtable = create_hashtable();
    struct index *index = create_index();

    insert_hashtable(hashtable, "key1", 1);
    insert_hashtable(hashtable, "key2", 2);
    insert_hashtable(hashtable, "key3", 3);
    insert_index(index, "key1", 1);
    insert_index(index, "key2", 2);
    insert_index(index, "key3", 3);

    printf("%d\n", get_hashtable(hashtable, "key1"));
    printf("%d\n", get_hashtable(hashtable, "key2"));
    printf("%d\n", get_hashtable(hashtable, "key3"));
    printf("%d\n", get_index(index, "key1"));
    printf("%d\n", get_index(index, "key2"));
    printf("%d\n", get_index(index, "key3"));

    return 0;
}