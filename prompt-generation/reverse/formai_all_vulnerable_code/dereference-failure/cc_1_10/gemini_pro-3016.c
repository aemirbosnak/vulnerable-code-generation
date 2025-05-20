//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure of a stock
typedef struct stock {
    char *name;
    double price;
    double change;
} stock;

// Create a new stock
stock *new_stock(char *name, double price, double change) {
    stock *s = malloc(sizeof(stock));
    s->name = strdup(name);
    s->price = price;
    s->change = change;
    return s;
}

// Print the details of a stock
void print_stock(stock *s) {
    printf("%s: $%.2f (%.2f%%)\n", s->name, s->price, s->change);
}

// Compare two stocks by their price
int compare_stocks_by_price(const void *a, const void *b) {
    stock *sa = (stock *)a;
    stock *sb = (stock *)b;
    return sa->price - sb->price;
}

// Compare two stocks by their change
int compare_stocks_by_change(const void *a, const void *b) {
    stock *sa = (stock *)a;
    stock *sb = (stock *)b;
    return sa->change - sb->change;
}

// Get the current time as a string
char *get_current_time() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *time_str = malloc(sizeof(char) * 20);
    strftime(time_str, 20, "%Y-%m-%d %H:%M:%S", tm);
    return time_str;
}

// Main function
int main() {
    // Create an array of stocks
    stock *stocks[] = {
        new_stock("Apple", 120.00, 1.00),
        new_stock("Microsoft", 100.00, -1.00),
        new_stock("Google", 150.00, 2.00),
        new_stock("Amazon", 180.00, 3.00),
        new_stock("Tesla", 200.00, 4.00),
    };

    // Print the current time
    char *current_time = get_current_time();
    printf("Current time: %s\n\n", current_time);

    // Print the original order of the stocks
    printf("Original order:\n");
    for (int i = 0; i < 5; i++) {
        print_stock(stocks[i]);
    }

    // Sort the stocks by price
    qsort(stocks, 5, sizeof(stock *), compare_stocks_by_price);

    // Print the stocks sorted by price
    printf("\nSorted by price:\n");
    for (int i = 0; i < 5; i++) {
        print_stock(stocks[i]);
    }

    // Sort the stocks by change
    qsort(stocks, 5, sizeof(stock *), compare_stocks_by_change);

    // Print the stocks sorted by change
    printf("\nSorted by change:\n");
    for (int i = 0; i < 5; i++) {
        print_stock(stocks[i]);
    }

    // Free the memory allocated for the stocks
    for (int i = 0; i < 5; i++) {
        free(stocks[i]->name);
        free(stocks[i]);
    }

    free(current_time);
    return 0;
}