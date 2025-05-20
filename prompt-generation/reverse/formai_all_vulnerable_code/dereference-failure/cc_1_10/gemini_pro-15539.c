//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Declare the Cafe and Item structures
typedef struct Cafe {
    char name[50];
    char address[100];
    char phone[20];
    int num_items;
    struct Item *items;
} Cafe;

typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

// Function to create a new Cafe
Cafe* create_cafe(char *name, char *address, char *phone, int num_items) {
    Cafe *cafe = (Cafe*)malloc(sizeof(Cafe));
    strcpy(cafe->name, name);
    strcpy(cafe->address, address);
    strcpy(cafe->phone, phone);
    cafe->num_items = num_items;
    cafe->items = (Item*)malloc(num_items * sizeof(Item));
    return cafe;
}

// Function to add an item to a Cafe
void add_item(Cafe *cafe, char *name, float price, int quantity) {
    Item *item = &cafe->items[cafe->num_items++];
    strcpy(item->name, name);
    item->price = price;
    item->quantity = quantity;
}

// Function to print the Cafe's menu
void print_menu(Cafe *cafe) {
    printf("\nWelcome to %s!\n", cafe->name);
    printf("Address: %s\n", cafe->address);
    printf("Phone: %s\n", cafe->phone);
    printf("\nMenu:\n");
    for (int i = 0; i < cafe->num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, cafe->items[i].name, cafe->items[i].price);
    }
}

// Function to take an order from a customer
void take_order(Cafe *cafe) {
    int num_items;
    printf("\nHow many items would you like to order? ");
    scanf("%d", &num_items);

    int *quantities = (int*)malloc(num_items * sizeof(int));
    float total = 0;
    for (int i = 0; i < num_items; i++) {
        int item_num;
        printf("Enter the item number: ");
        scanf("%d", &item_num);
        printf("Enter the quantity: ");
        scanf("%d", &quantities[i]);
        total += cafe->items[item_num - 1].price * quantities[i];
    }

    // Print the receipt
    printf("\nYour order:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f x %d = $%.2f\n", i + 1, cafe->items[i].name, cafe->items[i].price, quantities[i], cafe->items[i].price * quantities[i]);
    }
    printf("\nTotal: $%.2f\n", total);
}

// Main function
int main() {
    // Create a new Cafe
    Cafe *cafe = create_cafe("The Coffee Beanery", "123 Main Street", "555-1212", 5);

    // Add some items to the Cafe
    add_item(cafe, "Espresso", 2.50, 10);
    add_item(cafe, "Cappuccino", 3.00, 15);
    add_item(cafe, "Latte", 3.50, 20);
    add_item(cafe, "Mocha", 4.00, 10);
    add_item(cafe, "Tea", 2.00, 15);

    // Print the Cafe's menu
    print_menu(cafe);

    // Take an order from a customer
    take_order(cafe);

    return 0;
}