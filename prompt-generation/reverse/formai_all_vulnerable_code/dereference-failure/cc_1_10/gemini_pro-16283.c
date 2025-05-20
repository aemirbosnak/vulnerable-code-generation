//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Menu items
struct MenuItem {
    char name[30];
    float price;
};

// Order items
struct OrderItem {
    struct MenuItem *item;
    int quantity;
};

// Create a new menu item
struct MenuItem *createMenuItem(char *name, float price) {
    struct MenuItem *item = malloc(sizeof(struct MenuItem));
    strcpy(item->name, name);
    item->price = price;
    return item;
}

// Create a new order item
struct OrderItem *createOrderItem(struct MenuItem *item, int quantity) {
    struct OrderItem *orderItem = malloc(sizeof(struct OrderItem));
    orderItem->item = item;
    orderItem->quantity = quantity;
    return orderItem;
}

// Print the menu
void printMenu(struct MenuItem **menu, int numItems) {
    printf("Welcome to the Retro Cafe!\n");
    printf("------------------------\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i]->name, menu[i]->price);
    }
    printf("------------------------\n");
}

// Get the user's order
struct OrderItem **getOrder(struct MenuItem **menu, int numItems) {
    int numOrderItems;
    printf("How many items would you like to order? ");
    scanf("%d", &numOrderItems);

    struct OrderItem **orderItems = malloc(sizeof(struct OrderItem *) * numOrderItems);
    for (int i = 0; i < numOrderItems; i++) {
        int itemNum;
        int quantity;
        printf("Enter the item number: ");
        scanf("%d", &itemNum);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        struct MenuItem *item = menu[itemNum - 1];
        struct OrderItem *orderItem = createOrderItem(item, quantity);
        orderItems[i] = orderItem;
    }

    return orderItems;
}

// Calculate the total bill
float calculateTotalBill(struct OrderItem **orderItems, int numOrderItems) {
    float totalBill = 0;
    for (int i = 0; i < numOrderItems; i++) {
        struct OrderItem *orderItem = orderItems[i];
        totalBill += orderItem->item->price * orderItem->quantity;
    }
    return totalBill;
}

// Print the receipt
void printReceipt(struct OrderItem **orderItems, int numOrderItems, float totalBill) {
    printf("Thank you for dining at the Retro Cafe!\n");
    printf("------------------------\n");
    for (int i = 0; i < numOrderItems; i++) {
        struct OrderItem *orderItem = orderItems[i];
        printf("%s - $%.2f x %d = $%.2f\n", orderItem->item->name, orderItem->item->price, orderItem->quantity, orderItem->item->price * orderItem->quantity);
    }
    printf("------------------------\n");
    printf("Total Bill: $%.2f\n", totalBill);
}

// Main function
int main() {
    // Create the menu
    struct MenuItem *menu[] = {
        createMenuItem("Coffee", 2.50),
        createMenuItem("Tea", 2.00),
        createMenuItem("Soda", 1.50),
        createMenuItem("Hamburger", 5.00),
        createMenuItem("Cheeseburger", 5.50),
        createMenuItem("Hot Dog", 4.00),
        createMenuItem("Fries", 2.00),
        createMenuItem("Onion Rings", 2.50),
        createMenuItem("Milkshake", 3.00),
        createMenuItem("Sundae", 3.50),
    };
    int numItems = sizeof(menu) / sizeof(menu[0]);

    // Print the menu
    printMenu(menu, numItems);

    // Get the user's order
    struct OrderItem **orderItems = getOrder(menu, numItems);
    int numOrderItems = sizeof(orderItems) / sizeof(orderItems[0]);

    // Calculate the total bill
    float totalBill = calculateTotalBill(orderItems, numOrderItems);

    // Print the receipt
    printReceipt(orderItems, numOrderItems, totalBill);

    return 0;
}