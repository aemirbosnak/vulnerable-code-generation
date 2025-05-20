//FormAI DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    char address[50];
    char phone[15];
} Person;

typedef struct {
    Person **people;
    int count;
} Database;

Database *createDatabase() {
    Database *db = malloc(sizeof(Database));
    db->people = NULL;
    db->count = 0;
    return db;
}

void insertPerson(Database *db, Person *person) {
    db->count++;
    db->people = realloc(db->people, db->count * sizeof(Person *));
    db->people[db->count - 1] = person;
}

void printPerson(Person *person) {
    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Address: %s\n", person->address);
    printf("Phone number: %s\n", person->phone);
}

void printDatabase(Database *db) {
    for (int i = 0; i < db->count; i++) {
        printf("Person %d:\n", i+1);
        printPerson(db->people[i]);
    }
}

void deletePerson(Database *db, int id) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (db->people[i]->id == id) {
            free(db->people[i]);
            found = 1;
        }
        if (found && i+1 < db->count) {
            db->people[i] = db->people[i+1];
        }
    }
    if (found) {
        db->count--;
        db->people = realloc(db->people, db->count * sizeof(Person *));
    }
}

int main() {
    Database *db = createDatabase();

    // Add people to the database
    Person *p1 = malloc(sizeof(Person));
    p1->id = 1;
    strcpy(p1->name, "John Smith");
    p1->age = 25;
    strcpy(p1->address, "123 Main St");
    strcpy(p1->phone, "555-1234");
    insertPerson(db, p1);

    Person *p2 = malloc(sizeof(Person));
    p2->id = 2;
    strcpy(p2->name, "Jane Doe");
    p2->age = 30;
    strcpy(p2->address, "456 Elm St");
    strcpy(p2->phone, "555-5678");
    insertPerson(db, p2);

    // Print the contents of the database
    printf("Database before deletion:\n");
    printDatabase(db);

    // Delete a person
    deletePerson(db, 1);

    // Print the contents of the database again
    printf("Database after deletion:\n");
    printDatabase(db);

    return 0;
}