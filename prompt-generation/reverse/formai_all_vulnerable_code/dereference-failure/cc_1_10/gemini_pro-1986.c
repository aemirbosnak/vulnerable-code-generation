//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// A simple struct to hold a name and age
typedef struct {
    char* name;
    int age;
} person_t;

// A function to allocate memory for a person
person_t* create_person(const char* name, int age) {
    // Allocate memory for the person struct
    person_t* person = malloc(sizeof(person_t));
    if (person == NULL) {
        return NULL;
    }

    // Allocate memory for the name
    person->name = malloc(strlen(name) + 1);
    if (person->name == NULL) {
        free(person);
        return NULL;
    }

    // Copy the name into the person struct
    strcpy(person->name, name);

    // Set the age
    person->age = age;

    // Return the person
    return person;
}

// A function to free the memory allocated for a person
void destroy_person(person_t* person) {
    // Free the memory allocated for the name
    free(person->name);

    // Free the memory allocated for the person struct
    free(person);
}

// A function to print a person
void print_person(const person_t* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    // Create a person
    person_t* person = create_person("John Doe", 30);

    // Print the person
    print_person(person);

    // Free the memory allocated for the person
    destroy_person(person);

    return 0;
}