//FormAI DATASET v1.0 Category: Memory management ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ALLOCS 100     /* Maximum number of allocations */
#define MAX_ALLOC_SIZE 100 /* Maximum allocation size */

static int total_allocs;   /* Total number of allocations */
static int total_frees;    /* Total number of frees */
static int current_allocs; /* Current number of allocations */

/* Structure of allocated blocks */
typedef struct _alloc_info_t {
    void *ptr;              /* Pointer to the allocated block */
    size_t size;            /* Size of the allocated block */
    char file[256];         /* Filename of the allocation */
    int line;               /* Line number of the allocation */
} alloc_info_t;

static alloc_info_t allocs[MAX_ALLOCS]; /* Array of allocated blocks */

#define PARANOID_MALLOC(size) paranoid_malloc(size, __FILE__, __LINE__)
#define PARANOID_FREE(ptr) paranoid_free(ptr, __FILE__, __LINE__)

/* Function to allocate memory */
void *paranoid_malloc(size_t size, char *file, int line)
{
    void *ptr = malloc(size);
    if (ptr != NULL) {
        /* Add the allocation information to the list */
        alloc_info_t info;
        info.ptr = ptr;
        info.size = size;
        strncpy(info.file, file, sizeof(info.file) - 1);
        info.line = line;

        /* Check if maximum number of allocations reached */
        if (total_allocs >= MAX_ALLOCS) {
            fprintf(stderr, "Maximum number of allocations reached\n");
            free(ptr);
            ptr = NULL;
        } else {
            allocs[total_allocs++] = info;
            current_allocs++;
        }
    }
    return ptr;
}

/* Function to free memory */
void paranoid_free(void *ptr, char *file, int line)
{
    int i;
    for (i = 0; i < total_allocs; i++) {
        if (allocs[i].ptr == ptr) {
            /* Delete the allocation information from the list */
            alloc_info_t info = allocs[i];
            memmove(&allocs[i], &allocs[i + 1], (total_allocs - i - 1) * sizeof(alloc_info_t));
            total_allocs--;
            total_frees++;
            current_allocs--;

            /* Check if the file and line numbers match */
            if (strcmp(info.file, file) != 0 || info.line != line) {
                fprintf(stderr, "Freeing memory at wrong location: %s:%d\n", file, line);
                /* Simulate a crash to prevent further execution */
                *((volatile int *)0) = 0;
            }
            /* Free the memory block */
            free(ptr);
            return;
        }
    }
    /* Memory block not found */
    fprintf(stderr, "Freeing invalid memory: %s:%d\n", file, line);
    /* Simulate a crash to prevent further execution */
    *((volatile int *)0) = 0;
}

/* Function to print allocation information */
void print_allocs()
{
    int i;
    printf("Total allocations: %d\n", total_allocs);
    printf("Total frees: %d\n", total_frees);
    printf("Current allocations: %d\n", current_allocs);
    printf("Allocations:\n");
    for (i = 0; i < total_allocs; i++) {
        printf("%p %ld %s:%d\n", allocs[i].ptr, allocs[i].size, allocs[i].file, allocs[i].line);
    }
}

int main()
{
    int *p1, *p2, *p3;
    p1 = PARANOID_MALLOC(sizeof(int));
    p2 = PARANOID_MALLOC(sizeof(int));
    p3 = PARANOID_MALLOC(sizeof(int));

    print_allocs();

    PARANOID_FREE(p1);
    PARANOID_FREE(p2);

    print_allocs();

    return 0;
}