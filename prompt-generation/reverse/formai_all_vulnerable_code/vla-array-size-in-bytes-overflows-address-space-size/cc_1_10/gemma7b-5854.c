//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct item {
    char name[20];
    int price;
    int quantity;
} item_t;

// Define an array of items
item_t items[] = {
    {"Ale", 5, 10},
    {"Bread", 3, 20},
    {"Chicken", 7, 15},
    {"Fish", 6, 12},
    {"Pie", 4, 18}
};

// Define a function to calculate the total cost of an order
int calculate_total_cost(int num_items, item_t items[]) {
    int total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].price * items[i].quantity;
    }
    return total_cost;
}

// Define a function to print the bill
void print_bill(int total_cost, int num_items, item_t items[]) {
    printf("A feast fit for a king!\n");
    printf("------------------------\n");
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d x %d = %d\n", items[i].name, items[i].quantity, items[i].price, items[i].price * items[i].quantity);
    }
    printf("Total Cost: %d\n", total_cost);
    printf("May the dragon slumber well.\n");
}

int main() {
    // Get the number of items in the order
    int num_items;
    printf("How many items would you like to order? ");
    scanf("%d", &num_items);

    // Create an array of items in the order
    item_t items_ordered[num_items];

    // Get the item information for each item in the order
    for (int i = 0; i < num_items; i++) {
        printf("Enter the name of the item: ");
        scanf("%s", items_ordered[i].name);

        printf("Enter the price of the item: ");
        scanf("%d", &items_ordered[i].price);

        printf("Enter the quantity of the item: ");
        scanf("%d", &items_ordered[i].quantity);
    }

    // Calculate the total cost of the order
    int total_cost = calculate_total_cost(num_items, items_ordered);

    // Print the bill
    print_bill(total_cost, num_items, items_ordered);

    return 0;
}