//FormAI DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[20];
    int quantity;
    float price;
};

int main() {

    int n, choice, flag = 0, update_choice;
    float total_amount = 0.0;
    char name[20];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Taking inputs
    for(int i = 0; i < n; i++) {
        printf("\nItem %d details:\n", i+1);
        printf("Enter the name of the item: ");
        scanf("%s", items[i].name);
        printf("Enter the quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Enter the price: ");
        scanf("%f", &items[i].price);
    }

    // Menu
    printf("\nMenu\n");
    printf("1. Print inventory\n");
    printf("2. Search for an item\n");
    printf("3. Update inventory\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while(!(choice >=1 && choice <= 4)) {
        printf("Invalid choice, please select again: ");
        scanf("%d", &choice);
    }

    while(choice != 4) {

        switch(choice) {

            case 1:
                // Printing inventory
                printf("\nInventory:\n");
                printf("%-20s%-15s%-15s\n", "Item Name", "Quantity", "Price");
                for(int i = 0; i < n; i++) {
                    printf("%-20s%-15d%-15.2f\n", items[i].name, items[i].quantity, items[i].price);
                    total_amount += (items[i].quantity * items[i].price); // calculating the total cost
                }
                printf("\nTotal cost of inventory: %.2f\n\n", total_amount);
                break;

            case 2:
                // Searching for an item
                printf("\nEnter the name of the item to search: ");
                scanf("%s", name);
                for(int i = 0; i < n; i++) {
                    if(strcmp(name, items[i].name) == 0) {
                        printf("\nItem Found:\n");
                        printf("%-20s%-15s%-15s\n", "Item Name", "Quantity", "Price");
                        printf("%-20s%-15d%-15.2f\n", items[i].name, items[i].quantity, items[i].price);
                        total_amount += (items[i].quantity * items[i].price); // calculating the total cost
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nItem not found.\n\n");
                }
                break;

            case 3:
                // Updating inventory
                printf("\nEnter the name of the item to update: ");
                scanf("%s", name);
                for(int i = 0; i < n; i++) {
                    if(strcmp(name, items[i].name) == 0) {
                        printf("\nItem Found:\n");
                        printf("%-20s%-15s%-15s\n", "Item Name", "Quantity", "Price");
                        printf("%-20s%-15d%-15.2f\n", items[i].name, items[i].quantity, items[i].price);
                        printf("\nWhat do you want to update?\n");
                        printf("1. Quantity\n");
                        printf("2. Price\n");
                        printf("Enter your choice: ");
                        scanf("%d", &update_choice);

                        while(!(update_choice >=1 && update_choice <= 2)) {
                            printf("Invalid choice, please select again: ");
                            scanf("%d", &update_choice);
                        }

                        switch(update_choice) {

                            case 1:
                                printf("Enter the new quantity: ");
                                scanf("%d", &items[i].quantity);
                                printf("\nItem Updated:\n");
                                printf("%-20s%-15s%-15s\n", "Item Name", "Quantity", "Price");
                                printf("%-20s%-15d%-15.2f\n", items[i].name, items[i].quantity, items[i].price);
                                break;

                            case 2:
                                printf("Enter the new price: ");
                                scanf("%f", &items[i].price);
                                printf("\nItem Updated:\n");
                                printf("%-20s%-15s%-15s\n", "Item Name", "Quantity", "Price");
                                printf("%-20s%-15d%-15.2f\n", items[i].name, items[i].quantity, items[i].price);
                                break;
                        }

                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nItem not found.\n\n");
                }
                break;
        }

        // New menu
        flag = 0;
        total_amount = 0.0;
        printf("\nMenu\n");
        printf("1. Print inventory\n");
        printf("2. Search for an item\n");
        printf("3. Update inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        while(!(choice >=1 && choice <= 4)) {
            printf("Invalid choice, please select again: ");
            scanf("%d", &choice);
        }
    }

    printf("\nThank you for using the inventory system!\n");
    return 0;
}