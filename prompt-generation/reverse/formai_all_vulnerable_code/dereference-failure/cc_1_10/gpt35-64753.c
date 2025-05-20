//FormAI DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a person
typedef struct {
    int id;
    char name[20];
    int age;
} Person;

// Define a struct for the database
typedef struct {
    int size;
    Person** data;
} Database;

// Function to create a new person
Person* create_person(int id, char* name, int age) {
    Person* p = (Person*) malloc(sizeof(Person));
    p->id = id;
    strcpy(p->name, name);
    p->age = age;
    return p;
}

// Function to add a person to the database
void add_person(Database* db, Person* p) {
    db->data = realloc(db->data, (db->size + 1) * sizeof(Person*));
    db->data[db->size] = p;
    db->size++;
}

// Function to find a person in the database
Person* find_person(Database* db, int id) {
    int i;
    for(i = 0; i < db->size; i++) {
        if(db->data[i]->id == id) {
            return db->data[i];
        }
    }
    return NULL;
}

int main() {

    printf("Welcome to the Curious Database Simulation Program!\n");

    // Create a new empty database
    Database db;
    db.size = 0;
    db.data = NULL;

    // Add some people to the database
    Person* p1 = create_person(1, "Alice", 25);
    add_person(&db, p1);

    Person* p2 = create_person(2, "Bob", 30);
    add_person(&db, p2);

    Person* p3 = create_person(3, "Charlie", 35);
    add_person(&db, p3);

    // Find a person in the database
    int search_id = 2;
    Person* search_person = find_person(&db, search_id);
    if(search_person != NULL) {
        printf("Found person with ID %d: %s, %d years old\n", search_person->id, search_person->name, search_person->age);
    } else {
        printf("Person with ID %d not found in database\n", search_id);
    }

    // Free memory for the database
    int i;
    for(i = 0; i < db.size; i++) {
        free(db.data[i]);
    }
    free(db.data);

    return 0;
}