//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char name[30];
    float price;
};

// Define the table structure
struct Table {
    int tableNumber;
    int numCustomers;
    struct MenuItem *order[10]; // Array of pointers to menu items
    int numItemsOrdered;
    float totalBill;
};

// Create a new menu item
struct MenuItem *createMenuItem(char *name, float price) {
    struct MenuItem *item = malloc(sizeof(struct MenuItem));
    strcpy(item->name, name);
    item->price = price;
    return item;
}

// Create a new table
struct Table *createTable(int tableNumber, int numCustomers) {
    struct Table *table = malloc(sizeof(struct Table));
    table->tableNumber = tableNumber;
    table->numCustomers = numCustomers;
    table->numItemsOrdered = 0;
    table->totalBill = 0.0;
    return table;
}

// Add an item to the order
void addItemToOrder(struct Table *table, struct MenuItem *item) {
    table->order[table->numItemsOrdered] = item;
    table->numItemsOrdered++;
    table->totalBill += item->price;
}

// Print the bill
void printBill(struct Table *table) {
    printf("Table %d\n", table->tableNumber);
    printf("Number of customers: %d\n", table->numCustomers);
    printf("-------------------------------------\n");
    for (int i = 0; i < table->numItemsOrdered; i++) {
        printf("%s: $%.2f\n", table->order[i]->name, table->order[i]->price);
    }
    printf("-------------------------------------\n");
    printf("Total: $%.2f\n", table->totalBill);
}

// Main function
int main() {
    // Create the menu items
    struct MenuItem *item1 = createMenuItem("Pizza", 10.0);
    struct MenuItem *item2 = createMenuItem("Pasta", 12.0);
    struct MenuItem *item3 = createMenuItem("Salad", 8.0);
    struct MenuItem *item4 = createMenuItem("Drink", 2.0);

    // Create the tables
    struct Table *table1 = createTable(1, 4);
    struct Table *table2 = createTable(2, 2);

    // Add items to the orders
    addItemToOrder(table1, item1);
    addItemToOrder(table1, item2);
    addItemToOrder(table1, item3);
    addItemToOrder(table1, item4);

    addItemToOrder(table2, item1);
    addItemToOrder(table2, item3);

    // Print the bills
    printBill(table1);
    printBill(table2);

    // Free the memory
    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(table1);
    free(table2);

    return 0;
}