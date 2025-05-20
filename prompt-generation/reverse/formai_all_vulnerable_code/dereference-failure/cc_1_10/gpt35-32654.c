//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define customer struct
typedef struct Customer {
    char name[50];
    int tableNum;
    float total;
    struct Customer *next;
} Customer;

// Define global variable for the head of the linked list
Customer *head = NULL;

// Function to add a customer to the linked list
void addCustomer(char *name, int tableNum) {
    Customer *newCustomer = (Customer*) malloc(sizeof(Customer));
    newCustomer->tableNum = tableNum;
    strcpy(newCustomer->name, name);
    newCustomer->total = 0;

    // If head is NULL, set newCustomer as head
    if (head == NULL) {
        head = newCustomer;
        head->next = NULL;
        return;
    }

    // Traverse the linked list to find the end
    Customer *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Set the next customer to the new customer
    current->next = newCustomer;
    newCustomer->next = NULL;
}

// Function to find a customer by table number
Customer *findCustomer(int tableNum) {
    Customer *current = head;

    // Traverse the linked list until the table number is found
    while (current != NULL) {
        if (current->tableNum == tableNum) {
            return current;
        }
        current = current->next;
    }

    // If the table number is not found, return NULL
    return NULL;
}

// Function to add an item to a customer's bill
void addItem(int tableNum, float price) {
    Customer *customer = findCustomer(tableNum);
    if (customer == NULL) {
        printf("Table not found.\n");
        return;
    }

    customer->total += price;
}

// Function to display a customer's bill
void displayBill(int tableNum) {
    Customer *customer = findCustomer(tableNum);
    if (customer == NULL) {
        printf("Table not found.\n");
        return;
    }

    printf("Table %d - %s\n", customer->tableNum, customer->name);
    printf("Total bill: $%.2f\n", customer->total);
}

// Main function
int main() {
    int choice, tableNum;
    char name[50];

    while (1) {
        printf("Welcome to Cafe Billing System\n");
        printf("1. Add customer\n");
        printf("2. Add item to bill\n");
        printf("3. Display bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name);
                printf("Enter table number: ");
                scanf("%d", &tableNum);
                addCustomer(name, tableNum);
                printf("Customer added successfully!\n");
                break;

            case 2:
                printf("Enter table number: ");
                scanf("%d", &tableNum);
                printf("Enter item price: ");
                float price;
                scanf("%f", &price);
                addItem(tableNum, price);
                printf("Item added successfully!\n");
                break;

            case 3:
                printf("Enter table number: ");
                scanf("%d", &tableNum);
                displayBill(tableNum);
                break;

            case 4:
                printf("Thank you for using Cafe Billing System.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}