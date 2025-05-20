//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096

typedef struct Block {
    size_t size;
    struct Block *next;
    char data[BLOCK_SIZE];
} Block;

Block *heap = NULL;

void *my_malloc(size_t size) {
    Block *current, *prev;

    if (size == 0) {
        return NULL;
    }

    current = (Block *) malloc(sizeof(Block) + size);

    if (!current) {
        return NULL;
    }

    current->size = size;
    current->next = NULL;

    if (!heap) {
        heap = current;
        return (void *) (current + 1);
    }

    prev = heap;

    while (prev->next && prev->next->size < size) {
        prev = prev->next;
    }

    if (prev->next) {
        current->size = size;
        current->next = prev->next;
        prev->next = current;
        return (void *) (current + 1);
    }

    current->size = size;
    current->next = heap;
    heap = current;

    return (void *) (current + 1);
}

void my_free(void *ptr) {
    Block *current, *prev;

    if (!heap || (void *) heap >= ptr) {
        return;
    }

    current = heap;

    while (current && (void *) (current + 1) != ptr) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        return;
    }

    if (prev) {
        prev->next = current->next;
    } else {
        heap = current->next;
    }

    free(current);
}

int main() {
    char *str1 = (char *) my_malloc(5 * sizeof(char));
    char *str2 = (char *) my_malloc(10 * sizeof(char));
    char *str3 = (char *) my_malloc(1 * sizeof(char));

    strcpy(str1, "Hello");
    strcpy(str2, "World");

    if (str1 && str2) {
        printf("%s %s\n", str1, str2);
        my_free(str1);
        my_free(str2);
        my_free(str3);
    }

    char *str4 = (char *) my_malloc(20 * sizeof(char));

    if (str4) {
        strcpy(str4, "Surprise! I allocated a larger block than requested.");
        printf("%s\n", str4);
        my_free(str4);
    }

    return 0;
}