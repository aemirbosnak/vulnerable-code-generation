//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store customer information
typedef struct customer {
    char name[50];
    char address[100];
    char phone[20];
} customer;

// Define a structure to store menu items
typedef struct item {
    char name[50];
    float price;
    int quantity;
} item;

// Create a global list of customers
customer customers[100];

// Create a global list of menu items
item items[100];

// Function to add a customer to the list
void addCustomer(char *name, char *address, char *phone) {
    int i = 0;
    for (i = 0; i < 100; i++) {
        if (customers[i].name[0] == '\0') {
            strcpy(customers[i].name, name);
            strcpy(customers[i].address, address);
            strcpy(customers[i].phone, phone);
            return;
        }
    }
    printf("Error: customer list is full.\n");
}

// Function to add an item to the list
void addItem(char *name, float price, int quantity) {
    int i = 0;
    for (i = 0; i < 100; i++) {
        if (items[i].name[0] == '\0') {
            strcpy(items[i].name, name);
            items[i].price = price;
            items[i].quantity = quantity;
            return;
        }
    }
    printf("Error: item list is full.\n");
}

// Function to calculate the total cost of an order
float calculateTotalCost(item *items, int numItems) {
    int i = 0;
    float totalCost = 0.0f;
    for (i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

// Function to print an invoice
void printInvoice(customer *customer, item *items, int numItems, float totalCost) {
    printf("Customer Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Phone Number: %s\n", customer->phone);
    printf("Order Items:\n");
    int i = 0;
    for (i = 0; i < numItems; i++) {
        printf("%s - %d units at %f\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("Total Cost: %f\n", totalCost);
    printf("Thank you for your business!\n");
}

int main() {
    // Add some sample customers and items
    addCustomer("John Doe", "123 Main St.", "555-123-4567");
    addItem("Coffee", 2.0f, 10);
    addItem("Tea", 1.5f, 20);

    // Create an order
    item *orderItems = malloc(sizeof(item) * 2);
    orderItems[0] = items[0];
    orderItems[1] = items[1];

    // Calculate the total cost of the order
    float totalCost = calculateTotalCost(orderItems, 2);

    // Print the invoice
    printInvoice(&customers[0], orderItems, 2, totalCost);

    return 0;
}