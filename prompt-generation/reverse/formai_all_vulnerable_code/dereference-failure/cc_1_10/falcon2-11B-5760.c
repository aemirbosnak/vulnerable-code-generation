//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[100];
    int quantity;
    double price;
};

int main() {
    struct product products[100];
    int num_products = 0;
    int option = 0;
    char input[100];

    // Display menu
    printf("Welcome to the Warehouse Management System!\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Update Stock\n");
    printf("4. Display Inventory\n");
    printf("5. Exit\n");

    // Get user input
    scanf("%d", &option);

    while (option!= 5) {
        switch (option) {
            case 1:
                printf("Enter product name: ");
                fgets(input, sizeof(input), stdin);
                strcpy(products[num_products].name, input);
                printf("Enter quantity: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter price: ");
                scanf("%lf", &products[num_products].price);
                num_products++;
                break;

            case 2:
                printf("Enter product name: ");
                fgets(input, sizeof(input), stdin);
                strcpy(products[--num_products].name, input);
                break;

            case 3:
                printf("Enter product name: ");
                fgets(input, sizeof(input), stdin);
                strcpy(products[num_products].name, input);
                printf("Enter new quantity: ");
                scanf("%d", &products[num_products].quantity);
                break;

            case 4:
                printf("Inventory:\n");
                for (int i = 0; i < num_products; i++) {
                    printf("%s - %d units - $%.2lf each\n", products[i].name, products[i].quantity, products[i].price);
                }
                break;

            default:
                printf("Invalid option!\n");
                break;
        }

        printf("Enter another option (1-5): ");
        scanf("%d", &option);
    }

    printf("Goodbye!\n");

    return 0;
}