//FormAI DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product{
    int id;
    char name[100];
    double price;
    int quantity;
};

// Function to display product information
void displayProductInfo(struct Product p){
    printf("Product ID: %d\n", p.id);
    printf("Product Name: %s\n", p.name);
    printf("Product Price: %.2f\n", p.price);
    printf("Product Quantity: %d\n", p.quantity);
}

int main()
{
    int numOfProducts;
    printf("Enter the number of products: ");
    scanf("%d", &numOfProducts);
    
    struct Product products[numOfProducts];
    
    // Get the product information from user
    for(int i=0; i<numOfProducts; i++){
        printf("\nProduct %d\n", i+1);
        printf("Enter Product ID: ");
        scanf("%d", &products[i].id);
        printf("Enter Product Name: ");
        scanf("%s", products[i].name);
        printf("Enter Product Price: ");
        scanf("%lf", &products[i].price);
        printf("Enter Product Quantity: ");
        scanf("%d", &products[i].quantity);
    }

    // Display all products
    printf("\nAll Products\n");
    for(int i=0; i<numOfProducts; i++){
        printf("\nProduct %d\n", i+1);
        displayProductInfo(products[i]);
    }

    // Auction for the products
    int option;
    printf("\nEnter 1 to bid for a product, 0 to exit: ");
    scanf("%d", &option);
    while(option){
        int productId;
        printf("Enter the product ID to bid for: ");
        scanf("%d", &productId);

        // Find the product in the array
        int productIndex = -1;
        for(int i=0; i<numOfProducts; i++){
            if(products[i].id == productId){
                productIndex = i;
                break;
            }
        }

        // If product not found, display error message
        if(productIndex == -1){
            printf("Product with ID %d not found.\n", productId);
        } else{
            // Display the product information and ask for bid
            displayProductInfo(products[productIndex]);
            double bid;
            printf("Enter your bid: ");
            scanf("%lf", &bid);

            // If bid is less than price, display error message
            if(bid < products[productIndex].price){
                printf("Your bid is less than the product price.\n");
            } else{
                // Update the product information
                products[productIndex].price = bid;
                products[productIndex].quantity--;

                // Display success message
                printf("Bid successful. New price: %.2f, Quantity left: %d\n", products[productIndex].price, products[productIndex].quantity);
            }
        }

        printf("\nEnter 1 to bid for a product, 0 to exit: ");
        scanf("%d", &option);
    }

    return 0;
}