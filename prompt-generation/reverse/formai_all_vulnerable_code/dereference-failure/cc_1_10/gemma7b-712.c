//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct customer
{
    char name[50];
    int account_number;
    double balance;
    struct customer* next;
};

void insert(struct customer**, int account_number, double balance, char* name);
void search(struct customer* head, int account_number);
void update(struct customer* head, int account_number, double new_balance);
void delete(struct customer* head, int account_number);

int main()
{
    struct customer* head = NULL;

    insert(head, 1234, 5000, "John Doe");
    insert(head, 2345, 10000, "Jane Doe");
    insert(head, 3456, 20000, "Peter Pan");

    search(head, 2345);
    update(head, 1234, 10000);
    delete(head, 3456);

    return 0;
}

void insert(struct customer** head, int account_number, double balance, char* name)
{
    struct customer* new_customer = (struct customer*)malloc(sizeof(struct customer));

    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;

    if (*head == NULL)
    {
        *head = new_customer;
    }
    else
    {
        (*head)->next = new_customer;
        *head = new_customer;
    }
}

void search(struct customer* head, int account_number)
{
    while (head)
    {
        if (head->account_number == account_number)
        {
            printf("Name: %s\n", head->name);
            printf("Account Number: %d\n", head->account_number);
            printf("Balance: %f\n", head->balance);
            return;
        }
        head = head->next;
    }

    printf("Account not found.\n");
}

void update(struct customer* head, int account_number, double new_balance)
{
    while (head)
    {
        if (head->account_number == account_number)
        {
            head->balance = new_balance;
            return;
        }
        head = head->next;
    }

    printf("Account not found.\n");
}

void delete(struct customer* head, int account_number)
{
    struct customer* previous = NULL;
    struct customer* current = head;

    while (current)
    {
        if (current->account_number == account_number)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Account not found.\n");
}