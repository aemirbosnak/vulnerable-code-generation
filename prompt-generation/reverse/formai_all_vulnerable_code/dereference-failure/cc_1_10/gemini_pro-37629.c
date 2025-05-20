//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *key;
    char *value;
    struct node *next;
};

struct hashtable {
    int size;
    struct node **table;
};

struct hashtable *create_hashtable(int size) {
    struct hashtable *ht = malloc(sizeof(struct hashtable));
    ht->size = size;
    ht->table = malloc(sizeof(struct node *) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void free_hashtable(struct hashtable *ht) {
    for (int i = 0; i < ht->size; i++) {
        struct node *curr = ht->table[i];
        while (curr != NULL) {
            struct node *next = curr->next;
            free(curr->key);
            free(curr->value);
            free(curr);
            curr = next;
        }
    }
    free(ht->table);
    free(ht);
}

unsigned int hash(char *key, int size) {
    unsigned int h = 0;
    for (int i = 0; i < strlen(key); i++) {
        h = (h << 5) + h + key[i];
    }
    return h % size;
}

void insert(struct hashtable *ht, char *key, char *value) {
    unsigned int h = hash(key, ht->size);
    struct node *new = malloc(sizeof(struct node));
    new->key = strdup(key);
    new->value = strdup(value);
    new->next = ht->table[h];
    ht->table[h] = new;
}

char *get(struct hashtable *ht, char *key) {
    unsigned int h = hash(key, ht->size);
    struct node *curr = ht->table[h];
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            return curr->value;
        }
        curr = curr->next;
    }
    return NULL;
}

int main() {
    struct hashtable *ht = create_hashtable(100);
    insert(ht, "name", "John Doe");
    insert(ht, "age", "30");
    insert(ht, "city", "New York");

    printf("name: %s\n", get(ht, "name"));
    printf("age: %s\n", get(ht, "age"));
    printf("city: %s\n", get(ht, "city"));

    free_hashtable(ht);
    return 0;
}