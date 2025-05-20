//FormAI DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROD 100 // Maximum number of products in the inventory
#define MAX_NAME 50 // Maximum length of a product name
#define MAX_QUANTITY 999 // Maximum quantity of a product

typedef struct product {
    char name[MAX_NAME];
    int quantity;
} product;

void print_menu();
void add_product(product** inventory, int* num_products);
void remove_product(product** inventory, int* num_products);
void update_quantity(product** inventory, int num_products);
void search_product(product** inventory, int num_products);

int main() {
    product* inventory[MAX_PROD];
    int num_products = 0;
    int choice;

    printf("Welcome to the Paranoid Product Inventory System!\n");

    do {
        print_menu();
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                remove_product(inventory, &num_products);
                break;
            case 3:
                update_quantity(inventory, num_products);
                break;
            case 4:
                search_product(inventory, num_products);
                break;
            case 5:
                printf("Thank you for using the Paranoid Product Inventory System!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

void print_menu() {
    printf("\n1. Add new product\n");
    printf("2. Remove a product\n");
    printf("3. Update product quantity\n");
    printf("4. Search for a product\n");
    printf("5. Exit program\n");
}

void add_product(product** inventory, int* num_products) {
    char product_name[MAX_NAME];
    int product_quantity;

    if (*num_products >= MAX_PROD) {
        printf("Maximum number of products reached. Cannot add new product.\n");
        return;
    }

    printf("\nEnter name of product: ");
    scanf("%s", product_name);

    printf("Enter quantity of product: ");
    scanf("%d", &product_quantity);

    if (product_quantity > MAX_QUANTITY) {
        printf("Invalid quantity. Quantity cannot exceed %d.\n", MAX_QUANTITY);
        return;
    }

    product* new_product = (product*) malloc(sizeof(product));
    strncpy(new_product->name, product_name, MAX_NAME);
    new_product->quantity = product_quantity;

    inventory[*num_products] = new_product;
    (*num_products)++;

    printf("Product added.\n");
}

void remove_product(product** inventory, int* num_products) {
    char product_name[MAX_NAME];
    int i;

    printf("\nEnter name of product to remove: ");
    scanf("%s", product_name);

    for (i = 0; i < *num_products; i++) {
        if (strcmp(inventory[i]->name, product_name) == 0) {
            free(inventory[i]);
            (*num_products)--;
            inventory[i] = inventory[*num_products];
            printf("Product removed.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void update_quantity(product** inventory, int num_products) {
    char product_name[MAX_NAME];
    int i, product_quantity;

    printf("\nEnter name of product to update: ");
    scanf("%s", product_name);

    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i]->name, product_name) == 0) {
            printf("Enter new quantity of product: ");
            scanf("%d", &product_quantity);

            if (product_quantity > MAX_QUANTITY) {
                printf("Invalid quantity. Quantity cannot exceed %d.\n", MAX_QUANTITY);
                return;
            }

            inventory[i]->quantity = product_quantity;
            printf("Product quantity updated.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void search_product(product** inventory, int num_products) {
    char product_name[MAX_NAME];
    int i;

    printf("\nEnter name of product to search: ");
    scanf("%s", product_name);

    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i]->name, product_name) == 0) {
            printf("\nProduct found:\n");
            printf("Name: %s\n", inventory[i]->name);
            printf("Quantity: %d\n", inventory[i]->quantity);
            return;
        }
    }

    printf("Product not found.\n");
}