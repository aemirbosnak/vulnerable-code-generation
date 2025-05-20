//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MEMORY_POOL_SIZE 1024
#define MAX_OBJECTS 100

typedef struct object {
    int id;
    char name[20];
} object;

object* objects = NULL;

void init_objects() {
    objects = calloc(MAX_OBJECTS, sizeof(object));
    for (int i = 0; i < MAX_OBJECTS; i++) {
        objects[i].id = i;
        objects[i].name[0] = 'A' + (i % 2);
    }
}

void destroy_objects() {
    for (int i = 0; i < MAX_OBJECTS; i++) {
        free(objects[i].name);
    }
    free(objects);
}

object* create_object() {
    object* obj = calloc(1, sizeof(object));
    obj->id = rand() % MAX_OBJECTS;
    obj->name[0] = 'A' + (obj->id % 2);
    return obj;
}

void use_object(object* obj) {
    printf("Using object %d: %s\n", obj->id, obj->name);
    sleep(1);
}

int main() {
    init_objects();
    for (int i = 0; i < 10; i++) {
        object* obj = create_object();
        use_object(obj);
        free(obj);
    }
    destroy_objects();
    return 0;
}