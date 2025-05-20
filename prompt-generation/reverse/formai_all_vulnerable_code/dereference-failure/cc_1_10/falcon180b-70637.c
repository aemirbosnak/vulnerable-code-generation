//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person **rows;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->rows = (Person **)malloc(sizeof(Person *) * MAX_ROWS);
    db->num_rows = 0;
    db->num_cols = 2;
}

void add_row(Database *db, char *name, int age) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;

    db->rows[db->num_rows] = person;
    db->num_rows++;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("%s %d\n", db->rows[i]->name, db->rows[i]->age);
    }
}

int main() {
    Database db;
    init_database(&db);

    add_row(&db, "John", 25);
    add_row(&db, "Jane", 30);
    add_row(&db, "Bob", 40);

    print_database(&db);

    return 0;
}