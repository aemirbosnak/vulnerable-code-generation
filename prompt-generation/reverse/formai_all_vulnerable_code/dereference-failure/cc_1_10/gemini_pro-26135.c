//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: secure
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
    char customer_name[50];
    char date[11];
    item items[MAX_ITEMS];
    int num_items;
    float total_price;
} bill;

// Function to create a new bill
bill* create_bill(char* customer_name, char* date) {
    bill* new_bill = (bill*) malloc(sizeof(bill));
    strcpy(new_bill->customer_name, customer_name);
    strcpy(new_bill->date, date);
    new_bill->num_items = 0;
    new_bill->total_price = 0.0;
    return new_bill;
}

// Function to add an item to a bill
void add_item(bill* bill, item* new_item) {
    if (bill->num_items < MAX_ITEMS) {
        bill->items[bill->num_items] = *new_item;
        bill->num_items++;
        bill->total_price += new_item->price * new_item->quantity;
    } else {
        printf("Error: Cannot add more than %d items to a bill.\n", MAX_ITEMS);
    }
}

// Function to print a bill
void print_bill(bill* bill) {
    printf("Customer Name: %s\n", bill->customer_name);
    printf("Date: %s\n", bill->date);
    printf("\n");
    printf("Items:\n");
    for (int i = 0; i < bill->num_items; i++) {
        printf("    %s %dx $%.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price);
    }
    printf("\n");
    printf("Total Price: $%.2f\n", bill->total_price);
}

// Main function
int main() {
    // Create a new bill
    bill* my_bill = create_bill("John Doe", "2023-03-08");

    // Add some items to the bill
    item item1 = {"Coffee", 2.50, 2};
    item item2 = {"Tea", 1.50, 1};
    item item3 = {"Muffin", 3.00, 1};
    add_item(my_bill, &item1);
    add_item(my_bill, &item2);
    add_item(my_bill, &item3);

    // Print the bill
    print_bill(my_bill);

    // Free the memory allocated for the bill
    free(my_bill);

    return 0;
}