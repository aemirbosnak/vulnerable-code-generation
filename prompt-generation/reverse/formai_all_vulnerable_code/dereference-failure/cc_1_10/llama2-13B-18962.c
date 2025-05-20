//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_HEAP_SIZE 1024
#define MAX_OBJECT_SIZE 64

typedef struct object {
    int value;
    struct object *next;
} object;

typedef struct heap {
    object *head;
    object *tail;
    int size;
} heap;

void init_heap(heap *h) {
    h->head = NULL;
    h->tail = NULL;
    h->size = 0;
}

void insert_object(heap *h, int value) {
    object *obj = malloc(sizeof(object));
    obj->value = value;
    obj->next = NULL;

    if (h->size == 0) {
        h->head = obj;
        h->tail = obj;
    } else {
        h->tail->next = obj;
        h->tail = obj;
    }

    h->size++;
}

void delete_object(heap *h, int value) {
    object *cur = h->head;
    object *prev = NULL;

    while (cur != NULL) {
        if (cur->value == value) {
            if (prev == NULL) {
                h->head = cur->next;
            } else {
                prev->next = cur->next;
            }

            free(cur);
            h->size--;
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

void print_heap(heap *h) {
    object *cur = h->head;

    while (cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }

    printf("\n");
}

int main() {
    heap *h = malloc(sizeof(heap));
    init_heap(h);

    for (int i = 0; i < 10; i++) {
        insert_object(h, i * 2);
    }

    for (int i = 0; i < 10; i++) {
        delete_object(h, i * 2);
    }

    print_heap(h);

    return 0;
}