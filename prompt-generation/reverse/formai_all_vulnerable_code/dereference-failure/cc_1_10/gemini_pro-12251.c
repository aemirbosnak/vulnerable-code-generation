//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Stock data structure
typedef struct Stock {
    char *name;
    double price;
    double change;
} Stock;

// Create a new stock
Stock *new_stock(char *name, double price, double change) {
    Stock *stock = malloc(sizeof(Stock));
    stock->name = name;
    stock->price = price;
    stock->change = change;
    return stock;
}

// Print the stock
void print_stock(Stock *stock) {
    printf("%s: $%.2f (%.2f%%)\n", stock->name, stock->price, stock->change);
}

// Randomly generate a stock
Stock *random_stock() {
    // Generate a random name
    int name_length = rand() % 10 + 5;
    char *name = malloc(name_length + 1);
    for (int i = 0; i < name_length; i++) {
        name[i] = 'A' + rand() % 26;
    }
    name[name_length] = '\0';

    // Generate a random price
    double price = (rand() % 1000) / 100.0;

    // Generate a random change
    double change = (rand() % 100) / 100.0 - 0.5;

    // Create the stock
    return new_stock(name, price, change);
}

// Generate a random portfolio
Stock **random_portfolio(int size) {
    // Create an array of stocks
    Stock **portfolio = malloc(sizeof(Stock *) * size);

    // Generate a random stock for each slot
    for (int i = 0; i < size; i++) {
        portfolio[i] = random_stock();
    }

    // Return the portfolio
    return portfolio;
}

// Print the portfolio
void print_portfolio(Stock **portfolio, int size) {
    for (int i = 0; i < size; i++) {
        print_stock(portfolio[i]);
    }
}

// Free the portfolio
void free_portfolio(Stock **portfolio, int size) {
    for (int i = 0; i < size; i++) {
        free(portfolio[i]->name);
        free(portfolio[i]);
    }
    free(portfolio);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random portfolio
    Stock **portfolio = random_portfolio(10);

    // Print the portfolio
    printf("Your portfolio:\n");
    print_portfolio(portfolio, 10);

    // Free the portfolio
    free_portfolio(portfolio, 10);

    return 0;
}