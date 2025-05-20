//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in a bill
#define MAX_ITEMS 100

// Define the structure of an item in a bill
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Define the structure of a bill
typedef struct {
    char customerName[50];
    char date[50];
    Item items[MAX_ITEMS];
    int numItems;
    float total;
} Bill;

// Function to create a new bill
Bill* createBill(char* customerName, char* date) {
    Bill* bill = (Bill*) malloc(sizeof(Bill));
    strcpy(bill->customerName, customerName);
    strcpy(bill->date, date);
    bill->numItems = 0;
    bill->total = 0.0;
    return bill;
}

// Function to add an item to a bill
void addItem(Bill* bill, Item item) {
    bill->items[bill->numItems] = item;
    bill->numItems++;
    bill->total += item.quantity * item.price;
}

// Function to print a bill
void printBill(Bill* bill) {
    printf("Customer Name: %s\n", bill->customerName);
    printf("Date: %s\n", bill->date);
    printf("----------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Item", "Quantity", "Price");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < bill->numItems; i++) {
        printf("%-20s %-10d %-10.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price);
    }
    printf("----------------------------------------------------\n");
    printf("Total: %.2f\n", bill->total);
}

// Function to free the memory allocated for a bill
void freeBill(Bill* bill) {
    free(bill);
}

// Main function
int main() {
    // Create a new bill
    Bill* bill = createBill("John Doe", "2023-03-08");

    // Add items to the bill
    Item item1 = {"Coffee", 2, 2.50};
    addItem(bill, item1);
    Item item2 = {"Tea", 1, 1.50};
    addItem(bill, item2);
    Item item3 = {"Cake", 1, 3.00};
    addItem(bill, item3);

    // Print the bill
    printBill(bill);

    // Free the memory allocated for the bill
    freeBill(bill);

    return 0;
}