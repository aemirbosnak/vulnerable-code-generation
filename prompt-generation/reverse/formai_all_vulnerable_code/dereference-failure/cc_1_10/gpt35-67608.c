//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure to store the details of the order
struct Order {
    char item_name[50];
    int item_quantity;
    float item_price;
};

// function to display the menu and return the price of the selected item
float displayMenu() {
    int choice;
    float price;
    printf("\n--- Menu ---\n\n");
    printf("1. Coffee - $2.5\n");
    printf("2. Tea - $1.5\n");
    printf("3. Sandwich - $3.0\n");
    printf("4. Cake - $2.0\n");
    printf("5. Exit\n");
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                price = 2.5;
                break;
            case 2:
                price = 1.5;
                break;
            case 3:
                price = 3.0;
                break;
            case 4:
                price = 2.0;
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice. Please enter again.\n");
        }
    } while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
    return price;
}

// function to add an item to the order
void addOrder(struct Order *order, int *num_items) {
    printf("\nEnter the details of the item to be added to the order:\n");
    printf("Name: ");
    scanf("%s", order[*num_items].item_name);
    do {
        printf("Quantity: ");
        scanf("%d", &order[*num_items].item_quantity);
        if(order[*num_items].item_quantity <= 0) {
            printf("\nQuantity must be a positive integer. Please enter again.");
        }
    } while(order[*num_items].item_quantity <= 0);
    order[*num_items].item_price = displayMenu();
    (*num_items)++;
}

// function to display the order summary and calculate the total bill
void calculateBill(struct Order *order, int num_items) {
    float total = 0;
    printf("\n--- Order Summary ---\n\n");
    for(int i = 0; i < num_items; i++) {
        printf("%s x %d - $%.2f\n", order[i].item_name, order[i].item_quantity, order[i].item_quantity * order[i].item_price);
        total += order[i].item_quantity * order[i].item_price;
    }
    printf("\nTotal Bill: $%.2f\n\n", total);
}

int main() {
    // variable to store the maximum number of items that can be added to the order
    int max_items = 10;
    // variable to store the number of items currently in the order
    int num_items = 0;
    // dynamic allocation of memory for the order
    struct Order *order = (struct Order*) malloc(max_items * sizeof(struct Order));
    int choice;
    printf("--- Cafe Billing System ---\n\n");
    do {
        printf("1. Add Item to Order\n");
        printf("2. Generate Bill\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(num_items == max_items) {
                    printf("\nCannot add more items. Maximum limit reached.\n");
                } else {
                    addOrder(order, &num_items);
                }
                break;
            case 2:
                if(num_items == 0) {
                    printf("\nOrder is empty. Cannot generate bill.\n");
                } else {
                    calculateBill(order, num_items);
                    num_items = 0;
                    printf("Order has been cleared.\n\n");
                }
                break;
            case 3:
                printf("\nThank you for using the Cafe Billing System.\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter again.\n");
        }
    } while(choice != 3);
    free(order);
    return 0;
}