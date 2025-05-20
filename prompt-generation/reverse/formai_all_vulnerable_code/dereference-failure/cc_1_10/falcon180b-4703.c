//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the menu items
struct MenuItem {
    char name[50];
    float price;
};

// Define the structure of the order
struct Order {
    int itemCount;
    struct MenuItem items[10];
};

// Function to display the menu
void displayMenu(struct MenuItem menu[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take the order
void takeOrder(struct MenuItem menu[], int size, struct Order *order) {
    int choice;
    printf("Enter the number of items you want to order: ");
    scanf("%d", &order->itemCount);

    printf("Enter the numbers of the items you want to order (separated by space): ");
    scanf("%d", &choice);
    order->items[0] = menu[choice-1];
    order->itemCount = 1;
}

// Function to calculate the total price of the order
float calculateTotal(struct Order order) {
    float total = 0;
    for (int i = 0; i < order.itemCount; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to print the order
void printOrder(struct Order order) {
    printf("Order:\n");
    for (int i = 0; i < order.itemCount; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total: $%.2f\n", calculateTotal(order));
}

// Main function
int main() {
    // Define the menu
    struct MenuItem menu[] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Cake", 3.25}};
    int menuSize = sizeof(menu)/sizeof(menu[0]);

    // Define the order
    struct Order order;

    // Display the menu
    printf("Welcome to the Cafe!\n");
    displayMenu(menu, menuSize);

    // Take the order
    takeOrder(menu, menuSize, &order);

    // Print the order
    printf("\nYour order:\n");
    printOrder(order);

    return 0;
}