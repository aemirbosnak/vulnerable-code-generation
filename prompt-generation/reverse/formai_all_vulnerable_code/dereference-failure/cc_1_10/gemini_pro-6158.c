//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Item {
    char name[100];
    double price;
    int quantity;
};

struct Warehouse {
    struct Item *items;
    int size;
};

struct Warehouse *create_warehouse(int size) {
    struct Warehouse *warehouse = malloc(sizeof(struct Warehouse));
    warehouse->items = malloc(size * sizeof(struct Item));
    warehouse->size = size;
    return warehouse;
}

void add_item(struct Warehouse *warehouse, struct Item item) {
    for (int i = 0; i < warehouse->size; i++) {
        if (strcmp(warehouse->items[i].name, item.name) == 0) {
            warehouse->items[i].quantity += item.quantity;
            return;
        }
    }
    warehouse->items[warehouse->size++] = item;
}

void remove_item(struct Warehouse *warehouse, char *name, int quantity) {
    for (int i = 0; i < warehouse->size; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            if (warehouse->items[i].quantity < quantity) {
                printf("Insufficient quantity of item %s\n", name);
                return;
            }
            warehouse->items[i].quantity -= quantity;
            if (warehouse->items[i].quantity == 0) {
                for (int j = i; j < warehouse->size - 1; j++) {
                    warehouse->items[j] = warehouse->items[j + 1];
                }
                warehouse->size--;
            }
            return;
        }
    }
    printf("Item %s not found\n", name);
}

double get_total_value(struct Warehouse *warehouse) {
    double total_value = 0;
    for (int i = 0; i < warehouse->size; i++) {
        total_value += warehouse->items[i].price * warehouse->items[i].quantity;
    }
    return total_value;
}

void print_warehouse(struct Warehouse *warehouse) {
    printf("------------------------------------------------\n");
    printf("| Name | Price | Quantity | Total Value |\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < warehouse->size; i++) {
        printf("| %-20s | %-6.2f | %-8d | %-10.2f |\n",
               warehouse->items[i].name, warehouse->items[i].price,
               warehouse->items[i].quantity,
               warehouse->items[i].price * warehouse->items[i].quantity);
    }
    printf("------------------------------------------------\n");
    printf("Total Value: %.2f\n", get_total_value(warehouse));
    printf("------------------------------------------------\n");
}

int main() {
    srand(time(NULL));

    struct Warehouse *warehouse = create_warehouse(10);

    struct Item item1 = {"iPhone", 1000.0, 10};
    struct Item item2 = {"iPad", 800.0, 15};
    struct Item item3 = {"MacBook", 1500.0, 5};

    add_item(warehouse, item1);
    add_item(warehouse, item2);
    add_item(warehouse, item3);

    print_warehouse(warehouse);

    remove_item(warehouse, "iPhone", 5);
    remove_item(warehouse, "iPad", 10);
    remove_item(warehouse, "MacBook", 2);

    print_warehouse(warehouse);

    return 0;
}