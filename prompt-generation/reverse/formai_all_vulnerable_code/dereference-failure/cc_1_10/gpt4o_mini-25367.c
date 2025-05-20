//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

Employee* createEmployee(const char* name, int age, float salary) {
    Employee* emp = (Employee*)malloc(sizeof(Employee));
    if (emp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(emp->name, name, sizeof(emp->name) - 1);
    emp->name[sizeof(emp->name) - 1] = '\0'; // Ensure null-termination
    emp->age = age;
    emp->salary = salary;
    return emp;
}

void displayEmployee(const Employee* emp) {
    if (emp != NULL) {
        printf("Employee Name: %s\n", emp->name);
        printf("Employee Age: %d\n", emp->age);
        printf("Employee Salary: %.2f\n", emp->salary);
    } else {
        printf("No employee to display.\n");
    }
}

void freeEmployee(Employee* emp) {
    free(emp);
}

void allocateAndDisplayEmployees(int count) {
    Employee** employees = (Employee**)malloc(count * sizeof(Employee*));
    if (employees == NULL) {
        fprintf(stderr, "Memory allocation failed for employees array\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        char name[50];
        printf("Enter name for employee %d: ", i + 1);
        scanf("%49s", name); // Avoid buffer overflow
        int age;
        printf("Enter age for employee %d: ", i + 1);
        scanf("%d", &age);
        float salary;
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salary);

        employees[i] = createEmployee(name, age, salary);
    }

    printf("\nDisplaying Employee Details:\n");
    for (int i = 0; i < count; i++) {
        displayEmployee(employees[i]);
    }

    for (int i = 0; i < count; i++) {
        freeEmployee(employees[i]);
    }
    free(employees);
}

int main() {
    int numOfEmployees;

    printf("Enter the number of employees you wish to add: ");
    scanf("%d", &numOfEmployees);
    
    if (numOfEmployees <= 0) {
        printf("Number of employees must be greater than zero.\n");
        return EXIT_FAILURE;
    }

    allocateAndDisplayEmployees(numOfEmployees);

    return EXIT_SUCCESS;
}