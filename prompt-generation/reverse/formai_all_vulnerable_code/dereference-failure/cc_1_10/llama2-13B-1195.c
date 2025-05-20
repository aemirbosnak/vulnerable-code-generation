//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 100
#define MAX_MEM 1000

typedef struct mem_block {
    char *data;
    size_t size;
    struct mem_block *next;
} mem_block_t;

mem_block_t *mem_pool = NULL;

void init_mem_pool(void) {
    mem_pool = calloc(1, sizeof(mem_block_t));
    mem_pool->data = calloc(1, MAX_MEM);
    mem_pool->size = MAX_MEM;
}

void *malloc(size_t size) {
    if (size > MAX_MEM) {
        printf("Memory allocation failed: request size exceeds maximum available memory\n");
        exit(1);
    }

    if (mem_pool->size < size) {
        printf("Memory allocation failed: not enough memory available\n");
        exit(1);
    }

    void *ptr = mem_pool->data;
    mem_pool->data += size;
    mem_pool->size -= size;
    return ptr;
}

void free(void *ptr) {
    if (ptr == NULL) {
        printf("Invalid memory pointer passed to free()\n");
        exit(1);
    }

    char *data = (char *)ptr;
    size_t size = strlen(data) + 1;

    if (mem_pool->size < size) {
        printf("Memory free failed: not enough memory available\n");
        exit(1);
    }

    mem_pool->data = data;
    mem_pool->size += size;
}

int main(void) {
    init_mem_pool();

    char *str1 = malloc(10);
    char *str2 = malloc(20);
    char *str3 = malloc(30);

    strcpy(str1, "Hello, world!");
    strcpy(str2, "This is a test string!");
    strcpy(str3, "This is another test string!");

    free(str1);
    free(str2);
    free(str3);

    return 0;
}