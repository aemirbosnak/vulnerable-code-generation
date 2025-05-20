//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdint.h>

#define HASH_SIZE 10

typedef struct HashEntry {
    uint32_t key;
    struct HashEntry* next;
} HashEntry;

HashEntry** hash_table = NULL;

void hash_add(uint32_t key) {
    HashEntry* new_entry = malloc(sizeof(HashEntry));
    new_entry->key = key;
    new_entry->next = NULL;

    if (hash_table == NULL) {
        hash_table = malloc(sizeof(HashEntry*) * HASH_SIZE);
    }

    int index = key % HASH_SIZE;
    if (hash_table[index] == NULL) {
        hash_table[index] = new_entry;
    } else {
        HashEntry* current = hash_table[index];
        while (current->next) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

uint32_t hash_get(uint32_t key) {
    int index = key % HASH_SIZE;
    HashEntry* current = hash_table[index];

    while (current) {
        if (current->key == key) {
            return current->key;
        }
        current = current->next;
    }

    return -1;
}

int main() {
    hash_add(10);
    hash_add(20);
    hash_add(30);
    hash_add(40);

    uint32_t result = hash_get(20);

    if (result != -1) {
        printf("Key found: %d\n", result);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}