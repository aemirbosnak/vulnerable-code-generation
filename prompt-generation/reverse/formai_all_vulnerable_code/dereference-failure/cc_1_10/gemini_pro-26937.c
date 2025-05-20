//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a single item in the bill
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Structure to store the entire bill
typedef struct Bill {
    char customer_name[50];
    char date[20];
    Item items[100];
    int num_items;
    float total_amount;
} Bill;

// Function to create a new bill
Bill* create_bill(char* customer_name, char* date) {
    Bill* bill = (Bill*)malloc(sizeof(Bill));
    strcpy(bill->customer_name, customer_name);
    strcpy(bill->date, date);
    bill->num_items = 0;
    bill->total_amount = 0.0;
    return bill;
}

// Function to add an item to the bill
void add_item(Bill* bill, char* name, int quantity, float price) {
    strcpy(bill->items[bill->num_items].name, name);
    bill->items[bill->num_items].quantity = quantity;
    bill->items[bill->num_items].price = price;
    bill->num_items++;
    bill->total_amount += quantity * price;
}

// Function to print the bill
void print_bill(Bill* bill) {
    printf("**************************************************\n");
    printf("**                Cafe Billing System           **\n");
    printf("**************************************************\n");
    printf("Customer Name: %s\n", bill->customer_name);
    printf("Date: %s\n", bill->date);
    printf("--------------------------------------------------\n");
    printf("Item Name\tQuantity\tPrice\tTotal\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < bill->num_items; i++) {
        printf("%s\t%d\t%.2f\t%.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price, bill->items[i].quantity * bill->items[i].price);
    }
    printf("--------------------------------------------------\n");
    printf("Total Amount: %.2f\n", bill->total_amount);
    printf("**************************************************\n");
}

// Main function
int main() {
    // Create a new bill
    Bill* bill = create_bill("John Doe", "2023-03-08");

    // Add items to the bill
    add_item(bill, "Coffee", 2, 1.50);
    add_item(bill, "Tea", 1, 1.25);
    add_item(bill, "Sandwich", 1, 5.00);
    add_item(bill, "Cake", 1, 3.00);

    // Print the bill
    print_bill(bill);

    return 0;
}