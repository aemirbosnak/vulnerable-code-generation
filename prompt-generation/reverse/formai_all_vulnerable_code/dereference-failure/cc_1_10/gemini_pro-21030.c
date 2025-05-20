//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the product structure
typedef struct product {
    char *name;
    int quantity;
    float price;
} product;

// Create a new product
product *new_product(char *name, int quantity, float price) {
    product *p = malloc(sizeof(product));
    p->name = name;
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Print the product
void print_product(product *p) {
    printf("%s %d %.2f\n", p->name, p->quantity, p->price);
}

// Get the mean of the product's price
float get_mean(product *p, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += p[i].price;
    }
    return sum / n;
}

// Get the standard deviation of the product's price
float get_stddev(product *p, int n) {
    float mean = get_mean(p, n);
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(p[i].price - mean, 2);
    }
    return sqrt(sum / n);
}

// Main function
int main() {
    // Create an array of products
    product *products[] = {
        new_product("Apple", 10, 0.5),
        new_product("Banana", 20, 0.75),
        new_product("Orange", 30, 1.0),
        new_product("Grape", 40, 1.25),
        new_product("Strawberry", 50, 1.5),
    };

    // Print the products
    for (int i = 0; i < 5; i++) {
        print_product(products[i]);
    }

    // Get the mean and standard deviation of the product's price
    float mean = get_mean(products, 5);
    float stddev = get_stddev(products, 5);

    // Print the mean and standard deviation
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", stddev);

    return 0;
}