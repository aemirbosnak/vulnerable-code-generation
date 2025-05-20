//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the database structure
typedef struct {
    char name[50];
    int age;
    char address[100];
} person;

// Define the database
person database[] = {
    {"Alice", 25, "123 Main St"},
    {"Bob", 30, "456 Elm St"},
    {"Charlie", 35, "789 Oak St"},
    {"David", 20, "111 Maple St"},
    {"Eve", 28, "222 Walnut St"}
};

// Define the number of people in the database
#define PEOPLE_COUNT 5

// Define a function to insert a person into the database
void insert_person(person *database, int size, char *name, int age, char *address) {
    int i;

    // Check if the database is full
    if (size == PEOPLE_COUNT) {
        printf("Database is full, cannot insert %s\n", name);
        return;
    }

    // Find an empty slot in the database
    for (i = 0; i < size; i++) {
        if (strcmp(database[i].name, "") == 0) {
            break;
        }
    }

    // Insert the person into the database
    strcpy(database[i].name, name);
    database[i].age = age;
    strcpy(database[i].address, address);

    // Increment the size of the database
    size++;
}

// Define a function to retrieve a person from the database
person *retrieve_person(person *database, int size, char *name) {
    int i;

    // Check if the person is in the database
    for (i = 0; i < size; i++) {
        if (strcmp(database[i].name, name) == 0) {
            return &database[i];
        }
    }

    // Person not found, return a NULL pointer
    return NULL;
}

// Define a function to update a person in the database
void update_person(person *database, int size, char *name, int age, char *address) {
    int i;

    // Find the person in the database
    person *person = retrieve_person(database, size, name);

    // If the person is found, update their information
    if (person != NULL) {
        person->age = age;
        strcpy(person->address, address);
    }
}

// Define a function to delete a person from the database
void delete_person(person *database, int size, char *name) {
    int i;

    // Find the person in the database
    person *person = retrieve_person(database, size, name);

    // If the person is found, delete them from the database
    if (person != NULL) {
        for (i = 0; i < size; i++) {
            if (person == &database[i]) {
                break;
            }
        }

        // Replace the person with the last person in the list
        memcpy(&database[i], person, sizeof(person));
        size--;
    }
}

int main() {
    // Initialize the database
    person *database = malloc(sizeof(person) * PEOPLE_COUNT);
    for (int i = 0; i < PEOPLE_COUNT; i++) {
        insert_person(database, PEOPLE_COUNT, "Alice", 25, "123 Main St");
    }

    // Update the first person's information
    update_person(database, PEOPLE_COUNT, "Alice", 30, "456 Elm St");

    // Delete the second person from the database
    delete_person(database, PEOPLE_COUNT, "Bob");

    // Print the database
    for (int i = 0; i < PEOPLE_COUNT; i++) {
        printf("%d. %s (%d) %s\n", i + 1, database[i].name, database[i].age, database[i].address);
    }

    // Free the memory allocated for the database
    free(database);

    return 0;
}