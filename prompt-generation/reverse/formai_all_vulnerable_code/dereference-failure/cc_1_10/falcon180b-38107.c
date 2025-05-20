//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    char *address;
    char *phone;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} Database;

void initialize_database(Database *db) {
    db->data = NULL;
    db->size = 0;
    db->capacity = 0;
}

int is_database_empty(Database *db) {
    return db->size == 0;
}

void add_person(Database *db, char *name, char *address, char *phone) {
    if (db->size >= db->capacity) {
        db->capacity += 10;
        db->data = realloc(db->data, db->capacity * sizeof(Person));
    }

    Person *person = &db->data[db->size];
    person->name = strdup(name);
    person->address = strdup(address);
    person->phone = strdup(phone);

    db->size++;
}

void print_database(Database *db) {
    if (is_database_empty(db)) {
        printf("Database is empty.\n");
        return;
    }

    printf("Name\tAddress\tPhone\n");
    for (int i = 0; i < db->size; i++) {
        Person *person = &db->data[i];
        printf("%s\t%s\t%s\n", person->name, person->address, person->phone);
    }
}

int main() {
    Database db;
    initialize_database(&db);

    add_person(&db, "John Doe", "123 Main St.", "555-1234");
    add_person(&db, "Jane Smith", "456 Elm Ave.", "555-5678");

    print_database(&db);

    return 0;
}