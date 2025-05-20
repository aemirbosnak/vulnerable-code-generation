//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct item {
    char *name;
    int quantity;
    double price;
};

struct order {
    struct item *items;
    int num_items;
    double total_price;
};

struct order *new_order() {
    struct order *order = malloc(sizeof(struct order));
    order->items = NULL;
    order->num_items = 0;
    order->total_price = 0.0;
    return order;
}

void add_item(struct order *order, struct item *item) {
    order->items = realloc(order->items, (order->num_items + 1) * sizeof(struct item));
    order->items[order->num_items] = *item;
    order->num_items++;
    order->total_price += item->quantity * item->price;
}

void print_order(struct order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("  %d %s x %d @ $%.2f\n",
            i + 1, order->items[i].name, order->items[i].quantity, order->items[i].price);
    }
    printf("Total price: $%.2f\n", order->total_price);
}

int main() {
    struct order *order = new_order();

    // Add some items to the order
    struct item item1 = {"Coffee", 1, 2.50};
    add_item(order, &item1);
    struct item item2 = {"Tea", 2, 1.50};
    add_item(order, &item2);
    struct item item3 = {"Muffin", 3, 1.00};
    add_item(order, &item3);

    // Print the order
    print_order(order);

    // Free the order
    free(order->items);
    free(order);

    return 0;
}