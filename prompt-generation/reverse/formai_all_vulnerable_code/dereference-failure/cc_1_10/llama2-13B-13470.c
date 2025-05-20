//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: peaceful
// Peaceful Database Simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structure
typedef struct {
    char name[50];
    int age;
    float salary;
} employee;

// Define database functions
employee *create_employee(char *name, int age, float salary) {
    employee *emp = (employee *)malloc(sizeof(employee));
    strcpy(emp->name, name);
    emp->age = age;
    emp->salary = salary;
    return emp;
}

void display_employee(employee *emp) {
    printf("Name: %s\nAge: %d\nSalary: %f\n", emp->name, emp->age, emp->salary);
}

void add_employee(employee **database, employee *emp) {
    int i = 0;
    while (database[i]) {
        if (strcmp(database[i]->name, emp->name) > 0) {
            break;
        }
        i++;
    }
    database[i] = emp;
}

void remove_employee(employee **database, char *name) {
    int i = 0;
    while (database[i]) {
        if (strcmp(database[i]->name, name) == 0) {
            free(database[i]);
            database[i] = NULL;
            break;
        }
        i++;
    }
}

void update_employee(employee **database, char *name, int age, float salary) {
    int i = 0;
    while (database[i]) {
        if (strcmp(database[i]->name, name) == 0) {
            database[i]->age = age;
            database[i]->salary = salary;
            break;
        }
        i++;
    }
}

int main() {
    srand(time(NULL));

    // Create a new database
    employee *database[5];
    for (int i = 0; i < 5; i++) {
        database[i] = create_employee("Person", rand() % 50 + 20, rand() % 1000 + 500);
    }

    // Display the database
    for (int i = 0; i < 5; i++) {
        display_employee(database[i]);
    }

    // Add some employees
    employee *john = create_employee("John", 30, 80000);
    employee *jane = create_employee("Jane", 25, 60000);
    add_employee(database, john);
    add_employee(database, jane);

    // Remove an employee
    remove_employee(database, "John");

    // Update an employee's salary
    update_employee(database, "Jane", 30, 90000);

    // Display the updated database
    for (int i = 0; i < 5; i++) {
        display_employee(database[i]);
    }

    return 0;
}