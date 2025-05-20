//Falcon-180B DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *person, char *name, int age) {
    person->name = strdup(name);
    person->age = age;
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    Person *person1 = NULL;
    Person *person2 = NULL;

    // Create a person
    person1 = malloc(sizeof(Person));
    create_person(person1, "John", 30);
    print_person(person1);

    // Create another person
    person2 = malloc(sizeof(Person));
    create_person(person2, "Jane", 25);
    print_person(person2);

    // Delete the first person
    delete_person(person1);

    // Try to print the first person (should print an error message)
    print_person(person1);

    // Delete the second person
    delete_person(person2);

    // Try to print the second person (should print an error message)
    print_person(person2);

    return 0;
}