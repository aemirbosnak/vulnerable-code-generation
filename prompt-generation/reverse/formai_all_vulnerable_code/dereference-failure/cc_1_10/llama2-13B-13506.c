//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OBJS 10
#define MAX_NAME_LEN 20

typedef struct obj_t {
    char name[MAX_NAME_LEN];
    void* data;
    struct obj_t* next;
} obj_t;

void* malloc_fn(size_t size) {
    void* p = malloc(size);
    if (p == NULL) {
        printf("Memory allocation failed: %zu bytes\n", size);
        return NULL;
    }
    return p;
}

void free_fn(void* p) {
    free(p);
}

void* alloc_obj(char* name, void* data) {
    obj_t* obj = (obj_t*)malloc_fn(sizeof(obj_t));
    if (obj == NULL) {
        return NULL;
    }
    strcpy(obj->name, name);
    obj->data = data;
    obj->next = NULL;
    return obj;
}

void free_obj(void* obj) {
    obj_t* curr = (obj_t*)obj;
    while (curr != NULL) {
        obj_t* next = curr->next;
        free_fn(curr);
        curr = next;
    }
}

int main() {
    obj_t* objects[MAX_OBJS];
    for (int i = 0; i < MAX_OBJS; i++) {
        char name[MAX_NAME_LEN];
        printf("Enter object name: ");
        fgets(name, MAX_NAME_LEN, stdin);
        void* data = malloc_fn(100);
        objects[i] = alloc_obj(name, data);
        if (objects[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    for (int i = 0; i < MAX_OBJS; i++) {
        printf("%d: %s\n", i, objects[i]->name);
    }

    for (int i = 0; i < MAX_OBJS; i++) {
        free_obj(objects[i]);
    }

    return 0;
}