//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Stock {
    char symbol[5];
    float price;
    struct Stock *next;
} Stock;

void addStock(Stock **head, char symbol[], float price) {
    Stock *newStock = (Stock*) malloc(sizeof(Stock));
    strcpy(newStock->symbol, symbol);
    newStock->price = price;
    newStock->next = *head;
    *head = newStock;
}

void printStockList(Stock *head) {
    Stock *current = head;
    while (current != NULL) {
        printf("| %-5s | %6.2f |\n", current->symbol, current->price);
        current = current->next;
    }
}

void updateStockPrice(Stock **head, char symbol[]) {
    Stock *current = *head;
    Stock *previous = NULL;

    while (current != NULL && strcmp(current->symbol, symbol) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Stock not found.\n");
        return;
    }

    time_t now = time(NULL);
    float newPrice = 100.0 + 5.0 * (float) (now % 1000) / 100.0; // Just a placeholder for real-time stock price update
    current->price = newPrice;
    printf("Updated price of %s: %.2f\n", current->symbol, newPrice);
}

int main() {
    Stock *stockList = NULL;

    addStock(&stockList, "AAPL", 120.50);
    addStock(&stockList, "MSFT", 150.25);
    addStock(&stockList, "GOOG", 110.75);

    printf("Initial stock prices:\n");
    printStockList(stockList);

    updateStockPrice(&stockList, "MSFT");

    printf("\nStock prices after update:\n");
    printStockList(stockList);

    return 0;
}