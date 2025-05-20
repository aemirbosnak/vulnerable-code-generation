//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 100

typedef struct Customer
{
    char name[20];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

Customer* create_customer(char* name, int account_number, double balance)
{
    Customer* customer = (Customer*)malloc(sizeof(Customer));
    strcpy(customer->name, name);
    customer->account_number = account_number;
    customer->balance = balance;
    customer->next = NULL;
    return customer;
}

void add_customer(Customer* head, char* name, int account_number, double balance)
{
    Customer* new_customer = create_customer(name, account_number, balance);
    if (head == NULL)
    {
        head = new_customer;
    }
    else
    {
        Customer* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_customer;
    }
}

double get_balance(Customer* customer)
{
    return customer->balance;
}

void update_balance(Customer* customer, double new_balance)
{
    customer->balance = new_balance;
}

int main()
{
    Customer* head = NULL;
    add_customer(head, "John Doe", 12345, 1000);
    add_customer(head, "Jane Doe", 67890, 2000);
    add_customer(head, "Peter Pan", 34589, 3000);

    double balance = get_balance(head->next);
    update_balance(head->next, 5000);

    balance = get_balance(head->next);
    printf("Balance of Jane Doe: %.2lf", balance);

    return 0;
}