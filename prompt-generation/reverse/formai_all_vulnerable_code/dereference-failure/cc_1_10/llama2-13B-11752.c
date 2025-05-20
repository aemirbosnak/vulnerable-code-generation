//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MEMORY_SIZE 1024
#define PAIR_COUNT 20

typedef struct pair {
    int key;
    int value;
} pair_t;

typedef struct memory {
    pair_t *data;
    size_t capacity;
    size_t size;
} memory_t;

memory_t *create_memory(size_t capacity) {
    memory_t *mem = malloc(sizeof(memory_t));
    mem->capacity = capacity;
    mem->size = 0;
    mem->data = calloc(capacity, sizeof(pair_t));
    return mem;
}

void insert_pair(memory_t *mem, int key, int value) {
    if (mem->size >= mem->capacity) {
        mem->capacity *= 2;
        mem->data = realloc(mem->data, mem->capacity * sizeof(pair_t));
    }
    mem->data[mem->size].key = key;
    mem->data[mem->size].value = value;
    mem->size++;
}

int get_value(memory_t *mem, int key) {
    for (size_t i = 0; i < mem->size; i++) {
        if (mem->data[i].key == key) {
            return mem->data[i].value;
        }
    }
    return -1;
}

int main() {
    srand(time(NULL));
    memory_t *mem = create_memory(MEMORY_SIZE);
    for (size_t i = 0; i < PAIR_COUNT; i++) {
        int key = rand() % 100;
        int value = rand() % 100;
        insert_pair(mem, key, value);
    }
    for (size_t i = 0; i < PAIR_COUNT; i++) {
        int key = rand() % 100;
        int value = get_value(mem, key);
        printf("%d -> %d\n", key, value);
    }
    return 0;
}