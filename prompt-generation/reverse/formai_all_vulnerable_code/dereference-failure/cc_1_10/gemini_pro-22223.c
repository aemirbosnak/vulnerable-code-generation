//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Structure to represent a stock
typedef struct {
    char *name;
    double price;
    double change;
    double volume;
} Stock;

// Function to compare two stocks by price
int compare_stocks_by_price(const void *a, const void *b) {
    const Stock *stock1 = (const Stock *)a;
    const Stock *stock2 = (const Stock *)b;
    return stock1->price - stock2->price;
}

// Function to print a stock
void print_stock(const Stock *stock) {
    printf("%s %.2f (%.2f%%) %d\n", stock->name, stock->price, stock->change, stock->volume);
}

// Function to generate a random stock
Stock generate_random_stock(const char *name) {
    Stock stock;
    stock.name = (char *)malloc(strlen(name) + 1);
    strcpy(stock.name, name);
    stock.price = (double)rand() / RAND_MAX * 100.0;
    stock.change = (double)rand() / RAND_MAX * 20.0 - 10.0;
    stock.volume = (int)rand() / RAND_MAX * 10000;
    return stock;
}

// Main function
int main() {
    // Set random seed
    srand(time(NULL));

    // Create an array of stocks
    const int num_stocks = 10;
    Stock stocks[num_stocks];

    // Generate random stocks
    for (int i = 0; i < num_stocks; i++) {
        stocks[i] = generate_random_stock("Stock");
    }

    // Sort the stocks by price
    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks_by_price);

    // Print the stocks
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}