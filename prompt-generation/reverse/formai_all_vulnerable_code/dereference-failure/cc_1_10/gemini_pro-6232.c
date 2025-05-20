//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stock
typedef struct stock {
    char *name;
    double price;
    double change;
    double percent_change;
} stock_t;

// Function to create a new stock
stock_t *new_stock(char *name, double price, double change, double percent_change) {
    stock_t *stock = malloc(sizeof(stock_t));
    stock->name = strdup(name);
    stock->price = price;
    stock->change = change;
    stock->percent_change = percent_change;
    return stock;
}

// Function to free a stock
void free_stock(stock_t *stock) {
    free(stock->name);
    free(stock);
}

// Function to print a stock
void print_stock(stock_t *stock) {
    printf("%s: $%.2f (%.2f%%)\n", stock->name, stock->price, stock->percent_change);
}

// Function to compare two stocks by name
int compare_stocks_by_name(const void *a, const void *b) {
    stock_t *stock1 = *(stock_t **)a;
    stock_t *stock2 = *(stock_t **)b;
    return strcmp(stock1->name, stock2->name);
}

// Function to compare two stocks by price
int compare_stocks_by_price(const void *a, const void *b) {
    stock_t *stock1 = *(stock_t **)a;
    stock_t *stock2 = *(stock_t **)b;
    return stock1->price - stock2->price;
}

// Function to compare two stocks by change
int compare_stocks_by_change(const void *a, const void *b) {
    stock_t *stock1 = *(stock_t **)a;
    stock_t *stock2 = *(stock_t **)b;
    return stock1->change - stock2->change;
}

// Function to compare two stocks by percent change
int compare_stocks_by_percent_change(const void *a, const void *b) {
    stock_t *stock1 = *(stock_t **)a;
    stock_t *stock2 = *(stock_t **)b;
    return stock1->percent_change - stock2->percent_change;
}

// Main function
int main() {
    // Create an array of stocks
    stock_t *stocks[] = {
        new_stock("Apple", 123.45, 1.23, 1.00),
        new_stock("Google", 789.10, 5.67, 0.72),
        new_stock("Microsoft", 234.56, 3.45, 1.45),
        new_stock("Amazon", 987.65, 10.11, 1.03),
        new_stock("Tesla", 654.32, 7.89, 1.21),
    };

    // Get the number of stocks
    int num_stocks = sizeof(stocks) / sizeof(stocks[0]);

    // Sort the stocks by name
    qsort(stocks, num_stocks, sizeof(stocks[0]), compare_stocks_by_name);

    // Print the stocks sorted by name
    printf("Stocks sorted by name:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    // Sort the stocks by price
    qsort(stocks, num_stocks, sizeof(stocks[0]), compare_stocks_by_price);

    // Print the stocks sorted by price
    printf("\nStocks sorted by price:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    // Sort the stocks by change
    qsort(stocks, num_stocks, sizeof(stocks[0]), compare_stocks_by_change);

    // Print the stocks sorted by change
    printf("\nStocks sorted by change:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    // Sort the stocks by percent change
    qsort(stocks, num_stocks, sizeof(stocks[0]), compare_stocks_by_percent_change);

    // Print the stocks sorted by percent change
    printf("\nStocks sorted by percent change:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    // Free the stocks
    for (int i = 0; i < num_stocks; i++) {
        free_stock(stocks[i]);
    }

    return 0;
}