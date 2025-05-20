//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 10
#define MAX_ORDER_ITEMS 10

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int quantity;
    MenuItem item;
} OrderItem;

typedef struct {
    MenuItem items[MAX_MENU_ITEMS];
    int numItems;
} Menu;

typedef struct {
    OrderItem items[MAX_ORDER_ITEMS];
    int numItems;
    float totalPrice;
} Order;

void addMenuItem(Menu *menu, char *name, float price) {
    if (menu->numItems >= MAX_MENU_ITEMS) {
        printf("Menu is full. Cannot add more items.\n");
        return;
    }

    strcpy(menu->items[menu->numItems].name, name);
    menu->items[menu->numItems].price = price;
    menu->numItems++;
}

void printMenu(Menu *menu) {
    printf("Menu:\n");
    for (int i = 0; i < menu->numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu->items[i].name, menu->items[i].price);
    }
}

void addOrderItem(Order *order, int quantity, MenuItem *item) {
    if (order->numItems >= MAX_ORDER_ITEMS) {
        printf("Order is full. Cannot add more items.\n");
        return;
    }

    order->items[order->numItems].quantity = quantity;
    order->items[order->numItems].item = *item;
    order->numItems++;
}

void printOrder(Order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%d. %s - $%.2f x %d = $%.2f\n", i+1, order->items[i].item.name, order->items[i].item.price, order->items[i].quantity, order->items[i].item.price * order->items[i].quantity);
    }
}

int main() {
    Menu menu;
    Order order;

    addMenuItem(&menu, "Coffee", 2.50);
    addMenuItem(&menu, "Tea", 1.75);
    addMenuItem(&menu, "Cappuccino", 3.75);

    printMenu(&menu);

    addOrderItem(&order, 2, &menu.items[0]);
    addOrderItem(&order, 1, &menu.items[2]);

    printOrder(&order);

    return 0;
}