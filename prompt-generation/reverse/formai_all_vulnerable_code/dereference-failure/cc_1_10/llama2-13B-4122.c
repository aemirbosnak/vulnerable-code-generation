//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 1024
#define MAX_OBJECT_SIZE 128

typedef struct obj {
    char *name;
    void *data;
    struct obj *next;
} obj;

typedef struct heap {
    obj *root;
    int heap_size;
} heap;

void init_heap(heap *h) {
    h->root = NULL;
    h->heap_size = 0;
}

void insert_obj(heap *h, char *name, void *data) {
    obj *new_obj = malloc(sizeof(obj));
    new_obj->name = name;
    new_obj->data = data;
    new_obj->next = NULL;
    if (h->heap_size == 0) {
        h->root = new_obj;
    } else {
        obj *last = h->root;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_obj;
    }
    h->heap_size++;
}

void *get_obj(heap *h, char *name) {
    obj *cur = h->root;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            return cur->data;
        }
        cur = cur->next;
    }
    return NULL;
}

void delete_obj(heap *h, char *name) {
    obj *cur = h->root;
    obj *prev = NULL;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                h->root = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            h->heap_size--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

int main() {
    heap h;
    init_heap(&h);

    insert_obj(&h, "obj1", (void *)"data1");
    insert_obj(&h, "obj2", (void *)"data2");
    insert_obj(&h, "obj3", (void *)"data3");

    void *data = get_obj(&h, "obj2");
    printf("%p\n", data);

    delete_obj(&h, "obj2");

    data = get_obj(&h, "obj2");
    printf("%p\n", data);

    return 0;
}