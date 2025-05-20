//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MEMORY 1024
#define MAX_OBJS 100

typedef struct obj {
    void* data;
    size_t size;
} obj;

void* malloc_impl(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        printf("Error: Out of memory! : (%zu)\n", size);
        exit(EXIT_FAILURE);
    }
    return mem;
}

void free_impl(void* mem) {
    free(mem);
}

void* alloc_obj(size_t size) {
    obj* obj = calloc(1, sizeof(obj) + size);
    obj->data = malloc_impl(size);
    obj->size = size;
    return obj->data;
}

void free_obj(void* obj) {
    free_impl(obj);
    free(obj);
}

int main() {
    obj* obj_array = calloc(MAX_OBJS, sizeof(obj));
    for (size_t i = 0; i < MAX_OBJS; i++) {
        obj_array[i].data = alloc_obj(rand() % MAX_MEMORY);
        printf("Object %zu created with size %zu\n", i, obj_array[i].size);
    }

    for (size_t i = 0; i < MAX_OBJS; i++) {
        free_obj(obj_array[i].data);
        printf("Object %zu destroyed with size %zu\n", i, obj_array[i].size);
    }

    free(obj_array);
    return 0;
}