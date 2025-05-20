//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

struct item {
    char* name;
    int price;
    int quantity;
};

struct order {
    struct item items[100];
    int num_items;
    int total_price;
};

struct order* create_order() {
    struct order* order = malloc(sizeof(struct order));
    order->num_items = 0;
    order->total_price = 0;
    return order;
}

void add_item_to_order(struct order* order, struct item* item) {
    order->items[order->num_items] = *item;
    order->num_items++;
    order->total_price += item->price * item->quantity;
}

void print_order(struct order* order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s x %d: $%d\n", order->items[i].name, order->items[i].quantity, order->items[i].price);
    }
    printf("Total: $%d\n", order->total_price);
}

int main() {
    struct order* order = create_order();

    struct item item1 = { "Coffee", 2, 1 };
    add_item_to_order(order, &item1);

    struct item item2 = { "Tea", 3, 2 };
    add_item_to_order(order, &item2);

    struct item item3 = { "Cake", 5, 1 };
    add_item_to_order(order, &item3);

    print_order(order);

    return 0;
}