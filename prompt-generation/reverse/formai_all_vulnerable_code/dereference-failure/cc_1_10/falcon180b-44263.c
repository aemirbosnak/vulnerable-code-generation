//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a person
typedef struct {
    char name[50];
    int age;
    char address[100];
} person;

// Define a struct to represent a database
typedef struct {
    int num_people;
    person *people;
} database;

// Function to create a new person
person *create_person(char *name, int age, char *address) {
    person *new_person = (person *) malloc(sizeof(person));
    strcpy(new_person->name, name);
    new_person->age = age;
    strcpy(new_person->address, address);
    return new_person;
}

// Function to create a new database
database *create_database() {
    database *new_database = (database *) malloc(sizeof(database));
    new_database->num_people = 0;
    new_database->people = NULL;
    return new_database;
}

// Function to add a person to the database
void add_person(database *db, char *name, int age, char *address) {
    person *new_person = create_person(name, age, address);
    db->people = (person *) realloc(db->people, sizeof(person) * (db->num_people + 1));
    db->people[db->num_people] = *new_person;
    db->num_people++;
}

// Function to print all the people in the database
void print_database(database *db) {
    int i;
    for (i = 0; i < db->num_people; i++) {
        printf("Name: %s\n", db->people[i].name);
        printf("Age: %d\n", db->people[i].age);
        printf("Address: %s\n\n", db->people[i].address);
    }
}

// Main function
int main() {
    database *db = create_database();
    add_person(db, "John Doe", 25, "123 Main St.");
    add_person(db, "Jane Smith", 30, "456 Elm St.");
    print_database(db);
    return 0;
}