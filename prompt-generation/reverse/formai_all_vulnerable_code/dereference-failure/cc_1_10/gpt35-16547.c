//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item {
    char name[100];
    int quantity;
};

void displayInventory(struct item *inventory, int total_items);
void addItem(struct item *inventory, int total_items);
void removeItem(struct item *inventory, int total_items);
void searchItem(struct item *inventory, int total_items);

int main() {
    int total_items = 0;
    printf("Enter total number of items: ");
    scanf("%d", &total_items);
    struct item *inventory = (struct item*)malloc(total_items * sizeof(struct item));
    for(int i = 0; i < total_items; i++) {
        printf("Enter name and quantity of item %d: ", i + 1);
        scanf("%s %d", (inventory+i)->name, &(inventory+i)->quantity);
    }
    printf("Inventory has been initialized with the following items:\n");
    displayInventory(inventory, total_items);
    printf("Enter number of operations you want to perform: ");
    int num_operations; 
    scanf("%d", &num_operations);
    for(int i = 0; i < num_operations; i++) {
        int choice; 
        printf("Choose an operation:\n1. Add item\n2. Remove item\n3. Search item\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addItem(inventory, total_items);
                break;
            case 2:
                removeItem(inventory, total_items);
                break;
            case 3:
                searchItem(inventory, total_items);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    free(inventory);
    return 0;
}

void displayInventory(struct item *inventory, int total_items) {
    for(int i = 0; i < total_items; i++) {
        printf("%d. %s - %d\n", i + 1, (inventory+i)->name, (inventory+i)->quantity);
    }
}

void addItem(struct item *inventory, int total_items) {
    char item_name[100];
    int item_quantity;
    printf("Enter name and quantity of item to add: ");
    scanf("%s %d", item_name, &item_quantity);
    int exists = 0;
    for(int i = 0; i < total_items; i++) {
        if(strcmp(item_name, (inventory+i)->name) == 0) {
            (inventory+i)->quantity += item_quantity;
            exists = 1;
            break;
        }
    }
    if(!exists) {
        int index = total_items;
        strcpy((inventory+index)->name, item_name);
        (inventory+index)->quantity = item_quantity;
        total_items++;
    }
    printf("%s successfully added to inventory.\n", item_name);
}

void removeItem(struct item *inventory, int total_items) {
    char item_name[100];
    printf("Enter name of item to remove: ");
    scanf("%s", item_name);
    int exists = 0;
    for(int i = 0; i < total_items; i++) {
        if(strcmp(item_name, (inventory+i)->name) == 0) {
            exists = 1;
            if((inventory+i)->quantity == 1) {
                for(int j = i; j < total_items - 1; j++) {
                    strcpy((inventory+j)->name, (inventory+j+1)->name);
                    (inventory+j)->quantity = (inventory+j+1)->quantity;
                }
                total_items--;
            } else {
                (inventory+i)->quantity--;
            }
            printf("%s successfully removed from inventory.\n", item_name);
            break;
        }
    }
    if(!exists) {
        printf("%s not found in inventory.\n", item_name);
    }
}

void searchItem(struct item *inventory, int total_items) {
    char item_name[100];
    printf("Enter name of item to search: ");
    scanf("%s", item_name);
    int exists = 0;
    for(int i = 0; i < total_items; i++) {
        if(strcmp(item_name, (inventory+i)->name) == 0) {
            exists = 1;
            printf("%s - %d\n", (inventory+i)->name, (inventory+i)->quantity);
            break;
        }
    }
    if(!exists) {
        printf("%s not found in inventory.\n", item_name);
    }
}