//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    void *value;
} kvp;

typedef struct {
    int size;
    int capacity;
    kvp *kvp;
} hashtable;

hashtable *new_hashtable(int capacity) {
    hashtable *ht = malloc(sizeof(hashtable));
    ht->size = 0;
    ht->capacity = capacity;
    ht->kvp = malloc(sizeof(kvp) * capacity);
    return ht;
}

void free_hashtable(hashtable *ht) {
    for (int i = 0; i < ht->size; i++) {
        free(ht->kvp[i].key);
        free(ht->kvp[i].value);
    }
    free(ht->kvp);
    free(ht);
}

int hash(char *key, int capacity) {
    int h = 0;
    for (int i = 0; i < strlen(key); i++) {
        h = (h << 5) - h + key[i];
    }
    return h % capacity;
}

void insert(hashtable *ht, char *key, void *value) {
    int h = hash(key, ht->capacity);
    while (ht->kvp[h].key != NULL) {
        h = (h + 1) % ht->capacity;
    }
    ht->kvp[h].key = strdup(key);
    ht->kvp[h].value = value;
    ht->size++;
}

void *get(hashtable *ht, char *key) {
    int h = hash(key, ht->capacity);
    while (ht->kvp[h].key != NULL) {
        if (strcmp(ht->kvp[h].key, key) == 0) {
            return ht->kvp[h].value;
        }
        h = (h + 1) % ht->capacity;
    }
    return NULL;
}

int main() {
    hashtable *ht = new_hashtable(100);
    insert(ht, "name", "John Doe");
    insert(ht, "age", "30");
    insert(ht, "city", "New York");
    printf("%s\n", get(ht, "name"));
    printf("%s\n", get(ht, "age"));
    printf("%s\n", get(ht, "city"));
    free_hashtable(ht);
    return 0;
}