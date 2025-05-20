//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OBJECTS 100
#define MAX_STRING_LENGTH 1024

typedef struct object {
    int id;
    char name[MAX_STRING_LENGTH];
} object_t;

typedef struct array {
    object_t* objects;
    int capacity;
    int size;
} array_t;

void* alloc_object(object_t* obj) {
    void* mem = malloc(sizeof(object_t));
    obj->id = (int)mem;
    obj->name[0] = '\0';
    return mem;
}

void free_object(void* mem) {
    object_t* obj = (object_t*)mem;
    free(mem);
}

array_t* alloc_array(int capacity) {
    array_t* arr = (array_t*)malloc(sizeof(array_t));
    arr->capacity = capacity;
    arr->objects = (object_t*)malloc(capacity * sizeof(object_t));
    return arr;
}

void free_array(array_t* arr) {
    free(arr->objects);
    free(arr);
}

int main() {
    array_t* arr1 = alloc_array(10);
    array_t* arr2 = alloc_array(20);

    object_t obj1 = {1, "John"};
    object_t obj2 = {2, "Jane"};

    // Add objects to arrays
    arr1->objects[0] = obj1;
    arr1->objects[1] = obj2;
    arr2->objects[0] = obj1;
    arr2->objects[1] = obj2;

    // Free objects and arrays
    free_object(obj1.id);
    free_object(obj2.id);
    free_array(arr1);
    free_array(arr2);

    return 0;
}