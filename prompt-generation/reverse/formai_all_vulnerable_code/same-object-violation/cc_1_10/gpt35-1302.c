//FormAI DATASET v1.0 Category: Memory management ; Style: invasive
/* Invasive Memory Management Example Program */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VARIABLES 1000
#define BLOCK_SIZE 4096

/* Define a structure for a memory block */
typedef struct memory_block_ {
    int size;
    struct memory_block_ *next;
    char data[1];
} memory_block;

/* Define a structure for a variable node in the linked list */
typedef struct variable_node_ {
    char *name;
    void *value;
    struct variable_node_ *next;
} variable_node;

/* Define global variables for the memory allocator */
char *start = NULL;
char *end = NULL;
memory_block *free_blocks = NULL;
int num_allocations = 0;
int num_frees = 0;

/* Define function prototypes */
void *allocate_memory(int size);
void free_memory(void *ptr);
void initialize_memory_allocator(int num_blocks);
void *get_block(int size);
void release_block(memory_block *block);
void print_statistics();
void print_variables(variable_node *head);
void add_variable(variable_node **head, char *name, void *value);
void *get_variable(variable_node *head, char *name);

int main() {
    /* Initialize the memory allocator with 100 blocks */
    initialize_memory_allocator(100);

    /* Create a linked list of variables */
    variable_node *head = NULL;
    add_variable(&head, "x", allocate_memory(sizeof(int)));
    add_variable(&head, "y", allocate_memory(sizeof(int)));
    add_variable(&head, "z", allocate_memory(sizeof(double)));

    /* Set the values of the variables */
    *(int*)get_variable(head, "x") = 123;
    *(int*)get_variable(head, "y") = 456;
    *(double*)get_variable(head, "z") = 3.14159;

    /* Print the values of the variables */
    printf("x = %d\n", *(int*)get_variable(head, "x"));
    printf("y = %d\n", *(int*)get_variable(head, "y"));
    printf("z = %f\n", *(double*)get_variable(head, "z"));

    /* Print memory statistics */
    print_statistics();

    /* Free the variables */
    free_memory(get_variable(head, "x"));
    free_memory(get_variable(head, "y"));
    free_memory(get_variable(head, "z"));

    /* Print memory statistics */
    print_statistics();

    /* Free all blocks */
    while (free_blocks != NULL) {
        memory_block *next = free_blocks->next;
        free(free_blocks);
        free_blocks = next;
    }

    return 0;
}

/* Allocate memory using the memory allocator */
void *allocate_memory(int size) {
    /* Get a block of memory */
    memory_block *block = get_block(size);

    /* Return a pointer to the data section of the block */
    return block->data;
}

/* Free memory using the memory allocator */
void free_memory(void *ptr) {
    /* Release the block corresponding to the given pointer */
    release_block((memory_block*)((char*)ptr - sizeof(memory_block)));

    /* Increment the number of frees */
    num_frees++;
}

/* Initialize the memory allocator with a specified number of blocks */
void initialize_memory_allocator(int num_blocks) {
    /* Calculate the size of the memory pool */
    int size = num_blocks * BLOCK_SIZE;

    /* Allocate the memory pool */
    start = (char*)malloc(size);
    end = start + size;

    /* Initialize the free block list with a single block */
    free_blocks = (memory_block*)start;
    free_blocks->size = size - sizeof(memory_block);
    free_blocks->next = NULL;

    /* Increment the number of allocations */
    num_allocations++;
}

/* Get a memory block of the specified size */
void *get_block(int size) {
    /* Find a block in the free block list */
    memory_block *block = free_blocks;
    memory_block *prev = NULL;
    while (block != NULL) {
        /* If the block is large enough, use it */
        if (block->size >= size) {
            /* Remove the block from the free block list */
            if (prev == NULL) {
                free_blocks = block->next;
            } else {
                prev->next = block->next;
            }

            /* Split the block if necessary */
            if (block->size > size + sizeof(memory_block)) {
                /* Create a new block and update the next pointer */
                memory_block *new_block = (memory_block*)(block->data + size);
                new_block->size = block->size - size - sizeof(memory_block);
                new_block->next = block->next;

                /* Update the size of the original block */
                block->size = size;

                /* Insert the new block into the free block list */
                if (prev == NULL) {
                    free_blocks = new_block;
                } else {
                    prev->next = new_block;
                }
            }

            /* Increment the number of allocations */
            num_allocations++;

            /* Return a pointer to the data section of the block */
            return block->data;
        }

        /* Move to the next block */
        prev = block;
        block = block->next;
    }

    /* If no block was found, return NULL */
    return NULL;
}

/* Release a memory block */
void release_block(memory_block *block) {
    /* Insert the block into the free block list */
    memory_block *curr = free_blocks;
    memory_block *prev = NULL;
    while (curr != NULL && curr < block) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) {
        free_blocks = block;
    } else {
        prev->next = block;
    }
    block->next = curr;

    /* Increment the number of frees */
    num_frees++;
}

/* Print memory allocation statistics */
void print_statistics() {
    printf("Total memory allocated: %d bytes\n", num_allocations * BLOCK_SIZE);
    printf("Total memory freed: %d bytes\n", num_frees * BLOCK_SIZE);
    printf("Memory utilization: %.2f%%\n", (1.0 - num_frees / (double)num_allocations) * 100);
}

/* Print the variables in the linked list */
void print_variables(variable_node *head) {
    variable_node *current = head;
    while (current != NULL) {
        printf("%s = %p\n", current->name, current->value);
        current = current->next;
    }
}

/* Add a variable to the linked list */
void add_variable(variable_node **head, char *name, void *value) {
    variable_node *new_node = (variable_node*)malloc(sizeof(variable_node));
    new_node->name = name;
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

/* Get a variable from the linked list */
void *get_variable(variable_node *head, char *name) {
    variable_node *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}