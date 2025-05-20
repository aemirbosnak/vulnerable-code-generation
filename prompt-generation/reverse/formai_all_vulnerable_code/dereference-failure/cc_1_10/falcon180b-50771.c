//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// surrealist struct
typedef struct {
    int *dream;
    int size;
    int capacity;
} surreal_memory;

// surrealist function for memory allocation
void surreal_malloc(surreal_memory *mem) {
    mem->dream = malloc(mem->capacity * sizeof(int));
    if (mem->dream == NULL) {
        printf("Surrealist nightmare: Memory allocation failed!\n");
        exit(1);
    }
}

// surrealist function for memory reallocation
void surreal_realloc(surreal_memory *mem, int new_size) {
    mem->size = new_size;
    mem->capacity = mem->size + 10; // add 10 for surreal effect
    mem->dream = realloc(mem->dream, mem->capacity * sizeof(int));
    if (mem->dream == NULL) {
        printf("Surrealist nightmare: Memory reallocation failed!\n");
        exit(1);
    }
}

// surrealist function for memory deallocation
void surreal_free(surreal_memory *mem) {
    free(mem->dream);
    mem->dream = NULL;
    mem->size = 0;
    mem->capacity = 0;
}

// surrealist main function
int main() {
    surreal_memory mem;
    mem.dream = NULL;
    mem.size = 0;
    mem.capacity = 0;

    surreal_malloc(&mem);

    int i;
    for (i = 0; i < 10; i++) {
        surreal_realloc(&mem, i);
        memset(mem.dream, i, mem.size * sizeof(int));
        printf("Surrealist dream %d:\n", i);
        for (int j = 0; j < mem.size; j++) {
            printf("%d ", *(mem.dream + j));
        }
        printf("\n");
    }

    surreal_free(&mem);

    return 0;
}