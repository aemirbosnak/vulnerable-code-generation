//FormAI DATASET v1.0 Category: Stock market tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 5
#define STOCK_NAME_LENGTH 20

// A decentralized stock object
typedef struct Stock {
    char name[STOCK_NAME_LENGTH];
    float current_price;
    float prev_closing_price;
    float opening_price;
    float high_price;
    float low_price;
} Stock;

// Initialize an array of decentralized stocks
void initialize_stocks(Stock stocks[]) {
    char* stock_names[] = {"AAPL", "GOOGL", "TSLA", "MSFT", "AMZN"};
    srand(time(NULL)); // Seed the random number generator with current time
    
    for (int i = 0; i < NUM_STOCKS; i++) {
        stocks[i].current_price = rand() % 1000 + 1; // Generate a random current price
        stocks[i].prev_closing_price = stocks[i].current_price;
        stocks[i].opening_price = stocks[i].current_price;
        stocks[i].high_price = stocks[i].current_price;
        stocks[i].low_price = stocks[i].current_price;
        
        // Copy stock name into stock object
        for (int j = 0; j < STOCK_NAME_LENGTH; j++) {
            stocks[i].name[j] = stock_names[i][j];
        }
    }
}

// Update the prices of the decentralized stocks
void update_prices(Stock stocks[]) {
    for (int i = 0; i < NUM_STOCKS; i++) {
        stocks[i].prev_closing_price = stocks[i].current_price;
        stocks[i].current_price = rand() % 1000 + 1; // Generate a new random current price
        
        if (stocks[i].current_price > stocks[i].high_price) {
            stocks[i].high_price = stocks[i].current_price;
        }
        
        if (stocks[i].current_price < stocks[i].low_price) {
            stocks[i].low_price = stocks[i].current_price;
        }
    }
}

// Print the information of a decentralized stock
void print_stock_info(Stock stock) {
    printf("%s\n", stock.name);
    printf("Current Price: $%.2f\n", stock.current_price);
    printf("Previous Closing Price: $%.2f\n", stock.prev_closing_price);
    printf("Opening Price: $%.2f\n", stock.opening_price);
    printf("High Price: $%.2f\n", stock.high_price);
    printf("Low Price: $%.2f\n", stock.low_price);
}

// Print the information of all the decentralized stocks
void print_all_stocks_info(Stock stocks[]) {
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("======================\n");
        print_stock_info(stocks[i]);
        printf("======================\n");
    }
}

int main() {
    Stock stocks[NUM_STOCKS];
    initialize_stocks(stocks);
    
    printf("Initial Stock Prices:\n");
    print_all_stocks_info(stocks);
    
    // Update the prices of stocks and print after each update
    for (int i = 1; i <= 5; i++) {
        update_prices(stocks);
        printf("\nStock Prices after Update %d:\n", i);
        print_all_stocks_info(stocks);
    }
    
    return 0;
}