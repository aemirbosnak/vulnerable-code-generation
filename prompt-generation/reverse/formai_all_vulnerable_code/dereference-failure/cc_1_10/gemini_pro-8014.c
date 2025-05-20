//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom memory allocator
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    memset(ptr, 0, size);
    return ptr;
}

// Custom memory deallocator
void my_free(void *ptr) {
    if (ptr != NULL) {
        free(ptr);
    }
}

// Custom memory reallocator
void *my_realloc(void *ptr, size_t size) {
    void *new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        fprintf(stderr, "realloc failed\n");
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

// Custom memory pool
struct memory_pool {
    void *base;
    size_t size;
    size_t used;
};

struct memory_pool *my_pool_create(size_t size) {
    struct memory_pool *pool = my_malloc(sizeof(struct memory_pool));
    pool->base = my_malloc(size);
    pool->size = size;
    pool->used = 0;
    return pool;
}

void my_pool_destroy(struct memory_pool *pool) {
    my_free(pool->base);
    my_free(pool);
}

void *my_pool_alloc(struct memory_pool *pool, size_t size) {
    if (pool->used + size > pool->size) {
        fprintf(stderr, "pool allocation failed\n");
        exit(EXIT_FAILURE);
    }
    void *ptr = pool->base + pool->used;
    pool->used += size;
    return ptr;
}

void my_pool_free(struct memory_pool *pool, void *ptr) {
    if (ptr < pool->base || ptr >= pool->base + pool->size) {
        fprintf(stderr, "pool free failed\n");
        exit(EXIT_FAILURE);
    }
    pool->used -= ptr - pool->base;
}

// Custom memory leak detector
struct memory_leak_detector {
    void *ptr;
    struct memory_leak_detector *next;
};

struct memory_leak_detector *my_leak_detector_create() {
    struct memory_leak_detector *detector = my_malloc(sizeof(struct memory_leak_detector));
    detector->ptr = NULL;
    detector->next = NULL;
    return detector;
}

void my_leak_detector_destroy(struct memory_leak_detector *detector) {
    struct memory_leak_detector *current = detector;
    while (current != NULL) {
        struct memory_leak_detector *next = current->next;
        my_free(current);
        current = next;
    }
}

void my_leak_detector_add(struct memory_leak_detector *detector, void *ptr) {
    struct memory_leak_detector *new_detector = my_malloc(sizeof(struct memory_leak_detector));
    new_detector->ptr = ptr;
    new_detector->next = detector->next;
    detector->next = new_detector;
}

void my_leak_detector_remove(struct memory_leak_detector *detector, void *ptr) {
    struct memory_leak_detector *current = detector;
    while (current != NULL) {
        if (current->next != NULL && current->next->ptr == ptr) {
            struct memory_leak_detector *next = current->next->next;
            my_free(current->next);
            current->next = next;
            break;
        }
        current = current->next;
    }
}

void my_leak_detector_print(struct memory_leak_detector *detector) {
    struct memory_leak_detector *current = detector->next;
    while (current != NULL) {
        printf("Leaked memory: %p\n", current->ptr);
        current = current->next;
    }
}

// Example usage
int main() {
    // Create a memory leak detector
    struct memory_leak_detector *detector = my_leak_detector_create();

    // Allocate some memory
    void *ptr1 = my_malloc(100);
    void *ptr2 = my_realloc(ptr1, 200);
    void *ptr3 = my_pool_alloc(my_pool_create(1000), 100);

    // Add the allocated memory to the detector
    my_leak_detector_add(detector, ptr1);
    my_leak_detector_add(detector, ptr2);
    my_leak_detector_add(detector, ptr3);

    // Free some memory
    my_free(ptr2);
    my_pool_free(my_pool_create(1000), ptr3);

    // Remove the freed memory from the detector
    my_leak_detector_remove(detector, ptr2);
    my_leak_detector_remove(detector, ptr3);

    // Print any remaining leaked memory
    my_leak_detector_print(detector);

    // Destroy the memory leak detector
    my_leak_detector_destroy(detector);

    return 0;
}