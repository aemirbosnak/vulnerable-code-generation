//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int my_age = 24;
    float my_salary = 50000;
    char my_occupation[] = "Software Engineer";
    struct personal_finance
    {
        char name[50];
        int age;
        float salary;
        char occupation[50];
        struct personal_finance* next;
    } *my_finance = NULL;

    // Allocate memory for the first node
    my_finance = (struct personal_finance*)malloc(sizeof(struct personal_finance));

    // Initialize the first node
    strcpy(my_finance->name, "Romeo");
    my_finance->age = 24;
    my_finance->salary = 50000;
    strcpy(my_finance->occupation, "Software Engineer");

    // Create a linked list
    struct personal_finance* tail = my_finance;

    // Allocate memory for the second node
    my_finance = (struct personal_finance*)malloc(sizeof(struct personal_finance));

    // Initialize the second node
    strcpy(my_finance->name, "Juliet");
    my_finance->age = 21;
    my_finance->salary = 60000;
    strcpy(my_finance->occupation, "Nurse");

    // Append the second node to the linked list
    tail->next = my_finance;
    tail = my_finance;

    // Print the linked list
    struct personal_finance* current = my_finance;
    while (current)
    {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Salary: %.2f\n", current->salary);
        printf("Occupation: %s\n", current->occupation);
        printf("\n");
        current = current->next;
    }

    return 0;
}