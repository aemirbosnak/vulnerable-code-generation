//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for a stock
typedef struct {
    char *name;
    double price;
    double change;
    double volume;
} Stock;

// Define the data structure for a list of stocks
typedef struct {
    Stock *stocks;
    int size;
    int capacity;
} StockList;

// Create a new stock list
StockList *stock_list_new() {
    StockList *list = malloc(sizeof(StockList));
    list->stocks = malloc(sizeof(Stock) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

// Add a stock to the list
void stock_list_add(StockList *list, Stock stock) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->stocks = realloc(list->stocks, sizeof(Stock) * list->capacity);
    }
    list->stocks[list->size] = stock;
    list->size++;
}

// Print the list of stocks
void stock_list_print(StockList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s: $%.2f (%.2f%%)\n", list->stocks[i].name, list->stocks[i].price, list->stocks[i].change);
    }
}

// Free the memory allocated for the list
void stock_list_free(StockList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->stocks[i].name);
    }
    free(list->stocks);
    free(list);
}

// Main function
int main() {
    // Create a new stock list
    StockList *list = stock_list_new();

    // Add some stocks to the list
    stock_list_add(list, (Stock) { .name = "Apple", .price = 120.0, .change = 1.0, .volume = 100000 });
    stock_list_add(list, (Stock) { .name = "Google", .price = 100.0, .change = -1.0, .volume = 50000 });
    stock_list_add(list, (Stock) { .name = "Microsoft", .price = 90.0, .change = 0.0, .volume = 25000 });

    // Print the list of stocks
    stock_list_print(list);

    // Free the memory allocated for the list
    stock_list_free(list);

    return 0;
}