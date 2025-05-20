//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Stock
{
    char name[20];
    double price;
    int quantity;
} Stock;

void display_stocks(Stock **stocks, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s: %.2lf, Quantity: %d\n", stocks[i]->name, stocks[i]->price, stocks[i]->quantity);
    }
}

int main()
{
    Stock **stocks = NULL;
    int size = 0;

    // Dynamically allocate memory for the stocks array
    stocks = (Stock **)malloc(MAX * sizeof(Stock));

    // Add some sample stocks
    stocks[size++] = malloc(sizeof(Stock));
    strcpy(stocks[size - 1]->name, "Apple");
    stocks[size - 1]->price = 100.00;
    stocks[size - 1]->quantity = 100;

    stocks[size++] = malloc(sizeof(Stock));
    strcpy(stocks[size - 1]->name, "Microsoft");
    stocks[size - 1]->price = 200.00;
    stocks[size - 1]->quantity = 50;

    stocks[size++] = malloc(sizeof(Stock));
    strcpy(stocks[size - 1]->name, "Google");
    stocks[size - 1]->price = 150.00;
    stocks[size - 1]->quantity = 200;

    // Display the stocks
    display_stocks(stocks, size);

    // Free the memory allocated for the stocks array
    for (int i = 0; i < size; i++)
    {
        free(stocks[i]);
    }

    free(stocks);

    return 0;
}