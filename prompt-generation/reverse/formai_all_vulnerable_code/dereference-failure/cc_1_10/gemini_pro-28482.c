//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    int id;
    char *name;
    int quantity;
    float price;
};

struct warehouse {
    int id;
    char *name;
    struct item *items;
    int num_items;
};

struct order {
    int id;
    char *customer_name;
    struct item *items;
    int num_items;
};

int main() {
    // Create a warehouse
    struct warehouse w1 = {
        .id = 1,
        .name = "Warehouse 1",
        .items = NULL,
        .num_items = 0
    };

    // Add some items to the warehouse
    struct item item1 = {
        .id = 1,
        .name = "Item 1",
        .quantity = 10,
        .price = 10.0
    };

    struct item item2 = {
        .id = 2,
        .name = "Item 2",
        .quantity = 20,
        .price = 20.0
    };

    struct item item3 = {
        .id = 3,
        .name = "Item 3",
        .quantity = 30,
        .price = 30.0
    };

    w1.items = realloc(w1.items, (w1.num_items + 3) * sizeof(struct item));
    w1.items[w1.num_items++] = item1;
    w1.items[w1.num_items++] = item2;
    w1.items[w1.num_items++] = item3;

    // Create an order
    struct order o1 = {
        .id = 1,
        .customer_name = "Customer 1",
        .items = NULL,
        .num_items = 0
    };

    // Add some items to the order
    struct item item4 = {
        .id = 1,
        .name = "Item 1",
        .quantity = 2,
        .price = 10.0
    };

    struct item item5 = {
        .id = 2,
        .name = "Item 2",
        .quantity = 3,
        .price = 20.0
    };

    o1.items = realloc(o1.items, (o1.num_items + 2) * sizeof(struct item));
    o1.items[o1.num_items++] = item4;
    o1.items[o1.num_items++] = item5;

    // Print the warehouse
    printf("Warehouse:\n");
    printf("  ID: %d\n", w1.id);
    printf("  Name: %s\n", w1.name);
    printf("  Items:\n");
    for (int i = 0; i < w1.num_items; i++) {
        printf("    ID: %d\n", w1.items[i].id);
        printf("    Name: %s\n", w1.items[i].name);
        printf("    Quantity: %d\n", w1.items[i].quantity);
        printf("    Price: %.2f\n", w1.items[i].price);
    }

    // Print the order
    printf("Order:\n");
    printf("  ID: %d\n", o1.id);
    printf("  Customer Name: %s\n", o1.customer_name);
    printf("  Items:\n");
    for (int i = 0; i < o1.num_items; i++) {
        printf("    ID: %d\n", o1.items[i].id);
        printf("    Name: %s\n", o1.items[i].name);
        printf("    Quantity: %d\n", o1.items[i].quantity);
        printf("    Price: %.2f\n", o1.items[i].price);
    }

    return 0;
}