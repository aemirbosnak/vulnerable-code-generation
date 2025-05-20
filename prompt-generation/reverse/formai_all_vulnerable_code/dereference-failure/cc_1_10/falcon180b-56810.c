//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    float salary;
} Record;

typedef struct {
    Record *data;
    int num_rows;
    int num_cols;
} Database;

Database *create_database() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->data = (Record *)malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_cols = 3;
    return db;
}

void add_record(Database *db, char *name, int age, float salary) {
    Record *record = (Record *)malloc(sizeof(Record));
    record->name = strdup(name);
    record->age = age;
    record->salary = salary;
    db->data[db->num_rows++] = *record;
}

void print_database(Database *db) {
    printf("+----+----------------+----------------+\n");
    printf("| ID | Name            | Age            |\n");
    printf("+----+----------------+----------------+\n");
    for (int i = 0; i < db->num_rows; i++) {
        printf("| %d | %s            | %d            |\n", i + 1, db->data[i].name, db->data[i].age);
    }
    printf("+----+----------------+----------------+\n");
}

int main() {
    Database *db = create_database();
    add_record(db, "John Doe", 30, 50000.0);
    add_record(db, "Jane Smith", 28, 60000.0);
    add_record(db, "Bob Johnson", 25, 70000.0);
    print_database(db);
    return 0;
}