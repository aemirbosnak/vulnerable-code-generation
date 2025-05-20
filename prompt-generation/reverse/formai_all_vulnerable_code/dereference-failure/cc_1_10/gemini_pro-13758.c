//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Variables used for counting up
double total_profit = 0;
int total_wins = 0;
int total_losses = 0;

// Type stock_info represents a stock's details
typedef struct stock_info {
    char *stock_name;
    double current_price;
    int share_count;
} stock_info;

// Function to initialize a stock_info struct
stock_info *init_stock(char *stock_name, double current_price, int share_count) {
    stock_info *s = malloc(sizeof(stock_info));
    s->stock_name = strdup(stock_name);
    s->current_price = current_price;
    s->share_count = share_count;
    return s;
}

// Function to print the details of a stock
void print_stock(stock_info *s) {
    printf("%s: \n", s->stock_name);
    printf("\tCurrent Price: $%.2f\n", s->current_price);
    printf("\tShares Owned: %d\n", s->share_count);
}

// Function to simulate buying a stock
stock_info *buy_stock(stock_info *s, double buy_price, int share_count) {
    // Update the current price and share count
    s->current_price = buy_price;
    s->share_count += share_count;
    return s;
}

// Function to simulate selling a stock
stock_info *sell_stock(stock_info *s, double sell_price, int share_count) {
    // Update the current price and share count
    s->current_price = sell_price;
    s->share_count -= share_count;
    return s;
}

// Function to calculate the profit for a given stock
double get_profit(stock_info *s) {
    return s->current_price * s->share_count;
}

// Function to randomly generate a stock price
double generate_stock_price() {
    return (double)rand() / RAND_MAX * 100.0;
}

// Function to randomly buy a stock
stock_info *random_buy(char *stock_name) {
    double buy_price = generate_stock_price();
    int share_count = rand() % 100;
    return buy_stock(init_stock(stock_name, buy_price, share_count), buy_price, share_count);
}

// Function to randomly sell a stock
stock_info *random_sell(stock_info *s) {
    double sell_price = generate_stock_price();
    int share_count = rand() % s->share_count;
    return sell_stock(s, sell_price, share_count);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create some sample stocks
    stock_info *stock1 = init_stock("XYZ Corp.", 50.00, 100);
    stock_info *stock2 = init_stock("ABC Corp.", 25.00, 150);
    stock_info *stock3 = init_stock("DEF Corp.", 75.00, 50);

    // Let's start our stock market adventure!
    printf("Welcome to the Stock Market Adventure!\n");
    printf("Let's buy some stocks and see how we do!\n");

    // Simulate 10 days of stock trading
    for (int day = 0; day < 10; day++) {
        // Randomly buy and sell stocks
        stock1 = random_buy("XYZ Corp.");
        stock2 = random_sell(stock2);
        stock3 = random_buy("DEF Corp.");
        // Calculate the total profit, wins, and losses
        double total_profit = get_profit(stock1) + get_profit(stock2) + get_profit(stock3);
        int total_wins = (get_profit(stock3) > 1000) ? 1 : 0;
        int total_losses = (get_profit(stock1) < 1000) ? 1: 0;

        // Print the current day's results
        printf("Day %d: \n", day + 1);
        print_stock(stock1);
        print_stock(stock2);
        print_stock(stock3);
        printf("Total Profit: $%.2f\n", get_profit(stock1) + get_profit(stock2) + get_profit(stock3));
        printf("Total Wins: %d\n", total_wins);
        printf("Total Losses: %d\n", total_losses);
    }


    // Print the final results
    printf("Congratulations! Here's how you did: \n");
    printf("Total Profit: $%.2f\n", get_profit(stock1) + get_profit(stock2) + get_profit(stock3));
    printf("Total Wins: %d\n", total_wins);
    printf("Total Losses: %d\n", total_losses);

    return 0;
}