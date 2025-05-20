//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int key;
    char *value;
} entry;

typedef struct {
    int size;
    int capacity;
    entry *entries;
} hashtable;

hashtable *create_hashtable(int capacity) {
    hashtable *ht = malloc(sizeof(hashtable));
    ht->size = 0;
    ht->capacity = capacity;
    ht->entries = malloc(sizeof(entry) * capacity);
    return ht;
}

void destroy_hashtable(hashtable *ht) {
    for (int i = 0; i < ht->size; i++) {
        free(ht->entries[i].value);
    }
    free(ht->entries);
    free(ht);
}

int hash(int key, int capacity) {
    return key % capacity;
}

void insert(hashtable *ht, int key, char *value) {
    int index = hash(key, ht->capacity);
    while (ht->entries[index].key != 0) {
        index = (index + 1) % ht->capacity;
    }
    ht->entries[index].key = key;
    ht->entries[index].value = strdup(value);
    ht->size++;
}

char *get(hashtable *ht, int key) {
    int index = hash(key, ht->capacity);
    while (ht->entries[index].key != 0) {
        if (ht->entries[index].key == key) {
            return ht->entries[index].value;
        }
        index = (index + 1) % ht->capacity;
    }
    return NULL;
}

void print_hashtable(hashtable *ht) {
    for (int i = 0; i < ht->size; i++) {
        printf("%d: %s\n", ht->entries[i].key, ht->entries[i].value);
    }
}

int main() {
    hashtable *ht = create_hashtable(10);
    insert(ht, 1, "one");
    insert(ht, 2, "two");
    insert(ht, 3, "three");
    insert(ht, 4, "four");
    insert(ht, 5, "five");

    print_hashtable(ht);

    printf("Value for key 2: %s\n", get(ht, 2));

    destroy_hashtable(ht);
    return 0;
}