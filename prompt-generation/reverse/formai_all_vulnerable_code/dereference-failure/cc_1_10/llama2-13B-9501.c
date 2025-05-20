//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OBJS 1024
#define MAX_NAME_LEN 32

typedef struct obj_t {
    char name[MAX_NAME_LEN];
    void* data;
    struct obj_t* next;
} obj_t;

typedef struct {
    obj_t** obj_array;
    int capacity;
    int size;
} mem_pool_t;

void init_pool(mem_pool_t* pool, int capacity) {
    pool->obj_array = calloc(capacity, sizeof(obj_t*));
    pool->capacity = capacity;
    pool->size = 0;
}

void* alloc_obj(mem_pool_t* pool) {
    if (pool->size >= pool->capacity) {
        int new_capacity = pool->capacity * 2;
        obj_t** new_array = realloc(pool->obj_array, new_capacity * sizeof(obj_t*));
        if (!new_array) {
            printf("Out of memory\n");
            return NULL;
        }
        pool->obj_array = new_array;
        pool->capacity = new_capacity;
    }
    obj_t* obj = pool->obj_array[pool->size];
    pool->size++;
    return obj->data;
}

void free_obj(mem_pool_t* pool, void* obj) {
    obj_t* p = obj;
    while (p->next != NULL) {
        p = p->next;
    }
    pool->size--;
    p->next = pool->obj_array[pool->size];
    pool->obj_array[pool->size] = p;
}

int main() {
    mem_pool_t pool;
    init_pool(&pool, 16);

    // Create and free objects
    void* p1 = alloc_obj(&pool);
    void* p2 = alloc_obj(&pool);
    void* p3 = alloc_obj(&pool);
    free_obj(&pool, p1);
    free_obj(&pool, p2);
    free_obj(&pool, p3);

    // Check for memory leaks
    printf("Size of pool: %d\n", pool.size);
    for (int i = 0; i < pool.capacity; i++) {
        obj_t* obj = pool.obj_array[i];
        if (obj->data != NULL) {
            printf("Leak detected: %p\n", obj->data);
        }
    }

    return 0;
}