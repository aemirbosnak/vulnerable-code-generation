//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complete
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
obj_t *create_obj(char *name, int age) {
    obj_t *obj = (obj_t *)malloc(sizeof(obj_t));
    obj->name = name;
    obj->age = age;
    return obj;
}

// Function to delete an object
void delete_obj(obj_t *obj) {
    free(obj->name);
    free(obj);
}

// Function to print all objects
void print_objs(obj_t *objs[], int num_objs) {
    int i;
    for (i = 0; i < num_objs; i++) {
        printf("%s is %d years old\n", objs[i]->name, objs[i]->age);
    }
}

int main() {
    // Create some objects
    obj_t *objs[MAX_OBJS];
    for (int i = 0; i < MAX_OBJS; i++) {
        objs[i] = create_obj("Person", i % 2 == 0 ? 25 : 30);
    }

    // Print all objects
    print_objs(objs, MAX_OBJS);

    // Delete some objects
    for (int i = 0; i < 5; i++) {
        delete_obj(objs[i]);
    }

    // Print all remaining objects
    print_objs(objs, MAX_OBJS - 5);

    return 0;
}