//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 1000
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
    db->data = (Record *) malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_cols = 3;
}

void add_record(Database *db, char *name, int age, float salary) {
    Record *record = (Record *) malloc(sizeof(Record));
    record->name = name;
    record->age = age;
    record->salary = salary;
    db->data[db->num_rows++] = *record;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("%s %d %.2f\n", db->data[i].name, db->data[i].age, db->data[i].salary);
    }
}

int main() {
    Database db;
    create_database(&db);

    add_record(&db, "John Doe", 25, 50000);
    add_record(&db, "Jane Smith", 30, 60000);
    add_record(&db, "Bob Johnson", 40, 70000);

    print_database(&db);

    return 0;
}