//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a stock
typedef struct stock {
    char *name;      // The name of the stock
    float price;     // The current price of the stock
    float change;    // The change in price since the last update
} stock;

// A function to create a new stock
stock *new_stock(char *name, float price, float change) {
    stock *s = malloc(sizeof(stock));
    s->name = strdup(name);
    s->price = price;
    s->change = change;
    return s;
}

// A function to print a stock
void print_stock(stock *s) {
    printf("%s: $%.2f (%.2f%%)\n", s->name, s->price, s->change);
}

// A function to compare two stocks by their prices
int compare_stocks(const void *a, const void *b) {
    stock *stock1 = *(stock **)a;
    stock *stock2 = *(stock **)b;
    return stock1->price - stock2->price;
}

// The main function
int main() {
    // Create an array of stocks
    stock *stocks[] = {
        new_stock("AAPL", 120.50, 0.50),
        new_stock("GOOGL", 100.00, -1.00),
        new_stock("AMZN", 150.00, 2.00),
        new_stock("MSFT", 140.00, 1.00),
        new_stock("FB", 160.00, 0.00),
    };

    // Sort the array of stocks by their prices
    qsort(stocks, sizeof(stocks) / sizeof(stock *), sizeof(stock *), compare_stocks);

    // Print the sorted array of stocks
    printf("Sorted stocks by price:\n");
    for (int i = 0; i < sizeof(stocks) / sizeof(stock *); i++) {
        print_stock(stocks[i]);
    }

    // Free the memory allocated for the stocks
    for (int i = 0; i < sizeof(stocks) / sizeof(stock *); i++) {
        free(stocks[i]->name);
        free(stocks[i]);
    }

    return 0;
}