//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100
#define MAX_OBJECTS 10

// Structure to represent a person
typedef struct {
    char name[50];
    int age;
} Person;

// Function to create a new person object
Person* create_person(char* name, int age) {
    Person* person = (Person*) malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age;
    return person;
}

// Function to print a person object
void print_person(Person* person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

// Function to delete a person object
void delete_person(Person** persons, int num_persons, int index) {
    if (index < num_persons) {
        free(persons[index]);
        memmove(persons + index, persons + index + 1, (num_persons - index - 1) * sizeof(Person*));
        num_persons--;
    }
}

int main() {
    // Create an array of Person objects
    Person* persons[MAX_OBJECTS];
    for (int i = 0; i < MAX_OBJECTS; i++) {
        persons[i] = create_person("Person #" + (i + 1), i * 2);
    }

    // Print the array of Person objects
    for (int i = 0; i < MAX_OBJECTS; i++) {
        print_person(persons[i]);
    }

    // Delete the Person objects in a random order
    int random_index = rand() % MAX_OBJECTS;
    delete_person(persons, MAX_OBJECTS, random_index);

    // Print the remaining Person objects
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (i != random_index) {
            print_person(persons[i]);
        }
    }

    // Free the memory allocated for the Person objects
    for (int i = 0; i < MAX_OBJECTS; i++) {
        free(persons[i]);
    }

    return 0;
}