//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
} Stock;

void updatePrice(Stock* stock, float newPrice) {
    stock->price = newPrice;
}

void printStock(Stock stock) {
    printf("| %-49s | %10.2f |\n", stock.name, stock.price);
}

void createStock(Stock* stocks, const char* name, float price) {
    strcpy(stocks->name, name);
    updatePrice(stocks, price);
}

void addStock(Stock* stocks, int index, Stock newStock) {
    for (int i = 0; i < index; i++) {
        stocks++;
    }
    *stocks = newStock;
}

void printStocks(Stock* stocks, int numStocks) {
    printf("+---------------------------------------+------------------+\n");
    printf("| Stock Name                            | Current Price    |\n");
    printf("+---------------------------------------+------------------+\n");

    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }

    printf("+---------------------------------------+------------------+\n");
}

int main() {
    int numStocks = 5;
    Stock* stocks = (Stock*) malloc(numStocks * sizeof(Stock));

    createStock(stocks, "Gold", 1450.50);
    createStock(stocks + 1, "Silver", 21.50);
    createStock(stocks + 2, "Copper", 3.50);
    createStock(stocks + 3, "Iron", 10.50);
    createStock(stocks + 4, "Lead", 7.25);

    updatePrice(stocks + 1, 22.50);

    addStock(stocks, 6, (Stock){"Grain", 12.50});

    printStocks(stocks, numStocks + 1);

    free(stocks);

    return 0;
}