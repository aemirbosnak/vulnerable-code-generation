//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

typedef struct {
    Person **data;
    int num_rows;
    int num_cols;
} Database;

void create_database(Database *db) {
    db->data = (Person **)malloc(MAX_ROWS * sizeof(Person *));
    db->num_rows = 0;
    db->num_cols = 3;
}

void add_row(Database *db, char *name, int age, char *email) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->email = strdup(email);
    db->data[db->num_rows++] = person;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        Person *person = db->data[i];
        printf("%s, %d, %s\n", person->name, person->age, person->email);
    }
}

void delete_row(Database *db, int row) {
    if (row >= 0 && row < db->num_rows) {
        Person *person = db->data[row];
        free(person->name);
        free(person->email);
        free(person);
        for (int i = row; i < db->num_rows - 1; i++) {
            db->data[i] = db->data[i + 1];
        }
        db->num_rows--;
    }
}

int main() {
    Database db;
    create_database(&db);
    add_row(&db, "John Doe", 30, "john@example.com");
    add_row(&db, "Jane Doe", 28, "jane@example.com");
    print_database(&db);
    delete_row(&db, 1);
    print_database(&db);
    return 0;
}