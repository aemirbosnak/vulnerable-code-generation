//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 10

typedef struct {
    char *name;
    int age;
    float salary;
} Person;

typedef struct {
    Person **data;
    int num_rows;
    int num_columns;
} Database;

Database *create_database(int num_rows, int num_columns) {
    Database *db = malloc(sizeof(Database));
    db->data = malloc(sizeof(Person *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = malloc(sizeof(Person) * num_columns);
    }
    db->num_rows = num_rows;
    db->num_columns = num_columns;
    return db;
}

void free_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void insert_person(Database *db, int row, int column, Person person) {
    db->data[row][column] = person;
}

Person get_person(Database *db, int row, int column) {
    return db->data[row][column];
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_columns; j++) {
            Person person = get_person(db, i, j);
            printf("%s %d %.2f\n", person.name, person.age, person.salary);
        }
    }
}

int main() {
    Database *db = create_database(MAX_ROWS, MAX_COLUMNS);

    Person person1 = {"John Doe", 30, 100000.0};
    Person person2 = {"Jane Doe", 25, 80000.0};
    Person person3 = {"John Smith", 40, 120000.0};

    insert_person(db, 0, 0, person1);
    insert_person(db, 1, 0, person2);
    insert_person(db, 2, 0, person3);

    print_database(db);

    free_database(db);

    return 0;
}