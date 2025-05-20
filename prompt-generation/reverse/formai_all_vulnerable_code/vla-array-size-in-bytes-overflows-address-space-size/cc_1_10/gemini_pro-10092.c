//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to store item details
typedef struct item {
    int item_id;
    char item_name[50];
    float item_price;
    int item_qty;
} item;

// Function to display the menu
void display_menu(item items[], int num_items) {
    printf("\n\n=============================================================================\n");
    printf("                          Cafe Billing System\n");
    printf("=============================================================================\n");
    printf("\nItem ID\tItem Name\t\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t\t%s\t\t%.2f\t%d\n", items[i].item_id, items[i].item_name, items[i].item_price, items[i].item_qty);
    }
}

// Function to get the user's order
void get_order(item items[], int num_items, int order[], int num_order_items) {
    int item_id, qty;
    for (int i = 0; i < num_order_items; i++) {
        printf("\nEnter Item ID: ");
        scanf("%d", &item_id);
        printf("Enter Quantity: ");
        scanf("%d", &qty);

        // Check if item ID is valid
        int found = 0;
        for (int j = 0; j < num_items; j++) {
            if (items[j].item_id == item_id) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Invalid Item ID. Please try again.\n");
            i--;
            continue;
        }

        // Check if quantity is available
        if (qty > items[item_id - 1].item_qty) {
            printf("Insufficient quantity. Please try again.\n");
            i--;
            continue;
        }

        // Update order array
        order[item_id - 1] = qty;
    }
}

// Function to calculate the total bill
float calculate_bill(item items[], int order[], int num_order_items) {
    float total_bill = 0.0;
    for (int i = 0; i < num_order_items; i++) {
        total_bill += items[i].item_price * order[i];
    }
    return total_bill;
}

// Function to print the bill
void print_bill(item items[], int order[], int num_order_items, float total_bill) {
    printf("\n\n=============================================================================\n");
    printf("                          Cafe Billing System\n");
    printf("=============================================================================\n");
    printf("\nItem ID\tItem Name\t\tPrice\tQuantity\tTotal\n");
    for (int i = 0; i < num_order_items; i++) {
        printf("%d\t\t%s\t\t%.2f\t%d\t\t%.2f\n", items[i].item_id, items[i].item_name, items[i].item_price, order[i], items[i].item_price * order[i]);
    }
    printf("\n\nTotal Bill: %.2f\n", total_bill);
}

// Main function
int main() {
    // Define the menu items
    item items[] = {
        {1, "Coffee", 2.50, 10},
        {2, "Tea", 1.50, 15},
        {3, "Sandwich", 4.00, 5},
        {4, "Pastry", 2.00, 10}
    };
    int num_items = sizeof(items) / sizeof(items[0]);

    // Get the user's order
    int num_order_items;
    printf("Enter the number of items you want to order: ");
    scanf("%d", &num_order_items);
    int order[num_order_items];
    get_order(items, num_items, order, num_order_items);

    // Calculate the total bill
    float total_bill = calculate_bill(items, order, num_order_items);

    // Print the bill
    print_bill(items, order, num_order_items, total_bill);

    return 0;
}