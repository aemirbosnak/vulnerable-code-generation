//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: invasive
// C Cafe Billing System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CUSTOMERS 100
#define MAX_ITEMS 10

// Customer structure
typedef struct {
    char name[30];
    char address[50];
    int table_number;
} Customer;

// Item structure
typedef struct {
    char name[30];
    int price;
} Item;

// Bill structure
typedef struct {
    Customer customer;
    Item items[MAX_ITEMS];
    int num_items;
    float total_price;
} Bill;

// Function prototypes
void print_menu();
void get_customer_info(Customer *customer);
void get_order(Bill *bill);
void calculate_total(Bill *bill);
void print_bill(Bill *bill);

// Main function
int main() {
    // Initialize variables
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;
    int choice;

    // Print the menu
    print_menu();

    // Get customer information
    get_customer_info(&customers[num_customers]);
    num_customers++;

    // Get order
    get_order(&customers[num_customers - 1]);

    // Calculate total price
    calculate_total(&customers[num_customers - 1]);

    // Print bill
    print_bill(&customers[num_customers - 1]);

    // Exit the program
    return 0;
}

// Function definitions
void print_menu() {
    printf("Welcome to our cafe!\n");
    printf("Our menu includes:\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $2.00\n");
    printf("3. Sandwich - $5.00\n");
    printf("4. Salad - $4.50\n");
    printf("5. Chocolate Cake - $6.00\n");
    printf("6. Cookie - $3.50\n");
    printf("Enter your choice (1-6): ");
}

void get_customer_info(Customer *customer) {
    printf("Enter your name: ");
    scanf("%s", customer->name);
    printf("Enter your address: ");
    scanf("%s", customer->address);
    printf("Enter your table number: ");
    scanf("%d", &customer->table_number);
}

void get_order(Bill *bill) {
    printf("Enter the number of items you want to order: ");
    scanf("%d", &bill->num_items);
    for (int i = 0; i < bill->num_items; i++) {
        printf("Enter item %d: ", i + 1);
        scanf("%s", bill->items[i].name);
        printf("Enter price: ");
        scanf("%d", &bill->items[i].price);
    }
}

void calculate_total(Bill *bill) {
    bill->total_price = 0;
    for (int i = 0; i < bill->num_items; i++) {
        bill->total_price += bill->items[i].price;
    }
}

void print_bill(Bill *bill) {
    printf("Bill for %s\n", bill->customer.name);
    printf("Address: %s\n", bill->customer.address);
    printf("Table number: %d\n", bill->customer.table_number);
    printf("Items:\n");
    for (int i = 0; i < bill->num_items; i++) {
        printf("%s: $%d\n", bill->items[i].name, bill->items[i].price);
    }
    printf("Total price: $%.2f\n", bill->total_price);
}