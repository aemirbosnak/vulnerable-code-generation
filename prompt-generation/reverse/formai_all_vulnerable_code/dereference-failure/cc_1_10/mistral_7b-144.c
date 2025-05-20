//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 100
#define HASH_TABLE_SIZE 256

typedef struct {
    char data[BUFFER_SIZE];
    int head;
    int tail;
} CircularBuffer;

typedef struct {
    char key;
    int count;
} HashTableEntry;

CircularBuffer cb;
HashTableEntry hash_table[HASH_TABLE_SIZE];

unsigned int hash_function(char key) {
    return key % HASH_TABLE_SIZE;
}

void cb_init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
}

void cb_write(CircularBuffer *cb, char data) {
    if ((cb->tail + 1) % BUFFER_SIZE == cb->head) {
        printf("Buffer is full!\n");
        exit(EXIT_FAILURE);
    }

    cb->data[cb->tail] = data;
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
}

char cb_read(CircularBuffer *cb) {
    if (cb->head == cb->tail) {
        printf("Buffer is empty!\n");
        exit(EXIT_FAILURE);
    }

    char data = cb->data[cb->head];
    cb->head = (cb->head + 1) % BUFFER_SIZE;

    return data;
}

void hash_table_init() {
    memset(hash_table, 0, sizeof(HashTableEntry) * HASH_TABLE_SIZE);
}

void sequencing(FILE *file) {
    char nucleotide;

    cb_init(&cb);

    while (fscanf(file, "%c", &nucleotide) != EOF) {
        cb_write(&cb, nucleotide);

        unsigned int index = hash_function(nucleotide);
        HashTableEntry *entry = &hash_table[index];

        entry->key = nucleotide;
        entry->count++;
    }
}

int main() {
    FILE *file = fopen("sequence.txt", "r");

    if (!file) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    sequencing(file);

    fclose(file);

    printf("\nHash Table:\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (hash_table[i].count > 0) {
            printf("Key: %c, Count: %d\n", hash_table[i].key, hash_table[i].count);
        }
    }

    return 0;
}