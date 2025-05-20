//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#define STACK_ALIGNMENT 16
#define HEAP_ALIGNMENT 16
#define MALLOC_ALIGNMENT 16

#define NR_OF_STACK_AREAS 16
#define NR_OF_HEAP_AREAS 16
#define NR_OF_MALLOC_AREAS 16

typedef struct {
    void *start;
    void *end;
} area_t;

static area_t stack_areas[NR_OF_STACK_AREAS];
static area_t heap_areas[NR_OF_HEAP_AREAS];
static area_t malloc_areas[NR_OF_MALLOC_AREAS];

static uint64_t stack_usage = 0;
static uint64_t heap_usage = 0;
static uint64_t malloc_usage = 0;

static void *align_ptr(void *ptr, size_t alignment) {
    return (void *)(((uintptr_t)ptr + alignment - 1) & ~(alignment - 1));
}

static void *allocate_stack(size_t size) {
    void *ptr;

    ptr = malloc(size + STACK_ALIGNMENT);
    if (!ptr) {
        return NULL;
    }

    ptr = align_ptr(ptr, STACK_ALIGNMENT);

    for (int i = 0; i < NR_OF_STACK_AREAS; i++) {
        if (!stack_areas[i].start) {
            stack_areas[i].start = ptr;
            stack_areas[i].end = ptr + size;
            stack_usage += size;
            return ptr;
        }
    }

    free(ptr);
    return NULL;
}

static void *allocate_heap(size_t size) {
    void *ptr;

    ptr = malloc(size + HEAP_ALIGNMENT);
    if (!ptr) {
        return NULL;
    }

    ptr = align_ptr(ptr, HEAP_ALIGNMENT);

    for (int i = 0; i < NR_OF_HEAP_AREAS; i++) {
        if (!heap_areas[i].start) {
            heap_areas[i].start = ptr;
            heap_areas[i].end = ptr + size;
            heap_usage += size;
            return ptr;
        }
    }

    free(ptr);
    return NULL;
}

static void *allocate_malloc(size_t size) {
    void *ptr;

    ptr = malloc(size + MALLOC_ALIGNMENT);
    if (!ptr) {
        return NULL;
    }

    ptr = align_ptr(ptr, MALLOC_ALIGNMENT);

    for (int i = 0; i < NR_OF_MALLOC_AREAS; i++) {
        if (!malloc_areas[i].start) {
            malloc_areas[i].start = ptr;
            malloc_areas[i].end = ptr + size;
            malloc_usage += size;
            return ptr;
        }
    }

    free(ptr);
    return NULL;
}

static void free_stack(void *ptr) {
    for (int i = 0; i < NR_OF_STACK_AREAS; i++) {
        if (stack_areas[i].start == ptr) {
            stack_usage -= stack_areas[i].end - stack_areas[i].start;
            stack_areas[i].start = NULL;
            stack_areas[i].end = NULL;
            free(ptr);
            return;
        }
    }
}

static void free_heap(void *ptr) {
    for (int i = 0; i < NR_OF_HEAP_AREAS; i++) {
        if (heap_areas[i].start == ptr) {
            heap_usage -= heap_areas[i].end - heap_areas[i].start;
            heap_areas[i].start = NULL;
            heap_areas[i].end = NULL;
            free(ptr);
            return;
        }
    }
}

static void free_malloc(void *ptr) {
    for (int i = 0; i < NR_OF_MALLOC_AREAS; i++) {
        if (malloc_areas[i].start == ptr) {
            malloc_usage -= malloc_areas[i].end - malloc_areas[i].start;
            malloc_areas[i].start = NULL;
            malloc_areas[i].end = NULL;
            free(ptr);
            return;
        }
    }
}

static void print_ram_usage(void) {
    printf("Stack usage: %" PRIu64 " bytes\n", stack_usage);
    printf("Heap usage: %" PRIu64 " bytes\n", heap_usage);
    printf("Malloc usage: %" PRIu64 " bytes\n", malloc_usage);
}

int main(void) {
    void *ptr;

    ptr = allocate_stack(1024);
    if (!ptr) {
        printf("Failed to allocate stack memory\n");
        return 1;
    }

    ptr = allocate_heap(1024);
    if (!ptr) {
        printf("Failed to allocate heap memory\n");
        return 1;
    }

    ptr = allocate_malloc(1024);
    if (!ptr) {
        printf("Failed to allocate malloc memory\n");
        return 1;
    }

    print_ram_usage();

    free_stack(ptr);
    free_heap(ptr);
    free_malloc(ptr);

    print_ram_usage();

    return 0;
}