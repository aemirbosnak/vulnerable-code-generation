//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    float price;
    int quantity;
};

int main(int argc, char const *argv[]) {
    int option = 1;
    int numOfItems;
    int totalItems = 0;
    float totalAmount = 0.0;

    printf("Welcome to the Cafe Billing System\n");
    printf("Enter the number of items in the menu: ");
    scanf("%d", &numOfItems);

    struct item menu[numOfItems];

    for (int i = 0; i < numOfItems; i++) {
        printf("Enter item %d name: ", i + 1);
        scanf("%s", menu[i].name);
        printf("Enter item %d price: ", i + 1);
        scanf("%f", &menu[i].price);
        printf("Enter item %d quantity: ", i + 1);
        scanf("%d", &menu[i].quantity);
    }

    printf("\nThank you. Your menu has been added.\n");

    do {
        printf("\n-------------------------\n");
        printf("\nMenu Options:\n");
        printf("1. Add item to bill\n");
        printf("2. View bill\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nWhat item would you like to add? (Enter item name): ");
                char itemName[50];
                scanf("%s", itemName);
                int index;
                for (int i = 0; i < numOfItems; i++) {
                    if (strcmp(menu[i].name, itemName) == 0) {
                        index = i;
                        break;
                    }
                }
                printf("Enter the quantity: ");
                int quantity;
                scanf("%d", &quantity);

                menu[index].quantity -= quantity;
                totalItems += quantity;
                totalAmount += (menu[index].price * quantity);

                printf("\n%d %s added to bill.\n", quantity, menu[index].name);
                break;
            case 2:
                printf("\n-------------------------\n");
                printf("Your Bill:\n");
                printf("Item Name\tPrice\tQuantity\n\n");

                for (int i = 0; i < numOfItems; i++) {
                    if (menu[i].quantity != 0) {
                        printf("%s\t%.2f\t%d\n", menu[i].name, menu[i].price, menu[i].quantity);
                    }
                }

                printf("\nTotal Items: %d\n", totalItems);
                printf("Total Amount: $%.2f\n", totalAmount);
                break;
            case 3:
                printf("\nThank you for using our Cafe Billing System!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}