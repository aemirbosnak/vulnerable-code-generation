//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY_BLOCKS 1000

typedef struct {
    void *ptr;
    size_t size;
    char *file;
    int line;
} MemoryBlock;

static MemoryBlock memoryBlocks[MAX_MEMORY_BLOCKS];
static int numMemoryBlocks = 0;

static void printMemoryBlocks() {
    printf("Memory blocks:\n");
    for (int i = 0; i < numMemoryBlocks; i++) {
        printf("- %p (%zu bytes) allocated in %s:%d\n", memoryBlocks[i].ptr, memoryBlocks[i].size, memoryBlocks[i].file, memoryBlocks[i].line);
    }
}

void *myMalloc(size_t size, const char *file, int line) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Out of memory in %s:%d\n", file, line);
        exit(1);
    }
    memoryBlocks[numMemoryBlocks].ptr = ptr;
    memoryBlocks[numMemoryBlocks].size = size;
    memoryBlocks[numMemoryBlocks].file = strdup(file);
    memoryBlocks[numMemoryBlocks].line = line;
    numMemoryBlocks++;
    return ptr;
}

void myFree(void *ptr) {
    for (int i = 0; i < numMemoryBlocks; i++) {
        if (memoryBlocks[i].ptr == ptr) {
            free(ptr);
            numMemoryBlocks--;
            return;
        }
    }
    fprintf(stderr, "Invalid pointer in myFree()\n");
    exit(1);
}

int main() {
    char *str = myMalloc(10, __FILE__, __LINE__);
    strcpy(str, "Hello, world!");
    printf("Allocated string: %s\n", str);

    int *arr = myMalloc(100 * sizeof(int), __FILE__, __LINE__);
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }
    printf("Allocated array:");
    for (int i = 0; i < 100; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    myFree(str);
    myFree(arr);

    printMemoryBlocks();

    return 0;
}