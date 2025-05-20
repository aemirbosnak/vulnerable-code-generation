//FormAI DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    double salary;
} Employee;

void add_employee_to_database(Employee** database, int* database_length) {
    // Allocate memory for new employee
    Employee* new_employee = malloc(sizeof(Employee));

    // Prompt user for employee information
    printf("Enter the employee's name: ");
    scanf("%s", new_employee->name);
    printf("Enter the employee's age: ");
    scanf("%d", &new_employee->age);
    printf("Enter the employee's salary: ");
    scanf("%lf", &new_employee->salary);

    // Expand the database array to accommodate the new employee
    *database_length += 1;
    *database = realloc(*database, *database_length * sizeof(Employee));

    // Add the new employee to the end of the database
    (*database)[*database_length - 1] = *new_employee;

    // Free the memory for the new_employee struct
    free(new_employee);

    printf("\nEmployee added to database!\n\n");
}

void delete_employee_from_database(Employee** database, int* database_length, char* name) {
    int index = -1;
    for (int i = 0; i < *database_length; i++) {
        if (strcmp((*database)[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: employee \"%s\" not found in database.\n\n", name);
        return;
    }

    // Shift all employees after this one left by one index
    for (int i = index; i < *database_length - 1; i++) {
        (*database)[i] = (*database)[i+1];
    }

    // Shrink the database array to remove the last employee
    *database_length -= 1;
    *database = realloc(*database, *database_length * sizeof(Employee));

    printf("\nEmployee \"%s\" deleted from database.\n\n", name);
}

void print_database(Employee* database, int database_length) {
    for (int i = 0; i < database_length; i++) {
        printf("Name: %s\nAge: %d\nSalary: %.2lf\n\n", database[i].name, database[i].age, database[i].salary);
    }
}

int main() {
    Employee* database = NULL;
    int database_length = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Add employee to database\n");
        printf("2. Delete employee from database\n");
        printf("3. Print database\n");
        printf("4. Exit program\n\n");
        printf("Enter option (1-4): ");

        int option;
        scanf("%d", &option);

        printf("\n");

        if (option == 1) {
            add_employee_to_database(&database, &database_length);
        } else if (option == 2) {
            char name[20];
            printf("Enter the name of the employee to delete: ");
            scanf("%s", name);
            delete_employee_from_database(&database, &database_length, name);
        } else if (option == 3) {
            if (database_length == 0) {
                printf("There are no employees in the database.\n\n");
            } else {
                print_database(database, database_length);
            }
        } else if (option == 4) {
            break;
        } else {
            printf("Invalid option. Please enter a number between 1 and 4.\n\n");
        }
    }

    free(database);

    return 0;
}