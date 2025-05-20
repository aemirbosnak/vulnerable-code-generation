//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MAX_OBJS 10

typedef struct obj {
    int id;
    char name[MAX_STR_LEN];
    void* data;
} obj;

void* malloc_fn(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed: %zu\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void free_fn(void* ptr) {
    free(ptr);
}

int main() {
    srand(time(NULL));

    // Create some objects
    obj* objs = calloc(MAX_OBJS, sizeof(obj));
    for (int i = 0; i < MAX_OBJS; i++) {
        objs[i].id = rand() % 10;
        sprintf(objs[i].name, "Object %d", objs[i].id);
        objs[i].data = malloc_fn(rand() % 100);
    }

    // Print out the objects
    for (int i = 0; i < MAX_OBJS; i++) {
        printf("%d: %s (%p)\n", objs[i].id, objs[i].name, objs[i].data);
    }

    // Free some objects
    for (int i = 0; i < 5; i++) {
        free_fn(objs[i].data);
    }

    // Print out the objects again
    for (int i = 0; i < MAX_OBJS; i++) {
        printf("%d: %s (%p)\n", objs[i].id, objs[i].name, objs[i].data);
    }

    return 0;
}