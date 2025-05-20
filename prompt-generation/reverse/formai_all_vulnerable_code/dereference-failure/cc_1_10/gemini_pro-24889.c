//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the stock structure
typedef struct stock {
    char symbol[10];
    float price;
    float change;
    float percent_change;
} stock;

// Declare the stock list structure
typedef struct stock_list {
    stock *stocks;
    int count;
} stock_list;

// Function to create a new stock
stock *create_stock(char *symbol, float price, float change, float percent_change) {
    stock *new_stock = (stock *)malloc(sizeof(stock));
    strcpy(new_stock->symbol, symbol);
    new_stock->price = price;
    new_stock->change = change;
    new_stock->percent_change = percent_change;
    return new_stock;
}

// Function to create a new stock list
stock_list *create_stock_list() {
    stock_list *new_stock_list = (stock_list *)malloc(sizeof(stock_list));
    new_stock_list->stocks = (stock *)malloc(sizeof(stock) * 100);
    new_stock_list->count = 0;
    return new_stock_list;
}

// Function to add a stock to a stock list
void add_stock_to_list(stock_list *stock_list, stock *stock) {
    stock_list->stocks[stock_list->count] = *stock;
    stock_list->count++;
}

// Function to print a stock list
void print_stock_list(stock_list *stock_list) {
    for (int i = 0; i < stock_list->count; i++) {
        printf("%s: $%.2f (%.2f%%)\n", stock_list->stocks[i].symbol, stock_list->stocks[i].price, stock_list->stocks[i].percent_change);
    }
}

// Function to free a stock list
void free_stock_list(stock_list *stock_list) {
    free(stock_list->stocks);
    free(stock_list);
}

// Main function
int main() {
    // Create a new stock list
    stock_list *stock_list = create_stock_list();

    // Add some stocks to the stock list
    add_stock_to_list(stock_list, create_stock("AAPL", 123.45, 1.23, 1.0));
    add_stock_to_list(stock_list, create_stock("GOOG", 789.10, -2.34, -0.3));
    add_stock_to_list(stock_list, create_stock("AMZN", 1234.56, 3.45, 0.2));

    // Print the stock list
    printf("Here is the current stock market status:\n");
    print_stock_list(stock_list);

    // Free the stock list
    free_stock_list(stock_list);

    return 0;
}