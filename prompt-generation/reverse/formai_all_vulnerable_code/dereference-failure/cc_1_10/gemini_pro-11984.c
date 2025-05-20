//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an item
typedef struct item {
    char name[50];
    float price;
    int quantity;
} item;

// Define the structure of a bill
typedef struct bill {
    item items[MAX_ITEMS];
    int num_items;
    float total;
} bill;

// Function to create a new bill
bill *create_bill() {
    bill *b = malloc(sizeof(bill));
    b->num_items = 0;
    b->total = 0.0;
    return b;
}

// Function to add an item to a bill
void add_item(bill *b, item *i) {
    b->items[b->num_items] = *i;
    b->num_items++;
    b->total += i->price * i->quantity;
}

// Function to print a bill
void print_bill(bill *b) {
    printf("Cafe Billing System\n");
    printf("--------------------\n");
    printf("Item\tPrice\tQuantity\n");
    for (int i = 0; i < b->num_items; i++) {
        printf("%s\t%.2f\t%d\n", b->items[i].name, b->items[i].price, b->items[i].quantity);
    }
    printf("--------------------\n");
    printf("Total:\t%.2f\n", b->total);
}

// Main function
int main() {
    // Create a new bill
    bill *b = create_bill();

    // Add some items to the bill
    item i1 = {"Coffee", 2.50, 2};
    add_item(b, &i1);
    item i2 = {"Tea", 1.50, 1};
    add_item(b, &i2);
    item i3 = {"Cake", 3.00, 1};
    add_item(b, &i3);

    // Print the bill
    print_bill(b);

    // Free the memory allocated for the bill
    free(b);

    return 0;
}