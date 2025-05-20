//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for item prices
const float COFFEE_PRICE = 2.50;
const float TEA_PRICE = 2.00;
const float SANDWICH_PRICE = 4.50;
const float CAKE_PRICE = 3.00;

// Define the struct for an item on the menu
struct MenuItem {
    char *name;
    float price;
};

// Define the function to add an item to the menu
void addMenuItem(struct MenuItem *menu, int *numItems, char *name, float price) {
    // Allocate memory for the new item
    struct MenuItem newItem;
    newItem.name = (char *) malloc((strlen(name) + 1) * sizeof(char));
    strcpy(newItem.name, name);
    newItem.price = price;

    // Add the new item to the menu
    menu[*numItems] = newItem;
    (*numItems)++;
}

// Define the function to print out the menu
void printMenu(struct MenuItem *menu, int numItems) {
    printf("======= MENU =======\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%.2f\n", menu[i].name, menu[i].price);
    }
    printf("=====================\n");
}

// Define the main function
int main() {
    // Declare the menu items
    struct MenuItem menu[10];
    int numItems = 0;

    // Add the menu items
    addMenuItem(menu, &numItems, "Coffee", COFFEE_PRICE);
    addMenuItem(menu, &numItems, "Tea", TEA_PRICE);
    addMenuItem(menu, &numItems, "Sandwich", SANDWICH_PRICE);
    addMenuItem(menu, &numItems, "Cake", CAKE_PRICE);

    // Print out the menu
    printMenu(menu, numItems);

    // Get the user's order
    char order[20];
    printf("Enter your order (e.g. Coffee, Tea, Sandwich, Cake):\n");
    scanf("%s", order);

    // Find the item in the menu
    struct MenuItem item;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(order, menu[i].name) == 0) {
            item = menu[i];
            break;
        }
    }

    // Print out the bill
    printf("Your order: %s\n", item.name);
    printf("Price: %.2f\n", item.price);

    return 0;
}