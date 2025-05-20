//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a medieval database
typedef struct {
    char *name;
    char *title;
    int age;
} Person;

// Function to create a new person
Person *createPerson(char *name, char *title, int age) {
    Person *person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->title = strdup(title);
    person->age = age;
    return person;
}

// Function to print a person
void printPerson(Person *person) {
    printf("%s, the %s, is %d years old.\n", person->name, person->title, person->age);
}

// Main function
int main() {
    // Create a new database
    Person **database = malloc(100 * sizeof(Person));

    // Add some people to the database
    database[0] = createPerson("Sir Robin", "Knight", 25);
    database[1] = createPerson("Lady Guinevere", "Queen", 28);
    database[2] = createPerson("Merlin", "Wizard", 500);

    // Print the database
    for (int i = 0; i < 3; i++) {
        printPerson(database[i]);
    }

    // Free the database
    for (int i = 0; i < 3; i++) {
        free(database[i]->name);
        free(database[i]->title);
        free(database[i]);
    }
    free(database);

    return 0;
}