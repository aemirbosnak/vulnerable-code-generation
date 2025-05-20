//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
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
    db->num_cols = 0;
}

void destroy_database(Database *db) {
    free(db->data);
}

void add_record(Database *db, char *name, int age, float salary) {
    Record *record = &db->data[db->num_rows];
    strcpy(record->name, name);
    record->age = age;
    record->salary = salary;
    db->num_rows++;
}

int search_record(Database *db, char *name) {
    for (int i = 0; i < db->num_rows; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void print_record(Record *record) {
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    printf("Salary: $%.2f\n", record->salary);
}

int main() {
    Database db;
    create_database(&db);

    add_record(&db, "John Doe", 30, 50000.0);
    add_record(&db, "Jane Smith", 25, 45000.0);

    int index = search_record(&db, "John Doe");
    if (index!= -1) {
        print_record(&db.data[index]);
    }

    destroy_database(&db);

    return 0;
}