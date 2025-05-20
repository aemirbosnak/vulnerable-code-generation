//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

// Simple struct to hold a name and age
typedef struct {
    char* name;
    int age;
} person_t;

// Function to allocate memory for a person struct
person_t* create_person(char* name, int age) {
    person_t* person = (person_t*)malloc(sizeof(person_t));
    if (person == NULL) {
        return NULL;
    }

    person->name = (char*)malloc(strlen(name) + 1);
    if (person->name == NULL) {
        free(person);
        return NULL;
    }

    strcpy(person->name, name);
    person->age = age;

    return person;
}

// Function to free the memory allocated for a person struct
void destroy_person(person_t* person) {
    if (person == NULL) {
        return;
    }

    free(person->name);
    free(person);
}

int main() {
    // Create a few people
    person_t* alice = create_person("Alice", 25);
    person_t* bob = create_person("Bob", 30);
    person_t* carol = create_person("Carol", 35);

    // Print the people's names and ages
    printf("%s is %d years old.\n", alice->name, alice->age);
    printf("%s is %d years old.\n", bob->name, bob->age);
    printf("%s is %d years old.\n", carol->name, carol->age);

    // Free the memory allocated for the people
    destroy_person(alice);
    destroy_person(bob);
    destroy_person(carol);

    return 0;
}