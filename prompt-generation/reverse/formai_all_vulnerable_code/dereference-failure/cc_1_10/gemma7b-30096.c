//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 10

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

void create_customer(Customer** head) {
    *head = malloc(sizeof(Customer));
    (*head)->next = NULL;
    (*head)->balance = 0.0;
    return;
}

void deposit(Customer* customer, double amount) {
    customer->balance += amount;
}

void withdraw(Customer* customer, double amount) {
    if (amount <= customer->balance) {
        customer->balance -= amount;
    } else {
        printf("Insufficient funds.");
    }
}

void transfer(Customer* from_customer, Customer* to_customer, double amount) {
    if (amount <= from_customer->balance) {
        from_customer->balance -= amount;
        to_customer->balance += amount;
    } else {
        printf("Insufficient funds.");
    }
}

int main() {
    Customer* head = NULL;

    // Create some customers
    create_customer(&head);
    strcpy(head->name, "Bob");
    head->account_number = 1234;

    create_customer(&head);
    strcpy(head->next->name, "Alice");
    head->next->account_number = 5678;

    // Deposit some money
    deposit(head, 100.0);
    deposit(head->next, 200.0);

    // Withdraw some money
    withdraw(head, 50.0);
    withdraw(head->next, 75.0);

    // Transfer money
    transfer(head, head->next, 25.0);

    // Print the customer's balances
    printf("Bob's balance: %f\n", head->balance);
    printf("Alice's balance: %f\n", head->next->balance);

    return 0;
}