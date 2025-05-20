//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Person
{
    char name[MAX_NAME_LENGTH];
    int age;
    double income;
    double expenses;
    struct Person* next;
} Person;

void addPerson(Person** head, char* name, int age, double income, double expenses)
{
    Person* newPerson = malloc(sizeof(Person));

    strcpy(newPerson->name, name);
    newPerson->age = age;
    newPerson->income = income;
    newPerson->expenses = expenses;
    newPerson->next = NULL;

    if (*head == NULL)
    {
        *head = newPerson;
    }
    else
    {
        (*head)->next = newPerson;
    }
}

void printPersons(Person* head)
{
    while (head)
    {
        printf("Name: %s, Age: %d, Income: %.2lf, Expenses: %.2lf\n", head->name, head->age, head->income, head->expenses);
        head = head->next;
    }
}

int main()
{
    Person* head = NULL;

    addPerson(&head, "John Doe", 25, 50000, 2000);
    addPerson(&head, "Jane Doe", 30, 60000, 3000);
    addPerson(&head, "Bill Smith", 40, 70000, 4000);

    printPersons(head);

    return 0;
}