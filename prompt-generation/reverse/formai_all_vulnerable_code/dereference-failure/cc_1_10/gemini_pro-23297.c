//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our very own database simulation!
typedef struct {
    int id;
    char *name;
    int age;
} Person;

// A simple in-memory database
Person *database = NULL;
int databaseSize = 0;

// Function to create a new person
Person *createPerson(int id, char *name, int age) {
    Person *person = malloc(sizeof(Person));
    person->id = id;
    person->name = strdup(name);
    person->age = age;
    return person;
}

// Function to add a person to the database
void addPerson(Person *person) {
    database = realloc(database, (databaseSize + 1) * sizeof(Person));
    database[databaseSize++] = *person;
}

// Function to find a person by ID
Person *findPersonById(int id) {
    for (int i = 0; i < databaseSize; i++) {
        if (database[i].id == id) {
            return &database[i];
        }
    }
    return NULL;
}

// Function to print the database
void printDatabase() {
    for (int i = 0; i < databaseSize; i++) {
        printf("%d %s %d\n", database[i].id, database[i].name, database[i].age);
    }
}

// Let's play with our database!
int main() {
    // Create some people
    Person *alice = createPerson(1, "Alice", 25);
    Person *bob = createPerson(2, "Bob", 30);
    Person *charlie = createPerson(3, "Charlie", 35);

    // Add them to the database
    addPerson(alice);
    addPerson(bob);
    addPerson(charlie);

    // Print the database
    printf("Our database:\n");
    printDatabase();

    // Find Alice by her ID
    Person *foundAlice = findPersonById(1);
    if (foundAlice) {
        printf("Found Alice: %s, %d\n", foundAlice->name, foundAlice->age);
    } else {
        printf("Alice not found.\n");
    }

    // Clean up
    free(alice->name);
    free(bob->name);
    free(charlie->name);
    free(alice);
    free(bob);
    free(charlie);
    free(database);

    return 0;
}