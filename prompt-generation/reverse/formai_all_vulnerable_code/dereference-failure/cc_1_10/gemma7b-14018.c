//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Stock
{
    char name[20];
    int price;
    int quantity;
} Stock;

void updateStock(Stock *stock, int price, int quantity)
{
    stock->price = price;
    stock->quantity = quantity;
}

void displayStock(Stock *stock)
{
    printf("Name: %s\n", stock->name);
    printf("Price: %d\n", stock->price);
    printf("Quantity: %d\n", stock->quantity);
}

int main()
{
    Stock *stocks = (Stock *)malloc(MAX * sizeof(Stock));

    // Initialize stocks
    for (int i = 0; i < MAX; i++)
    {
        stocks[i].name[0] = '\0';
        stocks[i].price = 0;
        stocks[i].quantity = 0;
    }

    // Update stock information
    updateStock(&stocks[0], 100, 10);
    updateStock(&stocks[1], 200, 20);

    // Display stock information
    displayStock(&stocks[0]);
    displayStock(&stocks[1]);

    free(stocks);

    return 0;
}