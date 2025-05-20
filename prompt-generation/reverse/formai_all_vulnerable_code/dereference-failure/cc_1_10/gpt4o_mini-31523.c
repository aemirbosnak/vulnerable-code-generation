//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee* next;
} Employee;

Employee* head = NULL;

void addEmployee(int id, const char* name, float salary) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    newEmployee->salary = salary;
    newEmployee->next = head;
    head = newEmployee;
    printf("Employee added successfully!\n");
}

void viewEmployees() {
    Employee* current = head;
    if (current == NULL) {
        printf("No employees found.\n");
        return;
    }
    printf("Employee List:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", current->id, current->name, current->salary);
        current = current->next;
    }
}

void deleteEmployee(int id) {
    Employee* current = head;
    Employee* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        head = current->next; // If the employee to delete is the head
    } else {
        previous->next = current->next; // Bypass the current node
    }

    free(current);
    printf("Employee with ID %d deleted successfully!\n", id);
}

void freeMemory() {
    Employee* current = head;
    Employee* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int choice, id;
    char name[50];
    float salary;

    while (1) {
        printf("Employee Database Menu:\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                printf("Enter Employee Name: ");
                scanf("%s", name);
                printf("Enter Employee Salary: ");
                scanf("%f", &salary);
                addEmployee(id, name, salary);
                break;
            case 2:
                viewEmployees();
                break;
            case 3:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(id);
                break;
            case 4:
                freeMemory(); // Clean up memory before exiting
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}