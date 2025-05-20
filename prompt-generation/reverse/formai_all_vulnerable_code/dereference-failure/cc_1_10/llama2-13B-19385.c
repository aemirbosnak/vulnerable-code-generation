//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OBJS 10
#define OBJ_SIZE 40

typedef struct obj {
    int data[5];
    struct obj *next;
} obj;

void* malloc_func(size_t size) {
    void* mem = malloc(size);
    if (!mem) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return mem;
}

void free_func(void* mem) {
    free(mem);
}

int main() {
    obj* obj_head = NULL;
    obj* obj_tail = NULL;

    // Create 5 objects
    for (int i = 0; i < 5; i++) {
        obj* new_obj = (obj*)malloc_func(OBJ_SIZE);
        new_obj->data[0] = i * 2;
        new_obj->data[1] = i * 3;
        new_obj->data[2] = i * 4;
        new_obj->data[3] = i * 5;
        new_obj->data[4] = i * 6;
        new_obj->next = NULL;

        if (i == 0) {
            obj_head = new_obj;
        } else {
            obj_tail->next = new_obj;
        }
        obj_tail = new_obj;
    }

    // Remove an object
    obj_tail = obj_tail->next;
    free_func(obj_tail);

    // Add a new object after the removed one
    obj* new_obj = (obj*)malloc_func(OBJ_SIZE);
    new_obj->data[0] = 10;
    new_obj->data[1] = 20;
    new_obj->data[2] = 30;
    new_obj->data[3] = 40;
    new_obj->data[4] = 50;
    new_obj->next = obj_tail;
    obj_tail = new_obj;

    // Remove all objects
    while (obj_head != NULL) {
        obj_tail = obj_head->next;
        free_func(obj_head);
        obj_head = obj_tail;
    }

    return 0;
}