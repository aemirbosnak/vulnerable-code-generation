//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARANOIA_LEVEL 10

typedef struct {
    char *name;
    double price;
    double change;
} stock_t;

int main(int argc, char **argv) {
    // Initialize the stock market tracker.
    stock_t *stocks = NULL;
    int num_stocks = 0;

    // Read the stock data from a file.
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the stock data.
        char *name = strtok(line, ",");
        double price = atof(strtok(NULL, ","));
        double change = atof(strtok(NULL, ","));

        // Allocate memory for the stock.
        stock_t *stock = malloc(sizeof(stock_t));
        if (stock == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }

        // Initialize the stock.
        stock->name = strdup(name);
        stock->price = price;
        stock->change = change;

        // Add the stock to the list of stocks.
        stocks = realloc(stocks, (num_stocks + 1) * sizeof(stock_t));
        if (stocks == NULL) {
            perror("realloc");
            return EXIT_FAILURE;
        }

        stocks[num_stocks++] = *stock;
    }

    fclose(fp);

    // Print the stock data.
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Change");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s $%-10.2f %-10.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }

    // Free the memory allocated for the stocks.
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i].name);
        free(&stocks[i]);
    }

    free(stocks);

    return EXIT_SUCCESS;
}