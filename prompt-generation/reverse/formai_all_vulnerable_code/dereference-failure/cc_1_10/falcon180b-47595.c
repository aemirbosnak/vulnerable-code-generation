//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ROWS 1000
#define MAX_COLS 1000

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

void create_database(Database *db, int num_rows, int num_cols) {
    db->data = (Record *)malloc(num_rows * sizeof(Record));
    db->num_rows = num_rows;
    db->num_cols = num_cols;

    for (int i = 0; i < num_rows; i++) {
        sprintf(db->data[i].name, "Record %d", i + 1);
        db->data[i].age = i + 1;
        db->data[i].salary = (float)i * 1000;
    }
}

void print_database(Database *db) {
    printf("Database:\n");
    for (int i = 0; i < db->num_rows; i++) {
        printf("Name: %s\n", db->data[i].name);
        printf("Age: %d\n", db->data[i].age);
        printf("Salary: $%.2f\n\n", db->data[i].salary);
    }
}

void destroy_database(Database *db) {
    free(db->data);
}

int main() {
    Database db;
    create_database(&db, 10, 3);
    print_database(&db);
    destroy_database(&db);

    return 0;
}