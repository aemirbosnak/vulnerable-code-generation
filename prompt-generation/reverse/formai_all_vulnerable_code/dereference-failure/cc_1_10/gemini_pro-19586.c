//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 20

// Define the data structure to represent a stock
typedef struct stock {
    char* name;
    double price;
    int volume;
} stock_t;

// Define the function to create a new stock
stock_t* create_stock(char* name, double price, int volume) {
    stock_t* stock = malloc(sizeof(stock_t));
    stock->name = strdup(name);
    stock->price = price;
    stock->volume = volume;
    return stock;
}

// Define the function to print the details of a stock
void print_stock(stock_t* stock) {
    printf("Name: %s\n", stock->name);
    printf("Price: %.2f\n", stock->price);
    printf("Volume: %d\n", stock->volume);
}

// Define the function to compare two stocks by their names
int compare_stocks(stock_t* stock1, stock_t* stock2) {
    return strcmp(stock1->name, stock2->name);
}

// Define the function to sort an array of stocks by their names
void sort_stocks(stock_t* stocks, int num_stocks) {
    qsort(stocks, num_stocks, sizeof(stock_t), compare_stocks);
}

// Define the function to search for a stock in an array of stocks by its name
stock_t* search_stock(stock_t* stocks, int num_stocks, char* name) {
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            return &stocks[i];
        }
    }
    return NULL;
}

// Define the main function
int main() {
    // Create an array of stocks
    stock_t* stocks[MAX_STOCKS];

    // Initialize the array of stocks
    stocks[0] = create_stock("Apple", 100.0, 10000);
    stocks[1] = create_stock("Microsoft", 50.0, 50000);
    stocks[2] = create_stock("Google", 80.0, 20000);
    stocks[3] = create_stock("Amazon", 90.0, 15000);

    // Get the number of stocks in the array
    int num_stocks = sizeof(stocks) / sizeof(stock_t*);

    // Sort the array of stocks by their names
    sort_stocks(stocks, num_stocks);

    // Print the details of each stock
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
        printf("\n");
    }

    // Search for a stock in the array by its name
    char* name = "Google";
    stock_t* stock = search_stock(stocks, num_stocks, name);

    // Print the details of the stock if it was found
    if (stock != NULL) {
        printf("Stock found:\n");
        print_stock(stock);
        printf("\n");
    } else {
        printf("Stock not found.\n");
    }

    // Free the memory allocated for each stock
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i]->name);
        free(stocks[i]);
    }

    return 0;
}