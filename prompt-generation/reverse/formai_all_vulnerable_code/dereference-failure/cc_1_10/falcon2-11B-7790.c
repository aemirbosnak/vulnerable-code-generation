//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>

struct product {
    char name[50];
    int price;
    int quantity;
};

int main() {
    struct product products[] = {
        {"Apple", 10, 100},
        {"Banana", 5, 50},
        {"Orange", 8, 80},
        {"Grapes", 15, 150},
        {"Kiwi", 3, 30},
        {"Mango", 20, 200},
    };

    int choice, product_id, qty;
    int total_price = 0;

    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Display Products\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                fgets(products[product_id].name, sizeof(products[product_id].name), stdin);
                printf("Enter product price: ");
                scanf("%d", &products[product_id].price);
                printf("Enter product quantity: ");
                scanf("%d", &products[product_id].quantity);
                break;
            case 2:
                printf("Enter product ID: ");
                scanf("%d", &product_id);
                printf("Enter new product name: ");
                fgets(products[product_id].name, sizeof(products[product_id].name), stdin);
                printf("Enter new product price: ");
                scanf("%d", &products[product_id].price);
                printf("Enter new product quantity: ");
                scanf("%d", &products[product_id].quantity);
                break;
            case 3:
                printf("Enter product ID: ");
                scanf("%d", &product_id);
                break;
            case 4:
                printf("Products:\n");
                for (int i = 0; i < sizeof(products) / sizeof(struct product); i++) {
                    printf("Product ID: %d\n", i);
                    printf("Name: %s\n", products[i].name);
                    printf("Price: %d\n", products[i].price);
                    printf("Quantity: %d\n", products[i].quantity);
                }
                break;
            case 5:
                printf("Thank you for using the Product Inventory System!\n");
                return 0;
            default:
                printf("Invalid option selected!\n");
        }
    }
}