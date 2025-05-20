//FormAI DATASET v1.0 Category: Product Inventory System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INVENTORY 1000

typedef struct {
    char product_name[100];
    int product_id;
    int quantity;
    float price;
} product;

product inventory[MAX_INVENTORY];
int num_products = 0;

void add_product() {
    if (num_products < MAX_INVENTORY) {
        printf("Enter product name: ");
        scanf("%s", inventory[num_products].product_name);
        printf("Enter product ID: ");
        scanf("%d", &inventory[num_products].product_id);
        printf("Enter quantity: ");
        scanf("%d", &inventory[num_products].quantity);
        printf("Enter price: ");
        scanf("%f", &inventory[num_products].price);
        num_products++;
        printf("Product added successfully.\n");
    }
    else {
        printf("Inventory is full.\n");
    }
}

void sell_product() {
    int product_id, found_product = 0;
    printf("Enter product ID: ");
    scanf("%d", &product_id);
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].product_id == product_id) {
            found_product = 1;
            if (inventory[i].quantity == 0) {
                printf("Sorry, %s is out of stock.\n", inventory[i].product_name);
            }
            else {
                inventory[i].quantity--;
                printf("Sold 1 %s for $%.2f\n", inventory[i].product_name, inventory[i].price);
            }
            break;
        }
    }
    if (!found_product) {
        printf("Product not found.\n");
    }
}

void print_inventory() {
    if (num_products == 0) {
        printf("Inventory is empty.\n");
    }
    else {
        printf("Product Name\tProduct ID\tQuantity\tPrice\n");
        for (int i = 0; i < num_products; i++) {
            printf("%s\t\t%d\t\t%d\t\t%.2f\n", inventory[i].product_name, inventory[i].product_id, inventory[i].quantity, inventory[i].price);
        }
    }
}

void save_inventory() {
    FILE *fp;
    fp = fopen("inventory.txt", "w");
    if (fp == NULL) {
        printf("Unable to create file.\n");
    }
    else {
        for (int i = 0; i < num_products; i++) {
            fprintf(fp, "%s,%d,%d,%.2f\n", inventory[i].product_name, inventory[i].product_id, inventory[i].quantity, inventory[i].price);
        }
        printf("Inventory saved to file.\n");
    }
    fclose(fp);
}

void load_inventory() {
    FILE *fp;
    fp = fopen("inventory.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
    }
    else {
        num_products = 0;
        char line[100];
        while (fgets(line, sizeof(line), fp)) {
            char *token = strtok(line, ",");
            strcpy(inventory[num_products].product_name, token);
            token = strtok(NULL, ",");
            inventory[num_products].product_id = atoi(token);
            token = strtok(NULL, ",");
            inventory[num_products].quantity = atoi(token);
            token = strtok(NULL, ",");
            inventory[num_products].price = atof(token);
            num_products++;
        }
        printf("Inventory loaded from file.\n");
    }
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("Select an option:\n1. Add a product\n2. Sell a product\n3. Print inventory\n4. Save inventory\n5. Load inventory\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                sell_product();
                break;
            case 3:
                print_inventory();
                break;
            case 4:
                save_inventory();
                break;
            case 5:
                load_inventory();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}