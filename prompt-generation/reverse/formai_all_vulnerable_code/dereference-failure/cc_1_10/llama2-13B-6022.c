//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20
#define MAX_OBJ_COUNT 10

// Structure to represent a string object
typedef struct {
    char *data;
    size_t len;
} string_t;

// Function to create a new string object
string_t *new_string(const char *str) {
    size_t len = strlen(str);
    string_t *obj = (string_t *)malloc(sizeof(string_t));
    obj->data = (char *)malloc(len + 1);
    memcpy(obj->data, str, len + 1);
    obj->len = len;
    return obj;
}

// Function to print a string object
void print_string(string_t *obj) {
    printf("%s\n", obj->data);
}

// Function to create a new object
typedef struct {
    int x;
    string_t *name;
} obj_t;

obj_t *new_obj(int x, const char *name) {
    obj_t *obj = (obj_t *)malloc(sizeof(obj_t));
    obj->x = x;
    obj->name = new_string(name);
    return obj;
}

// Function to print an object
void print_obj(obj_t *obj) {
    printf("x: %d, name: %s\n", obj->x, obj->name->data);
}

int main() {
    // Create some objects
    obj_t *obj1 = new_obj(1, "John");
    obj_t *obj2 = new_obj(2, "Jane");
    obj_t *obj3 = new_obj(3, "Jim");

    // Print the objects
    print_obj(obj1);
    print_obj(obj2);
    print_obj(obj3);

    // Free the objects
    free(obj1);
    free(obj2);
    free(obj3);

    return 0;
}