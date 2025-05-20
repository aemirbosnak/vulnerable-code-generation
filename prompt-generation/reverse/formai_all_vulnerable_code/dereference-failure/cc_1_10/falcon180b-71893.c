//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
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
    Record **data;
    int num_rows;
    int num_cols;
} Database;

Database* create_database(int num_rows, int num_cols) {
    Database *db = (Database*) malloc(sizeof(Database));
    db->data = (Record**) malloc(sizeof(Record*) * num_rows);
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = (Record*) malloc(sizeof(Record) * num_cols);
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            free(db->data[i][j].name);
        }
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void add_record(Database *db, int row, int col, char *name, int age, float salary) {
    Record *record = (Record*) malloc(sizeof(Record));
    record->name = strdup(name);
    record->age = age;
    record->salary = salary;
    db->data[row][col] = *record;
    free(record);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%s\t", db->data[i][j].name);
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database(3, 3);
    add_record(db, 0, 0, "John Doe", 30, 50000);
    add_record(db, 1, 0, "Jane Smith", 28, 60000);
    add_record(db, 2, 0, "Bob Johnson", 25, 70000);
    print_database(db);
    destroy_database(db);
    return 0;
}