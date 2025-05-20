//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store employee information
typedef struct Employee {
    char name[50];
    int age;
    double salary;
    struct Employee* next;
} Employee;

// Function to insert a new employee at the end
void insertEmployee(Employee* head) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    printf("Enter name: ");
    scanf("%s", newEmployee->name);
    printf("Enter age: ");
    scanf("%d", &newEmployee->age);
    printf("Enter salary: ");
    scanf("%lf", &newEmployee->salary);

    if (head == NULL) {
        head = newEmployee;
    } else {
        Employee* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEmployee;
    }
}

// Function to print all employees
void printEmployees(Employee* head) {
    Employee* temp = head;
    while (temp) {
        printf("%s, %d, %.2lf\n", temp->name, temp->age, temp->salary);
        temp = temp->next;
    }
}

int main() {
    Employee* head = NULL;

    // Insert a few employees
    insertEmployee(head);
    insertEmployee(head);
    insertEmployee(head);

    // Print all employees
    printEmployees(head);

    return 0;
}