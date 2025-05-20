//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    char* name;
    float price;
    int quantity;
} Item;

typedef struct order {
    Item items[10];
    int num_items;
    float total;
} Order;

void create_order(Order* order, char* item_name, float price, int quantity) {
    if (order->num_items >= 10) {
        printf("Sorry, your order is too large.\n");
        return;
    }

    Item item;
    item.name = malloc(strlen(item_name) + 1);
    strcpy(item.name, item_name);
    item.price = price;
    item.quantity = quantity;
    order->items[order->num_items++] = item;
}

void print_order(Order* order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("- %s (%0.2f) x%d\n", order->items[i].name, order->items[i].price, order->items[i].quantity);
    }
    printf("Total: %0.2f\n", order->total);
}

int main() {
    Order order;
    order.num_items = 0;

    create_order(&order, "Candy Bar", 0.50, 1);
    create_order(&order, "Lollipop", 1.00, 5);
    create_order(&order, "Sour Patch Kid", 0.75, 3);

    printf("Order:\n");
    print_order(&order);

    return 0;
}