//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a custom data structure to store a person's information
typedef struct {
    char *name;
    int age;
    char *occupation;
} person_t;

// Define a function to create a new person
person_t *create_person(const char *name, int age, const char *occupation) {
    // Allocate memory for the new person
    person_t *person = malloc(sizeof(person_t));
    if (person == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new person.\n");
        exit(EXIT_FAILURE);
    }

    // Copy the name, age, and occupation into the new person
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    person->occupation = malloc(strlen(occupation) + 1);
    strcpy(person->occupation, occupation);

    // Return the new person
    return person;
}

// Define a function to destroy a person
void destroy_person(person_t *person) {
    // Free the memory allocated for the person's name, occupation, and the person itself
    free(person->name);
    free(person->occupation);
    free(person);
}

// Define a function to print a person's information
void print_person(const person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Occupation: %s\n", person->occupation);
}

// Define a function to test the memory management functions
void test_memory_management() {
    // Create a new person
    person_t *person = create_person("John Doe", 30, "Software Engineer");

    // Print the person's information
    print_person(person);

    // Destroy the person
    destroy_person(person);
}

// Define the main function
int main() {
    // Test the memory management functions
    test_memory_management();

    return 0;
}