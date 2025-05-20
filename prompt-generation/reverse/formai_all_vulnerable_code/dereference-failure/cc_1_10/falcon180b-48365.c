//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Define the structure of the database
typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

// Define the functions for the database
void createDatabase();
void addPerson(Person *person);
void deletePerson(char *name);
void searchPerson(char *name);
void displayPersons();

// Define the global variables for the database
Person *database;
int numPersons;

// Define the main function
int main() {
    createDatabase();

    // Add some persons to the database
    addPerson((Person *)malloc(sizeof(Person)));
    addPerson((Person *)malloc(sizeof(Person)));
    addPerson((Person *)malloc(sizeof(Person)));

    // Search for a person
    searchPerson("John");

    // Display all the persons in the database
    displayPersons();

    // Delete a person from the database
    deletePerson("John");

    // Display all the persons in the database again
    displayPersons();

    return 0;
}

// Create the database
void createDatabase() {
    database = (Person *)malloc(MAX_ROWS * MAX_COLS * sizeof(Person));
    numPersons = 0;
}

// Add a person to the database
void addPerson(Person *person) {
    int row = numPersons / MAX_COLS;
    int col = numPersons % MAX_COLS;
    database[row * MAX_COLS + col] = *person;
    numPersons++;
}

// Delete a person from the database
void deletePerson(char *name) {
    int i;
    for (i = 0; i < numPersons; i++) {
        if (strcmp(database[i].name, name) == 0) {
            numPersons--;
            break;
        }
    }
}

// Search for a person in the database
void searchPerson(char *name) {
    int i;
    for (i = 0; i < numPersons; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Found person: %s\n", name);
            printf("Age: %d\n", database[i].age);
            printf("Gender: %s\n", database[i].gender);
            break;
        }
    }
}

// Display all the persons in the database
void displayPersons() {
    int i;
    for (i = 0; i < numPersons; i++) {
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Gender: %s\n", database[i].gender);
        printf("\n");
    }
}