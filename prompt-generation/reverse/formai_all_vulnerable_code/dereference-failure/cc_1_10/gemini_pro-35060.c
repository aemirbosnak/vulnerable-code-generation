//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define NUM_BUCKETS 1024

typedef struct {
    int key;
    int value;
} pair_t;

typedef struct {
    pair_t *pairs;
    int size;
    int capacity;
} hashtable_t;

hashtable_t *hashtable_create(int capacity) {
    hashtable_t *table = malloc(sizeof(hashtable_t));
    table->pairs = malloc(sizeof(pair_t) * capacity);
    table->size = 0;
    table->capacity = capacity;
    return table;
}

void hashtable_destroy(hashtable_t *table) {
    free(table->pairs);
    free(table);
}

int hashtable_hash(hashtable_t *table, int key) {
    return key % table->capacity;
}

void hashtable_insert(hashtable_t *table, int key, int value) {
    int index = hashtable_hash(table, key);
    for (int i = index; i < table->capacity; i++) {
        if (table->pairs[i].key == key) {
            table->pairs[i].value = value;
            return;
        }
        if (table->pairs[i].key == 0) {
            table->pairs[i].key = key;
            table->pairs[i].value = value;
            table->size++;
            return;
        }
    }
    for (int i = 0; i < index; i++) {
        if (table->pairs[i].key == key) {
            table->pairs[i].value = value;
            return;
        }
        if (table->pairs[i].key == 0) {
            table->pairs[i].key = key;
            table->pairs[i].value = value;
            table->size++;
            return;
        }
    }
}

int hashtable_get(hashtable_t *table, int key) {
    int index = hashtable_hash(table, key);
    for (int i = index; i < table->capacity; i++) {
        if (table->pairs[i].key == key) {
            return table->pairs[i].value;
        }
    }
    for (int i = 0; i < index; i++) {
        if (table->pairs[i].key == key) {
            return table->pairs[i].value;
        }
    }
    return -1;
}

bool hashtable_contains(hashtable_t *table, int key) {
    int index = hashtable_hash(table, key);
    for (int i = index; i < table->capacity; i++) {
        if (table->pairs[i].key == key) {
            return true;
        }
    }
    for (int i = 0; i < index; i++) {
        if (table->pairs[i].key == key) {
            return true;
        }
    }
    return false;
}

void hashtable_print(hashtable_t *table) {
    for (int i = 0; i < table->capacity; i++) {
        if (table->pairs[i].key != 0) {
            printf("%d:%d\n", table->pairs[i].key, table->pairs[i].value);
        }
    }
}

int main() {
    hashtable_t *table = hashtable_create(NUM_BUCKETS);

    hashtable_insert(table, 1, 10);
    hashtable_insert(table, 2, 20);
    hashtable_insert(table, 3, 30);
    hashtable_insert(table, 4, 40);
    hashtable_insert(table, 5, 50);

    hashtable_print(table);

    printf("%d\n", hashtable_get(table, 3));

    hashtable_destroy(table);

    return 0;
}