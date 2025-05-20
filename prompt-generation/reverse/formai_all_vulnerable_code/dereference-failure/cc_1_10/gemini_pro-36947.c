//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char address[50];
} Person;

typedef struct {
    Person *people;
    int size;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->people = NULL;
    db->size = 0;
    return db;
}

void add_person(Database *db, Person *person) {
    db->people = realloc(db->people, (db->size + 1) * sizeof(Person));
    db->people[db->size++] = *person;
}

void print_database(Database *db) {
    for (int i = 0; i < db->size; i++) {
        printf("Person %d:\n", i + 1);
        printf("Name: %s\n", db->people[i].name);
        printf("Age: %d\n", db->people[i].age);
        printf("Address: %s\n", db->people[i].address);
        printf("\n");
    }
}

void free_database(Database *db) {
    free(db->people);
    free(db);
}

int main() {
    Database *db = create_database();

    // Add some people to the database
    Person p1 = {"John Smith", 30, "123 Main Street"};
    add_person(db, &p1);
    Person p2 = {"Jane Doe", 25, "456 Elm Street"};
    add_person(db, &p2);
    Person p3 = {"Bill Jones", 40, "789 Oak Street"};
    add_person(db, &p3);

    // Print the database
    print_database(db);

    // Free the database
    free_database(db);

    return 0;
}