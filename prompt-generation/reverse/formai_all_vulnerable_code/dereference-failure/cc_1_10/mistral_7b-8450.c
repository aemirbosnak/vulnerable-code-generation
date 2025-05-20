//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRYSTAL_SIZE 1024

typedef struct Crystal {
    void* data;
    size_t size;
    struct Crystal* next;
} Crystal;

Crystal* crystals = NULL;

void print_memory() {
    printf("========== MEMORY INVENTORY ==========\n");
    Crystal* current = crystals;
    while (current != NULL) {
        printf("Crystal ID: %ld, Size: %ld bytes, Data: %p\n", current - crystals, current->size, current->data);
        current = current->next;
    }
    printf("=====================================\n");
}

void* allocate_memory(size_t size) {
    if (size == 0) {
        printf("Error: Invalid size\n");
        return NULL;
    }

    Crystal* new_crystal = (Crystal*) malloc(sizeof(Crystal) + size);
    if (new_crystal == NULL) {
        printf("Error: Out of magical crystals\n");
        return NULL;
    }

    new_crystal->size = size;
    new_crystal->data = (void*) ((char*) new_crystal + sizeof(Crystal));
    new_crystal->next = crystals;
    crystals = new_crystal;

    print_memory();
    return new_crystal->data;
}

void deallocate_memory(void* ptr, size_t size) {
    if (ptr == NULL) {
        printf("Error: Invalid pointer\n");
        return;
    }

    Crystal* current = crystals;
    Crystal* previous = NULL;

    while (current != NULL) {
        if (current->data == ptr && current->size == size) {
            if (previous == NULL) {
                crystals = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            print_memory();
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Error: Unknown pointer or size\n");
}

int main() {
    char* magical_scroll = (char*) allocate_memory(512);
    strcpy(magical_scroll, "I conjure forth a fireball of destruction and mayhem!");

    int* enchanted_numbers = (int*) allocate_memory(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        enchanted_numbers[i] = i * 13;
    }

    print_memory();

    free(enchanted_numbers);
    free(magical_scroll);

    return 0;
}