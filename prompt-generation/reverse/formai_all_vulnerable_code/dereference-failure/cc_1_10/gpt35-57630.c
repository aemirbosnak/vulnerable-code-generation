//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Data structure to hold information about a person
typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
} Person;

// Data structure to hold information about a database
typedef struct {
    Person* data[MAX_SIZE];
    int size;
} Database;

// Function to add a person to the database
void add_person(Database* db, int id, char name[], int age) {
    Person* person = (Person*) malloc(sizeof(Person));
    person->id = id;
    strcpy(person->name, name);
    person->age = age;
    db->data[db->size++] = person;
}

// Function to delete a person from the database
void delete_person(Database* db, int id) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (db->data[i]->id == id) {
            free(db->data[i]);
            db->data[i] = NULL;
            int j;
            for (j = i; j < db->size-1; j++) {
                db->data[j] = db->data[j+1];
            }
            db->data[db->size-1] = NULL;
            db->size--;
            break;
        }
    }
}

// Function to print all people in the database
void print_database(Database* db) {
    int i;
    for (i = 0; i < db->size; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", 
                db->data[i]->id, db->data[i]->name, db->data[i]->age);
    }
}

int main() {
    // Initialize the database
    Database db;
    db.size = 0;

    // Add some people to the database
    add_person(&db, 1, "Alice", 25);
    add_person(&db, 2, "Bob", 30);
    add_person(&db, 3, "Charlie", 35);

    // Print the database
    printf("Initial database:\n");
    print_database(&db);

    // Delete a person from the database
    printf("\nDeleting Bob:\n");
    delete_person(&db, 2);
    print_database(&db);

    return 0;
}