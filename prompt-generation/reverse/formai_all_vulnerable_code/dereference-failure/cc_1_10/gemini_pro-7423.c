//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    double price;
} Item;

typedef struct {
    int num_items;
    Item *items;
} Order;

Order *new_order() {
    Order *order = malloc(sizeof(Order));
    order->num_items = 0;
    order->items = NULL;
    return order;
}

void add_item(Order *order, char *name, int quantity, double price) {
    order->num_items++;
    order->items = realloc(order->items, sizeof(Item) * order->num_items);
    Item *item = &order->items[order->num_items - 1];
    item->name = name;
    item->quantity = quantity;
    item->price = price;
}

double calculate_total(Order *order) {
    double total = 0;
    for (int i = 0; i < order->num_items; i++) {
        Item *item = &order->items[i];
        total += item->quantity * item->price;
    }
    return total;
}

void print_order(Order *order) {
    printf("Order Summary\n");
    for (int i = 0; i < order->num_items; i++) {
        Item *item = &order->items[i];
        printf("%s x %d = $%.2f\n", item->name, item->quantity, item->price * item->quantity);
    }
    printf("Total: $%.2f\n", calculate_total(order));
}

int main() {
    Order *order = new_order();
    add_item(order, "Coffee", 2, 2.50);
    add_item(order, "Tea", 1, 1.50);
    add_item(order, "Pastry", 1, 3.00);
    print_order(order);
    return 0;
}