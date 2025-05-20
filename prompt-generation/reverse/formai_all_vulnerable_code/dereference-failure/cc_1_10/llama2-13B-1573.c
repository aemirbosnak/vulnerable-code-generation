//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRLEN 1024
#define MAX_OBJS 10

typedef struct obj_t {
    char *name;
    size_t size;
    struct obj_t *next;
} obj_t;

typedef struct heap_t {
    obj_t *root;
    size_t max_size;
} heap_t;

void init_heap(heap_t *h) {
    h->root = NULL;
    h->max_size = 0;
}

void insert_obj(heap_t *h, char *name, size_t size) {
    obj_t *new_obj = (obj_t *)malloc(sizeof(obj_t));
    new_obj->name = name;
    new_obj->size = size;
    new_obj->next = NULL;

    if (h->max_size < size) {
        h->max_size = size;
    }

    if (h->root == NULL) {
        h->root = new_obj;
    } else {
        obj_t *current = h->root;
        while (current->next != NULL) {
            if (current->next->size < size) {
                current = current->next;
            } else {
                break;
            }
        }
        current->next = new_obj;
    }
}

void print_heap(heap_t *h) {
    obj_t *current = h->root;
    printf("Heap: ");
    while (current != NULL) {
        printf("%s (%zu) ", current->name, current->size);
        current = current->next;
    }
    printf("\n");
}

void delete_obj(heap_t *h, char *name) {
    obj_t *current = h->root;
    obj_t *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                h->root = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    heap_t *h = (heap_t *)malloc(sizeof(heap_t));
    init_heap(h);

    char *names[] = {"apple", "banana", "cherry", "date", "elephant"};
    size_t sizes[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
        insert_obj(h, names[i], sizes[i]);
    }

    print_heap(h);

    delete_obj(h, "apple");
    print_heap(h);

    return 0;
}