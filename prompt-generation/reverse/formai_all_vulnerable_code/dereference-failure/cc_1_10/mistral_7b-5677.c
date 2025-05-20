//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 10
#define MAX_PRICE 100.0

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Order;

void add_item(Order *order, const char *name, int quantity, float price) {
    if (order->num_items >= MAX_ITEMS) {
        fprintf(stderr, "Error: Maximum number of items reached.\n");
        return;
    }

    strcpy(order->items[order->num_items].name, name);
    order->items[order->num_items].quantity = quantity;
    order->items[order->num_items].price = price;
    order->num_items++;
}

void print_order(const Order *order) {
    printf("Order Summary:\n");
    float total = 0.0;

    for (int i = 0; i < order->num_items; i++) {
        printf("%s: %d x %0.2f = %0.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price, order->items[i].quantity * order->items[i].price);
        total += order->items[i].quantity * order->items[i].price;
    }

    printf("Total: %0.2f\n", total);
}

int main() {
    srand(time(NULL));
    Order order;

    printf("Welcome to C Cafe Billing System!\n");
    printf("Enter the number of items in the order (max. %d): ", MAX_ITEMS);
    int num_items;
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        char name[MAX_NAME_LEN];
        int quantity;
        float price;

        printf("Enter item %d name (max. %d chars): ", i+1, MAX_NAME_LEN);
        scanf("%s", name);
        strcpy(order.items[i].name, name);

        printf("Enter item %d quantity: ", i+1);
        scanf("%d", &quantity);
        order.items[i].quantity = quantity;

        printf("Enter item %d price: ", i+1);
        scanf("%f", &price);
        order.items[i].price = price;

        add_item(&order, name, quantity, price);
    }

    print_order(&order);

    return 0;
}