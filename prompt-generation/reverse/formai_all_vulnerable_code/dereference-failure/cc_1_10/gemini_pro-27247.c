//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a stock
typedef struct stock {
    char *symbol;
    double price;
} stock_t;

// Create a new stock
stock_t *new_stock(char *symbol, double price) {
    stock_t *stock = malloc(sizeof(stock_t));
    stock->symbol = symbol;
    stock->price = price;
    return stock;
}

// Print the stock
void print_stock(stock_t *stock) {
    printf("%s: $%.2f\n", stock->symbol, stock->price);
}

// Compare two stocks
int compare_stocks(stock_t *stock1, stock_t *stock2) {
    return strcmp(stock1->symbol, stock2->symbol);
}

// Sort an array of stocks
void sort_stocks(stock_t **stocks, int num_stocks) {
    qsort(stocks, num_stocks, sizeof(stock_t *), compare_stocks);
}

// Get the stock price for a given symbol
double get_stock_price(char *symbol) {
    // In a real program, this would query a stock market API
    return rand() % 100;
}

// Main function
int main() {
    // Create an array of stocks
    stock_t *stocks[] = {
        new_stock("AAPL", get_stock_price("AAPL")),
        new_stock("GOOG", get_stock_price("GOOG")),
        new_stock("MSFT", get_stock_price("MSFT")),
        new_stock("AMZN", get_stock_price("AMZN")),
        new_stock("TSLA", get_stock_price("TSLA")),
    };

    // Sort the stocks
    sort_stocks(stocks, 5);

    // Print the stocks
    for (int i = 0; i < 5; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}