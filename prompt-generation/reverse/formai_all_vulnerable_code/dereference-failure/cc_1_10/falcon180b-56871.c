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
    int num_rows;
    int num_cols;
    Record **data;
} Database;

Database *create_database(int num_rows, int num_cols) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = (Record **)malloc(num_rows * sizeof(Record *));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = (Record *)malloc(num_cols * sizeof(Record));
    }
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            if (db->data[i][j].name!= NULL) {
                free(db->data[i][j].name);
            }
        }
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

int add_record(Database *db, int row, int col, char *name, int age, float salary) {
    if (row >= db->num_rows || col >= db->num_cols) {
        return -1;
    }
    db->data[row][col].name = strdup(name);
    db->data[row][col].age = age;
    db->data[row][col].salary = salary;
    return 0;
}

int get_record(Database *db, int row, int col, char **name, int *age, float *salary) {
    if (row >= db->num_rows || col >= db->num_cols) {
        return -1;
    }
    *name = db->data[row][col].name;
    *age = db->data[row][col].age;
    *salary = db->data[row][col].salary;
    return 0;
}

int main() {
    Database *db = create_database(3, 3);
    add_record(db, 0, 0, "John", 30, 50000);
    add_record(db, 1, 0, "Jane", 28, 45000);
    add_record(db, 2, 0, "Bob", 25, 40000);
    char *name;
    int age;
    float salary;
    get_record(db, 0, 0, &name, &age, &salary);
    printf("Name: %s, Age: %d, Salary: %.2f\n", name, age, salary);
    destroy_database(db);
    return 0;
}