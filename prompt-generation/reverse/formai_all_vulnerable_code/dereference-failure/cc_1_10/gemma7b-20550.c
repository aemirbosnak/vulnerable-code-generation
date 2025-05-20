//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store employee information
typedef struct Employee
{
    char name[50];
    int id;
    float salary;
    struct Employee* next;
} Employee;

// Create a linked list of employees
Employee* head = NULL;

// Function to add an employee to the linked list
void addEmployee(char* name, int id, float salary)
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmployee->name, name);
    newEmployee->id = id;
    newEmployee->salary = salary;
    newEmployee->next = NULL;

    if (head == NULL)
    {
        head = newEmployee;
    }
    else
    {
        head->next = newEmployee;
        head = newEmployee;
    }
}

// Function to print employee information
void printEmployees()
{
    Employee* currentEmployee = head;

    while (currentEmployee)
    {
        printf("Name: %s\n", currentEmployee->name);
        printf("ID: %d\n", currentEmployee->id);
        printf("Salary: %.2f\n", currentEmployee->salary);
        printf("\n");
        currentEmployee = currentEmployee->next;
    }
}

int main()
{
    // Add some employees
    addEmployee("John Doe", 123, 50000);
    addEmployee("Jane Doe", 456, 60000);
    addEmployee("Peter Pan", 789, 70000);

    // Print employee information
    printEmployees();

    return 0;
}