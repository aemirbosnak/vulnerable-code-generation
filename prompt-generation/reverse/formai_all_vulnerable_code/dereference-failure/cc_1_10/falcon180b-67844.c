//Falcon-180B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

void createEmployee(Employee *emp) {
    emp->name = (char *)malloc(MAX_SIZE * sizeof(char));
    printf("Enter the name of the employee: ");
    scanf("%s", emp->name);

    printf("Enter the age of the employee: ");
    scanf("%d", &emp->age);

    printf("Enter the salary of the employee: ");
    scanf("%f", &emp->salary);
}

void displayEmployee(Employee emp) {
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n", emp.salary);
}

void deleteEmployee(Employee *emp) {
    free(emp->name);
    emp->name = NULL;
}

int main() {
    Employee emp;
    int choice, i;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Create Employee\n");
        printf("2. Display Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createEmployee(&emp);
                break;
            case 2:
                displayEmployee(emp);
                break;
            case 3:
                deleteEmployee(&emp);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice!= 4);

    return 0;
}