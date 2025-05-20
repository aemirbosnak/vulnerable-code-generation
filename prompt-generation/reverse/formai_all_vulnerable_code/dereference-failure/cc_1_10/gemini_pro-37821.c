//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the maximum length of a stock symbol
#define MAX_SYMBOL_LENGTH 10

// Define the maximum length of a stock name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a stock price
#define MAX_PRICE_LENGTH 10

// Define the structure of a stock
typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    char name[MAX_NAME_LENGTH];
    double price;
    double change;
    double percent_change;
} stock;

// Define the structure of a portfolio
typedef struct {
    stock stocks[MAX_STOCKS];
    int num_stocks;
} portfolio;

// Define the function to create a new portfolio
portfolio* create_portfolio() {
    portfolio* portfolio = malloc(sizeof(portfolio));
    portfolio->num_stocks = 0;
    return portfolio;
}

// Define the function to add a stock to a portfolio
void add_stock(portfolio* portfolio, stock* stock) {
    portfolio->stocks[portfolio->num_stocks] = *stock;
    portfolio->num_stocks++;
}

// Define the function to get a stock by symbol
stock* get_stock_by_symbol(portfolio* portfolio, char* symbol) {
    for (int i = 0; i < portfolio->num_stocks; i++) {
        if (strcmp(portfolio->stocks[i].symbol, symbol) == 0) {
            return &portfolio->stocks[i];
        }
    }
    return NULL;
}

// Define the function to print a portfolio
void print_portfolio(portfolio* portfolio) {
    printf("My Beloved Portfolio:\n");
    for (int i = 0; i < portfolio->num_stocks; i++) {
        printf("%s: %s, $%.2f, %.2f%%", portfolio->stocks[i].symbol, portfolio->stocks[i].name, portfolio->stocks[i].price, portfolio->stocks[i].percent_change);
        if (portfolio->stocks[i].change > 0) {
            printf(" 📈");
        } else if (portfolio->stocks[i].change < 0) {
            printf(" 📉");
        }
        printf("\n");
    }
}

// Define the function to main
int main() {
    // Create a new portfolio
    portfolio* portfolio = create_portfolio();

    // Add some stocks to the portfolio
    stock stock1 = {"AAPL", "Apple Inc.", 140.00, 1.00, 0.71};
    add_stock(portfolio, &stock1);
    stock stock2 = {"GOOGL", "Google LLC", 1,200.00, 0.00, 0.00};
    add_stock(portfolio, &stock2);
    stock stock3 = {"AMZN", "Amazon.com, Inc.", 1,800.00, -2.00, -0.11};
    add_stock(portfolio, &stock3);

    // Print the portfolio
    print_portfolio(portfolio);

    // Get a stock by symbol
    stock* stock = get_stock_by_symbol(portfolio, "GOOGL");
    if (stock != NULL) {
        printf("The stock with the symbol GOOGL is %s, trading at $%.2f.\n", stock->name, stock->price);
    } else {
        printf("The stock with the symbol GOOGL was not found.\n");
    }

    return 0;
}