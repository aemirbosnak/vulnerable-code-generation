//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
    char *name;
    int age;
    char *address;
    char *phone_number;
} Person;

// Create a new person
Person *create_person(char *name, int age, char *address, char *phone_number) {
    Person *person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->address = strdup(address);
    person->phone_number = strdup(phone_number);
    return person;
}

// Print a person's information
void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Address: %s\n", person->address);
    printf("Phone number: %s\n", person->phone_number);
}

// Free the memory allocated for a person
void free_person(Person *person) {
    free(person->name);
    free(person->address);
    free(person->phone_number);
    free(person);
}

// Main function
int main() {
    // Create a few people
    Person *person1 = create_person("John Doe", 30, "123 Main Street", "555-1212");
    Person *person2 = create_person("Jane Doe", 25, "456 Elm Street", "555-1213");
    Person *person3 = create_person("Bill Smith", 40, "789 Oak Street", "555-1214");

    // Print the people's information
    print_person(person1);
    print_person(person2);
    print_person(person3);

    // Free the memory allocated for the people
    free_person(person1);
    free_person(person2);
    free_person(person3);

    return 0;
}