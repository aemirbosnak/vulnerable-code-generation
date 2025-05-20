//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: romantic
#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 10

typedef struct Customer
{
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

Customer* create_customer(char* name, int account_number, double balance)
{
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));

    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;

    return new_customer;
}

void deposit(Customer* customer, double amount)
{
    customer->balance += amount;
}

void withdraw(Customer* customer, double amount)
{
    if (amount <= customer->balance)
    {
        customer->balance -= amount;
    }
    else
    {
        printf("Insufficient funds\n");
    }
}

void transfer(Customer* from_customer, Customer* to_customer, double amount)
{
    if (amount <= from_customer->balance)
    {
        deposit(to_customer, amount);
        withdraw(from_customer, amount);
    }
    else
    {
        printf("Insufficient funds\n");
    }
}

int main()
{
    Customer* head = NULL;

    // Create some customers
    Customer* customer1 = create_customer("John Doe", 12345, 1000);
    Customer* customer2 = create_customer("Jane Doe", 65432, 2000);
    Customer* customer3 = create_customer("Peter Pan", 98412, 3000);

    // Deposit some money
    deposit(customer1, 500);
    deposit(customer2, 200);

    // Withdraw some money
    withdraw(customer2, 100);
    withdraw(customer3, 200);

    // Transfer some money
    transfer(customer1, customer2, 150);

    // Print the customer balances
    printf("Customer 1: %f\n", customer1->balance);
    printf("Customer 2: %f\n", customer2->balance);
    printf("Customer 3: %f\n", customer3->balance);

    return 0;
}