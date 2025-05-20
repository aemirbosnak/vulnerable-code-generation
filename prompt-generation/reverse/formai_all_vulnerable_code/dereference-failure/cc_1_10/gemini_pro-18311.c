//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a stock
typedef struct stock {
    char *name;
    float price;
    float change;
} stock;

// A function to print a stock
void print_stock(stock *s) {
    printf("%s %.2f (%.2f%%)\n", s->name, s->price, s->change);
}

// A function to compare two stocks by price
int compare_stocks(const void *a, const void *b) {
    stock *sa = (stock *)a;
    stock *sb = (stock *)b;
    return sa->price - sb->price;
}

// A function to load stocks from a CSV file
stock *load_stocks(const char *filename, int *num_stocks) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the first line of the file to get the number of stocks
    char line[1024];
    if (fgets(line, sizeof(line), file) == NULL) {
        perror("Error reading file");
        fclose(file);
        return NULL;
    }
    *num_stocks = atoi(line);

    // Allocate memory for the stocks
    stock *stocks = malloc(*num_stocks * sizeof(stock));
    if (stocks == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read the remaining lines of the file to get the stock data
    for (int i = 0; i < *num_stocks; i++) {
        if (fgets(line, sizeof(line), file) == NULL) {
            perror("Error reading file");
            fclose(file);
            free(stocks);
            return NULL;
        }

        // Parse the stock data from the line
        char *name = strtok(line, ",");
        float price = atof(strtok(NULL, ","));
        float change = atof(strtok(NULL, ","));

        // Create a stock struct and store the data
        stocks[i].name = malloc(strlen(name) + 1);
        strcpy(stocks[i].name, name);
        stocks[i].price = price;
        stocks[i].change = change;
    }

    // Close the file
    fclose(file);

    // Return the stocks
    return stocks;
}

// A function to free the memory allocated for the stocks
void free_stocks(stock *stocks, int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i].name);
    }
    free(stocks);
}

// The main function
int main() {
    // Load the stocks from the CSV file
    int num_stocks;
    stock *stocks = load_stocks("stocks.csv", &num_stocks);
    if (stocks == NULL) {
        return 1;
    }

    // Print the loaded stocks
    printf("Loaded %d stocks:\n", num_stocks);
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    // Sort the stocks by price
    qsort(stocks, num_stocks, sizeof(stock), compare_stocks);

    // Print the sorted stocks
    printf("\nSorted stocks by price:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    // Free the memory allocated for the stocks
    free_stocks(stocks, num_stocks);

    return 0;
}