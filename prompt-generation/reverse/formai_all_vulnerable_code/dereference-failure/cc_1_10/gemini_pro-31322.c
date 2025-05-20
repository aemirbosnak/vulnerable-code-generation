//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int item_id;
    char item_name[MAX_NAME_LENGTH];
    float item_price;
} Item;

typedef struct {
    int order_id;
    int table_number;
    Item items[MAX_ITEMS];
    int num_items;
    float total_price;
} Order;

// Function to create a new item
Item *create_item(int item_id, char *item_name, float item_price) {
    Item *item = (Item *)malloc(sizeof(Item));
    item->item_id = item_id;
    strcpy(item->item_name, item_name);
    item->item_price = item_price;
    return item;
}

// Function to create a new order
Order *create_order(int order_id, int table_number) {
    Order *order = (Order *)malloc(sizeof(Order));
    order->order_id = order_id;
    order->table_number = table_number;
    order->num_items = 0;
    order->total_price = 0.0;
    return order;
}

// Function to add an item to an order
void add_item_to_order(Order *order, Item *item) {
    order->items[order->num_items++] = *item;
    order->total_price += item->item_price;
}

// Function to print an order
void print_order(Order *order) {
    printf("Order ID: %d\n", order->order_id);
    printf("Table Number: %d\n", order->table_number);
    printf("Items:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("    - %s: $%.2f\n", order->items[i].item_name, order->items[i].item_price);
    }
    printf("Total Price: $%.2f\n", order->total_price);
}

// Main Function
int main() {
    // Create a menu of items
    Item items[] = {
        {1, "Pizza", 10.0},
        {2, "Pasta", 12.0},
        {3, "Salad", 8.0},
        {4, "Burger", 15.0},
        {5, "Fries", 5.0},
        {6, "Soda", 2.0},
        {7, "Water", 1.0},
    };

    // Create a new order
    Order *order = create_order(1, 2);

    // Add items to the order
    add_item_to_order(order, &items[0]);
    add_item_to_order(order, &items[1]);
    add_item_to_order(order, &items[2]);

    // Print the order
    print_order(order);

    return 0;
}