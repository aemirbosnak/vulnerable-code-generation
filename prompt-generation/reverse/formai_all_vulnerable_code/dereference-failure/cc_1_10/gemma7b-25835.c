//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store customer information
typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

// Define a function to insert a customer into the linked list
void insertCustomer(Customer* head, char* name, int account_number, double balance) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    strcpy(newCustomer->name, name);
    newCustomer->account_number = account_number;
    newCustomer->balance = balance;
    newCustomer->next = NULL;

    if (head == NULL) {
        head = newCustomer;
    } else {
        Customer* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCustomer;
    }
}

// Define a function to search for a customer by account number
Customer* searchCustomerByAccountNumber(Customer* head, int account_number) {
    Customer* temp = head;
    while (temp) {
        if (temp->account_number == account_number) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Define a function to withdraw money from a customer's account
void withdrawMoney(Customer* customer, double amount) {
    if (amount <= customer->balance) {
        customer->balance -= amount;
    } else {
        printf("Error: Insufficient funds.\n");
    }
}

// Define a function to deposit money into a customer's account
void depositMoney(Customer* customer, double amount) {
    customer->balance += amount;
}

int main() {
    Customer* head = NULL;

    // Insert some customers
    insertCustomer(head, "John Doe", 123456, 1000);
    insertCustomer(head, "Jane Doe", 654912, 2000);
    insertCustomer(head, "Peter Pan", 321486, 3000);

    // Search for a customer by account number
    Customer* customer = searchCustomerByAccountNumber(head, 123456);

    // Withdraw money from the customer's account
    withdrawMoney(customer, 500);

    // Deposit money into the customer's account
    depositMoney(customer, 200);

    // Print the customer's balance
    printf("Customer's balance: $%f\n", customer->balance);

    return 0;
}