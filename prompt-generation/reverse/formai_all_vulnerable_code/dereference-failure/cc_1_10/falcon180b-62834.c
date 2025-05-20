//Falcon-180B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void init(int size) {
    printf("Initializing memory...\n");
    for (int i = 0; i < size; i++) {
        char *ptr = malloc(MAX_SIZE);
        if (ptr == NULL) {
            printf("Error: Memory allocation failed!\n");
            exit(1);
        }
        strcpy(ptr, "");
    }
}

void add_person(Person **people, int *size, char *name, int age) {
    printf("Adding person: %s, %d\n", name, age);
    Person *new_person = malloc(sizeof(Person));
    if (new_person == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    new_person->name = malloc(strlen(name) + 1);
    if (new_person->name == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    strcpy(new_person->name, name);
    new_person->age = age;
    (*size)++;
    (*people) = realloc(*people, (*size) * sizeof(Person));
    if ((*people) == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    (*people)[*size - 1] = *new_person;
}

void print_people(Person *people, int size) {
    printf("Printing people:\n");
    for (int i = 0; i < size; i++) {
        printf("%s, %d\n", people[i].name, people[i].age);
    }
}

void free_memory(Person *people, int size) {
    printf("Freeing memory...\n");
    for (int i = 0; i < size; i++) {
        free(people[i].name);
    }
    free(people);
}

int main() {
    int size = 0;
    Person *people = NULL;

    init(MAX_SIZE);

    add_person(&people, &size, "John", 30);
    add_person(&people, &size, "Jane", 28);
    add_person(&people, &size, "Bob", 25);

    print_people(people, size);

    free_memory(people, size);

    return 0;
}