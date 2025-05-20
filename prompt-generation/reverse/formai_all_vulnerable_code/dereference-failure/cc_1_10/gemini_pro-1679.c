//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct stock {
    char symbol[10];  // The stock symbol
    double price;     // The current price of the stock
    double change;    // The change in price since the previous day
    double percent_change;  // The percentage change in price since the previous day
} stock;

// Define the array of stocks to track
stock stocks[MAX_STOCKS];

// Define the function to get the stock data from a file
void get_stock_data(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the header line
    char line[1024];
    fgets(line, sizeof(line), fp);

    // Read the stock data
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Parse the stock data
        char *token = strtok(line, ",");
        strcpy(stocks[i].symbol, token);

        token = strtok(NULL, ",");
        stocks[i].price = atof(token);

        token = strtok(NULL, ",");
        stocks[i].change = atof(token);

        token = strtok(NULL, ",");
        stocks[i].percent_change = atof(token);

        i++;
    }

    // Close the file
    fclose(fp);
}

// Define the function to print the stock data
void print_stock_data() {
    // Print the header
    printf("%-10s %-10s %-10s %-10s\n", "Symbol", "Price", "Change", "Percent Change");

    // Print the stock data
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%-10s $%-10.2f %-10.2f %10.2f%%\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
    }
}

// Define the main function
int main(int argc, char *argv[]) {
    // Get the stock data from the file
    get_stock_data("stocks.txt");

    // Print the stock data
    print_stock_data();

    return 0;
}