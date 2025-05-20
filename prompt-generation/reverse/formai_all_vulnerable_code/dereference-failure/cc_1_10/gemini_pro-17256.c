//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stock data structure
typedef struct {
    char *symbol;
    double price;
    double change;
} Stock;

// Create a new stock
Stock *new_stock(char *symbol, double price, double change) {
    Stock *stock = malloc(sizeof(Stock));
    stock->symbol = strdup(symbol);
    stock->price = price;
    stock->change = change;
    return stock;
}

// Print the stock information
void print_stock(Stock *stock) {
    printf("%s: $%.2f (%.2f%%)\n", stock->symbol, stock->price, stock->change);
}

// Free the stock
void free_stock(Stock *stock) {
    free(stock->symbol);
    free(stock);
}

// Main function
int main() {
    // Create a list of stocks
    Stock *stocks[] = {
        new_stock("AAPL", 120.00, 1.00),
        new_stock("GOOG", 1000.00, 2.00),
        new_stock("AMZN", 2000.00, 3.00),
        new_stock("TSLA", 500.00, 4.00),
        new_stock("NVDA", 250.00, 5.00),
    };

    // Print the list of stocks
    printf("Here are the latest stock prices:\n");
    for (int i = 0; i < 5; i++) {
        print_stock(stocks[i]);
    }

    // Free the list of stocks
    for (int i = 0; i < 5; i++) {
        free_stock(stocks[i]);
    }

    return 0;
}