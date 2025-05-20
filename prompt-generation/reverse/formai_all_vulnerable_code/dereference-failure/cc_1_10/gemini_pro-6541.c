//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 10

// Define the menu items and their prices
char menu_items[MAX_ITEMS][20] = {
    "Coffee",
    "Tea",
    "Soda",
    "Juice",
    "Pastry",
    "Sandwich",
    "Salad",
    "Soup",
    "Chips",
    "Cookies"
};

float menu_prices[MAX_ITEMS] = {
    1.50,
    1.25,
    1.00,
    1.25,
    2.00,
    4.00,
    5.00,
    3.50,
    1.00,
    1.50
};

// Define the order struct
typedef struct {
    int item_number;
    int quantity;
} order_item;

// Define the order struct
typedef struct {
    order_item items[MAX_ITEMS];
    int num_items;
    float total_price;
} order;

// Create a new order
order* create_order() {
    order* new_order = (order*)malloc(sizeof(order));
    new_order->num_items = 0;
    new_order->total_price = 0.0;
    return new_order;
}

// Add an item to an order
void add_item_to_order(order* order, int item_number, int quantity) {
    order->items[order->num_items].item_number = item_number;
    order->items[order->num_items].quantity = quantity;
    order->num_items++;
    order->total_price += menu_prices[item_number] * quantity;
}

// Print an order
void print_order(order* order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s x%d\n", menu_items[order->items[i].item_number], order->items[i].quantity);
    }
    printf("Total Price: $%.2f\n", order->total_price);
}

// Get the user's input
int get_user_input() {
    int input;
    printf("Enter an item number (0 to quit): ");
    scanf("%d", &input);
    return input;
}

// Main function
int main() {
    // Create a new order
    order* order = create_order();

    // Get the user's input
    int item_number;
    int quantity;
    do {
        item_number = get_user_input();
        if (item_number > 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            add_item_to_order(order, item_number - 1, quantity);
        }
    } while (item_number != 0);

    // Print the order
    print_order(order);

    // Free the memory allocated for the order
    free(order);

    return 0;
}