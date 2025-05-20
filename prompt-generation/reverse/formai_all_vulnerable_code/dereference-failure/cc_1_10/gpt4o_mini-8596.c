//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float salary;
} Employee;

Employee* employees[MAX_EMPLOYEES];
int employee_count = 0;

void add_employee(int id, const char* name, float salary) {
    if (employee_count < MAX_EMPLOYEES) {
        Employee* new_employee = (Employee*)malloc(sizeof(Employee));
        new_employee->id = id;
        strncpy(new_employee->name, name, NAME_LENGTH - 1);
        new_employee->name[NAME_LENGTH - 1] = '\0';  // Ensure null-termination
        new_employee->salary = salary;
        employees[employee_count++] = new_employee;
        printf("Employee added: %d, %s, %.2f\n", id, name, salary);
    } else {
        printf("Employee database is full. Cannot add more employees.\n");
    }
}

void display_employees() {
    printf("\nEmployee Records:\n");
    printf("ID\tName\t\tSalary\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < employee_count; i++) {
        printf("%d\t%s\t\t%.2f\n", employees[i]->id, employees[i]->name, employees[i]->salary);
    }
}

int search_employee(int id) {
    for (int i = 0; i < employee_count; i++) {
        if (employees[i]->id == id) {
            return i;  // Return index of found employee
        }
    }
    return -1;  // Not found
}

void delete_employee(int id) {
    int index = search_employee(id);
    if (index != -1) {
        free(employees[index]);
        employees[index] = employees[employee_count - 1];  // Move the last one to the deleted spot
        employees[employee_count - 1] = NULL;  // Clear the last pointer
        employee_count--;
        printf("Employee with ID %d deleted.\n", id);
    } else {
        printf("Employee with ID %d not found.\n", id);
    }
}

void cleanup() {
    for (int i = 0; i < employee_count; i++) {
        free(employees[i]);
    }
    employee_count = 0;
}

int main() {
    int choice, id;
    char name[NAME_LENGTH];
    float salary;

    while (1) {
        printf("\n--- Employee Database Menu ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                printf("Enter Employee Name: ");
                getchar(); // Clear newline from input buffer
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                printf("Enter Employee Salary: ");
                scanf("%f", &salary);
                add_employee(id, name, salary);
                break;

            case 2:
                display_employees();
                break;

            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                int search_index = search_employee(id);
                if (search_index != -1) {
                    printf("Employee found: ID: %d, Name: %s, Salary: %.2f\n",
                           employees[search_index]->id,
                           employees[search_index]->name,
                           employees[search_index]->salary);
                } else {
                    printf("Employee with ID %d not found.\n", id);
                }
                break;

            case 4:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                delete_employee(id);
                break;

            case 5:
                cleanup();
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}