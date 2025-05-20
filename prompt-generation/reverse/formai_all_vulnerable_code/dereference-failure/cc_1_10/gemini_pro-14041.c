//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store stock data
typedef struct stock {
    char symbol[10];
    float price;
    float change;
    float percent_change;
} stock;

// Array of stock symbols
char *symbols[] = {"AAPL", "GOOG", "MSFT", "AMZN", "TSLA"};

// Function to get stock data from a file
int get_stock_data(stock *stocks, int num_stocks) {
    FILE *fp;
    char line[100];
    int i;

    // Open the file containing the stock data
    fp = fopen("stock_data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the file line by line and store the data in the stocks array
    for (i = 0; i < num_stocks; i++) {
        fgets(line, sizeof(line), fp);
        sscanf(line, "%s,%f,%f,%f", stocks[i].symbol, &stocks[i].price, &stocks[i].change, &stocks[i].percent_change);
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Function to print the stock data
void print_stock_data(stock *stocks, int num_stocks) {
    int i;

    // Print the header
    printf("%-10s %-10s %-10s %-10s\n", "Symbol", "Price", "Change", "Percent Change");

    // Print the stock data
    for (i = 0; i < num_stocks; i++) {
        printf("%-10s $%-10.2f %-+10.2f %-+10.2f%%\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
    }
}

// Function to get the user's input
int get_user_input(int *num_stocks, char ***symbols) {
    int i;

    // Get the number of stocks to track
    printf("Enter the number of stocks to track: ");
    scanf("%d", num_stocks);

    // Allocate memory for the array of stock symbols
    *symbols = (char **)malloc(*num_stocks * sizeof(char *));

    // Get the stock symbols
    for (i = 0; i < *num_stocks; i++) {
        printf("Enter the symbol for stock %d: ", i + 1);
        scanf("%s", (*symbols)[i]);
    }

    return 0;
}

// Main function
int main() {
    int num_stocks;
    char **symbols;
    stock *stocks;
    int i;

    // Get the user's input
    get_user_input(&num_stocks, &symbols);

    // Allocate memory for the array of stocks
    stocks = (stock *)malloc(num_stocks * sizeof(stock));

    // Get the stock data
    get_stock_data(stocks, num_stocks);

    // Print the stock data
    print_stock_data(stocks, num_stocks);

    // Free the memory allocated for the arrays
    free(stocks);
    for (i = 0; i < num_stocks; i++) {
        free(symbols[i]);
    }
    free(symbols);

    return 0;
}