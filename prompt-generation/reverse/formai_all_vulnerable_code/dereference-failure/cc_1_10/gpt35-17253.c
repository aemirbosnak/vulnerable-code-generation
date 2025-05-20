//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    float price;
} Product;

typedef struct {
    int id;
    char *category;
    Product *products;
    int num_products;
} Warehouse;

void add_product(Product *product, Warehouse *warehouse) {
    warehouse->products = realloc(warehouse->products, (warehouse->num_products + 1) * sizeof(Product));
    warehouse->products[warehouse->num_products] = *product;
    warehouse->num_products++;
}

void display_warehouse(Warehouse *warehouse) {
    printf("\n\nWarehouse %d, Category: %s\n", warehouse->id, warehouse->category);
    printf("\n%-10s %-20s %-10s\n", "Product ID", "Name", "Price");
    for(int i = 0; i < warehouse->num_products; i++) {
        printf("%-10d %-20s $%-9.2f\n", i+1, warehouse->products[i].name, warehouse->products[i].price);
    }
}

void sell_product(int product_id, int quantity, Warehouse *warehouse) {
    if(product_id < 1 || product_id > warehouse->num_products) {
        printf("Invalid Product ID\n");
        return;
    }
    if(quantity > warehouse->products[product_id-1].quantity) {
        printf("Not enough quantity in stock\n");
        return;
    }
    printf("\nSold %d units of %s for $%.2f\n", quantity, warehouse->products[product_id-1].name, warehouse->products[product_id-1].price * quantity);
    warehouse->products[product_id-1].quantity -= quantity;
}

int main() {
    Warehouse warehouse1 = {1, "Electronics", NULL, 0};
    Warehouse warehouse2 = {2, "Clothing", NULL, 0};

    Product product1 = {"Laptop", 10, 1200.50};
    Product product2 = {"Smartphone", 20, 700.00};
    Product product3 = {"T-Shirt", 50, 20.00};
    Product product4 = {"Jeans", 30, 50.00};

    add_product(&product1, &warehouse1);
    add_product(&product2, &warehouse1);
    add_product(&product3, &warehouse2);
    add_product(&product4, &warehouse2);

    display_warehouse(&warehouse1);
    display_warehouse(&warehouse2);

    sell_product(1, 5, &warehouse1);
    sell_product(3, 10, &warehouse2);

    display_warehouse(&warehouse1);
    display_warehouse(&warehouse2);

    return 0;
}