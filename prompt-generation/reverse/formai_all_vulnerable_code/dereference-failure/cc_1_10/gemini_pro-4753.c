//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

// Create a new item
Item* createItem(char *name, float price, int quantity) {
    Item *item = (Item*)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->price = price;
    item->quantity = quantity;
    return item;
}

// Print an item
void printItem(Item *item) {
    printf("%s %.2f %d\n", item->name, item->price, item->quantity);
}

// Create a new bill
typedef struct Bill {
    char customerName[50];
    Item **items;
    int numItems;
    float total;
} Bill;

// Create a new bill
Bill* createBill(char *customerName) {
    Bill *bill = (Bill*)malloc(sizeof(Bill));
    strcpy(bill->customerName, customerName);
    bill->items = (Item**)malloc(sizeof(Item*) * 10);
    bill->numItems = 0;
    bill->total = 0;
    return bill;
}

// Add an item to a bill
void addItemToBill(Bill *bill, Item *item) {
    bill->items[bill->numItems] = item;
    bill->numItems++;
    bill->total += item->price * item->quantity;
}

// Print a bill
void printBill(Bill *bill) {
    printf("Customer Name: %s\n", bill->customerName);
    printf("Items:\n");
    for (int i = 0; i < bill->numItems; i++) {
        printItem(bill->items[i]);
    }
    printf("Total: %.2f\n", bill->total);
}

// Main function
int main() {
    // Create a new bill
    Bill *bill = createBill("John Doe");

    // Add items to the bill
    addItemToBill(bill, createItem("Coffee", 2.50, 2));
    addItemToBill(bill, createItem("Tea", 1.50, 1));
    addItemToBill(bill, createItem("Cake", 4.00, 1));

    // Print the bill
    printBill(bill);

    return 0;
}