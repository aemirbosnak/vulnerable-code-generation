//Falcon-180B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold our data
typedef struct {
    int id;
    char name[20];
    int age;
} Person;

// Function to allocate memory for a new person
Person* createPerson(int id, char* name, int age) {
    Person* person = (Person*) malloc(sizeof(Person));
    if (person == NULL) {
        printf("Error: Could not allocate memory for new person.\n");
        exit(1);
    }
    person->id = id;
    strcpy(person->name, name);
    person->age = age;
    return person;
}

// Function to print a person's information
void printPerson(Person* person) {
    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

// Function to free the memory used by a person
void deletePerson(Person* person) {
    free(person);
}

int main() {
    // Create a new person
    Person* john = createPerson(1, "John Doe", 25);
    printPerson(john);

    // Create another person
    Person* jane = createPerson(2, "Jane Smith", 30);
    printPerson(jane);

    // Delete the first person
    deletePerson(john);

    // Print the second person's information again
    printPerson(jane);

    // Delete the second person
    deletePerson(jane);

    return 0;
}