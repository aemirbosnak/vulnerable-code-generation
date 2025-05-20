//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Stock data structure
typedef struct stock {
    char *name;
    double price;
    double change;
} stock;

// Create a new stock
stock *stock_create(const char *name, double price, double change) {
    stock *s = malloc(sizeof(stock));
    s->name = strdup(name);
    s->price = price;
    s->change = change;
    return s;
}

// Free a stock
void stock_free(stock *s) {
    free(s->name);
    free(s);
}

// Print a stock
void stock_print(const stock *s) {
    printf("%s %.2f %.2f\n", s->name, s->price, s->change);
}

// Compare two stocks by price
int stock_compare_price(const stock *a, const stock *b) {
    return a->price - b->price;
}

// Compare two stocks by change
int stock_compare_change(const stock *a, const stock *b) {
    return a->change - b->change;
}

// Main function
int main() {
    // Create an array of stocks
    stock *stocks[] = {
        stock_create("AAPL", 120.00, +1.00),
        stock_create("GOOG", 900.00, -2.00),
        stock_create("AMZN", 1800.00, +3.00),
        stock_create("MSFT", 260.00, -1.00),
        stock_create("FB", 100.00, +0.50),
    };

    // Sort the stocks by price
    qsort(stocks, sizeof(stocks) / sizeof(stock *), sizeof(stock *), stock_compare_price);

    // Print the sorted stocks
    printf("Stocks sorted by price:\n");
    for (int i = 0; i < sizeof(stocks) / sizeof(stock *); i++) {
        stock_print(stocks[i]);
    }

    // Sort the stocks by change
    qsort(stocks, sizeof(stocks) / sizeof(stock *), sizeof(stock *), stock_compare_change);

    // Print the sorted stocks
    printf("Stocks sorted by change:\n");
    for (int i = 0; i < sizeof(stocks) / sizeof(stock *); i++) {
        stock_print(stocks[i]);
    }

    // Free the stocks
    for (int i = 0; i < sizeof(stocks) / sizeof(stock *); i++) {
        stock_free(stocks[i]);
    }

    return 0;
}