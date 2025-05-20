//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items
typedef struct {
    char name[20];
    float price;
} MenuItem;

// Define the order
typedef struct {
    char name[20];
    int quantity;
    float price;
} OrderItem;

// Define the table
typedef struct {
    int tableNumber;
    char serverName[20];
    OrderItem *orderItems;
    int numOrderItems;
    float total;
} Table;

// Define the cafe
typedef struct {
    char name[20];
    int numTables;
    Table *tables;
} Cafe;

// Create a new cafe
Cafe *createCafe(char *name, int numTables) {
    Cafe *cafe = malloc(sizeof(Cafe));
    strcpy(cafe->name, name);
    cafe->numTables = numTables;
    cafe->tables = malloc(sizeof(Table) * numTables);
    for (int i = 0; i < numTables; i++) {
        cafe->tables[i].tableNumber = i + 1;
        cafe->tables[i].numOrderItems = 0;
        cafe->tables[i].total = 0.0;
    }
    return cafe;
}

// Add a new menu item to the cafe
void addMenuItem(Cafe *cafe, char *name, float price) {
    MenuItem *menuItem = malloc(sizeof(MenuItem));
    strcpy(menuItem->name, name);
    menuItem->price = price;
    // TODO: Add the menu item to the cafe's menu
}

// Add an order item to a table
void addOrderItem(Table *table, char *name, int quantity, float price) {
    OrderItem *orderItem = malloc(sizeof(OrderItem));
    strcpy(orderItem->name, name);
    orderItem->quantity = quantity;
    orderItem->price = price;
    table->orderItems = realloc(table->orderItems, sizeof(OrderItem) * (table->numOrderItems + 1));
    table->orderItems[table->numOrderItems] = *orderItem;
    table->numOrderItems++;
    table->total += price * quantity;
}

// Print the bill for a table
void printBill(Table *table) {
    printf("Cafe: %s\n", table->tableNumber);
    printf("Server: %s\n", table->serverName);
    printf("-----------------------------------------\n");
    printf("Item\t\tQuantity\tPrice\n");
    for (int i = 0; i < table->numOrderItems; i++) {
        printf("%s\t\t%d\t\t%.2f\n", table->orderItems[i].name, table->orderItems[i].quantity, table->orderItems[i].price);
    }
    printf("-----------------------------------------\n");
    printf("Total: %.2f\n", table->total);
}

// Main function
int main() {
    // Create a new cafe
    Cafe *cafe = createCafe("My Cafe", 10);

    // Add some menu items to the cafe
    addMenuItem(cafe, "Coffee", 2.50);
    addMenuItem(cafe, "Tea", 2.00);
    addMenuItem(cafe, "Cake", 5.00);

    // Take an order for a table
    Table *table = &cafe->tables[0];
    addOrderItem(table, "Coffee", 2, 2.50);
    addOrderItem(table, "Tea", 1, 2.00);
    addOrderItem(table, "Cake", 1, 5.00);

    // Print the bill for the table
    printBill(table);

    return 0;
}