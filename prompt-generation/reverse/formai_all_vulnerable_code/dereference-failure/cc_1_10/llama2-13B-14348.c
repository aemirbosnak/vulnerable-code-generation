//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a customer
struct customer {
    int id;
    char name[20];
    int balance;
    struct customer *next;
};

// Function to create a new customer
struct customer *new_customer(int id, char name[20], int balance) {
    struct customer *new_customer = (struct customer *)malloc(sizeof(struct customer));
    new_customer->id = id;
    strcpy(new_customer->name, name);
    new_customer->balance = balance;
    new_customer->next = NULL;
    return new_customer;
}

// Function to deposit money
void deposit(struct customer *customer, int amount) {
    customer->balance += amount;
}

// Function to withdraw money
void withdraw(struct customer *customer, int amount) {
    if (customer->balance >= amount) {
        customer->balance -= amount;
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to display the list of customers
void display_customers(struct customer *head) {
    struct customer *current = head;
    while (current != NULL) {
        printf("%d - %s - %d\n", current->id, current->name, current->balance);
        current = current->next;
    }
}

// Main function
int main() {
    struct customer *head = NULL;

    // Create some customers
    struct customer *customer1 = new_customer(1, "John", 1000);
    struct customer *customer2 = new_customer(2, "Jane", 500);
    struct customer *customer3 = new_customer(3, "Bob", 2000);

    // Add customers to the list
    head = customer1;
    customer1->next = customer2;
    customer2->next = customer3;

    // Deposit and withdraw money
    deposit(customer1, 500);
    deposit(customer2, 200);
    withdraw(customer1, 300);
    withdraw(customer2, 400);

    // Display the list of customers
    display_customers(head);

    return 0;
}