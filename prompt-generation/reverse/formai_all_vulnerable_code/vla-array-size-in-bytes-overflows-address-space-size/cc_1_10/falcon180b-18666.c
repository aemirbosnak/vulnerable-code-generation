//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for the menu items
typedef struct {
    char name[50];
    float price;
    char category[50];
} MenuItem;

// Define the structure for the order
typedef struct {
    MenuItem item;
    int quantity;
} OrderItem;

void displayMenu() {
    MenuItem menuItems[] = {
        {"Hamburger", 4.99, "Food"},
        {"Fries", 2.99, "Food"},
        {"Coke", 1.99, "Drinks"},
        {"Pepsi", 1.99, "Drinks"},
        {"Water", 0.99, "Drinks"}
    };
    int i;
    for(i = 0; i < sizeof(menuItems)/sizeof(menuItems[0]); i++) {
        printf("%s - $%.2f - %s\n", menuItems[i].name, menuItems[i].price, menuItems[i].category);
    }
}

void addOrderItem(OrderItem* order, int index) {
    printf("Enter the name of the item: ");
    scanf("%s", &order[index].item.name);
    printf("Enter the price of the item: ");
    scanf("%f", &order[index].item.price);
    printf("Enter the category of the item: ");
    scanf("%s", &order[index].item.category);
    printf("Enter the quantity: ");
    scanf("%d", &order[index].quantity);
}

void calculateTotal(OrderItem* order, int numItems) {
    float total = 0;
    int i;
    for(i = 0; i < numItems; i++) {
        total += (order[i].item.price * order[i].quantity);
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    int numItems;
    printf("Enter the number of items you want to order: ");
    scanf("%d", &numItems);
    OrderItem order[numItems];
    int i;
    for(i = 0; i < numItems; i++) {
        addOrderItem(order, i);
    }
    calculateTotal(order, numItems);
    return 0;
}