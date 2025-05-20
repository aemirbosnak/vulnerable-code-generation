//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50
#define INVENTORY_FILE "inventory.dat"

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

void load_inventory(Product inventory[]) {
    FILE *file = fopen(INVENTORY_FILE, "rb");

    if (file == NULL) {
        printf("Error: Could not open inventory file.\n");
        exit(1);
    }

    fread(inventory, sizeof(Product), MAX_PRODUCTS, file);
    fclose(file);
}

void save_inventory(Product inventory[]) {
    FILE *file = fopen(INVENTORY_FILE, "wb");

    if (file == NULL) {
        printf("Error: Could not open inventory file for writing.\n");
        exit(1);
    }

    fwrite(inventory, sizeof(Product), MAX_PRODUCTS, file);
    fclose(file);
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int i, choice, product_index;
    char name[PRODUCT_NAME_LENGTH];

    load_inventory(inventory);

    do {
        printf("\nProduct Inventory System\n");
        printf("--------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. List products\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                strcpy(inventory[i].name, name);
                printf("Enter product quantity: ");
                scanf("%d", &inventory[i].quantity);
                i++;
                break;
            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", name);
                for (int j = 0; j < i; j++) {
                    if (strcmp(inventory[j].name, name) == 0) {
                        product_index = j;
                        break;
                    }
                }
                for (int j = product_index; j < i - 1; j++) {
                    strcpy(inventory[j].name, inventory[j + 1].name);
                    inventory[j].quantity = inventory[j + 1].quantity;
                }
                i--;
                break;
            case 3:
                for (int j = 0; j < i; j++) {
                    printf("\nProduct %d:\n", j + 1);
                    printf("Name: %s\n", inventory[j].name);
                    printf("Quantity: %d\n", inventory[j].quantity);
                }
                break;
            case 4:
                save_inventory(inventory);
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}