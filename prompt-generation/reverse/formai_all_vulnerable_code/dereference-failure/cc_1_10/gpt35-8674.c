//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int quantity;
    float cost;
} item;

int main() {
    int num_items = 0;
    item *inventory = NULL;
    
    // prompt user for number of items in inventory
    printf("Enter the number of items in the inventory: ");
    scanf("%d", &num_items);
    
    // allocate memory for inventory
    inventory = (item*)malloc(num_items * sizeof(item));
    
    // populate inventory with user input data
    for (int i = 0; i < num_items; i++) {
        printf("Enter the details for item %d\n", i+1);
        inventory[i].id = i+1;
        printf("Item name: ");
        scanf("%s", inventory[i].name);
        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
        printf("Cost: ");
        scanf("%f", &inventory[i].cost);
    }
    
    // display inventory data
    printf("\nInventory Data:\n");
    printf("ID\tName\tQuantity\tCost\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].cost);
    }
    
    // sort inventory by cost in ascending order
    for (int i = 0; i < num_items-1; i++) {
        for (int j = 0; j < num_items-i-1; j++) {
            if (inventory[j].cost > inventory[j+1].cost) {
                item temp = inventory[j];
                inventory[j] = inventory[j+1];
                inventory[j+1] = temp;
            }
        }
    }
    
    // display inventory data sorted by cost in ascending order
    printf("\nInventory Data Sorted by Cost:\n");
    printf("ID\tName\tQuantity\tCost\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].cost);
    }
    
    // search for item by name
    char search_name[100];
    printf("\nEnter the name of the item to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(search_name, inventory[i].name) == 0) {
            printf("\nItem Found!\nID: %d\nName: %s\nQuantity: %d\nCost: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].cost);
            found = 1;
        }
    }
    if (!found) {
        printf("\nItem not found!\n");
    }
    
    // free memory allocated for inventory
    free(inventory);
    
    return 0;
}