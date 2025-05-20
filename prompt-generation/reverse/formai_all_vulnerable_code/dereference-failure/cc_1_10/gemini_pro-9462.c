//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data types
typedef struct {
    char *name;
    int age;
    float height;
} Person;

// Functions
Person *createPerson(char *name, int age, float height);
void printPerson(Person *person);
void freePerson(Person *person);

// Main function
int main() {
    // Create some data
    Person *people[] = {
        createPerson("John", 30, 1.80),
        createPerson("Mary", 25, 1.65),
        createPerson("Bob", 40, 1.70),
        createPerson("Alice", 35, 1.75),
        createPerson("Tom", 20, 1.85),
    };

    // Print the data
    for (int i = 0; i < 5; i++) {
        printPerson(people[i]);
    }

    // Free the data
    for (int i = 0; i < 5; i++) {
        freePerson(people[i]);
    }

    return 0;
}

// Create a person
Person *createPerson(char *name, int age, float height) {
    Person *person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->height = height;
    return person;
}

// Print a person
void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %.2f\n", person->height);
    printf("\n");
}

// Free a person
void freePerson(Person *person) {
    free(person->name);
    free(person);
}