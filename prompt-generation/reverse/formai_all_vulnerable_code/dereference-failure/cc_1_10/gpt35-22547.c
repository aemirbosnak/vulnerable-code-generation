//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
    char* address;
} Person;

// Custom error handler function
void handle_error(char* error_message) {
    printf("Oh no! An error occurred: %s\n", error_message);
    exit(1); // Exit program with error code 1
}

// Function to create new person
Person* create_person(char* name, int age, char* address) {
    Person* new_person = malloc(sizeof(Person)); // Allocate memory for person struct

    if (!new_person) {
        handle_error("Failed to allocate memory for new person.");
    }

    // Copy name and address to new memory location
    new_person->name = malloc(strlen(name) + 1);
    if (!new_person->name) {
        handle_error("Failed to allocate memory for new person name.");
    }
    strcpy(new_person->name, name);

    new_person->address = malloc(strlen(address) + 1);
    if (!new_person->address) {
        handle_error("Failed to allocate memory for new person address.");
    }
    strcpy(new_person->address, address);

    // Set age
    if (age >= 0 && age <= 120) {
        new_person->age = age;
    } else {
        handle_error("Invalid age value.");
    }

    return new_person;
}

// Function to print person details
void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Address: %s\n", person->address);
}

int main() {
    // Test create_person function with valid input
    Person* person1 = create_person("John Doe", 35, "123 Main St.");
    print_person(person1); // Print person details

    // Test create_person function with invalid age input
    Person* person2 = create_person("Jane Doe", 150, "456 Elm St.");
    print_person(person2); // This should never execute

    return 0; // Exit program with success code 0
}