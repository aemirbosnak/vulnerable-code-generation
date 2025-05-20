//FormAI DATASET v1.0 Category: Product Inventory System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int product_id;
    char product_name[50];
    int quantity;
    float cost_price;
    float selling_price;
} Product;

int menu() {
    int choice;
    printf("PRODUCT INVENTORY SYSTEM\n");
    printf("1. Add Product\n");
    printf("2. View All Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_product(Product **inventory, int *size, Product p) {
    *inventory = (Product*)realloc(*inventory, (*size + 1) * sizeof(Product));
    (*inventory)[*size] = p;
    (*size)++;
    printf("Product added successfully!\n");
}

void view_products(Product *inventory, int size) {
    printf("PRODUCT ID\tPRODUCT NAME\tQUANTITY\tCOST PRICE\tSELLING PRICE\n");
    for(int i = 0; i < size; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%.2f\n", inventory[i].product_id, inventory[i].product_name, inventory[i].quantity, inventory[i].cost_price, inventory[i].selling_price);
    }
}

void update_product(Product *inventory, int size, int product_id, Product updated_product) {
    for(int i = 0; i < size; i++) {
        if(inventory[i].product_id == product_id) {
            inventory[i] = updated_product;
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found!\n", product_id);
}

void delete_product(Product **inventory, int *size, int product_id) {
    int found = 0;
    for(int i = 0; i < *size; i++) {
        if((*inventory)[i].product_id == product_id) {
            for(int j = i; j < *size - 1; j++) {
                (*inventory)[j] = (*inventory)[j + 1];
            }
            *inventory = (Product*)realloc(*inventory, (*size - 1) * sizeof(Product));
            (*size)--;
            printf("Product deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Product with ID %d not found!\n", product_id);
    }
}

int main() {
    Product *inventory = NULL;
    int size = 0;
    while(1) {
        int choice = menu();
        switch(choice) {
            case 1: 
                {
                    Product p;
                    printf("Enter product ID: ");
                    scanf("%d", &p.product_id);
                    printf("Enter product name: ");
                    scanf(" %[^\n]", p.product_name);
                    printf("Enter quantity: ");
                    scanf("%d", &p.quantity);
                    printf("Enter cost price: ");
                    scanf("%f", &p.cost_price);
                    printf("Enter selling price: ");
                    scanf("%f", &p.selling_price);
                    add_product(&inventory, &size, p);
                }
                break;
            case 2:
                {
                    if(size == 0) {
                        printf("No products found!\n");
                    } else {
                        view_products(inventory, size);
                    }
                }
                break;
            case 3:
                {
                    int product_id;
                    printf("Enter product ID to update: ");
                    scanf("%d", &product_id);
                    Product updated_product;
                    printf("Enter new product ID: ");
                    scanf("%d", &updated_product.product_id);
                    printf("Enter new product name: ");
                    scanf(" %[^\n]", updated_product.product_name);
                    printf("Enter new quantity: ");
                    scanf("%d", &updated_product.quantity);
                    printf("Enter new cost price: ");
                    scanf("%f", &updated_product.cost_price);
                    printf("Enter new selling price: ");
                    scanf("%f", &updated_product.selling_price);
                    update_product(inventory, size, product_id, updated_product);
                }
                break;
            case 4:
                {
                    int product_id;
                    printf("Enter product ID to delete: ");
                    scanf("%d", &product_id);
                    delete_product(&inventory, &size, product_id);
                }
                break;
            case 5: 
                exit(0);
            default: 
                printf("Invalid choice!\n");
        }
    }
    free(inventory);
    return 0;
}