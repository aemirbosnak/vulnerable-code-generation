//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCK_NUM 10

typedef struct Stock
{
    char name[20];
    double price;
    double change;
    double prev_price;
} Stock;

void update_stock(Stock *stock)
{
    stock->prev_price = stock->price;
    stock->change = (rand() % 5 - 2) / 10.0;
    stock->price = stock->prev_price + stock->change;
}

void display_stocks(Stock *stocks)
{
    printf("----------------------------------------\n");
    printf("  Stock Market Simulator\n");
    printf("----------------------------------------\n");
    printf("Stock | Price | Change | Previous Price |\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        printf("%s | %.2lf | %.2lf | %.2lf |\n", stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].prev_price);
    }
    printf("----------------------------------------\n");
}

int main()
{
    srand(time(NULL));

    Stock stocks[MAX_STOCK_NUM];
    for (int i = 0; i < MAX_STOCK_NUM; i++)
    {
        strcpy(stocks[i].name, "Stock #" + i);
        stocks[i].price = (rand() % 100) + 100.0;
        stocks[i].prev_price = stocks[i].price;
    }

    while (1)
    {
        update_stock(stocks);
        display_stocks(stocks);

        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}