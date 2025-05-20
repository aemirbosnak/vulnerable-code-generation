//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HEAP_SIZE 1024
#define MAX_STR_LEN 100

typedef struct {
    char *name;
    size_t size;
    struct node *next;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
} heap_t;

void init_heap(heap_t *h) {
    h->head = NULL;
    h->tail = NULL;
}

void insert_node(heap_t *h, char *name, size_t size) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->name = name;
    new_node->size = size;
    new_node->next = NULL;

    if (h->head == NULL) {
        h->head = new_node;
        h->tail = new_node;
    } else {
        h->tail->next = new_node;
        h->tail = new_node;
    }
}

void delete_node(heap_t *h, char *name) {
    node_t *current = h->head;
    node_t *prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            h->head = current->next;
        } else {
            prev->next = current->next;
        }

        free(current);
    }
}

void print_heap(heap_t *h) {
    node_t *current = h->head;

    while (current != NULL) {
        printf("%s (%zu bytes)\n", current->name, current->size);
        current = current->next;
    }
}

int main() {
    heap_t *h = (heap_t *)malloc(sizeof(heap_t));
    init_heap(h);

    char *names[] = {"Hello", "World", "C", "Memory", "Management", NULL};
    size_t sizes[] = {10, 10, 5, 20, 10};

    for (int i = 0; i < sizeof(names) / sizeof(char *); i++) {
        insert_node(h, names[i], sizes[i]);
    }

    print_heap(h);

    // Test delete_node() function
    delete_node(h, "C");
    print_heap(h);

    // Test again to ensure no leaks
    print_heap(h);

    return 0;
}