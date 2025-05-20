//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct stock {
    char *name;
    char *symbol;
    double price;
    double change;
} stock;

int main() {
    // Initialize the stock market
    stock market[10];
    strcpy(market[0].name, "Apple Inc.");
    strcpy(market[0].symbol, "AAPL");
    market[0].price = 174.87;
    market[0].change = -0.06;
    strcpy(market[1].name, "Microsoft Corporation");
    strcpy(market[1].symbol, "MSFT");
    market[1].price = 276.92;
    market[1].change = 0.23;
    strcpy(market[2].name, "Amazon.com, Inc.");
    strcpy(market[2].symbol, "AMZN");
    market[2].price = 3,344.23;
    market[2].change = -0.12;
    strcpy(market[3].name, "Alphabet Inc.");
    strcpy(market[3].symbol, "GOOGL");
    market[3].price = 2,411.30;
    market[3].change = 0.15;
    strcpy(market[4].name, "Tesla, Inc.");
    strcpy(market[4].symbol, "TSLA");
    market[4].price = 1,105.60;
    market[4].change = -0.35;
    strcpy(market[5].name, "Berkshire Hathaway Inc.");
    strcpy(market[5].symbol, "BRK.A");
    market[5].price = 486,860.00;
    market[5].change = 0.03;
    strcpy(market[6].name, "JPMorgan Chase & Co.");
    strcpy(market[6].symbol, "JPM");
    market[6].price = 144.33;
    market[6].change = -0.05;
    strcpy(market[7].name, "Bank of America Corporation");
    strcpy(market[7].symbol, "BAC");
    market[7].price = 44.02;
    market[7].change = 0.10;
    strcpy(market[8].name, "UnitedHealth Group Incorporated");
    strcpy(market[8].symbol, "UNH");
    market[8].price = 466.37;
    market[8].change = 0.27;
    strcpy(market[9].name, "Johnson & Johnson");
    strcpy(market[9].symbol, "JNJ");
    market[9].price = 174.51;
    market[9].change = 0.08;

    // Print the stock market
    printf("Stock Market Tracker\n");
    printf("---------------------\n");
    printf("| Name           | Symbol | Price   | Change  |\n");
    printf("|-----------------|--------|---------|---------|\n");
    for (int i = 0; i < 10; i++) {
        printf("| %-15s | %-6s | $%-7.2f | %5.2f%% |\n", market[i].name, market[i].symbol, market[i].price, market[i].change);
    }
    printf("---------------------\n");

    // Get the user's input
    char input[10];
    printf("\nEnter a stock symbol to track: ");
    scanf("%s", input);

    // Find the stock in the market
    int index = -1;
    for (int i = 0; i < 10; i++) {
        if (strcmp(market[i].symbol, input) == 0) {
            index = i;
            break;
        }
    }

    // If the stock was found, print its details
    if (index != -1) {
        printf("\nStock Details\n");
        printf("-------------\n");
        printf("Name: %s\n", market[index].name);
        printf("Symbol: %s\n", market[index].symbol);
        printf("Price: $%.2f\n", market[index].price);
        printf("Change: %.2f%%\n", market[index].change);
        printf("---------------------\n");
    } else {
        printf("\nStock not found.\n");
    }

    return 0;
}