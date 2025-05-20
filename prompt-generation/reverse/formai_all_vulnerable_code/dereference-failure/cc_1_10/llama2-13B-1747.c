//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20
#define MAX_OBJS 10

// Structure to represent a object
struct obj {
    int id;
    char name[MAX_STR_LEN];
};

// Function to create an object
struct obj *create_obj(int id, char *name) {
    struct obj *obj = (struct obj *) malloc(sizeof(struct obj));
    obj->id = id;
    strcpy(obj->name, name);
    return obj;
}

// Function to print an object
void print_obj(struct obj *obj) {
    printf("Object ID: %d, Name: %s\n", obj->id, obj->name);
}

// Function to delete an object
void delete_obj(struct obj **obj_ptr) {
    if (*obj_ptr != NULL) {
        free((*obj_ptr)->name);
        free(*obj_ptr);
        *obj_ptr = NULL;
    }
}

int main() {
    // Create some objects
    struct obj *obj1 = create_obj(1, "Object 1");
    struct obj *obj2 = create_obj(2, "Object 2");
    struct obj *obj3 = create_obj(3, "Object 3");

    // Print the objects
    print_obj(obj1);
    print_obj(obj2);
    print_obj(obj3);

    // Delete an object
    delete_obj(&obj2);

    // Print the remaining objects
    print_obj(obj1);
    print_obj(obj3);

    return 0;
}