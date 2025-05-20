//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Item structure
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Invoice structure
typedef struct {
    char customer_name[50];
    char date[20];
    Item items[50];
    int num_items;
    float total_amount;
} Invoice;

// Function to create a new invoice
Invoice *create_invoice(char *customer_name, char *date) {
    Invoice *invoice = (Invoice *)malloc(sizeof(Invoice));
    strcpy(invoice->customer_name, customer_name);
    strcpy(invoice->date, date);
    invoice->num_items = 0;
    invoice->total_amount = 0.0;
    return invoice;
}

// Function to add an item to the invoice
void add_item(Invoice *invoice, char *name, int quantity, float price) {
    strcpy(invoice->items[invoice->num_items].name, name);
    invoice->items[invoice->num_items].quantity = quantity;
    invoice->items[invoice->num_items].price = price;
    invoice->num_items++;
    invoice->total_amount += quantity * price;
}

// Function to print the invoice
void print_invoice(Invoice *invoice) {
    printf("Invoice\n");
    printf("Customer Name: %s\n", invoice->customer_name);
    printf("Date: %s\n", invoice->date);
    printf("=======================================================\n");
    printf("%-30s %-10s %-10s %-10s\n", "Item", "Quantity", "Price", "Total");
    printf("=======================================================\n");
    for (int i = 0; i < invoice->num_items; i++) {
        printf("%-30s %-10d %-10.2f %-10.2f\n", invoice->items[i].name, invoice->items[i].quantity,
               invoice->items[i].price, invoice->items[i].quantity * invoice->items[i].price);
    }
    printf("=======================================================\n");
    printf("Total Amount: %.2f\n", invoice->total_amount);
}

int main() {
    // Create a new invoice
    Invoice *invoice = create_invoice("John Doe", "2022-03-08");

    // Add items to the invoice
    add_item(invoice, "Coffee", 2, 2.5);
    add_item(invoice, "Tea", 1, 1.5);
    add_item(invoice, "Cake", 1, 3.0);

    // Print the invoice
    print_invoice(invoice);

    return 0;
}