//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_SIZE 50
#define PRODUCT_QUANTITY_SIZE 10

typedef struct {
    char name[PRODUCT_NAME_SIZE];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }
    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    num_products++;
}

void remove_product(char *name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = 0;
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            break;
        }
    }
    if (i == num_products) {
        printf("Error: Product not found.\n");
    }
}

void display_inventory() {
    int i;
    printf("Product Inventory:\n");
    for (i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [add|remove] [product_name] [quantity]\n", argv[0]);
        return 1;
    }

    char command = argv[1][0];
    if (command != 'a' && command != 'r') {
        printf("Error: Invalid command.\n");
        return 1;
    }

    char *product_name = argv[2];
    int quantity = 1;

    if (command == 'a') {
        if (argc != 4) {
            printf("Usage: %s a [product_name] [quantity]\n", argv[0]);
            return 1;
        }

        quantity = atoi(argv[3]);
        add_product(product_name, quantity);
    } else if (command == 'r') {
        remove_product(product_name);
    }

    display_inventory();

    return 0;
}