//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an item
typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

// Create an array of items
Item items[MAX_ITEMS] = {
    {"Coffee", 5.0, 0},
    {"Tea", 4.0, 0},
    {"Juice", 3.0, 0},
    {"Smoothie", 6.0, 0},
    {"Mocha", 7.0, 0},
    {"Latte", 8.0, 0},
    {"Cappuccino", 9.0, 0},
    {"Americano", 4.5, 0},
    {"Ice Tea", 3.5, 0},
    {"Iced Coffee", 5.5, 0}
};

// Define the function to calculate the total cost of an order
float calculate_total_cost(Item items[], int num_items) {
    float total_cost = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].price * items[i].quantity;
    }
    return total_cost;
}

// Define the function to print the bill
void print_bill(Item items[], int num_items, float total_cost) {
    printf("----------------------------------------\n");
    printf("                                 Cafe Bill\n");
    printf("----------------------------------------\n");
    printf("Item\t\t\tPrice\t\tQuantity\t\tTotal Cost\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%.2f\t\t%d\t\t%.2f\n", items[i].name, items[i].price, items[i].quantity, items[i].price * items[i].quantity);
    }
    printf("----------------------------------------\n");
    printf("Total Cost:\t\t\t\t\t%.2f\n", total_cost);
    printf("----------------------------------------\n");
    printf("Thank you for your visit! Come again soon!\n");
    printf("----------------------------------------\n");
}

int main() {
    // Get the number of items in the order
    int num_items = 0;
    printf("Please enter the number of items you want to order: ");
    scanf("%d", &num_items);

    // Create an array of items for the order
    Item order[num_items];

    // Get the items for the order
    for (int i = 0; i < num_items; i++) {
        printf("Please enter the name of the item you want to order: ");
        scanf("%s", order[i].name);

        printf("Please enter the price of the item: ");
        scanf("%f", &order[i].price);

        printf("Please enter the quantity of the item you want to order: ");
        scanf("%d", &order[i].quantity);
    }

    // Calculate the total cost of the order
    float total_cost = calculate_total_cost(order, num_items);

    // Print the bill
    print_bill(order, num_items, total_cost);

    return 0;
}