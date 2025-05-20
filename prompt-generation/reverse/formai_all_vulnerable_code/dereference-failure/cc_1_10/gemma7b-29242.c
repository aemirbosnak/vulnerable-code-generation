//Gemma-7B DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure named Employee
typedef struct Employee
{
    char name[50];
    int age;
    double salary;
    struct Employee* next;
} Employee;

// Function to insert a node at the end of a linked list
void insertAtEnd(Employee** head, Employee* newEmployee)
{
    if (*head == NULL)
    {
        *head = newEmployee;
    }
    else
    {
        (*head)->next = newEmployee;
        *head = newEmployee;
    }
}

// Function to print the employees in a linked list
void printEmployees(Employee* head)
{
    while (head)
    {
        printf("%s, %d, %.2lf\n", head->name, head->age, head->salary);
        head = head->next;
    }
}

int main()
{
    // Create a linked list of employees
    Employee* head = NULL;

    // Insert some employees
    insertAtEnd(&head, malloc(sizeof(Employee)));
    strcpy(head->name, "John Doe");
    head->age = 25;
    head->salary = 50000;

    insertAtEnd(&head, malloc(sizeof(Employee)));
    strcpy(head->next->name, "Jane Doe");
    head->next->age = 30;
    head->next->salary = 60000;

    insertAtEnd(&head, malloc(sizeof(Employee)));
    strcpy(head->next->next->name, "Peter Pan");
    head->next->next->age = 20;
    head->next->next->salary = 70000;

    // Print the employees in the linked list
    printEmployees(head);

    return 0;
}