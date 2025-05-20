//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <string.h>

// Define the menu structure
typedef struct MenuItem {
    char name[20];
    float price;
    int quantity;
} MenuItem;

// Define the bill structure
typedef struct Bill {
    char customer_name[20];
    char address[50];
    float total_amount;
    MenuItem items[10];
} Bill;

// Function to add an item to the bill
void add_item(Bill *bill, MenuItem item) {
    int i = 0;
    for (i = 0; i < bill->items[0].quantity; i++) {
        if (bill->items[i].name == item.name) {
            bill->items[i].quantity++;
            return;
        }
    }

    // If the item is not found, add it to the bill
    bill->items[bill->items[0].quantity] = item;
    bill->items[bill->items[0].quantity].quantity = 1;
    bill->items[0].quantity++;
}

// Function to calculate the total amount of the bill
float calculate_total(Bill *bill) {
    int i = 0;
    float total = 0.0f;
    for (i = 0; i < bill->items[0].quantity; i++) {
        total += bill->items[i].price * bill->items[i].quantity;
    }

    return total;
}

// Function to print the bill
void print_bill(Bill *bill) {
    int i = 0;
    printf("Customer Name: %s\n", bill->customer_name);
    printf("Address: %s\n", bill->address);
    printf("Total Amount: %.2f\n", bill->total_amount);
    printf("Items:\n");
    for (i = 0; i < bill->items[0].quantity; i++) {
        printf("%s: %d @ %.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price);
    }
}

int main() {
    // Create a menu item
    MenuItem item1 = {"Coffee", 5.0f, 10};
    MenuItem item2 = {"Tea", 4.0f, 5};
    MenuItem item3 = {"Juice", 3.0f, 2};

    // Create a bill
    Bill bill = {"John Doe", "123 Main St.", 100.0f, {item1, item2, item3}};

    // Add items to the bill
    add_item(&bill, item1);
    add_item(&bill, item2);
    add_item(&bill, item3);

    // Calculate the total amount of the bill
    bill.total_amount = calculate_total(&bill);

    // Print the bill
    print_bill(&bill);

    return 0;
}