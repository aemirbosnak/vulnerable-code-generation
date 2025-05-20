//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 255

typedef struct Employee
{
    char name[MAX_NAME_LENGTH];
    int salary;
    struct Employee* next;
} Employee;

int main()
{
    Employee* head = NULL;
    Employee* tail = NULL;

    // Simulate a random number generator
    srand(time(NULL));

    // Create a few employees
    for (int i = 0; i < 10; i++)
    {
        Employee* newEmployee = (Employee*)malloc(sizeof(Employee));

        // Generate a random name
        newEmployee->name[0] = 'A' + rand() % 26;
        newEmployee->name[1] = rand() % 26;
        newEmployee->name[2] = '\0';

        // Assign a random salary
        newEmployee->salary = rand() % 10000;

        // Insert the new employee into the linked list
        if (head == NULL)
        {
            head = newEmployee;
            tail = newEmployee;
        }
        else
        {
            tail->next = newEmployee;
            tail = newEmployee;
        }
    }

    // Print the employees
    Employee* currentEmployee = head;
    while (currentEmployee)
    {
        printf("%s - %d\n", currentEmployee->name, currentEmployee->salary);
        currentEmployee = currentEmployee->next;
    }

    return 0;
}