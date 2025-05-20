//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->data = NULL;
    db->size = 0;
    db->capacity = 0;
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->size; i++) {
        free(db->data[i].name);
        free(db->data[i].email);
    }
    free(db->data);
    free(db);
}

void add_person(Database *db, char *name, char *email, int age) {
    if (db->size == db->capacity) {
        db->capacity = db->capacity * 2 + 1;
        db->data = realloc(db->data, sizeof(Person) * db->capacity);
    }
    db->data[db->size].name = strdup(name);
    db->data[db->size].email = strdup(email);
    db->data[db->size].age = age;
    db->size++;
}

void print_database(Database *db) {
    for (int i = 0; i < db->size; i++) {
        printf("%s (%s) - %d\n", db->data[i].name, db->data[i].email, db->data[i].age);
    }
}

int main() {
    Database *db = create_database();

    add_person(db, "John Smith", "john.smith@example.com", 30);
    add_person(db, "Jane Doe", "jane.doe@example.com", 25);
    add_person(db, "Peter Parker", "peter.parker@example.com", 18);

    print_database(db);

    destroy_database(db);

    return 0;
}