//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void init_array(Array *array) {
    array->data = (Person *)malloc(MAX_SIZE * sizeof(Person));
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void add_person(Array *array, char *name, int age) {
    if (array->size >= array->capacity) {
        printf("Error: Array is full.\n");
        return;
    }

    array->data[array->size].name = strdup(name);
    array->data[array->size].age = age;
    array->size++;
}

void print_array(Array *array) {
    printf("Array:\n");
    for (int i = 0; i < array->size; i++) {
        printf("Name: %s\n", array->data[i].name);
        printf("Age: %d\n", array->data[i].age);
        printf("\n");
    }
}

int main() {
    Array people;
    init_array(&people);

    add_person(&people, "Alice", 25);
    add_person(&people, "Bob", 30);
    add_person(&people, "Charlie", 35);

    print_array(&people);

    return 0;
}