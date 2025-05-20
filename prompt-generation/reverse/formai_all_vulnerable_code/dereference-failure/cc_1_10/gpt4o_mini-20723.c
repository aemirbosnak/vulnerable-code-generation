//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 100

typedef struct {
    char *data;
    size_t length;
} DataBlock;

DataBlock *create_data_block(const char *initial_data) {
    DataBlock *block = (DataBlock *)malloc(sizeof(DataBlock));
    if (!block) {
        perror("Failed to allocate memory for DataBlock");
        exit(EXIT_FAILURE);
    }

    block->length = strlen(initial_data);
    block->data = (char *)malloc(block->length + 1);
    if (!block->data) {
        perror("Failed to allocate memory for data");
        free(block);
        exit(EXIT_FAILURE);
    }

    strcpy(block->data, initial_data);
    return block;
}

void display_data_block(const DataBlock *block) {
    printf("DataBlock length: %zu\n", block->length);
    printf("DataBlock content: %s\n", block->data);
}

void append_to_data_block(DataBlock *block, const char *data_to_append) {
    size_t new_length = block->length + strlen(data_to_append);
    if (new_length > MAX_DATA_SIZE) {
        fprintf(stderr, "Maximum data size exceeded; cannot append data.\n");
        return;
    }

    // Reallocate memory to accommodate new data
    char *new_data = (char *)realloc(block->data, new_length + 1);
    if (!new_data) {
        perror("Failed to expand memory for data");
        free(block->data);
        free(block);
        exit(EXIT_FAILURE);
    }

    block->data = new_data;
    strcat(block->data, data_to_append);
    block->length = new_length;
}

void free_data_block(DataBlock *block) {
    if (block) {
        free(block->data);
        free(block);
    }
}

void manipulate_data_blocks() {
    DataBlock *block1 = create_data_block("Hello, ");
    
    display_data_block(block1);
    
    append_to_data_block(block1, "World!");
    display_data_block(block1);
    
    DataBlock *block2 = create_data_block("Memory management in C. ");
    append_to_data_block(block2, "It's quite interesting!");
    display_data_block(block2);
    
    // Free allocated memory
    free_data_block(block1);
    free_data_block(block2);
}

int main() {
    printf("Starting Memory Management Example Program\n");

    manipulate_data_blocks();

    printf("Completed Memory Management Example Program\n");
    return 0;
}