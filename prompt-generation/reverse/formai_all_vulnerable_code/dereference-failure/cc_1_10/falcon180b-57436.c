//Falcon-180B DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void error(char *message) {
    printf("Error: %s\n", message);
    exit(1);
}

void add_person(Person *people, int *size) {
    if (*size >= MAX_SIZE) {
        error("Cannot add more people");
    }

    Person *new_person = (Person *) malloc(sizeof(Person));
    if (new_person == NULL) {
        error("Memory allocation failed");
    }

    new_person->name = NULL;
    new_person->age = 0;

    people[*size] = *new_person;
    (*size)++;
}

void remove_person(Person *people, int *size, int index) {
    if (index < 0 || index >= *size) {
        error("Invalid person index");
    }

    free(people[index].name);
    people[index] = people[*size - 1];
    (*size)--;
}

void print_people(Person *people, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }
}

int main() {
    Person *people = NULL;
    int size = 0;

    add_person(people, &size);
    add_person(people, &size);
    add_person(people, &size);

    print_people(people, size);

    remove_person(people, &size, 1);

    print_people(people, size);

    for (int i = 0; i < size; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}