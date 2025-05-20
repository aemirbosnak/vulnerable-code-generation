//FormAI DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 1024

char *memory_start;
char *memory_end;

/* Function to initialize the memory */
void init_memory() {
    memory_start = (char *) malloc(MEMORY_SIZE);
    memory_end = memory_start + MEMORY_SIZE;
    memset(memory_start, '\0', MEMORY_SIZE);
}

/* Function to allocate memory */
void *alloc_memory(size_t size) {
    if (memory_start == NULL) {
        /* Initialize memory if not already initialized */
        init_memory();
    }
    char *memory_pointer = memory_start;
    while (memory_pointer < memory_end) {
        /* If there is enough space between current memory pointer
           and end of memory for the requested size */
        if (memory_end - memory_pointer >= size) {
            /* Set a paranoid value at the end of the allocated memory */
            memset(memory_pointer + size, 0xff, 4);
            return memory_pointer;
        }
        memory_pointer++;
    }
    /* Return NULL if memory could not be allocated */
    return NULL;
}

/* Function to free memory */
void free_memory(void *memory_pointer) {
    if (memory_pointer != NULL) {
        /* Check if the paranoid value at the end of the memory block is still intact */
        if (memcmp(memory_pointer + strlen(memory_pointer), "\xff\xff\xff\xff", 4) != 0) {
            /* If not, display an error message and terminate */
            printf("Error: memory corrupted!\n");
            exit(1);
        }
        /* Overwrite all the memory with 0 before freeing */
        memset(memory_pointer, 0, strlen(memory_pointer));
        free(memory_pointer);
    }
}

/* Main function */
int main() {
    char *str1 = (char *) alloc_memory(10);
    strcpy(str1, "hello");
    printf("%s\n", str1);

    char *str2 = (char *) alloc_memory(20);
    strcpy(str2, "world");
    printf("%s\n", str2);

    free_memory(str1);
    free_memory(str2);

    /* Try to free an already freed memory block */
    free_memory(str1);

    /* Check if memory blocks can still be allocated */
    char *str3 = (char *) alloc_memory(5);
    strcpy(str3, "test");
    printf("%s\n", str3);

    return 0;
}