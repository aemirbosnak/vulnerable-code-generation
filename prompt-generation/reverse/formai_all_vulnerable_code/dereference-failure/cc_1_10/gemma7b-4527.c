//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 5.0, 10},
    {"Tea", 4.0, 8},
    {"Juice", 3.0, 12},
    {"Smoothie", 6.0, 6},
    {"Water", 2.0, 15},
    {"Soda", 3.5, 9},
    {"Energy Drink", 4.5, 7},
    {"Juice Drink", 3.2, 11},
    {"Smoothie Boost", 7.0, 5},
    {"Smoothie Delight", 8.0, 3}
};

int main() {
    int item_num, total_items = 0, total_price = 0, choice;
    char item_name[20];
    float item_price;
    int item_quantity;

    printf("Welcome to the C Cafe Billing System!\n");

    // Loop to get the number of items
    printf("How many items do you want to order? ");
    scanf("%d", &item_num);

    // Allocate memory for the items
    Item *items_ptr = (Item *)malloc(item_num * sizeof(Item));

    // Get the item information
    for (int i = 0; i < item_num; i++) {
        printf("Enter the name of the item: ");
        scanf("%s", items_ptr[i].name);

        printf("Enter the price of the item: ");
        scanf("%f", &items_ptr[i].price);

        printf("Enter the quantity of the item: ");
        scanf("%d", &items_ptr[i].quantity);

        total_items++;
        total_price += items_ptr[i].quantity * items_ptr[i].price;
    }

    // Calculate the total cost
    float total_cost = total_price + 0.1 * total_price;

    // Print the receipt
    printf("------------------------------------------------------------\n");
    printf("Order Summary\n");
    printf("------------------------------------------------------------\n");
    printf("Total items: %d\n", total_items);
    printf("Total price: %.2f\n", total_price);
    printf("Total cost: %.2f\n", total_cost);
    printf("------------------------------------------------------------\n");

    // Free the memory
    free(items_ptr);

    return 0;
}