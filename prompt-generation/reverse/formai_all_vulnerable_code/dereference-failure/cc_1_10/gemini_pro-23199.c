//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: statistical
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
    float totalAmount;
} Bill;

// Function to create a new bill
Bill *createBill() {
    Bill *bill = (Bill *)malloc(sizeof(Bill));
    bill->numItems = 0;
    bill->totalAmount = 0.0;
    return bill;
}

// Function to add an item to a bill
void addItem(Bill *bill, char *name, int quantity, float price) {
    strcpy(bill->items[bill->numItems].name, name);
    bill->items[bill->numItems].quantity = quantity;
    bill->items[bill->numItems].price = price;
    bill->numItems++;
    bill->totalAmount += quantity * price;
}

// Function to print a bill
void printBill(Bill *bill) {
    printf("Customer Name: %s\n", bill->customerName);
    printf("Date: %s\n", bill->date);
    printf("---------------------------------------------------------\n");
    printf("Item Name\tQuantity\tPrice\tAmount\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < bill->numItems; i++) {
        printf("%s\t%d\t%.2f\t%.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price, bill->items[i].quantity * bill->items[i].price);
    }
    printf("---------------------------------------------------------\n");
    printf("Total Amount: %.2f\n", bill->totalAmount);
}

// Function to free the memory allocated for a bill
void freeBill(Bill *bill) {
    free(bill);
}

// Main function
int main() {
    // Create a new bill
    Bill *bill = createBill();

    // Add some items to the bill
    addItem(bill, "Coffee", 2, 2.0);
    addItem(bill, "Tea", 1, 1.5);
    addItem(bill, "Cake", 1, 3.0);

    // Set the customer name and date
    strcpy(bill->customerName, "John Doe");
    strcpy(bill->date, "2022-03-08");

    // Print the bill
    printBill(bill);

    // Free the memory allocated for the bill
    freeBill(bill);

    return 0;
}