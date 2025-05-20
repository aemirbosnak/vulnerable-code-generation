//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products and orders
#define MAX_PRODUCTS 100
#define MAX_ORDERS 100

// Define the product structure
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Define the order structure
typedef struct order {
    int id;
    int product_id;
    int quantity;
    float total_price;
} order;

// Define the warehouse structure
typedef struct warehouse {
    product products[MAX_PRODUCTS];
    int num_products;
    order orders[MAX_ORDERS];
    int num_orders;
} warehouse;

// Create a new warehouse
warehouse* create_warehouse() {
    warehouse* w = (warehouse*)malloc(sizeof(warehouse));
    w->num_products = 0;
    w->num_orders = 0;
    return w;
}

// Add a new product to the warehouse
void add_product(warehouse* w, product p) {
    w->products[w->num_products] = p;
    w->num_products++;
}

// Add a new order to the warehouse
void add_order(warehouse* w, order o) {
    w->orders[w->num_orders] = o;
    w->num_orders++;
}

// Get the total value of the warehouse
float get_total_value(warehouse* w) {
    float total_value = 0;
    for (int i = 0; i < w->num_products; i++) {
        total_value += w->products[i].quantity * w->products[i].price;
    }
    return total_value;
}

// Print the warehouse inventory
void print_inventory(warehouse* w) {
    printf("Warehouse inventory:\n");
    for (int i = 0; i < w->num_products; i++) {
        printf("Product %d: %s, quantity %d, price %.2f\n", w->products[i].id, w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

// Print the warehouse orders
void print_orders(warehouse* w) {
    printf("Warehouse orders:\n");
    for (int i = 0; i < w->num_orders; i++) {
        printf("Order %d: product %d, quantity %d, total price %.2f\n", w->orders[i].id, w->orders[i].product_id, w->orders[i].quantity, w->orders[i].total_price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some products to the warehouse
    product p1 = {1, "Apple", 10, 1.0};
    product p2 = {2, "Orange", 20, 2.0};
    product p3 = {3, "Banana", 30, 3.0};
    add_product(w, p1);
    add_product(w, p2);
    add_product(w, p3);

    // Add some orders to the warehouse
    order o1 = {1, 1, 5, 5.0};
    order o2 = {2, 2, 10, 20.0};
    order o3 = {3, 3, 15, 45.0};
    add_order(w, o1);
    add_order(w, o2);
    add_order(w, o3);

    // Print the warehouse inventory
    print_inventory(w);

    // Print the warehouse orders
    print_orders(w);

    // Get the total value of the warehouse
    float total_value = get_total_value(w);
    printf("Total value of the warehouse: %.2f\n", total_value);

    return 0;
}