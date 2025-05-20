//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the maximum length of strings
#define MAX_ITEM_NAME_LEN 50
#define MAX_LOCATION_LEN 20
#define MAX_QUANTITY_LEN 10

// Define a struct to represent an item in the warehouse
typedef struct {
    char name[MAX_ITEM_NAME_LEN];
    char location[MAX_LOCATION_LEN];
    int quantity;
} Item;

// Define a function to add an item to the warehouse
void add_item(Item *items, int *num_items) {
    char name[MAX_ITEM_NAME_LEN];
    char location[MAX_LOCATION_LEN];
    char quantity_str[MAX_QUANTITY_LEN];
    int quantity;

    // Get user input for the new item's name
    printf("Enter the item name: ");
    fgets(name, MAX_ITEM_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    // Get user input for the new item's location
    printf("Enter the item location: ");
    fgets(location, MAX_LOCATION_LEN, stdin);
    location[strcspn(location, "\n")] = '\0';

    // Get user input for the new item's quantity
    printf("Enter the item quantity: ");
    fgets(quantity_str, MAX_QUANTITY_LEN, stdin);
    quantity_str[strcspn(quantity_str, "\n")] = '\0';
    quantity = atoi(quantity_str);

    // Add the new item to the array of items
    Item new_item = { .quantity = quantity };
    strncpy(new_item.name, name, MAX_ITEM_NAME_LEN);
    strncpy(new_item.location, location, MAX_LOCATION_LEN);
    items[*num_items] = new_item;
    (*num_items)++;
}

// Define a function to remove an item from the warehouse
void remove_item(Item *items, int *num_items) {
    int item_index;
    char index_str[MAX_QUANTITY_LEN];

    // Get user input for the index of the item to remove
    printf("Enter the index of the item to remove: ");
    fgets(index_str, MAX_QUANTITY_LEN, stdin);
    item_index = atoi(index_str);

    // Shift all items after the removed item back by one position
    for (int i = item_index; i < *num_items - 1; i++) {
        items[i] = items[i+1];
    }

    // Decrease the number of items by one
    (*num_items)--;
}

// Define a function to print the list of items in the warehouse
void print_items(Item *items, int num_items) {
    printf("Items in the warehouse:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s, %s, %d\n", i, items[i].name, items[i].location, items[i].quantity);
    }
}

int main() {
    // Initialize an array of items and the number of items
    Item items[100];
    int num_items = 0;

    // Display the main menu and get user input for the action to take
    char input[MAX_QUANTITY_LEN];
    int action;
    do {
        printf("\nWarehouse Management System\n");
        printf("----------------------------\n");
        printf("1. Add an item\n");
        printf("2. Remove an item\n");
        printf("3. Print items\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        fgets(input, MAX_QUANTITY_LEN, stdin);
        action = atoi(input);

        switch (action) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                remove_item(items, &num_items);
                break;
            case 3:
                print_items(items, num_items);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (action != 4);

    return 0;
}