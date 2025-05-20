//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100
#define PI 3.14159265358979323846

typedef struct {
    char *name;
    int age;
    float height;
    float weight;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray() {
    DynamicArray *array = malloc(sizeof(DynamicArray));
    array->data = NULL;
    array->size = 0;
    array->capacity = MAX_SIZE;
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    if (array->data!= NULL) {
        for (int i = 0; i < array->size; i++) {
            free(array->data[i].name);
        }
        free(array->data);
    }
    free(array);
}

int isFull(DynamicArray *array) {
    return array->size == array->capacity;
}

void resize(DynamicArray *array) {
    array->capacity *= 2;
    array->data = realloc(array->data, sizeof(Person) * array->capacity);
}

void addPerson(DynamicArray *array, char *name, int age, float height, float weight) {
    if (isFull(array)) {
        resize(array);
    }
    Person *person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->height = height;
    person->weight = weight;
    array->data[array->size++] = *person;
    free(person);
}

void printDynamicArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("Name: %s\nAge: %d\nHeight: %.2f\nWeight: %.2f\n", array->data[i].name, array->data[i].age, array->data[i].height, array->data[i].weight);
    }
}

int main() {
    DynamicArray *array = createDynamicArray();
    addPerson(array, "John", 25, 180.0, 80.0);
    addPerson(array, "Jane", 30, 165.0, 60.0);
    addPerson(array, "Bob", 40, 170.0, 90.0);
    addPerson(array, "Alice", 45, 155.0, 50.0);
    printDynamicArray(array);
    destroyDynamicArray(array);
    return 0;
}