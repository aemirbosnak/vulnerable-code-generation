//FormAI DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct inventory {
    char product_name[50];
    int quantity;
    float price;
};

typedef struct inventory Inventory;

int main() {
    int n, option, index = 0;
    char temp_name[50];
    float temp_price;
    int temp_quantity;
    printf("Welcome to the Product Inventory System.\nPlease enter the number of products you want to add: ");
    scanf("%d", &n);
    Inventory *inventory_list = malloc(n * sizeof(Inventory));
    if (inventory_list == NULL) {
        printf("Failed to allocate memory for inventory list.\n");
        return 1;
    }

    while (1) {
        printf("\n\nEnter an Option:\n1 - Add a Product\n2 - Remove a Product\n3 - Display Inventory\n4 - Search by Product Name\n5 - Search by Price\n6 - Exit\nOption: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("\n\nEnter Product Details:\nName: ");
            scanf("%s", &temp_name);
            printf("Quantity: ");
            scanf("%d", &temp_quantity);
            printf("Price: ");
            scanf("%f", &temp_price);
            Inventory item;
            strcpy(item.product_name, temp_name);
            item.quantity = temp_quantity;
            item.price = temp_price;
            inventory_list[index] = item;
            index++;
            printf("Product Added Successfully.\n");
        }

        else if (option == 2) {
            printf("\n\nEnter Product Name to be Removed: ");
            scanf("%s", &temp_name);
            int item_found = 0;
            for (int i = 0; i < index; i++) {
                if (strcmp(inventory_list[i].product_name, temp_name) == 0) {
                    item_found = 1;
                    if (i+1 == index) {
                        index--;
                    }
                    else {
                        for (int j = i; j < index - 1; j++) {
                            inventory_list[j] = inventory_list[j+1];
                        }
                        index--;
                    }
                    printf("Product Removed Successfully.\n");
                }
            }
            if (!item_found) {
                printf("Product Not Found.\n");
            }
        }

        else if (option == 3) {
            printf("\n\nInventory Details:\n");
            for (int i = 0; i < index; i++) {
                printf("Product Name: %s\nQuantity: %d\nPrice: $%.2f\n\n", inventory_list[i].product_name, inventory_list[i].quantity, inventory_list[i].price);
            }
        }

        else if (option == 4) {
            printf("\nEnter Product Name to Search: ");
            scanf("%s", &temp_name);
            int item_found = 0;
            for (int i = 0; i < index; i++) {
                if (strcmp(inventory_list[i].product_name, temp_name) == 0) {
                    item_found = 1;
                    printf("Product Found:\nName: %s\nQuantity: %d\nPrice: $%.2f\n", inventory_list[i].product_name, inventory_list[i].quantity, inventory_list[i].price);
                }
            }
            if (!item_found) {
                printf("Product Not Found.\n");
            }
        }

        else if (option == 5) {
            printf("\nEnter Price to Search: ");
            scanf("%f", &temp_price);
            int item_found = 0;
            for (int i = 0; i < index; i++) {
                if (inventory_list[i].price == temp_price) {
                    item_found = 1;
                    printf("Product Found:\nName: %s\nQuantity: %d\nPrice: $%.2f\n", inventory_list[i].product_name, inventory_list[i].quantity, inventory_list[i].price);
                }
            }
            if (!item_found) {
                printf("Product Not Found.\n");
            }
        }

        else if (option == 6) {
            printf("\nExiting Product Inventory System.\n\n");
            break;
        }

        else {
            printf("\nInvalid Option. Please Try Again!\n");
        }
    }
    free(inventory_list);
    return 0;
}