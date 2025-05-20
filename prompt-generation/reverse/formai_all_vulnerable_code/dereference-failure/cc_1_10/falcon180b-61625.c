//Falcon-180B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCK_SIZE 1024
#define MAX_NUM_BLOCKS 100

typedef struct block_t {
    int size;
    char *data;
    struct block_t *next;
} Block;

Block *free_blocks = NULL;
int num_free_blocks = 0;
int num_total_blocks = 0;

void init() {
    num_free_blocks = 0;
    num_total_blocks = 0;
    free_blocks = NULL;
}

void *my_malloc(int size) {
    Block *new_block = (Block *) malloc(sizeof(Block));
    if (new_block == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    new_block->size = size;
    new_block->data = (char *) malloc(size);
    if (new_block->data == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    new_block->next = free_blocks;
    free_blocks = new_block;
    num_free_blocks++;
    num_total_blocks++;
    return new_block->data;
}

void my_free(void *ptr) {
    Block *current_block = free_blocks;
    while (current_block!= NULL && current_block->data!= ptr) {
        current_block = current_block->next;
    }
    if (current_block == NULL) {
        printf("Error: Invalid pointer!\n");
        exit(1);
    }
    free(current_block->data);
    free(current_block);
    num_free_blocks--;
    num_total_blocks--;
}

void *my_realloc(void *ptr, int size) {
    Block *current_block = free_blocks;
    while (current_block!= NULL && current_block->data!= ptr) {
        current_block = current_block->next;
    }
    if (current_block == NULL) {
        printf("Error: Invalid pointer!\n");
        exit(1);
    }
    if (size <= current_block->size) {
        return ptr;
    }
    void *new_data = (char *) malloc(size);
    if (new_data == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    memcpy(new_data, ptr, current_block->size);
    my_free(ptr);
    return new_data;
}

int main() {
    init();
    char *str1 = my_malloc(20);
    strcpy(str1, "Hello, world!");
    printf("str1 = %s\n", str1);
    char *str2 = my_malloc(30);
    strcpy(str2, "This is a longer string.");
    printf("str2 = %s\n", str2);
    char *str3 = my_realloc(str1, 30);
    strcpy(str3, "Hello again, world!");
    printf("str3 = %s\n", str3);
    my_free(str2);
    my_free(str3);
    return 0;
}