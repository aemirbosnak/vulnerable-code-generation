//Falcon-180B DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LENGTH 100

typedef struct {
    char name[MAX_DATA_LENGTH];
    int age;
    float salary;
} employee;

typedef struct {
    employee data[MAX_ROWS][MAX_COLS];
    int num_rows;
    int num_cols;
} database;

database* create_database() {
    database* db = (database*) malloc(sizeof(database));
    db->num_rows = 0;
    db->num_cols = 0;
    return db;
}

void destroy_database(database* db) {
    free(db);
}

void add_row(database* db) {
    db->num_rows++;
}

void add_col(database* db) {
    db->num_cols++;
}

void add_data(database* db, int row, int col, char* name, int age, float salary) {
    strcpy(db->data[row][col].name, name);
    db->data[row][col].age = age;
    db->data[row][col].salary = salary;
}

void print_database(database* db) {
    int i, j;
    for (i = 0; i < db->num_rows; i++) {
        for (j = 0; j < db->num_cols; j++) {
            printf("%s %d %.2f\n", db->data[i][j].name, db->data[i][j].age, db->data[i][j].salary);
        }
    }
}

void select_data(database* db, char* name) {
    int i, j;
    for (i = 0; i < db->num_rows; i++) {
        for (j = 0; j < db->num_cols; j++) {
            if (strcmp(db->data[i][j].name, name) == 0) {
                printf("%s %d %.2f\n", db->data[i][j].name, db->data[i][j].age, db->data[i][j].salary);
            }
        }
    }
}

int main() {
    database* db = create_database();
    add_row(db);
    add_col(db);
    add_data(db, 0, 0, "Sir William", 45, 5000.50);
    add_data(db, 0, 1, "Lady Isabella", 40, 4000.25);
    print_database(db);
    select_data(db, "Sir William");
    destroy_database(db);
    return 0;
}