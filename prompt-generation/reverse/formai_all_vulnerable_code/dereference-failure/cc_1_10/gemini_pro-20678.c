//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *name;
    int age;
    bool is_active;
} Person;

typedef struct {
    Person *people;
    int count;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->people = malloc(sizeof(Person) * 10);
    db->count = 0;
    return db;
}

void destroy_database(Database *db) {
    free(db->people);
    free(db);
}

void add_person(Database *db, Person *person) {
    db->people[db->count++] = *person;
}

Person *get_person(Database *db, int index) {
    if (index < 0 || index >= db->count) {
        return NULL;
    }
    return &db->people[index];
}

void print_database(Database *db) {
    for (int i = 0; i < db->count; i++) {
        Person *person = &db->people[i];
        printf("Name: %s, Age: %d, Is Active: %d\n", person->name, person->age, person->is_active);
    }
}

int main() {
    Database *db = create_database();

    Person person1 = {"John Doe", 30, true};
    add_person(db, &person1);

    Person person2 = {"Jane Doe", 25, false};
    add_person(db, &person2);

    print_database(db);

    destroy_database(db);

    return 0;
}