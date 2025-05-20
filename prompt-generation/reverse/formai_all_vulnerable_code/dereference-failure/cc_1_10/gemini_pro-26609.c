//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

typedef struct {
    Employee *employees;
    int count;
    int capacity;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->employees = malloc(sizeof(Employee) * 10);
    db->count = 0;
    db->capacity = 10;
    return db;
}

void add_employee(Database *db, Employee *employee) {
    if (db->count == db->capacity) {
        db->employees = realloc(db->employees, sizeof(Employee) * db->capacity * 2);
        db->capacity *= 2;
    }
    db->employees[db->count++] = *employee;
}

Employee *get_employee(Database *db, char *name) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->employees[i].name, name) == 0) {
            return &db->employees[i];
        }
    }
    return NULL;
}

void print_database(Database *db) {
    for (int i = 0; i < db->count; i++) {
        printf("%s, %d, %.2f\n", db->employees[i].name, db->employees[i].age, db->employees[i].salary);
    }
}

int main() {
    Database *db = create_database();

    Employee emp1 = {"John", 30, 10000.00};
    Employee emp2 = {"Jane", 25, 12000.00};
    Employee emp3 = {"Bob", 40, 15000.00};

    add_employee(db, &emp1);
    add_employee(db, &emp2);
    add_employee(db, &emp3);

    print_database(db);

    Employee *emp4 = get_employee(db, "John");
    if (emp4 != NULL) {
        printf("Found employee: %s, %d, %.2f\n", emp4->name, emp4->age, emp4->salary);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}