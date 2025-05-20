//FormAI DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a person's information
typedef struct {
    int id;
    char name[20];
    int age;
} Person;

// Define global variables for the database
Person* people;
int num_people = 0;
int capacity = 10;

// Function to add a person to the database
void add_person(int id, char* name, int age) {
    if (num_people >= capacity) {
        // If the array is full, double the capacity
        capacity *= 2;
        people = realloc(people, capacity * sizeof(Person));
    }
    // Add the new person to the array
    people[num_people].id = id;
    strcpy(people[num_people].name, name);
    people[num_people].age = age;
    num_people++;
}

// Function to get a person's information from their ID
Person get_person(int id) {
    for (int i = 0; i < num_people; i++) {
        if (people[i].id == id) {
            return people[i];
        }
    }
    // If the ID is not found, return a person with ID -1
    Person not_found = {-1, "", 0};
    return not_found;
}

int main() {
    // Allocate memory for the array of people
    people = malloc(capacity * sizeof(Person));

    // Add several people to the database
    add_person(1, "Alice", 24);
    add_person(2, "Bob", 32);
    add_person(3, "Charlie", 41);
    add_person(4, "Dave", 19);

    // Get a person's information using their ID
    Person person = get_person(2);

    // Print the person's information
    if (person.id == -1) {
        printf("Person not found.\n");
    } else {
        printf("ID: %d\nName: %s\nAge: %d\n", person.id, person.name, person.age);
    }

    // Free the memory allocated for the array
    free(people);

    return 0;
}