//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: realistic
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

void create_database(Database *db) {
    db->data = (Record *)malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_cols = 3; // 3 columns: name, age, salary
}

void add_record(Database *db, char *name, int age, float salary) {
    if (db->num_rows >= MAX_ROWS) {
        printf("Error: database is full\n");
        return;
    }

    Record *new_record = (Record *)malloc(sizeof(Record));
    new_record->name = strdup(name);
    new_record->age = age;
    new_record->salary = salary;

    db->data[db->num_rows] = *new_record;
    db->num_rows++;
}

void print_records(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("%s %d %.2f\n", db->data[i].name, db->data[i].age, db->data[i].salary);
    }
}

int main() {
    Database db;
    create_database(&db);

    add_record(&db, "John Doe", 30, 50000);
    add_record(&db, "Jane Doe", 25, 45000);
    add_record(&db, "Bob Smith", 40, 70000);

    print_records(&db);

    return 0;
}