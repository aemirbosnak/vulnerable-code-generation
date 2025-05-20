//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Product structure
typedef struct product {
    int id;
    char *name;
    double reserve_price;
    double current_bid;
    int num_bids;
    bool sold;
} product;

// Function to create a new product
product *create_product(int id, char *name, double reserve_price) {
    product *new_product = malloc(sizeof(product));
    new_product->id = id;
    new_product->name = strdup(name);
    new_product->reserve_price = reserve_price;
    new_product->current_bid = 0.0;
    new_product->num_bids = 0;
    new_product->sold = false;
    return new_product;
}

// Function to free the memory allocated for a product
void free_product(product *product) {
    free(product->name);
    free(product);
}

// Function to print the details of a product
void print_product(product *product) {
    printf("Product ID: %d\n", product->id);
    printf("Product Name: %s\n", product->name);
    printf("Reserve Price: %.2f\n", product->reserve_price);
    printf("Current Bid: %.2f\n", product->current_bid);
    printf("Number of Bids: %d\n", product->num_bids);
    printf("Sold: %s\n", product->sold ? "Yes" : "No");
    printf("\n");
}

// Function to compare two products by their current bids
int compare_products_by_current_bid(const void *a, const void *b) {
    product *product1 = *(product **)a;
    product *product2 = *(product **)b;
    return product1->current_bid - product2->current_bid;
}

// Function to conduct an auction for a list of products
void conduct_auction(product **products, int num_products) {
    // Sort the products by their current bids
    qsort(products, num_products, sizeof(product *), compare_products_by_current_bid);

    // Iterate over the products and conduct the auction for each product
    for (int i = 0; i < num_products; i++) {
        product *product = products[i];

        // Check if the product has not been sold yet
        if (!product->sold) {
            // Print the details of the product
            printf("Product ID: %d\n", product->id);
            printf("Product Name: %s\n", product->name);
            printf("Reserve Price: %.2f\n", product->reserve_price);
            printf("Current Bid: %.2f\n", product->current_bid);
            printf("Number of Bids: %d\n", product->num_bids);
            printf("\n");

            // Get the new bid from the user
            double new_bid;
            printf("Enter your bid (0 to exit): ");
            scanf("%lf", &new_bid);

            // Check if the new bid is valid
            if (new_bid > 0.0 && new_bid >= product->current_bid) {
                // Update the current bid and the number of bids
                product->current_bid = new_bid;
                product->num_bids++;

                // Check if the new bid meets the reserve price
                if (product->current_bid >= product->reserve_price) {
                    // Mark the product as sold
                    product->sold = true;

                    // Print the winning bid
                    printf("Product %s sold for %.2f\n", product->name, product->current_bid);
                }
            } else {
                // Print an error message
                printf("Invalid bid. Please enter a bid greater than 0.0 and greater than or equal to the current bid.\n");
            }
        }
    }
}

int main() {
    // Create a list of products
    product *products[] = {
        create_product(1, "iPhone 13 Pro Max", 1000.0),
        create_product(2, "MacBook Air M2", 1200.0),
        create_product(3, "Apple Watch Series 8", 400.0),
        create_product(4, "iPad Air 5", 600.0),
        create_product(5, "AirPods Pro 2", 250.0)
    };

    // Conduct the auction
    conduct_auction(products, 5);

    // Free the memory allocated for the products
    for (int i = 0; i < 5; i++) {
        free_product(products[i]);
    }

    return 0;
}