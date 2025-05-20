//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store item details
typedef struct item {
    char name[50];
    float price;
    int quantity;
} item;

// Function to create a new item
item *create_item(char *name, float price, int quantity) {
    item *i = malloc(sizeof(item));
    strcpy(i->name, name);
    i->price = price;
    i->quantity = quantity;
    return i;
}

// Function to add an item to the bill
void add_item(item *i, float *total) {
    *total += i->price * i->quantity;
}

// Function to print the bill
void print_bill(item **items, int n, float total) {
    printf("Cafe Billing System\n");
    printf("--------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%.2f\n", items[i]->name, items[i]->quantity, items[i]->price * items[i]->quantity);
    }
    printf("Total:\t\t%.2f\n", total);
}

// Main function
int main() {
    // Create an array of items
    item *items[] = {
        create_item("Coffee", 1.50, 2),
        create_item("Tea", 1.20, 1),
        create_item("Cake", 2.00, 1),
    };

    // Calculate the total bill
    float total = 0;
    for (int i = 0; i < 3; i++) {
        add_item(items[i], &total);
    }

    // Print the bill
    print_bill(items, 3, total);

    return 0;
}