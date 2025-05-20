//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEM_NAME_LEN 100
#define MAX_ITEM_QTY 1000
#define MAX_WAREHOUSE_SIZE 1000
#define MAX_ORDER_SIZE 100

typedef struct {
    char name[MAX_ITEM_NAME_LEN];
    int qty;
} Item;

typedef struct {
    Item *items;
    int num_items;
    int warehouse_size;
} Warehouse;

typedef struct {
    Item *items;
    int num_items;
} Order;

void generate_random_item(Item *item) {
    sprintf(item->name, "Item %d", rand() % MAX_ITEM_QTY);
    item->qty = rand() % MAX_ITEM_QTY;
}

void print_item(const Item *item) {
    printf("%s (%d)\n", item->name, item->qty);
}

void generate_random_warehouse(Warehouse *warehouse) {
    warehouse->items = (Item *)malloc(MAX_WAREHOUSE_SIZE * sizeof(Item));
    warehouse->num_items = 0;
    warehouse->warehouse_size = MAX_WAREHOUSE_SIZE;

    for (int i = 0; i < MAX_WAREHOUSE_SIZE; i++) {
        generate_random_item(&warehouse->items[i]);
        warehouse->num_items++;
    }
}

void print_warehouse(const Warehouse *warehouse) {
    printf("Warehouse:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        print_item(&warehouse->items[i]);
    }
}

void generate_random_order(Order *order) {
    order->items = (Item *)malloc(MAX_ORDER_SIZE * sizeof(Item));
    order->num_items = 0;

    for (int i = 0; i < MAX_ORDER_SIZE; i++) {
        generate_random_item(&order->items[i]);
        order->num_items++;
    }
}

void print_order(const Order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        print_item(&order->items[i]);
    }
}

int main() {
    srand(time(NULL));

    Warehouse warehouse;
    generate_random_warehouse(&warehouse);
    print_warehouse(&warehouse);

    Order order;
    generate_random_order(&order);
    print_order(&order);

    return 0;
}