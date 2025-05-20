//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRATEFUL_MEMORY_SIZE 10

typedef struct grateful_memory_t {
    int key;
    char value[20];
} grateful_memory_t;

grateful_memory_t *grateful_memory_create(void) {
    grateful_memory_t *mem = calloc(1, sizeof(grateful_memory_t));
    return mem;
}

void grateful_memory_add(grateful_memory_t *mem, int key, char *value) {
    mem->key = key;
    strcpy(mem->value, value);
}

void *grateful_memory_get(grateful_memory_t *mem, int key) {
    void *ptr = NULL;
    if (mem->key == key) {
        ptr = mem->value;
    }
    return ptr;
}

int grateful_memory_exist(grateful_memory_t *mem, int key) {
    return mem->key == key;
}

void grateful_memory_delete(grateful_memory_t *mem, int key) {
    mem->key = 0;
    strcpy(mem->value, "deleted");
}

void grateful_memory_clear(grateful_memory_t *mem) {
    mem->key = 0;
    strcpy(mem->value, "deleted");
}

int main(void) {
    srand(time(NULL));

    grateful_memory_t *mem = grateful_memory_create();

    for (int i = 0; i < GRATEFUL_MEMORY_SIZE; i++) {
        int key = rand() % 10;
        char value[20];
        snprintf(value, sizeof(value), "value %d", key);
        grateful_memory_add(mem, key, value);
    }

    for (int i = 0; i < GRATEFUL_MEMORY_SIZE; i++) {
        int key = rand() % 10;
        if (grateful_memory_exist(mem, key)) {
            void *ptr = grateful_memory_get(mem, key);
            printf("Memory key %d value %s\n", key, (char *)ptr);
        } else {
            printf("Memory key %d does not exist\n", key);
        }
    }

    for (int i = 0; i < GRATEFUL_MEMORY_SIZE; i++) {
        int key = rand() % 10;
        grateful_memory_delete(mem, key);
    }

    for (int i = 0; i < GRATEFUL_MEMORY_SIZE; i++) {
        int key = rand() % 10;
        if (grateful_memory_exist(mem, key)) {
            printf("Memory key %d value deleted\n", key);
        } else {
            printf("Memory key %d does not exist\n", key);
        }
    }

    grateful_memory_clear(mem);

    for (int i = 0; i < GRATEFUL_MEMORY_SIZE; i++) {
        int key = rand() % 10;
        if (grateful_memory_exist(mem, key)) {
            printf("Memory key %d value deleted\n", key);
        } else {
            printf("Memory key %d does not exist\n", key);
        }
    }

    return 0;
}