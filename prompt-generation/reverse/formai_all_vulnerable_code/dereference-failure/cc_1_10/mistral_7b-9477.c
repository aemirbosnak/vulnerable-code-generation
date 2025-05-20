//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    size_t size;
    char *data;
    struct Element *next;
} Element;

Element *memory_pool = NULL;
size_t current_size = 0;
size_t initial_size = 16;

void grow_memory_pool() {
    Element *new_pool = (Element *)realloc(memory_pool, (current_size + initial_size) * sizeof(Element));
    if (new_pool == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for the memory pool.\n");
        exit(EXIT_FAILURE);
    }
    memory_pool = new_pool;
}

void *my_malloc(size_t size) {
    if (size == 0) {
        fprintf(stderr, "Error: Size is zero.\n");
        return NULL;
    }

    if (current_size + size > (initial_size * sizeof(Element))) {
        grow_memory_pool();
    }

    Element *new_element = &memory_pool[current_size++];
    new_element->size = size;
    new_element->data = (char *)(&new_element[1]);

    return new_element->data;
}

void my_free(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Error: Pointer is null.\n");
        return;
    }

    Element *current = memory_pool;
    Element *previous = NULL;

    while (current != NULL) {
        if ((char *)current + current->size == ptr) {
            if (previous == NULL) {
                memory_pool = current->next;
            } else {
                previous->next = current->next;
            }
            --current_size;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    char *str1 = my_malloc(10);
    strcpy(str1, "The Elixir of Life");

    char *str2 = my_malloc(20);
    strcpy(str2, "The Philosopher's Stone");

    printf("str1: %s, size: %zu\n", str1, strlen(str1) + 1);
    printf("str2: %s, size: %zu\n", str2, strlen(str2) + 1);

    my_free(str1);
    my_free(str2);

    return EXIT_SUCCESS;
}