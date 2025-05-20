//Falcon-180B DATASET v1.0 Category: Error handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *people;
    int size;
    int capacity;
} PeopleList;

void init_people_list(PeopleList *list) {
    list->people = NULL;
    list->size = 0;
    list->capacity = MAX_SIZE;
}

void add_person(PeopleList *list, const char *name, int age) {
    if (list->size >= list->capacity) {
        printf("Error: List is full.\n");
        return;
    }

    Person *person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;

    list->people = realloc(list->people, sizeof(Person) * (list->size + 1));
    list->people[list->size] = *person;
    list->size++;
}

void print_people_list(const PeopleList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s (%d)\n", list->people[i].name, list->people[i].age);
    }
}

int main() {
    PeopleList people_list;
    init_people_list(&people_list);

    add_person(&people_list, "Alice", 25);
    add_person(&people_list, "Bob", 30);
    add_person(&people_list, "Charlie", 20);

    print_people_list(&people_list);

    return 0;
}