//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
} item_t;

typedef struct {
    item_t items[MAX_ITEMS];
    int num_items;
} order_t;

void add_item(order_t* order, const char* name, double price) {
    if (order->num_items >= MAX_ITEMS) {
        printf("Error: Order is full.\n");
        return;
    }

    strncpy(order->items[order->num_items].name, name, MAX_NAME_LEN);
    order->items[order->num_items].price = price;
    order->num_items++;
}

double get_total_price(const order_t* order) {
    double total_price = 0.0;

    for (int i = 0; i < order->num_items; i++) {
        total_price += order->items[i].price;
    }

    return total_price;
}

void print_order(const order_t* order) {
    printf("Order:\n");

    for (int i = 0; i < order->num_items; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }

    printf("Total price: $%.2f\n", get_total_price(order));
}

int main() {
    order_t order;

    add_item(&order, "Apple", 0.99);
    add_item(&order, "Banana", 0.50);
    add_item(&order, "Orange", 0.75);

    print_order(&order);

    return 0;
}