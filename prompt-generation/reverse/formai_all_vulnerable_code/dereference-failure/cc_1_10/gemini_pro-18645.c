//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structures
typedef struct Stock {
    char *symbol;
    double price;
    double change;
    double volume;
} Stock;

typedef struct Portfolio {
    Stock *stocks;
    int num_stocks;
} Portfolio;

// Function prototypes
void print_stock(Stock *stock);
void print_portfolio(Portfolio *portfolio);
double calculate_portfolio_value(Portfolio *portfolio);

// Main function
int main() {
    // Create a portfolio
    Portfolio portfolio;
    portfolio.stocks = malloc(sizeof(Stock) * 5);
    portfolio.num_stocks = 5;

    // Initialize the portfolio with some sample data
    portfolio.stocks[0].symbol = "AAPL";
    portfolio.stocks[0].price = 100.0;
    portfolio.stocks[0].change = 1.0;
    portfolio.stocks[0].volume = 1000000;

    portfolio.stocks[1].symbol = "GOOG";
    portfolio.stocks[1].price = 500.0;
    portfolio.stocks[1].change = 2.0;
    portfolio.stocks[1].volume = 500000;

    portfolio.stocks[2].symbol = "AMZN";
    portfolio.stocks[2].price = 1000.0;
    portfolio.stocks[2].change = 3.0;
    portfolio.stocks[2].volume = 250000;

    portfolio.stocks[3].symbol = "MSFT";
    portfolio.stocks[3].price = 200.0;
    portfolio.stocks[3].change = 4.0;
    portfolio.stocks[3].volume = 1500000;

    portfolio.stocks[4].symbol = "BRK.A";
    portfolio.stocks[4].price = 3000.0;
    portfolio.stocks[4].change = 5.0;
    portfolio.stocks[4].volume = 100000;

    // Print the portfolio
    print_portfolio(&portfolio);

    // Calculate the portfolio value
    double portfolio_value = calculate_portfolio_value(&portfolio);

    // Print the portfolio value
    printf("Portfolio value: %.2f\n", portfolio_value);

    return 0;
}

// Function to print a stock
void print_stock(Stock *stock) {
    printf("Symbol: %s, Price: %.2f, Change: %.2f, Volume: %d\n", 
        stock->symbol, stock->price, stock->change, stock->volume);
}

// Function to print a portfolio
void print_portfolio(Portfolio *portfolio) {
    for (int i = 0; i < portfolio->num_stocks; i++) {
        print_stock(&portfolio->stocks[i]);
    }
}

// Function to calculate the portfolio value
double calculate_portfolio_value(Portfolio *portfolio) {
    double portfolio_value = 0.0;
    for (int i = 0; i < portfolio->num_stocks; i++) {
        portfolio_value += portfolio->stocks[i].price * portfolio->stocks[i].volume;
    }
    return portfolio_value;
}