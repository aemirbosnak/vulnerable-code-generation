//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} Array;

void init(Array *array) {
    array->data = (Person *)malloc(MAX_SIZE * sizeof(Person));
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void resize(Array *array) {
    array->capacity *= 2;
    Person *new_data = (Person *)malloc(array->capacity * sizeof(Person));
    memcpy(new_data, array->data, array->size * sizeof(Person));
    free(array->data);
    array->data = new_data;
}

void add(Array *array, char *name, int age) {
    if (array->size == array->capacity) {
        resize(array);
    }
    strcpy(array->data[array->size].name, name);
    array->data[array->size].age = age;
    array->size++;
}

void print(Array array) {
    for (int i = 0; i < array.size; i++) {
        printf("%s %d\n", array.data[i].name, array.data[i].age);
    }
}

int main() {
    Array people;
    init(&people);
    add(&people, "Alice", 25);
    add(&people, "Bob", 30);
    add(&people, "Charlie", 20);
    print(people);
    return 0;
}