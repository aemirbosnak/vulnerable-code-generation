//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#define MAX_ORDERS 10
#define MAX_ITEMS 10

typedef struct {
    char name[30];
    float price;
} Item;

typedef struct {
    int qty;
    Item menuItem;
} Order;

void initMenu(Item menu[], const char menuItems[], int numItems) {
    for (int i = 0; i < numItems; ++i) {
        strcpy(menu[i].name, menuItems + i * 30);
        sscanf(menuItems + i * 30 + 28, "%f", &menu[i].price);
    }
}

void addOrder(Order orders[], int *numOrders, Order newOrder) {
    orders[*numOrders] = newOrder;
    (*numOrders)++;
}

float calculateTotal(Order orders[], int numOrders) {
    float total = 0;
    for (int i = 0; i < numOrders; ++i) {
        total += orders[i].qty * orders[i].menuItem.price;
    }
    return total;
}

void printOrder(Order order) {
    printf("%d. %s (%d pcs): %.2f$\n", order.qty, order.menuItem.name, order.qty, order.menuItem.price);
}

void printReceipt(Order orders[], int numOrders, float total) {
    printf("\n-------------------------------------------\n");
    printf("| Billing Receipt                          |\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < numOrders; ++i) {
        printOrder(orders[i]);
    }
    printf("-------------------------------------------\n");
    printf("| Total: %.2f$                            |\n", total);
    printf("-------------------------------------------\n");
}

int main() {
    Item menu[MAX_ITEMS];
    initMenu(menu, "Burger King Menu\0", MAX_ITEMS);

    Order orders[MAX_ORDERS];
    int numOrders = 0;

    for (int i = 0; i < 5; ++i) {
        Order newOrder;
        newOrder.qty = i + 1;
        strcpy(newOrder.menuItem.name, "Whopper");
        newOrder.menuItem.price = menu[0].price;
        addOrder(orders, &numOrders, newOrder);
    }

    float total = calculateTotal(orders, numOrders);

    printf("You have ordered:\n");
    for (int i = 0; i < numOrders; ++i) {
        printOrder(orders[i]);
    }

    printf("\nPress Enter to calculate the total and print the receipt...");
    getchar();
    printReceipt(orders, numOrders, total);

    return 0;
}