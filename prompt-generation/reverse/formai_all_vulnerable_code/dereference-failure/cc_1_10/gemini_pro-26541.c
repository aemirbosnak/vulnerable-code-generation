//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a stock
typedef struct Stock {
    char *name;
    double price;
    double change;
} Stock;

// Function to create a new stock
Stock *new_stock(char *name, double price, double change) {
    Stock *stock = malloc(sizeof(Stock));
    stock->name = name;
    stock->price = price;
    stock->change = change;
    return stock;
}

// Function to print a stock
void print_stock(Stock *stock) {
    printf("%s $%.2f (%.2f%%)\n", stock->name, stock->price, stock->change);
}

// Function to update a stock's price and change
void update_stock(Stock *stock, double new_price) {
    double old_price = stock->price;
    stock->price = new_price;
    stock->change = (new_price - old_price) / old_price * 100;
}

// Function to track a stock's price recursively
void track_stock(Stock *stock, int depth) {
    // Base case: depth is 0
    if (depth == 0) {
        print_stock(stock);
        return;
    }

    // Recursive case: depth is greater than 0
    double new_price = stock->price * (1 + (rand() % 11 - 5) / 100.0);
    update_stock(stock, new_price);
    track_stock(stock, depth - 1);
}

// Main function
int main() {
    // Create a new stock
    Stock *stock = new_stock("AAPL", 100.00, 0.00);

    // Track the stock's price recursively for 100 days
    track_stock(stock, 100);

    // Free the stock
    free(stock);

    return 0;
}