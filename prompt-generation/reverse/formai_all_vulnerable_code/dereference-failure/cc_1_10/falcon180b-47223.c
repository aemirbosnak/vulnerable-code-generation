//Falcon-180B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User-defined data structure
typedef struct {
    int id;
    char name[50];
} Person;

// Function to create a new person
Person* create_person(int id, char* name) {
    Person* new_person = (Person*) malloc(sizeof(Person));
    if (new_person == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    new_person->id = id;
    strcpy(new_person->name, name);
    return new_person;
}

// Function to delete a person
void delete_person(Person* person) {
    free(person);
}

// Function to display a person's details
void display_person(Person* person) {
    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
}

int main() {
    // Create two persons
    Person* person1 = create_person(1, "John");
    Person* person2 = create_person(2, "Jane");

    // Display their details
    display_person(person1);
    display_person(person2);

    // Delete the first person
    delete_person(person1);

    // Display the remaining person's details
    display_person(person2);

    // Delete the second person
    delete_person(person2);

    return 0;
}