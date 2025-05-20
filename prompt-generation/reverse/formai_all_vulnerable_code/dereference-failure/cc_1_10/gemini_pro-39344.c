//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the stock market structure
typedef struct {
    char *name;
    double price;
    double change;
} Stock;

// Create a new stock market structure
Stock *new_stock(char *name, double price, double change) {
    Stock *stock = malloc(sizeof(Stock));
    stock->name = name;
    stock->price = price;
    stock->change = change;
    return stock;
}

// Free the memory allocated to a stock market structure
void free_stock(Stock *stock) {
    free(stock->name);
    free(stock);
}

// Print the stock market structure
void print_stock(Stock *stock) {
    printf("%s: $%.2f (%.2f%%)\n", stock->name, stock->price, stock->change);
}

// Create a new stock market
Stock **new_stock_market(int num_stocks) {
    Stock **stock_market = malloc(sizeof(Stock *) * num_stocks);
    for (int i = 0; i < num_stocks; i++) {
        char *name = malloc(8);
        sprintf(name, "Stock%d", i + 1);
        double price = rand() % 100 + 1;
        double change = (rand() % 21 - 10) / 10.0;
        stock_market[i] = new_stock(name, price, change);
    }
    return stock_market;
}

// Free the memory allocated to a stock market
void free_stock_market(Stock **stock_market, int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        free_stock(stock_market[i]);
    }
    free(stock_market);
}

// Print the stock market
void print_stock_market(Stock **stock_market, int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stock_market[i]);
    }
}

// Update the stock market
void update_stock_market(Stock **stock_market, int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        stock_market[i]->price += (rand() % 21 - 10) / 10.0;
        stock_market[i]->change = (stock_market[i]->price - stock_market[i]->price) / stock_market[i]->price * 100;
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new stock market
    Stock **stock_market = new_stock_market(10);

    // Print the stock market
    printf("Welcome to the peaceful stock market!\n\n");
    print_stock_market(stock_market, 10);

    // Update the stock market
    for (int i = 0; i < 10; i++) {
        update_stock_market(stock_market, 10);
        printf("\nThe stock market has been updated:\n\n");
        print_stock_market(stock_market, 10);
    }

    // Free the memory allocated to the stock market
    free_stock_market(stock_market, 10);

    return 0;
}