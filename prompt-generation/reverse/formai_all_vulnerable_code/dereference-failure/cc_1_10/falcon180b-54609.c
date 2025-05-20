//Falcon-180B DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    char *data;
} block_t;

void *my_malloc(size_t size) {
    block_t *block = (block_t *)malloc(sizeof(block_t));
    if (block == NULL) {
        return NULL;
    }
    block->size = size;
    block->data = (char *)malloc(size);
    if (block->data == NULL) {
        free(block);
        return NULL;
    }
    return block->data;
}

void my_free(void *ptr) {
    block_t *block = (block_t *)ptr;
    if (ptr == NULL) {
        return;
    }
    free(block->data);
    free(block);
}


int main() {
    char *str1 = (char *)my_malloc(50);
    char *str2 = (char *)my_malloc(100);
    char *str3 = (char *)my_malloc(25);

    strcpy(str1, "Hello World!");
    strcpy(str2, "This is a test of my memory management system.");
    strcpy(str3, "I hope it works!");

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

    my_free(str1);
    my_free(str2);
    my_free(str3);

    return 0;
}