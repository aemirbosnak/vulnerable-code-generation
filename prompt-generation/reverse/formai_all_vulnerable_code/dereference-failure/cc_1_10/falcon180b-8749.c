//Falcon-180B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *person, char *name, int age) {
    person->name = malloc(strlen(name) + 1);
    if (person->name == NULL) {
        printf("Memory error: failed to allocate memory for name\n");
        exit(1);
    }
    strcpy(person->name, name);
    person->age = age;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int main() {
    Person *person1 = NULL;
    Person *person2 = NULL;
    Person *person3 = NULL;

    person1 = malloc(sizeof(Person));
    if (person1 == NULL) {
        printf("Memory error: failed to allocate memory for person 1\n");
        exit(1);
    }

    create_person(person1, "John", 25);
    print_person(person1);

    person2 = malloc(sizeof(Person));
    if (person2 == NULL) {
        printf("Memory error: failed to allocate memory for person 2\n");
        exit(1);
    }

    create_person(person2, "Jane", 30);
    print_person(person2);

    person3 = malloc(sizeof(Person));
    if (person3 == NULL) {
        printf("Memory error: failed to allocate memory for person 3\n");
        exit(1);
    }

    create_person(person3, "Bob", 40);
    print_person(person3);

    delete_person(person1);
    delete_person(person2);
    delete_person(person3);

    return 0;
}