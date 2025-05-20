//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJECTS 100
#define MAX_OBJECT_SIZE 1024

typedef struct {
    char *name;
    int size;
} Object;

Object *objects[MAX_OBJECTS];
int num_objects = 0;

void init_memory() {
    printf("Initializing memory...\n");
    for (int i = 0; i < MAX_OBJECTS; i++) {
        objects[i] = NULL;
    }
}

void *allocate_memory(int size) {
    printf("Allocating %d bytes of memory...\n", size);
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    return ptr;
}

void deallocate_memory(void *ptr) {
    printf("Deallocating memory at %p...\n", ptr);
    free(ptr);
}

void add_object(char *name, int size) {
    printf("Adding object '%s' (%d bytes)...\n", name, size);
    if (num_objects >= MAX_OBJECTS) {
        printf("Error: Too many objects!\n");
        exit(1);
    }
    Object *obj = allocate_memory(sizeof(Object));
    obj->name = strdup(name);
    obj->size = size;
    objects[num_objects++] = obj;
}

void remove_object(int index) {
    printf("Removing object at index %d...\n", index);
    if (index < 0 || index >= num_objects) {
        printf("Error: Invalid index!\n");
        exit(1);
    }
    deallocate_memory(objects[index]);
    num_objects--;
    for (int i = index; i < num_objects; i++) {
        objects[i] = objects[i+1];
    }
}

void list_objects() {
    printf("Listing objects:\n");
    for (int i = 0; i < num_objects; i++) {
        printf("%s (%d bytes)\n", objects[i]->name, objects[i]->size);
    }
}

int main() {
    init_memory();
    add_object("Cyberdeck", 1024);
    add_object("Neural Interface", 2048);
    list_objects();
    remove_object(0);
    list_objects();
    return 0;
}