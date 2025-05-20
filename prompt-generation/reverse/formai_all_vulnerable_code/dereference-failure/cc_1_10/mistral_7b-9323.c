//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Product {
    char name[50];
    char sku[20];
    int stock;
} Product;

int num_products = 0;
Product *products = NULL;

void add_product(const char *name, const char *sku, int stock) {
    Product *new_product = (Product *) malloc(sizeof(Product));

    strcpy(new_product->name, name);
    strcpy(new_product->sku, sku);
    new_product->stock = stock;

    products[num_products++] = *new_product;
}

bool remove_product(const char *sku) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].sku, sku) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                products[j] = products[j + 1];
            }
            num_products--;
            return true;
        }
    }

    return false;
}

int get_stock(const char *sku) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].sku, sku) == 0) {
            return products[i].stock;
        }
    }

    return -1;
}

void display_inventory() {
    printf("\n-------------------------------------------------\n");
    printf("|              The Enchanted Warehouse            |\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("| %-20s | %-10s | %d                             |\n", products[i].name, products[i].sku, products[i].stock);
    }

    printf("-------------------------------------------------\n");
}

int main() {
    add_product("Mystic Orb", "MORB-001", 25);
    add_product("Enchanted Elixir", "EE-002", 12);
    add_product("Crystal Wand", "CW-003", 5);

    display_inventory();

    printf("\nRemove Crystal Wand from inventory...\n");
    remove_product("CW-003");

    display_inventory();

    printf("\nCheck the stock level of Mystic Orb...\n");
    int stock_level = get_stock("MORB-001");
    printf("The stock level of Mystic Orb is: %d\n", stock_level);

    return 0;
}