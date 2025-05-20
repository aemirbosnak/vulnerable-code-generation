//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_SIZE 20

typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
    int age;
} Person;

typedef struct {
    Person* data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createDynamicArray() {
    DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
    array->data = NULL;
    array->size = 0;
    array->capacity = MAX_SIZE;
    return array;
}

int isFull(DynamicArray* array) {
    return array->size == array->capacity;
}

void resize(DynamicArray* array, int newCapacity) {
    Person* newData = (Person*)malloc(newCapacity * sizeof(Person));
    memcpy(newData, array->data, array->size * sizeof(Person));
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void add(DynamicArray* array, Person person) {
    if (isFull(array)) {
        resize(array, array->capacity * 2);
    }
    array->data[array->size++] = person;
}

void printDynamicArray(DynamicArray* array) {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < array->size; i++) {
        printf("%d\t%s\t%d\n", array->data[i].id, array->data[i].name, array->data[i].age);
    }
}

int main() {
    DynamicArray* array = createDynamicArray();
    Person person1 = {1, "Alice", 25};
    Person person2 = {2, "Bob", 30};
    Person person3 = {3, "Charlie", 35};

    add(array, person1);
    add(array, person2);
    add(array, person3);

    printDynamicArray(array);

    free(array->data);
    free(array);

    return 0;
}