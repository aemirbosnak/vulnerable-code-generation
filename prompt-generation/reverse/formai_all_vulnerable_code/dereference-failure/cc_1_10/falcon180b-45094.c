//Falcon-180B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJECTS 100
#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
    int size;
} Object;

int objectCount = 0;
Object *objects[MAX_OBJECTS];

void *myMalloc(int size) {
    void *ptr = malloc(size);
    if (!ptr) {
        printf("Out of memory!\n");
        exit(1);
    }
    return ptr;
}

void myFree(void *ptr) {
    free(ptr);
}

void init() {
    for (int i = 0; i < MAX_OBJECTS; i++) {
        objects[i] = NULL;
    }
}

void createObject(int id, char *name, int size) {
    Object *obj = myMalloc(sizeof(Object));
    obj->id = id;
    strcpy(obj->name, name);
    obj->size = size;
    objects[objectCount++] = obj;
}

void destroyObject(int id) {
    for (int i = 0; i < objectCount; i++) {
        if (objects[i]!= NULL && objects[i]->id == id) {
            myFree(objects[i]);
            objects[i] = NULL;
            objectCount--;
            break;
        }
    }
}

int main() {
    init();
    createObject(1, "Object 1", 20);
    createObject(2, "Object 2", 50);
    createObject(3, "Object 3", 30);
    printf("Number of objects: %d\n", objectCount);
    printf("Total memory used: %d\n", objectCount * sizeof(Object));
    destroyObject(2);
    printf("Number of objects: %d\n", objectCount);
    printf("Total memory used: %d\n", objectCount * sizeof(Object));
    return 0;
}