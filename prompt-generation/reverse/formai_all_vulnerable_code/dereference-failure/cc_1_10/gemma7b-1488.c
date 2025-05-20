//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MONEY_MAX 1000000

struct Record
{
    char name[20];
    int account_no;
    double balance;
    struct Record* next;
};

void deposit(struct Record* head, double amount)
{
    struct Record* new_record = malloc(sizeof(struct Record));
    new_record->balance = amount;
    new_record->next = NULL;

    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        struct Record* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_record;
    }
}

void withdraw(struct Record* head, double amount)
{
    struct Record* current = head;
    while (current)
    {
        if (current->balance >= amount)
        {
            current->balance -= amount;
            break;
        }
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Insufficient funds.\n");
    }
}

int main()
{
    struct Record* head = NULL;

    deposit(head, 1000);
    deposit(head, 2000);
    withdraw(head, 500);
    withdraw(head, 200);
    withdraw(head, 1000);

    struct Record* current = head;
    while (current)
    {
        printf("Name: %s, Account No: %d, Balance: %.2lf\n", current->name, current->account_no, current->balance);
        current = current->next;
    }

    return 0;
}