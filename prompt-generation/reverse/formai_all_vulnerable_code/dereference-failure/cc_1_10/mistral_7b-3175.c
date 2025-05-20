//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define NUM_EMPLOYEES 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Employee;

int main() {
    Employee *employees, *temp;
    int i;

    // Allocate memory for an array of Employee pointers
    employees = (Employee*) malloc(NUM_EMPLOYEES * sizeof(Employee*));

    if (employees == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    // Allocate memory for each Employee and initialize their data
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        employees[i] = (Employee) {
            .age = i + 1,
            .salary = 500.0 + (float)i * 100.0
        };
        strcpy(employees[i].name, ("Employee")[i]);
    }

    // Display employee information
    printf("\nEmployee Information:\n");
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        printf("\nName: %s", employees[i].name);
        printf("\nAge: %d", employees[i].age);
        printf("\nSalary: $%.2f", employees[i].salary);
    }

    // Free memory for each Employee
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        temp = &employees[i];
        free(temp);
    }

    // Free memory for the array of Employee pointers
    free(employees);

    printf("\nMemory has been freed.\n");

    return 0;
}