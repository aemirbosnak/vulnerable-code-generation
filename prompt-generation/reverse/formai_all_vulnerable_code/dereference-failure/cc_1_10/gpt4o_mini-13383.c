//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void addEmployee(Employee **employees, int *currentSize) {
    *currentSize += 1;
    *employees = realloc(*employees, (*currentSize) * sizeof(Employee));
    
    if (*employees == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    Employee *newEmployee = &(*employees)[*currentSize - 1];

    printf("Enter name: ");
    fgets(newEmployee->name, sizeof(newEmployee->name), stdin);
    newEmployee->name[strcspn(newEmployee->name, "\n")] = 0; // Remove newline

    printf("Enter age: ");
    scanf("%d", &newEmployee->age);
    
    printf("Enter salary: ");
    scanf("%f", &newEmployee->salary);
    getchar(); // Clear the newline character from buffer
}

void displayEmployees(Employee *employees, int size) {
    printf("\nEmployee List:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
}

void freeMemory(Employee *employees) {
    free(employees);
}

int main() {
    Employee *employees = NULL;
    int currentSize = 0;
    char choice;

    do {
        printf("\n1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        choice = getchar();
        getchar(); // Clear the newline character from buffer
        
        switch (choice) {
            case '1':
                addEmployee(&employees, &currentSize);
                break;
            case '2':
                displayEmployees(employees, currentSize);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '3');

    freeMemory(employees);
    return 0;
}