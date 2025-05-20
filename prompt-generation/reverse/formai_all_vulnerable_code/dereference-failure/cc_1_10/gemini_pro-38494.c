//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock {
    char *symbol;
    double price;
    double prev_price;
    time_t timestamp;
};

struct stock_node {
    struct stock stock;
    struct stock_node *next;
};

struct stock_list {
    struct stock_node *head;
    int size;
};

struct stock_list *create_stock_list() {
    struct stock_list *list = malloc(sizeof(struct stock_list));
    list->head = NULL;
    list->size = 0;
    return list;
}

void add_stock(struct stock_list *list, char *symbol, double price, time_t timestamp) {
    struct stock_node *node = malloc(sizeof(struct stock_node));
    node->stock.symbol = malloc(strlen(symbol) + 1);
    strcpy(node->stock.symbol, symbol);
    node->stock.price = price;
    node->stock.prev_price = 0.0;
    node->stock.timestamp = timestamp;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void print_stock_list(struct stock_list *list) {
    struct stock_node *node = list->head;
    while (node != NULL) {
        printf("%s: %.2f (%.2f)\n", node->stock.symbol, node->stock.price, node->stock.prev_price);
        node = node->next;
    }
}

void free_stock_list(struct stock_list *list) {
    struct stock_node *node = list->head;
    while (node != NULL) {
        struct stock_node *next = node->next;
        free(node->stock.symbol);
        free(node);
        node = next;
    }
    free(list);
}

int main() {
    struct stock_list *list = create_stock_list();

    // Add some sample stocks to the list
    add_stock(list, "AAPL", 123.45, time(NULL));
    add_stock(list, "GOOGL", 876.54, time(NULL));
    add_stock(list, "AMZN", 1000.00, time(NULL));

    // Print the list of stocks
    print_stock_list(list);

    // Free the list
    free_stock_list(list);

    return 0;
}