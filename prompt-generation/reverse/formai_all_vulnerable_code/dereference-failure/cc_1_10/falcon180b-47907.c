//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    float height;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} ArrayList;

void initArrayList(ArrayList *list) {
    list->data = (Person *)malloc(MAX_SIZE * sizeof(Person));
    list->size = 0;
    list->capacity = MAX_SIZE;
}

void addElement(ArrayList *list, Person *person) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (Person *)realloc(list->data, list->capacity * sizeof(Person));
    }
    memcpy(&list->data[list->size], person, sizeof(Person));
    list->size++;
}

void printArrayList(ArrayList *list) {
    int i;
    for (i = 0; i < list->size; i++) {
        printf("Name: %s, Age: %d, Height: %f\n", list->data[i].name, list->data[i].age, list->data[i].height);
    }
}

int main() {
    ArrayList list;
    initArrayList(&list);

    Person person1 = {"John", 25, 1.8};
    Person person2 = {"Jane", 30, 1.65};
    Person person3 = {"Bob", 40, 1.9};

    addElement(&list, &person1);
    addElement(&list, &person2);
    addElement(&list, &person3);

    printArrayList(&list);

    return 0;
}