//Gemma-7B DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store employee information
typedef struct Employee
{
    char name[50];
    int id;
    double salary;
    struct Employee* next;
} Employee;

// Function to insert an employee at the end
void insertEmployee(Employee** head, char* name, int id, double salary)
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmployee->name, name);
    newEmployee->id = id;
    newEmployee->salary = salary;
    newEmployee->next = NULL;

    if (*head == NULL)
    {
        *head = newEmployee;
    }
    else
    {
        (*head)->next = newEmployee;
    }
}

// Function to find an employee by ID
Employee* findEmployee(Employee* head, int id)
{
    Employee* currentEmployee = head;

    while (currentEmployee)
    {
        if (currentEmployee->id == id)
        {
            return currentEmployee;
        }
        currentEmployee = currentEmployee->next;
    }

    return NULL;
}

// Function to update an employee's salary
void updateEmployeeSalary(Employee* employee, double newSalary)
{
    employee->salary = newSalary;
}

int main()
{
    Employee* head = NULL;

    // Insert some employees
    insertEmployee(&head, "John Doe", 1, 50000);
    insertEmployee(&head, "Jane Doe", 2, 60000);
    insertEmployee(&head, "Peter Pan", 3, 70000);

    // Find and update employee salary
    Employee* employee = findEmployee(head, 2);
    updateEmployeeSalary(employee, 80000);

    // Print updated employee salary
    printf("Employee name: %s, Salary: %lf\n", employee->name, employee->salary);

    return 0;
}