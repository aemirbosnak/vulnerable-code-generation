//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OBJECTS 100
#define OBJECT_SIZE 20

typedef struct object {
    char name[20];
    int age;
} object_t;

typedef struct memory_block {
    object_t* objects;
    size_t size;
    size_t capacity;
} memory_block_t;

memory_block_t* create_memory_block(size_t size) {
    memory_block_t* block = (memory_block_t*)calloc(1, sizeof(memory_block_t));
    block->size = size;
    block->capacity = size;
    block->objects = (object_t*)calloc(1, size * sizeof(object_t));
    return block;
}

void destroy_memory_block(memory_block_t* block) {
    free(block->objects);
    free(block);
}

object_t* create_object(const char* name, int age) {
    object_t* obj = (object_t*)calloc(1, sizeof(object_t));
    strcpy(obj->name, name);
    obj->age = age;
    return obj;
}

void add_object_to_block(memory_block_t* block, object_t* obj) {
    if (block->capacity <= block->size) {
        size_t new_capacity = block->capacity * 2;
        object_t** new_objects = (object_t**)realloc(block->objects, new_capacity * sizeof(object_t));
        if (new_objects == NULL) {
            perror("realloc failed");
            exit(EXIT_FAILURE);
        }
        block->objects = new_objects;
        block->capacity = new_capacity;
    }
    block->objects[block->size] = *obj;
    block->size++;
}

void print_objects(memory_block_t* block) {
    for (size_t i = 0; i < block->size; i++) {
        printf("%s %d\n", block->objects[i].name, block->objects[i].age);
    }
}

int main() {
    memory_block_t* block = create_memory_block(MAX_OBJECTS * OBJECT_SIZE);
    object_t* obj1 = create_object("John", 25);
    object_t* obj2 = create_object("Jane", 30);
    object_t* obj3 = create_object("Bob", 40);

    add_object_to_block(block, obj1);
    add_object_to_block(block, obj2);
    add_object_to_block(block, obj3);

    print_objects(block);

    destroy_memory_block(block);

    return 0;
}