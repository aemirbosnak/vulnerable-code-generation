//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

int main() {
    // Create an array of 10 people.
    Person people[10];

    // Allocate memory for each person's name.
    for (int i = 0; i < 10; i++) {
        people[i].name = malloc(256);
    }

    // Set the names of the people.
    strcpy(people[0].name, "Alice");
    strcpy(people[1].name, "Bob");
    strcpy(people[2].name, "Carol");
    strcpy(people[3].name, "Dave");
    strcpy(people[4].name, "Eve");
    strcpy(people[5].name, "Frank");
    strcpy(people[6].name, "George");
    strcpy(people[7].name, "Helen");
    strcpy(people[8].name, "Ian");
    strcpy(people[9].name, "Jack");

    // Set the ages of the people.
    for (int i = 0; i < 10; i++) {
        people[i].age = i + 1;
    }

    // Set the occupations of the people.
    strcpy(people[0].occupation, "Software engineer");
    strcpy(people[1].occupation, "Doctor");
    strcpy(people[2].occupation, "Lawyer");
    strcpy(people[3].occupation, "Teacher");
    strcpy(people[4].occupation, "Nurse");
    strcpy(people[5].occupation, "Police officer");
    strcpy(people[6].occupation, "Firefighter");
    strcpy(people[7].occupation, "Chef");
    strcpy(people[8].occupation, "Waiter");
    strcpy(people[9].occupation, "Cashier");

    // Print the information about the people.
    for (int i = 0; i < 10; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Occupation: %s\n\n", people[i].occupation);
    }

    // Free the memory allocated for the people's names.

    for (int i = 0; i < 10; i++) {
        free(people[i].name);
    }

    return 0;
}