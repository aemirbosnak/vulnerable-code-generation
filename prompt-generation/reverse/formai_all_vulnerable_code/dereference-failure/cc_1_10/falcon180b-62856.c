//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: retro
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
    array->data = (Person *) malloc(MAX_SIZE * sizeof(Person));
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void add_person(Array *array, char *name, int age) {
    if (array->size >= array->capacity) {
        printf("Array is full. Cannot add more elements.\n");
        return;
    }

    array->data[array->size] = (Person) {
       .name = strdup(name),
       .age = age
    };

    array->size++;
}

void print_array(Array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%s is %d years old.\n", array->data[i].name, array->data[i].age);
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