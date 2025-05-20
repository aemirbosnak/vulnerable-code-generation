//Falcon-180B DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for our data
typedef struct {
    char* name;
    int age;
} Person;

// Function to initialize a new Person struct with default values
Person* newPerson() {
    Person* person = (Person*) malloc(sizeof(Person));
    if (person == NULL) {
        printf("Error: Failed to allocate memory for new Person\n");
        exit(1);
    }
    person->name = NULL;
    person->age = 0;
    return person;
}

// Function to set the name of a Person struct
void setName(Person* person, char* name) {
    if (person->name!= NULL) {
        free(person->name);
    }
    person->name = (char*) malloc(strlen(name) + 1);
    if (person->name == NULL) {
        printf("Error: Failed to allocate memory for new name\n");
        exit(1);
    }
    strcpy(person->name, name);
}

// Function to set the age of a Person struct
void setAge(Person* person, int age) {
    person->age = age;
}

// Function to print the details of a Person struct
void printPerson(Person* person) {
    if (person->name == NULL) {
        printf("Name: (null)\n");
    } else {
        printf("Name: %s\n", person->name);
    }
    printf("Age: %d\n", person->age);
}

// Main function to demonstrate usage of our Person struct and functions
int main() {
    Person* person = newPerson();
    setName(person, "Alice");
    setAge(person, 25);
    printPerson(person);

    // Free the memory used by our Person struct
    free(person->name);
    free(person);

    return 0;
}