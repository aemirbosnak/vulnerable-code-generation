//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 20

// Define the structure of a stock
typedef struct stock {
    char *name;    // The name of the stock
    double price;   // The current price of the stock
    double change;  // The change in price since the previous day
    double volume;  // The volume of shares traded in the previous day
} stock;

// Declare an array of stocks
stock stocks[MAX_STOCKS];

// Declare the number of stocks being tracked
int num_stocks = 0;

// Get the stock data from a file
void get_stock_data(char *filename) {
    FILE *fp;
    char line[1024];

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the line
        char *name = strtok(line, ",");
        double price = atof(strtok(NULL, ","));
        double change = atof(strtok(NULL, ","));
        double volume = atof(strtok(NULL, ","));

        // Add the stock to the array
        stocks[num_stocks].name = strdup(name);
        stocks[num_stocks].price = price;
        stocks[num_stocks].change = change;
        stocks[num_stocks].volume = volume;

        // Increment the number of stocks
        num_stocks++;
    }

    // Close the file
    fclose(fp);
}

// Print the stock data
void print_stock_data() {
    // Print the header
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Price", "Change", "Volume");

    // Print the data for each stock
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s %-10.2f %-10.2f %-10.2f\n", stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].volume);
    }
}

// Free the memory allocated for the stock data
void free_stock_data() {
    // Free the memory for each stock
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i].name);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the stock data from the file
    get_stock_data(argv[1]);

    // Print the stock data
    print_stock_data();

    // Free the memory allocated for the stock data
    free_stock_data();

    return EXIT_SUCCESS;
}