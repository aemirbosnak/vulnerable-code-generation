//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the information of each item in the menu.
struct MenuItem {
    char name[50];
    float price;
};

// Structure to store the information of each order.
struct Order {
    struct MenuItem item;
    int quantity;
};

// Function to display the menu to the user.
void display_menu(struct MenuItem menu[], int menu_size) {
    printf("\n========== MENU ==========\n");
    for (int i = 0; i < menu_size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to place an order.
struct Order* place_order(struct MenuItem menu[], int menu_size, int *order_size) {
    int item_no, quantity;
    char choice;

    // Allocate memory for the new order.
    struct Order *new_order = (struct Order*) malloc(sizeof(struct Order));

    // Loop to take user input for the item number and quantity.
    do {
        display_menu(menu, menu_size);
        printf("\nEnter the item number to order: ");
        scanf("%d", &item_no);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        // Store the order in the new_order structure.
        new_order[*order_size].item = menu[item_no-1];
        new_order[*order_size].quantity = quantity;

        printf("\nDo you want to order something else? (y/n) ");
        scanf(" %c", &choice);

        (*order_size)++;

    } while (choice == 'y');

    return new_order;
}

// Function to calculate the total bill for the order.
float calculate_bill(struct Order order[], int order_size) {
    float total = 0.0;
    for (int i = 0; i < order_size; i++) {
        total += order[i].item.price * order[i].quantity;
    }
    return total;
}

// Main function to run the program.
int main() {
    int menu_size = 5, order_size = 0;
    struct MenuItem menu[5] = {
        {"Coffee", 2.50},
        {"Tea", 2.00},
        {"Sandwich", 5.00},
        {"Cake", 3.00},
        {"Scone", 2.00}
    };

    struct Order *new_order = place_order(menu, menu_size, &order_size);

    printf("\n\nThank you for your order! Here is your bill:\n\n");

    // Displaying the order details and the bill.
    for (int i = 0; i < order_size; i++) {
        printf("%d. %s x %d = $%.2f\n", i+1, new_order[i].item.name, new_order[i].quantity, new_order[i].item.price*new_order[i].quantity);
    }

    printf("\nTotal bill: $%.2f", calculate_bill(new_order, order_size));

    // Freeing the memory allocated for the new_order structure.
    free(new_order);

    return 0;
}