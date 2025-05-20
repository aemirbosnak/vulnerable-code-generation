//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char name[MAX_DATA_SIZE];
    int age;
    float salary;
} Employee;

typedef struct {
    Employee data[MAX_ROWS][MAX_COLS];
    int num_rows;
    int num_cols;
} Database;

Database* create_database() {
    Database* db = (Database*) malloc(sizeof(Database));
    db->num_rows = 0;
    db->num_cols = 0;
    return db;
}

void destroy_database(Database* db) {
    free(db);
}

void add_row(Database* db) {
    db->num_rows++;
}

void add_col(Database* db) {
    db->num_cols++;
}

void print_database(Database* db) {
    int i, j;
    for (i = 0; i < db->num_rows; i++) {
        for (j = 0; j < db->num_cols; j++) {
            printf("%s %d %.2f\n", db->data[i][j].name, db->data[i][j].age, db->data[i][j].salary);
        }
    }
}

int main() {
    Database* db = create_database();
    add_row(db);
    add_col(db);

    Employee emp1 = {"John Doe", 25, 50000};
    Employee emp2 = {"Jane Smith", 30, 60000};
    Employee emp3 = {"Jim Brown", 35, 70000};

    db->data[0][0] = emp1;
    db->data[0][1] = emp2;
    db->data[1][0] = emp3;

    print_database(db);

    destroy_database(db);

    return 0;
}