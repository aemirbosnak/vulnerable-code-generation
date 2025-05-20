//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the stock structure
typedef struct {
    char symbol[10];
    float price;
    float change;
} Stock;

// Define the portfolio structure
typedef struct {
    Stock stocks[10];
    int num_stocks;
} Portfolio;

// Create a new portfolio
Portfolio* create_portfolio() {
    Portfolio* portfolio = malloc(sizeof(Portfolio));
    portfolio->num_stocks = 0;
    return portfolio;
}

// Add a stock to the portfolio
void add_stock(Portfolio* portfolio, Stock stock) {
    portfolio->stocks[portfolio->num_stocks] = stock;
    portfolio->num_stocks++;
}

// Print the portfolio
void print_portfolio(Portfolio* portfolio) {
    for (int i = 0; i < portfolio->num_stocks; i++) {
        printf("%-10s $%.2f %.2f%%\n", portfolio->stocks[i].symbol,
            portfolio->stocks[i].price, portfolio->stocks[i].change);
    }
}

// Get the stock price from the user
float get_stock_price() {
    float price;
    printf("Enter the stock price: ");
    scanf("%f", &price);
    return price;
}

// Get the stock change from the user
float get_stock_change() {
    float change;
    printf("Enter the stock change: ");
    scanf("%f", &change);
    return change;
}

// Get the stock symbol from the user
char* get_stock_symbol() {
    char* symbol = malloc(10);
    printf("Enter the stock symbol: ");
    scanf("%s", symbol);
    return symbol;
}

// Main function
int main() {
    // Create a new portfolio
    Portfolio* portfolio = create_portfolio();

    // Add some stocks to the portfolio
    Stock stock1 = {"AAPL", 100.00, 1.00};
    add_stock(portfolio, stock1);
    Stock stock2 = {"GOOGL", 120.00, 2.00};
    add_stock(portfolio, stock2);
    Stock stock3 = {"MSFT", 90.00, 3.00};
    add_stock(portfolio, stock3);

    // Print the portfolio
    printf("Your portfolio:\n");
    print_portfolio(portfolio);

    // Get a new stock from the user
    Stock new_stock;
    strcpy(new_stock.symbol, get_stock_symbol());
    new_stock.price = get_stock_price();
    new_stock.change = get_stock_change();

    // Add the new stock to the portfolio
    add_stock(portfolio, new_stock);

    // Print the updated portfolio
    printf("\nYour updated portfolio:\n");
    print_portfolio(portfolio);

    return 0;
}