//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    char gender;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} Array;

void initArray(Array *array) {
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

void resizeArray(Array *array, int newCapacity) {
    Person *newData = (Person *) malloc(newCapacity * sizeof(Person));
    if (array->data!= NULL) {
        memcpy(newData, array->data, array->size * sizeof(Person));
        free(array->data);
    }
    array->data = newData;
    array->capacity = newCapacity;
}

void addPerson(Array *array, char *name, int age, char gender) {
    if (array->size == array->capacity) {
        resizeArray(array, array->capacity * 2);
    }
    array->data[array->size] = (Person) {.name = strdup(name),.age = age,.gender = gender };
    array->size++;
}

void printArray(Array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%s %d %c\n", array->data[i].name, array->data[i].age, array->data[i].gender);
    }
}

int main() {
    Array people = { NULL, 0, 0 };
    initArray(&people);

    addPerson(&people, "Alice", 25, 'F');
    addPerson(&people, "Bob", 30, 'M');
    addPerson(&people, "Charlie", 20, 'M');

    printArray(&people);

    return 0;
}