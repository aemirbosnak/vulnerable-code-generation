//Gemma-7B DATASET v1.0 Category: Database querying ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct employee {
    char name[50];
    int id;
    float salary;
    struct employee* next;
} employee;

// Function to insert a new employee into the database
void insertEmployee(employee** head) {
    // Allocate memory for the new employee
    employee* newEmployee = (employee*)malloc(sizeof(employee));

    // Get the employee's name, id, and salary
    printf("Enter employee name: ");
    scanf("%s", newEmployee->name);

    printf("Enter employee id: ");
    scanf("%d", &newEmployee->id);

    printf("Enter employee salary: ");
    scanf("%f", &newEmployee->salary);

    // Insert the new employee into the database
    if (*head == NULL) {
        *head = newEmployee;
    } else {
        (*head)->next = newEmployee;
    }
    newEmployee->next = NULL;
}

// Function to search for an employee in the database
void searchEmployee(employee* head, char* name) {
    // Traverse the database to find the employee
    while (head) {
        if (strcmp(head->name, name) == 0) {
            // Print the employee's information
            printf("Employee name: %s\n", head->name);
            printf("Employee id: %d\n", head->id);
            printf("Employee salary: %.2f\n", head->salary);
            break;
        }
        head = head->next;
    }

    // If the employee is not found, print an error message
    if (head == NULL) {
        printf("Employee not found.\n");
    }
}

int main() {
    // Create a new employee database
    employee* head = NULL;

    // Insert some employees into the database
    insertEmployee(&head);
    insertEmployee(&head);
    insertEmployee(&head);

    // Search for an employee in the database
    searchEmployee(head, "John Doe");

    return 0;
}