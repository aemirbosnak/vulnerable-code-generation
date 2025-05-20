//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MEMORY_SIZE 10
#define MEMORY_SPACE 100

typedef struct memory_space {
    char **mem;
    int size;
    int space;
} memory_space;

void init_memory(memory_space *ms) {
    ms->mem = (char **) malloc(MEMORY_SIZE * sizeof(char *));
    ms->size = MEMORY_SIZE;
    ms->space = MEMORY_SPACE;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        ms->mem[i] = (char *) malloc(MEMORY_SPACE * sizeof(char));
    }
}

void print_memory(memory_space *ms) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        printf("[%d] %s\n", i, ms->mem[i]);
    }
}

void add_element(memory_space *ms, char *element) {
    if (ms->space > 0) {
        ms->mem[ms->size] = element;
        ms->size++;
        ms->space--;
    } else {
        printf("Memory is full, cannot add %s\n", element);
    }
}

void remove_element(memory_space *ms, int index) {
    if (index < ms->size) {
        free(ms->mem[index]);
        ms->mem[index] = NULL;
        ms->space++;
    } else {
        printf("Element not found\n");
    }
}

int is_empty(memory_space *ms) {
    for (int i = 0; i < ms->size; i++) {
        if (ms->mem[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

int main() {
    memory_space ms;
    init_memory(&ms);

    char *elements[] = {"apple", "banana", "cherry", "date", "elephant"};
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {
        add_element(&ms, elements[i]);
    }

    print_memory(&ms);

    // Remove some elements
    remove_element(&ms, 2);
    remove_element(&ms, 4);

    print_memory(&ms);

    // Check if memory is empty
    if (is_empty(&ms)) {
        printf("Memory is empty\n");
    }

    return 0;
}