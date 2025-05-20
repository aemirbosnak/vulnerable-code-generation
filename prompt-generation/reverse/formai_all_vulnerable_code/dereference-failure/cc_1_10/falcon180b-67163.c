//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person *createPerson(char *name, int age) {
    Person *person = (Person *) malloc(sizeof(Person));
    if (person == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    person->name = (char *) malloc(strlen(name) + 1);
    if (person->name == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    strcpy(person->name, name);
    person->age = age;
    return person;
}

void deletePerson(Person *person) {
    free(person->name);
    free(person);
}

void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    Person *person1 = createPerson("John", 25);
    printf("Person 1:\n");
    printPerson(person1);

    Person *person2 = createPerson("Jane", 30);
    printf("\nPerson 2:\n");
    printPerson(person2);

    deletePerson(person1);
    printf("\nPerson 1 deleted.\n");

    deletePerson(person2);
    printf("\nPerson 2 deleted.\n");

    return 0;
}