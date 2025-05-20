//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: artistic
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
    int num_rows;
    int num_cols;
    Record **data;
} Database;

void init_database(Database *db) {
    db->num_rows = 0;
    db->num_cols = 0;
    db->data = NULL;
}

int add_record(Database *db, Record *rec) {
    int i;
    for (i = 0; i < db->num_rows; i++) {
        if (strcmp(db->data[i]->name, rec->name) == 0) {
            fprintf(stderr, "Error: Duplicate record found.\n");
            return -1;
        }
    }
    db->data[db->num_rows++] = rec;
    return 0;
}

int search_record(Database *db, char *name) {
    int i;
    for (i = 0; i < db->num_rows; i++) {
        if (strcmp(db->data[i]->name, name) == 0) {
            printf("Name: %s\n", db->data[i]->name);
            printf("Age: %d\n", db->data[i]->age);
            printf("Salary: $%.2f\n\n", db->data[i]->salary);
            return 0;
        }
    }
    fprintf(stderr, "Error: Record not found.\n");
    return -1;
}

int main() {
    Database db;
    init_database(&db);

    Record rec1 = {"John Doe", 25, 50000.00};
    Record rec2 = {"Jane Smith", 30, 60000.00};
    Record rec3 = {"John Doe", 25, 50000.00}; // Duplicate record

    add_record(&db, &rec1);
    add_record(&db, &rec2);
    add_record(&db, &rec3);

    search_record(&db, "John Doe");
    search_record(&db, "Jane Smith");
    search_record(&db, "Bob Johnson");

    return 0;
}