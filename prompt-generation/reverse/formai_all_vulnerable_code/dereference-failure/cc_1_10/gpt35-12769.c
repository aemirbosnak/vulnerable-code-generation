//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: visionary
#include <stdio.h>

struct Product {
    int id;
    char name[50];
    double price;
    int quantity;
};

void printProduct(struct Product p) {
    printf("ID: %d, Name: %s, Price: %.2lf, Quantity: %d\n", p.id, p.name, p.price, p.quantity);
}

int main() {
    int n;
    printf("Enter the number of products: ");
    scanf("%d", &n);

    // dynamically allocate memory for products
    struct Product *products = (struct Product*) malloc(n * sizeof(struct Product));

    // get input for each product
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Product %d:", i+1);
        printf("\nEnter ID: ");
        scanf("%d", &products[i].id);
        printf("Enter Name: ");
        scanf("%s", products[i].name);
        printf("Enter Price: ");
        scanf("%lf", &products[i].price);
        printf("Enter Quantity: ");
        scanf("%d", &products[i].quantity);
    }

    // display all the products
    printf("\nWarehouse Inventory: \n");
    for (int i = 0; i < n; i++) {
        printProduct(products[i]);
    }

    // find the most expensive product
    double max_price = products[0].price;
    int max_price_index = 0;
    for (int i = 1; i < n; i++) {
        if (products[i].price > max_price) {
            max_price = products[i].price;
            max_price_index = i;
        }
    }
    printf("\nMost Expensive Product: ");
    printProduct(products[max_price_index]);

    // find the product with the least quantity
    int min_quantity = products[0].quantity;
    int min_quantity_index = 0;
    for (int i = 1; i < n; i++) {
        if (products[i].quantity < min_quantity) {
            min_quantity = products[i].quantity;
            min_quantity_index = i;
        }
    }
    printf("\nProduct with Least Quantity: ");
    printProduct(products[min_quantity_index]);

    // free up the dynamically allocated memory
    free(products);

    return 0;
}