//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a person
typedef struct {
    char* name;
    int age;
    char* occupation;
} Person;

// Function prototypes
void print_person(Person* person);
Person* create_person(char* name, int age, char* occupation);
void free_person(Person* person);

// Main function
int main() {
    // Create two people
    Person* romeo = create_person("Romeo", 18, "Montague");
    Person* juliet = create_person("Juliet", 16, "Capulet");

    // Print their information
    printf("Romeo:\n");
    print_person(romeo);
    printf("\nJuliet:\n");
    print_person(juliet);

    // Free the memory used by the people
    free_person(romeo);
    free_person(juliet);

    return 0;
}

// Function to print a person's information
void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Occupation: %s\n", person->occupation);
}

// Function to create a person
Person* create_person(char* name, int age, char* occupation) {
    // Allocate memory for the person
    Person* person = (Person*) malloc(sizeof(Person));

    // Set the person's information
    person->name = strdup(name);
    person->age = age;
    person->occupation = strdup(occupation);

    return person;
}

// Function to free a person's memory
void free_person(Person* person) {
    // Free the person's name
    free(person->name);

    // Free the person's occupation
    free(person->occupation);

    // Free the person itself
    free(person);
}