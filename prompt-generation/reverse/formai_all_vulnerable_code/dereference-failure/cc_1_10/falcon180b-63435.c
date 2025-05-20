//Falcon-180B DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *email;
} person_t;

// Function to create a new person
person_t *create_person(const char *name, int age, const char *email) {
    person_t *person = malloc(sizeof(person_t));
    if (person == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }
    person->name = strdup(name);
    person->age = age;
    person->email = strdup(email);
    return person;
}

// Function to print a person's information
void print_person(const person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Email: %s\n", person->email);
}

// Function to free a person's memory
void free_person(person_t *person) {
    free(person->name);
    free(person->email);
    free(person);
}

// Main function
int main() {
    person_t *person1 = create_person("John Doe", 30, "john.doe@example.com");
    person_t *person2 = create_person("Jane Doe", 28, "jane.doe@example.com");

    print_person(person1);
    print_person(person2);

    free_person(person1);
    free_person(person2);

    return 0;
}

// End of program