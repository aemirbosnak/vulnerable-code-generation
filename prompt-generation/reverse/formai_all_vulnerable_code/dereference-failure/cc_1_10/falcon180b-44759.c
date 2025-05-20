//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 50

typedef struct {
    char *name;
    int age;
    char *email;
} Record;

typedef struct {
    Record *data;
    int num_rows;
    int num_cols;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->data = malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_cols = 3;
    return db;
}

void add_row(Database *db, char *name, int age, char *email) {
    Record *row = malloc(sizeof(Record));
    row->name = name;
    row->age = age;
    row->email = email;
    db->data[db->num_rows++] = *row;
}

void print_row(Record *row) {
    printf("%s %d %s\n", row->name, row->age, row->email);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        print_row(&db->data[i]);
    }
}

int main() {
    Database *db = create_database();
    add_row(db, "John Doe", 30, "johndoe@gmail.com");
    add_row(db, "Jane Doe", 25, "janedoe@gmail.com");
    print_database(db);
    return 0;
}