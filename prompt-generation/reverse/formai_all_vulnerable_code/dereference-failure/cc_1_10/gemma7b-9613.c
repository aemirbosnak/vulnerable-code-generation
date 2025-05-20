//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Personal Finance Planner structure
typedef struct PersonalFinancePlanner
{
    char name[50];
    int age;
    double income;
    double expenses;
    double net_worth;
    struct PersonalFinancePlanner* next;
} PersonalFinancePlanner;

// Function to create a new Personal Finance Planner node
PersonalFinancePlanner* create_node(char* name, int age, double income, double expenses)
{
    PersonalFinancePlanner* new_node = (PersonalFinancePlanner*)malloc(sizeof(PersonalFinancePlanner));

    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->income = income;
    new_node->expenses = expenses;
    new_node->net_worth = income - expenses;
    new_node->next = NULL;

    return new_node;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(PersonalFinancePlanner* head, PersonalFinancePlanner* new_node)
{
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        PersonalFinancePlanner* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the Personal Finance Planner list
void print_list(PersonalFinancePlanner* head)
{
    PersonalFinancePlanner* current = head;
    while (current)
    {
        printf("%s, %d, %.2lf, %.2lf, %.2lf\n", current->name, current->age, current->income, current->expenses, current->net_worth);
        current = current->next;
    }
}

int main()
{
    // Create a new Personal Finance Planner node
    PersonalFinancePlanner* head = create_node("John Doe", 25, 50000, 20000);

    // Insert a new node at the end of the list
    insert_at_end(head, create_node("Jane Doe", 30, 60000, 30000));

    // Insert a new node at the end of the list
    insert_at_end(head, create_node("Peter Pan", 12, 20000, 10000));

    // Print the Personal Finance Planner list
    print_list(head);

    return 0;
}