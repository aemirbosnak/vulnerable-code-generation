//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OBJECTS 10
#define MAX_SIZE 100

// Structure to represent an object
typedef struct {
    char *name;
    int age;
} object_t;

// Function to create an object
object_t *create_object(char *name, int age) {
    object_t *obj = (object_t *)malloc(sizeof(object_t));
    obj->name = name;
    obj->age = age;
    return obj;
}

// Function to delete an object
void delete_object(object_t **obj) {
    if (*obj != NULL) {
        free((*obj)->name);
        free(*obj);
        *obj = NULL;
    }
}

// Function to manage memory for a list of objects
object_t **object_list = NULL;
int object_list_size = 0;

void add_object(object_t *obj) {
    if (object_list_size == MAX_OBJECTS) {
        printf("Error: Object list is full\n");
        return;
    }
    object_list[object_list_size] = obj;
    object_list_size++;
}

void delete_all_objects() {
    for (int i = 0; i < object_list_size; i++) {
        delete_object(&object_list[i]);
    }
    object_list_size = 0;
}

int main() {
    object_t *obj1 = create_object("John", 25);
    object_t *obj2 = create_object("Jane", 30);
    object_t *obj3 = create_object("Bob", 35);

    add_object(obj1);
    add_object(obj2);
    add_object(obj3);

    // Print the list of objects
    for (int i = 0; i < object_list_size; i++) {
        printf("%d: %s %d\n", i, object_list[i]->name, object_list[i]->age);
    }

    // Delete all objects
    delete_all_objects();

    return 0;
}