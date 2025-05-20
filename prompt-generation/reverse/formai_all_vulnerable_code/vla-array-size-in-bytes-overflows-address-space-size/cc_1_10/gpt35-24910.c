//FormAI DATASET v1.0 Category: Stock market tracker ; Style: lively
// Welcome to the Ultimate Stock Market Tracker!

// Here, we've got everything you need to keep up with the fast-paced world of stock trading.
// Our program is designed to give you real-time updates on the state of the market and your own portfolio.

// So sit back, relax, and get ready to make some serious gains!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables for user profile
    char username[20];
    int initial_investment;
    int total_investment;
    int num_stocks;
    
    // Prompt user for information
    printf("Welcome to the Ultimate Stock Market Tracker!\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your initial investment (in dollars): ");
    scanf("%d", &initial_investment);
    total_investment = initial_investment;
    printf("Please enter the number of stocks in your portfolio: ");
    scanf("%d", &num_stocks);

    // Initialize variables for stock market tracker
    int stock_prices[num_stocks];
    int stock_quantities[num_stocks];
    int total_value = 0;
    int overall_diff = 0;

    // Populate arrays with initial values
    for (int i = 0; i < num_stocks; i++) {
        stock_prices[i] = rand() % 101;
        stock_quantities[i] = rand() % 101;
        total_value += stock_prices[i] * stock_quantities[i];
    }

    // Print initial portfolio values
    printf("\n%s's Portfolio\n", username);
    printf("Initial Investment: $%d\n", initial_investment);
    printf("Total Value: $%d\n", total_value);
    printf("Overall Difference: $%d\n\n", total_value - initial_investment);

    // Track stock market changes every minute for one hour
    for (int j = 0; j < 60; j++) {
        printf("Minute %d\n", j+1);
        printf("Stock\tPrice\tQuantity\tValue\n");
        for (int k = 0; k < num_stocks; k++) {
            // Generate random stock price change
            int price_change = rand() % 11 - 5;
            stock_prices[k] += price_change;
            
            // Print updated stock information
            printf("%d\t$%d\t%d\t\t$%d\n", k+1, stock_prices[k], stock_quantities[k], stock_prices[k]*stock_quantities[k]);

            // Update total value and overall difference
            total_value += price_change * stock_quantities[k];
            overall_diff = total_value - initial_investment;
        }
        printf("Total Value: $%d\n", total_value);
        printf("Overall Difference: $%d\n\n", overall_diff);

        // Wait one minute before updating prices again
        sleep(60);
    }

    // Print final portfolio values
    printf("Final Portfolio Values:\n");
    printf("Total Value: $%d\n", total_value);
    printf("Overall Difference: $%d\n\n", overall_diff);

    return 0;
}