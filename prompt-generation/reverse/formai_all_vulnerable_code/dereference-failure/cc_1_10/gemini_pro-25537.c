//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items
char *menu_items[] = {
    "Coffee",
    "Tea",
    "Soda",
    "Water",
    "Juice",
    "Milk",
    "Food"
};

// Define the menu prices
float menu_prices[] = {
    1.50,
    1.25,
    1.00,
    0.50,
    1.25,
    1.00,
    2.00
};

// Define the maximum number of menu items
#define MAX_MENU_ITEMS 7

// Define the maximum number of orders
#define MAX_ORDERS 100

// Define the order struct
typedef struct {
    char *item;
    float price;
    int quantity;
} order_t;

// Define the cafe struct
typedef struct {
    order_t orders[MAX_ORDERS];
    int num_orders;
    float total_price;
} cafe_t;

// Create a new cafe
cafe_t *create_cafe() {
    cafe_t *cafe = malloc(sizeof(cafe_t));
    cafe->num_orders = 0;
    cafe->total_price = 0.0;
    return cafe;
}

// Add an order to the cafe
void add_order(cafe_t *cafe, char *item, float price, int quantity) {
    order_t order;
    order.item = item;
    order.price = price;
    order.quantity = quantity;
    cafe->orders[cafe->num_orders] = order;
    cafe->num_orders++;
    cafe->total_price += price * quantity;
}

// Print the cafe's menu
void print_menu(cafe_t *cafe) {
    printf("Menu:\n");
    for (int i = 0; i < MAX_MENU_ITEMS; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu_items[i], menu_prices[i]);
    }
}

// Get the user's order
void get_order(cafe_t *cafe) {
    int item_num;
    int quantity;
    printf("What would you like to order? (Enter the menu item number or 0 to finish): ");
    scanf("%d", &item_num);
    while (item_num != 0) {
        printf("How many of item %d would you like? ", item_num);
        scanf("%d", &quantity);
        add_order(cafe, menu_items[item_num - 1], menu_prices[item_num - 1], quantity);
        printf("What else would you like to order? (Enter the menu item number or 0 to finish): ");
        scanf("%d", &item_num);
    }
}

// Print the cafe's bill
void print_bill(cafe_t *cafe) {
    printf("Bill:\n");
    for (int i = 0; i < cafe->num_orders; i++) {
        printf("%s x %d - $%.2f\n", cafe->orders[i].item, cafe->orders[i].quantity, cafe->orders[i].price * cafe->orders[i].quantity);
    }
    printf("Total: $%.2f\n", cafe->total_price);
}

// Free the cafe's memory
void free_cafe(cafe_t *cafe) {
    free(cafe);
}

// Main function
int main() {
    // Create a new cafe
    cafe_t *cafe = create_cafe();

    // Print the cafe's menu
    print_menu(cafe);

    // Get the user's order
    get_order(cafe);

    // Print the cafe's bill
    print_bill(cafe);

    // Free the cafe's memory
    free_cafe(cafe);

    return 0;
}