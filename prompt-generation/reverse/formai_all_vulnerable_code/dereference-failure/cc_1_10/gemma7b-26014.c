//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct BankRecord {
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
};

struct BankRecord* insert_at_tail(struct BankRecord* head, char* name, int account_number, double balance)
{
    struct BankRecord* new_node = (struct BankRecord*)malloc(sizeof(struct BankRecord));
    strcpy(new_node->name, name);
    new_node->account_number = account_number;
    new_node->balance = balance;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct BankRecord* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return head;
}

struct BankRecord* search_by_account_number(struct BankRecord* head, int account_number)
{
    struct BankRecord* temp = head;
    while (temp)
    {
        if (temp->account_number == account_number)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

int main()
{
    struct BankRecord* head = NULL;
    insert_at_tail(head, "John Doe", 12345, 1000.0);
    insert_at_tail(head, "Jane Doe", 67890, 2000.0);
    insert_at_tail(head, "Peter Pan", 32146, 3000.0);

    struct BankRecord* found_node = search_by_account_number(head, 12345);
    if (found_node)
    {
        printf("Name: %s\n", found_node->name);
        printf("Account Number: %d\n", found_node->account_number);
        printf("Balance: %f\n", found_node->balance);
    }

    return 0;
}