//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_CATEGORY_LEN 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    double price;
} Item;

void print_item(Item *item) {
    printf("Name: %s\n", item->name);
    printf("Description: %s\n", item->description);
    printf("Category: %s\n", item->category);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: $%.2f\n\n", item->price);
}

int main() {
    // Initialize inventory
    Item inventory[MAX_ITEMS];
    int num_items = 0;

    // Read items from file
    FILE *fp = fopen("inventory.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open inventory file.\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_items >= MAX_ITEMS) {
            printf("Error: Inventory is full.\n");
            exit(1);
        }

        char *token = strtok(line, ",");
        if (token == NULL) {
            printf("Error: Invalid item format.\n");
            exit(1);
        }

        strcpy(inventory[num_items].name, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid item format.\n");
            exit(1);
        }

        strcpy(inventory[num_items].description, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid item format.\n");
            exit(1);
        }

        strcpy(inventory[num_items].category, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid item format.\n");
            exit(1);
        }

        inventory[num_items].quantity = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid item format.\n");
            exit(1);
        }

        inventory[num_items].price = atof(token);
        num_items++;
    }

    fclose(fp);

    // Display inventory
    printf("Inventory:\n");
    for (int i = 0; i < num_items; i++) {
        print_item(&inventory[i]);
    }

    return 0;
}