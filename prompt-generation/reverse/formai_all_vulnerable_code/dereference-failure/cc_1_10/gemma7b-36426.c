//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct HashTable {
    char **keys;
    int size;
    int capacity;
} HashTable;

int hashFunction(char *key) {
    return (int)key[0] * key[1] % MAX_BUFFER_SIZE;
}

void insertIntoHashTable(HashTable *ht, char *key) {
    int index = hashFunction(key);
    ht->keys[index] = key;
}

void calculateChecksum(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    int bytesRead = 0;
    unsigned int checksum = 0;

    while ((bytesRead = fread(buffer, 1, MAX_BUFFER_SIZE, fp)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            checksum += (int)buffer[i];
        }
    }

    fclose(fp);

    printf("Checksum for file '%s': %u\n", filename, checksum);
}

int main() {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->keys = malloc(MAX_BUFFER_SIZE * sizeof(char *));
    ht->size = 0;
    ht->capacity = MAX_BUFFER_SIZE;

    insertIntoHashTable(ht, "a.txt");
    insertIntoHashTable(ht, "b.txt");
    insertIntoHashTable(ht, "c.txt");

    calculateChecksum("a.txt");
    calculateChecksum("b.txt");
    calculateChecksum("c.txt");

    free(ht->keys);
    free(ht);

    return 0;
}