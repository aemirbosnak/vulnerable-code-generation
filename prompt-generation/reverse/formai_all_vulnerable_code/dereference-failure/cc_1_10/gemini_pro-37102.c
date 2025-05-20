//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an item
typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

// Define the structure of a bill
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    float total_price;
} Bill;

// Function to create a new bill
Bill* create_bill() {
    Bill* bill = (Bill*)malloc(sizeof(Bill));
    bill->num_items = 0;
    bill->total_price = 0.0;
    return bill;
}

// Function to add an item to a bill
void add_item_to_bill(Bill* bill, Item item) {
    bill->items[bill->num_items] = item;
    bill->num_items++;
    bill->total_price += item.price * item.quantity;
}

// Function to print a bill
void print_bill(Bill* bill) {
    printf("====================================================\n");
    printf("Cafe Billing System\n");
    printf("====================================================\n");
    printf("Item\t\tPrice\tQuantity\tTotal\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < bill->num_items; i++) {
        printf("%s\t\t%.2f\t%d\t\t%.2f\n", bill->items[i].name, bill->items[i].price, bill->items[i].quantity, bill->items[i].price * bill->items[i].quantity);
    }
    printf("-----------------------------------------------------\n");
    printf("Total:\t\t\t\t%.2f\n", bill->total_price);
    printf("====================================================\n");
}

// Main function
int main() {
    // Create a new bill
    Bill* bill = create_bill();

    // Add some items to the bill
    Item item1 = {"Coffee", 2.50, 2};
    add_item_to_bill(bill, item1);
    Item item2 = {"Tea", 1.50, 1};
    add_item_to_bill(bill, item2);
    Item item3 = {"Cake", 3.00, 1};
    add_item_to_bill(bill, item3);

    // Print the bill
    print_bill(bill);

    // Free the memory allocated for the bill
    free(bill);

    return 0;
}