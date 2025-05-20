//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} Array;

Array *create_array() {
    Array *arr = (Array *)malloc(sizeof(Array));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
    return arr;
}

void destroy_array(Array *arr) {
    if (arr->data!= NULL) {
        free(arr->data);
        arr->data = NULL;
    }
    arr->size = 0;
    arr->capacity = 0;
}

void add_element(Array *arr, Person *elem) {
    if (arr->size == arr->capacity) {
        arr->capacity += MAX_SIZE;
        arr->data = (Person *)realloc(arr->data, arr->capacity * sizeof(Person));
    }
    arr->data[arr->size++] = *elem;
}

void remove_element(Array *arr, int index) {
    if (index >= 0 && index < arr->size) {
        for (int i = index; i < arr->size - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->size--;
    } else {
        printf("Invalid index\n");
    }
}

void print_array(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%s %d\n", arr->data[i].name, arr->data[i].age);
    }
}

int main() {
    Array *arr = create_array();
    Person p1 = {"John", 30};
    Person p2 = {"Jane", 25};
    Person p3 = {"Bob", 40};
    add_element(arr, &p1);
    add_element(arr, &p2);
    add_element(arr, &p3);
    print_array(arr);
    remove_element(arr, 1);
    print_array(arr);
    destroy_array(arr);
    return 0;
}