//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

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

void create_table(Database *db, char *name, int num_cols) {
    db->num_rows = 0;
    db->num_cols = num_cols;
    db->data = malloc(sizeof(Record) * MAX_ROWS);
    memset(db->data, 0, sizeof(Record) * MAX_ROWS);
}

void add_row(Database *db, Record row) {
    db->data[db->num_rows++] = row;
}

void print_table(Database *db) {
    printf("+---+------------------+------------------+\n");
    printf("| %10s | %20s | %20s |\n", "Name", "Age", "Salary");
    printf("+---+------------------+------------------+\n");

    for (int i = 0; i < db->num_rows; i++) {
        printf("| %10s | %20d | %20.2f |\n", db->data[i].name, db->data[i].age, db->data[i].salary);
    }

    printf("+---+------------------+------------------+\n");
}

int main() {
    Database db;
    create_table(&db, "Employees", 3);

    Record row1 = {"John Doe", 30, 50000};
    Record row2 = {"Jane Smith", 28, 55000};
    Record row3 = {"Jim Brown", 35, 60000};

    add_row(&db, row1);
    add_row(&db, row2);
    add_row(&db, row3);

    print_table(&db);

    return 0;
}