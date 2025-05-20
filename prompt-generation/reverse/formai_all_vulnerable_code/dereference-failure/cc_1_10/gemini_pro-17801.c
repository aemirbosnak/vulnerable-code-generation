//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Item types
#define FOOD 1
#define DRINK 2
#define DESSERT 3

// Payment types
#define CASH 1
#define CARD 2

// Item struct
typedef struct Item {
    int type;
    char* name;
    float price;
} Item;

// Order struct
typedef struct Order {
    Item** items;
    int num_items;
    float total_price;
    int payment_type;
} Order;

// Function to create an item
Item* create_item(int type, char* name, float price) {
    Item* item = (Item*)malloc(sizeof(Item));
    item->type = type;
    item->name = name;
    item->price = price;
    return item;
}

// Function to create an order
Order* create_order() {
    Order* order = (Order*)malloc(sizeof(Order));
    order->items = NULL;
    order->num_items = 0;
    order->total_price = 0.0f;
    order->payment_type = 0;
    return order;
}

// Function to add an item to an order
void add_item_to_order(Order* order, Item* item) {
    order->items = (Item**)realloc(order->items, (order->num_items + 1) * sizeof(Item*));
    order->items[order->num_items++] = item;
    order->total_price += item->price;
}

// Function to calculate the total price of an order
float calculate_total_price(Order* order) {
    float total_price = 0.0f;
    for (int i = 0; i < order->num_items; i++) {
        total_price += order->items[i]->price;
    }
    return total_price;
}

// Function to print an order
void print_order(Order* order) {
    printf("Order:\n");
    printf("Items:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s: $%.2f\n", order->items[i]->name, order->items[i]->price);
    }
    printf("Total price: $%.2f\n", order->total_price);
}

// Function to get the payment type from the user
int get_payment_type() {
    int payment_type;
    printf("Please choose a payment type:\n");
    printf("1. Cash\n");
    printf("2. Card\n");
    scanf("%d", &payment_type);
    return payment_type;
}

// Function to process the order
void process_order(Order* order) {
    order->payment_type = get_payment_type();
    print_order(order);
    printf("Payment type: ");
    switch (order->payment_type) {
        case CASH:
            printf("Cash\n");
            break;
        case CARD:
            printf("Card\n");
            break;
        default:
            printf("Invalid payment type\n");
            break;
    }
}

// Main function
int main() {
    // Create an order
    Order* order = create_order();

    // Add items to the order
    add_item_to_order(order, create_item(FOOD, "Hamburger", 10.99f));
    add_item_to_order(order, create_item(DRINK, "Coke", 2.99f));
    add_item_to_order(order, create_item(DESSERT, "Cheesecake", 6.99f));

    // Process the order
    process_order(order);

    // Free the memory allocated for the order
    free(order->items);
    free(order);

    return 0;
}