//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: all-encompassing
// Database simulation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the table structure
typedef struct {
    char *name;
    int age;
    char *city;
} Person;

// Define the database structure
typedef struct {
    Person *people;
    int num_people;
} Database;

// Create a new database
Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->people = NULL;
    db->num_people = 0;
    return db;
}

// Add a new person to the database
void add_person(Database *db, char *name, int age, char *city) {
    // Allocate memory for the new person
    Person *person = malloc(sizeof(Person));

    // Copy the person's information into the new struct
    person->name = strdup(name);
    person->age = age;
    person->city = strdup(city);

    // Add the new person to the database
    db->people = realloc(db->people, (db->num_people + 1) * sizeof(Person));
    db->people[db->num_people++] = *person;
}

// Find a person in the database by name
Person *find_person(Database *db, char *name) {
    for (int i = 0; i < db->num_people; i++) {
        if (strcmp(db->people[i].name, name) == 0) {
            return &db->people[i];
        }
    }
    return NULL;
}

// Print the database
void print_database(Database *db) {
    for (int i = 0; i < db->num_people; i++) {
        printf("%s, %d, %s\n", db->people[i].name, db->people[i].age, db->people[i].city);
    }
}

// Free the memory allocated for the database
void free_database(Database *db) {
    for (int i = 0; i < db->num_people; i++) {
        free(db->people[i].name);
        free(db->people[i].city);
    }
    free(db->people);
    free(db);
}

// Main function
int main() {
    // Create a new database
    Database *db = create_database();

    // Add some people to the database
    add_person(db, "John Doe", 30, "New York");
    add_person(db, "Jane Doe", 25, "San Francisco");
    add_person(db, "Bob Smith", 40, "Los Angeles");

    // Print the database
    print_database(db);

    // Find a person in the database by name
    Person *person = find_person(db, "John Doe");
    if (person != NULL) {
        printf("Found person: %s, %d, %s\n", person->name, person->age, person->city);
    } else {
        printf("Person not found.\n");
    }

    // Free the memory allocated for the database
    free_database(db);

    return 0;
}