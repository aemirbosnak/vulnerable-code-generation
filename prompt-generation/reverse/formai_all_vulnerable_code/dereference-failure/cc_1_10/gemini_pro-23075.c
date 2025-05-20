//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Create a structure to store stock data
typedef struct {
    char *name;
    double price;
    double change;
} stock;

// Function to compare two stocks by price
int compare_stocks(const void *a, const void *b) {
    const stock *stock1 = (const stock *)a;
    const stock *stock2 = (const stock *)b;

    return (stock1->price - stock2->price);
}

// Function to generate a random stock price
double generate_stock_price() {
    return (100.0 + (50.0 * (rand() / (RAND_MAX + 1.0))));
}

// Function to generate a random stock change
double generate_stock_change() {
    return (5.0 + (2.5 * (rand() / (RAND_MAX + 1.0))));
}

// Function to create a new stock
stock *create_stock(char *name) {
    stock *new_stock = malloc(sizeof(stock));

    new_stock->name = strdup(name);
    new_stock->price = generate_stock_price();
    new_stock->change = generate_stock_change();

    return new_stock;
}

// Function to destroy a stock
void destroy_stock(stock *stock) {
    free(stock->name);
    free(stock);
}

// Function to print a stock
void print_stock(stock *stock) {
    printf("%s: $%.2f (%.2f%%)\n", stock->name, stock->price, stock->change);
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Create an array of stocks
    stock *stocks[10];

    for (int i = 0; i < 10; i++) {
        char *name = malloc(16);
        sprintf(name, "Stock %d", i);
        stocks[i] = create_stock(name);
    }

    // Sort the stocks by price
    qsort(stocks, 10, sizeof(stock *), compare_stocks);

    // Print the sorted stocks
    printf("Sorted stocks:\n");
    for (int i = 0; i < 10; i++) {
        print_stock(stocks[i]);
    }

    // Free the memory allocated for the stocks
    for (int i = 0; i < 10; i++) {
        destroy_stock(stocks[i]);
    }

    return 0;
}