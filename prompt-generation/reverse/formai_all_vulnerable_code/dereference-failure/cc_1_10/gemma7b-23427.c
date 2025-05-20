//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct PersonalFinance
{
    char name[50];
    int age;
    double income;
    double expenses;
    double networth;
    struct PersonalFinance* next;
};

void createPersonalFinance(struct PersonalFinance** head)
{
    *head = (struct PersonalFinance*)malloc(sizeof(struct PersonalFinance));
    (*head)->name[0] = '\0';
    (*head)->age = 0;
    (*head)->income = 0.0;
    (*head)->expenses = 0.0;
    (*head)->networth = 0.0;
    (*head)->next = NULL;
}

void addPersonalFinance(struct PersonalFinance** head, char* name, int age, double income, double expenses, double networth)
{
    struct PersonalFinance* new_node = (struct PersonalFinance*)malloc(sizeof(struct PersonalFinance));
    new_node->name[0] = '\0';
    new_node->age = age;
    new_node->income = income;
    new_node->expenses = expenses;
    new_node->networth = networth;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        (*head)->next = new_node;
        *head = new_node;
    }
}

void displayPersonalFinance(struct PersonalFinance* head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Age: %d\n", head->age);
        printf("Income: %.2lf\n", head->income);
        printf("Expenses: %.2lf\n", head->expenses);
        printf("Net Worth: %.2lf\n", head->networth);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    struct PersonalFinance* head = NULL;

    createPersonalFinance(&head);
    addPersonalFinance(&head, "John Doe", 25, 50000.0, 20000.0, 30000.0);
    addPersonalFinance(&head, "Jane Doe", 30, 60000.0, 30000.0, 40000.0);
    addPersonalFinance(&head, "Peter Pan", 12, 40000.0, 10000.0, 20000.0);

    displayPersonalFinance(head);

    return 0;
}