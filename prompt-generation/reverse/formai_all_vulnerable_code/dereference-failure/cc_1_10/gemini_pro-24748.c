//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>

// Custom memory manager to demonstrate memory allocation and deallocation in a single-threaded program.

typedef struct _mem_block {
    size_t size;
    void *data;
    struct _mem_block *next;
} mem_block;

typedef struct _mem_manager {
    mem_block *head;
    mem_block *tail;
} mem_manager;

mem_manager *mem_mgr;

void mem_init() {
    mem_mgr = malloc(sizeof(mem_manager));
    mem_mgr->head = NULL;
    mem_mgr->tail = NULL;
}

void mem_destroy() {
    mem_block *block = mem_mgr->head;
    while (block != NULL) {
        mem_block *next = block->next;
        free(block->data);
        free(block);
        block = next;
    }
    free(mem_mgr);
}

void *mem_alloc(size_t size) {
    mem_block *new_block = malloc(sizeof(mem_block));
    new_block->size = size;
    new_block->data = malloc(size);
    new_block->next = NULL;

    if (mem_mgr->head == NULL) {
        mem_mgr->head = new_block;
        mem_mgr->tail = new_block;
    } else {
        mem_mgr->tail->next = new_block;
        mem_mgr->tail = new_block;
    }

    return new_block->data;
}

void mem_free(void *ptr) {
    mem_block *block = mem_mgr->head;
    mem_block *prev = NULL;

    while (block != NULL) {
        if (block->data == ptr) {
            if (prev == NULL) {
                mem_mgr->head = block->next;
            } else {
                prev->next = block->next;
            }
            if (block == mem_mgr->tail) {
                mem_mgr->tail = prev;
            }
            free(block->data);
            free(block);
            return;
        }
        prev = block;
        block = block->next;
    }
}

int main() {
    mem_init();

    int *array = mem_alloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++) {
        array[i] = i;
    }

    for (int i = 0; i < 100; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    mem_free(array);

    mem_destroy();

    return 0;
}