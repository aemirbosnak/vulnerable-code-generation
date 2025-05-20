//Gemma-7B DATASET v1.0 Category: Database querying ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store employee information
typedef struct Employee
{
    char name[50];
    int age;
    float salary;
    struct Employee* next;
} Employee;

// Function to insert a new employee at the end
void insertEmployee(Employee* head, char* name, int age, float salary)
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmployee->name, name);
    newEmployee->age = age;
    newEmployee->salary = salary;
    newEmployee->next = NULL;

    if (head == NULL)
    {
        head = newEmployee;
    }
    else
    {
        Employee* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEmployee;
    }
}

// Function to search for an employee by name
Employee* searchEmployeeByName(Employee* head, char* name)
{
    Employee* temp = head;
    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    Employee* head = NULL;

    // Insert some employees
    insertEmployee(head, "John Doe", 25, 50000);
    insertEmployee(head, "Jane Doe", 30, 60000);
    insertEmployee(head, "Peter Pan", 12, 70000);

    // Search for an employee by name
    Employee* employee = searchEmployeeByName(head, "Jane Doe");

    // Print employee information
    if (employee)
    {
        printf("Name: %s\n", employee->name);
        printf("Age: %d\n", employee->age);
        printf("Salary: %.2f\n", employee->salary);
    }
    else
    {
        printf("Employee not found.\n");
    }

    return 0;
}