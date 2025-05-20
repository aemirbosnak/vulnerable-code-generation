//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    double salary;
} Employee;

typedef struct {
    Employee rows[MAX_ROWS];
    int num_rows;
    int num_cols;
} Database;

Database* create_database(int num_cols) {
    Database* db = malloc(sizeof(Database));
    db->num_rows = 0;
    db->num_cols = num_cols;
    return db;
}

void destroy_database(Database* db) {
    free(db);
}

int add_row(Database* db, Employee employee) {
    if (db->num_rows >= MAX_ROWS) {
        return -1;
    }

    db->rows[db->num_rows++] = employee;
    return 0;
}

int get_row(Database* db, int row_index, Employee* employee) {
    if (row_index < 0 || row_index >= db->num_rows) {
        return -1;
    }

    *employee = db->rows[row_index];
    return 0;
}

int update_row(Database* db, int row_index, Employee employee) {
    if (row_index < 0 || row_index >= db->num_rows) {
        return -1;
    }

    db->rows[row_index] = employee;
    return 0;
}

int delete_row(Database* db, int row_index) {
    if (row_index < 0 || row_index >= db->num_rows) {
        return -1;
    }

    for (int i = row_index; i < db->num_rows - 1; i++) {
        db->rows[i] = db->rows[i + 1];
    }

    db->num_rows--;
    return 0;
}

void print_database(Database* db) {
    printf("Database:\n");
    for (int i = 0; i < db->num_rows; i++) {
        Employee employee = db->rows[i];
        printf("%s | %d | %.2f\n", employee.name, employee.age, employee.salary);
    }
}

int main() {
    Database* db = create_database(3);

    Employee employee1 = {"John Doe", 30, 50000.00};
    add_row(db, employee1);

    Employee employee2 = {"Jane Doe", 25, 40000.00};
    add_row(db, employee2);

    Employee employee3 = {"Bob Smith", 40, 60000.00};
    add_row(db, employee3);

    print_database(db);

    Employee employee;
    get_row(db, 1, &employee);
    printf("Employee at row 1: %s | %d | %.2f\n", employee.name, employee.age, employee.salary);

    employee.age = 35;
    update_row(db, 1, employee);
    print_database(db);

    delete_row(db, 1);
    print_database(db);

    destroy_database(db);

    return 0;
}