//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

struct BankRecord
{
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
};

void insert_at_tail(struct BankRecord** head, char* name, int account_number, double balance)
{
    struct BankRecord* new_node = (struct BankRecord*)malloc(sizeof(struct BankRecord));
    strcpy(new_node->name, name);
    new_node->account_number = account_number;
    new_node->balance = balance;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        (*head)->next = new_node;
    }
}

void print_all_records(struct BankRecord* head)
{
    struct BankRecord* current = head;
    while (current)
    {
        printf("Name: %s\n", current->name);
        printf("Account Number: %d\n", current->account_number);
        printf("Balance: %.2lf\n", current->balance);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    struct BankRecord* head = NULL;

    insert_at_tail(&head, "John Doe", 123456, 1000.0);
    insert_at_tail(&head, "Jane Doe", 654923, 2000.0);
    insert_at_tail(&head, "Peter Pan", 321485, 3000.0);

    print_all_records(head);

    return 0;
}