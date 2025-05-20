//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: shocked
// The Ultimate Shocking Database Simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structures
typedef struct {
    char name[50];
    int age;
} person;

typedef struct {
    person *persons;
    int num_persons;
} database;

// Function to insert a person into the database
void insert_person(database *db, char *name, int age) {
    person *new_person = malloc(sizeof(person));
    strcpy(new_person->name, name);
    new_person->age = age;
    db->persons = realloc(db->persons, (db->num_persons + 1) * sizeof(person));
    db->persons[db->num_persons] = *new_person;
    db->num_persons++;
}

// Function to retrieve a person from the database
person *retrieve_person(database *db, char *name) {
    for (int i = 0; i < db->num_persons; i++) {
        if (strcmp(db->persons[i].name, name) == 0) {
            return &db->persons[i];
        }
    }
    return NULL;
}

// Function to update a person's information in the database
void update_person(database *db, char *name, int age) {
    person *person = retrieve_person(db, name);
    if (person != NULL) {
        person->age = age;
    }
}

// Function to delete a person from the database
void delete_person(database *db, char *name) {
    int i;
    for (i = 0; i < db->num_persons; i++) {
        if (strcmp(db->persons[i].name, name) == 0) {
            break;
        }
    }
    if (i < db->num_persons) {
        memmove(db->persons + i, db->persons + i + 1, (db->num_persons - i - 1) * sizeof(person));
        db->num_persons--;
    }
}

int main() {
    srand(time(NULL));
    database db;

    // Insert some people into the database
    insert_person(&db, "John", 25);
    insert_person(&db, "Jane", 30);
    insert_person(&db, "Bob", 35);

    // Retrieve and update a person's information
    person *john = retrieve_person(&db, "John");
    if (john != NULL) {
        john->age = rand() % 5 + 25;
        update_person(&db, "John", john->age);
    }

    // Delete a person from the database
    delete_person(&db, "Bob");

    // Print the updated database
    for (int i = 0; i < db.num_persons; i++) {
        printf("%d. %s (%d)\n", i + 1, db.persons[i].name, db.persons[i].age);
    }

    return 0;
}