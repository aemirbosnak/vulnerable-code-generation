//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int key;
    char value[100];
} Bucket;

typedef struct {
    int size;
    Bucket *buckets;
} HashTable;

HashTable *create_hash_table(int size) {
    HashTable *table = malloc(sizeof(HashTable));
    table->size = size;
    table->buckets = malloc(sizeof(Bucket) * size);
    for (int i = 0; i < size; i++) {
        table->buckets[i].key = -1;
        strcpy(table->buckets[i].value, "");
    }
    return table;
}

void insert_into_hash_table(HashTable *table, int key, char *value) {
    int index = key % table->size;
    while (table->buckets[index].key != -1) {
        index++;
        if (index == table->size) {
            index = 0;
        }
    }
    table->buckets[index].key = key;
    strcpy(table->buckets[index].value, value);
}

char *get_from_hash_table(HashTable *table, int key) {
    int index = key % table->size;
    while (table->buckets[index].key != -1) {
        if (table->buckets[index].key == key) {
            return table->buckets[index].value;
        }
        index++;
        if (index == table->size) {
            index = 0;
        }
    }
    return NULL;
}

void print_hash_table(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        if (table->buckets[i].key != -1) {
            printf("%d: %s\n", table->buckets[i].key, table->buckets[i].value);
        }
    }
}

int main() {
    HashTable *table = create_hash_table(MAX_SIZE);

    insert_into_hash_table(table, 1, "One");
    insert_into_hash_table(table, 2, "Two");
    insert_into_hash_table(table, 3, "Three");
    insert_into_hash_table(table, 4, "Four");
    insert_into_hash_table(table, 5, "Five");

    printf("Hash Table:\n");
    print_hash_table(table);

    char *value = get_from_hash_table(table, 3);
    if (value != NULL) {
        printf("Value for key 3: %s\n", value);
    } else {
        printf("Key 3 not found in hash table.\n");
    }

    return 0;
}