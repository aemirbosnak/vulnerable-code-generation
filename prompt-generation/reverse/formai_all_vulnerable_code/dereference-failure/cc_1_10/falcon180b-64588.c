//Falcon-180B DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a structure for a person
typedef struct {
    char name[50];
    int age;
    char address[100];
} PERSON;

// Function to create a new person
PERSON* createPerson() {
    PERSON* newPerson = (PERSON*) malloc(sizeof(PERSON));
    if (newPerson == NULL) {
        printf("Error: Could not create a new person.\n");
        return NULL;
    }
    strcpy(newPerson->name, "");
    newPerson->age = 0;
    strcpy(newPerson->address, "");
    return newPerson;
}

// Function to delete a person
void deletePerson(PERSON* person) {
    free(person);
}

// Function to display a person's information
void displayPerson(PERSON* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Address: %s\n", person->address);
}

// Main function
int main() {
    PERSON* person1 = createPerson();
    PERSON* person2 = createPerson();
    PERSON* person3 = createPerson();

    strcpy(person1->name, "John Doe");
    person1->age = 25;
    strcpy(person1->address, "123 Main St.");

    strcpy(person2->name, "Jane Smith");
    person2->age = 30;
    strcpy(person2->address, "456 Elm St.");

    strcpy(person3->name, "Bob Johnson");
    person3->age = 40;
    strcpy(person3->address, "789 Oak St.");

    displayPerson(person1);
    displayPerson(person2);
    displayPerson(person3);

    deletePerson(person1);
    deletePerson(person2);
    deletePerson(person3);

    return 0;
}