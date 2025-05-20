//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Person
{
    char name[MAX_NAME_LENGTH];
    int age;
    double salary;
    struct Person* next;
} Person;

void insertPerson(Person** head, char* name, int age, double salary)
{
    Person* newPerson = malloc(sizeof(Person));
    strcpy(newPerson->name, name);
    newPerson->age = age;
    newPerson->salary = salary;
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
        printf("%s (age: %d), salary: %.2lf\n", head->name, head->age, head->salary);
        head = head->next;
    }
}

int main()
{
    Person* head = NULL;

    insertPerson(&head, "John Doe", 30, 50000);
    insertPerson(&head, "Jane Doe", 25, 60000);
    insertPerson(&head, "Peter Pan", 12, 10000);

    printPersons(head);

    return 0;
}