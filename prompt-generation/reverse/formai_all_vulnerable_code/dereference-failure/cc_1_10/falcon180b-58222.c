//Falcon-180B DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold our data
typedef struct {
    char* name;
    int age;
} Person;

// Function to create a new person
Person* createPerson(char* name, int age) {
    Person* person = (Person*)malloc(sizeof(Person));
    if (person == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    person->name = strdup(name);
    person->age = age;
    return person;
}

// Function to delete a person
void deletePerson(Person* person) {
    free(person->name);
    free(person);
}

// Function to print a person's information
void printPerson(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    // Create some people
    Person* alice = createPerson("Alice", 25);
    Person* bob = createPerson("Bob", 30);
    Person* carol = createPerson("Carol", 20);

    // Print their information
    printPerson(alice);
    printPerson(bob);
    printPerson(carol);

    // Delete the people
    deletePerson(alice);
    deletePerson(bob);
    deletePerson(carol);

    return 0;
}