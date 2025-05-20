//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store customer information
typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
} Customer;

// Create a linked list to store customers
typedef struct Node {
    Customer customer;
    struct Node* next;
} Node;

// Function to insert a customer into the linked list
void insert_customer(Node** head, Customer customer) {
    Node* new_node = malloc(sizeof(Node));
    new_node->customer = customer;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to find a customer from the linked list
Customer* find_customer(Node* head, int account_number) {
    while (head) {
        if (head->customer.account_number == account_number) {
            return &head->customer;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update a customer's balance
void update_balance(Customer* customer, double new_balance) {
    customer->balance = new_balance;
}

// Main function
int main() {
    // Create a linked list of customers
    Node* head = NULL;

    // Insert some customers into the linked list
    Customer customer1 = {"John Doe", 12345, 1000.0};
    insert_customer(&head, customer1);

    Customer customer2 = {"Jane Doe", 65432, 2000.0};
    insert_customer(&head, customer2);

    // Find a customer from the linked list
    Customer* found_customer = find_customer(head, 12345);

    // If the customer is found, update their balance
    if (found_customer) {
        update_balance(found_customer, 2500.0);
    }

    // Print the updated customer's balance
    printf("Updated customer balance: %f\n", found_customer->balance);

    return 0;
}