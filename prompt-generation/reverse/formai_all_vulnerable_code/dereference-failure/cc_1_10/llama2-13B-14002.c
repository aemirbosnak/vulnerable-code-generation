//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 20
#define MAX_OBJS 10

// Structure to represent a object
typedef struct {
    char *name;
    int age;
} obj_t;

// Function to create an object
obj_t *create_obj(const char *name, int age) {
    obj_t *obj = malloc(sizeof(obj_t));
    obj->name = strdup(name);
    obj->age = age;
    return obj;
}

// Function to print an object
void print_obj(obj_t *obj) {
    printf("Name: %s, Age: %d\n", obj->name, obj->age);
}

// Function to delete an object
void delete_obj(obj_t *obj) {
    free(obj->name);
    free(obj);
}

int main() {
    // Create some objects
    obj_t *obj1 = create_obj("John", 25);
    obj_t *obj2 = create_obj("Jane", 30);
    obj_t *obj3 = create_obj("Bob", 35);

    // Print the objects
    print_obj(obj1);
    print_obj(obj2);
    print_obj(obj3);

    // Delete the objects
    delete_obj(obj1);
    delete_obj(obj2);
    delete_obj(obj3);

    // Create some more objects
    obj_t *obj4 = create_obj("Alice", 22);
    obj_t *obj5 = create_obj("Mike", 40);

    // Print the objects again
    print_obj(obj4);
    print_obj(obj5);

    // Delete the objects again
    delete_obj(obj4);
    delete_obj(obj5);

    return 0;
}