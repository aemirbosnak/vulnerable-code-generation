//FormAI DATASET v1.0 Category: Stock market tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define struct for keeping track of the stock details
typedef struct 
{
    char symbol[5];
    float price;
    int volume;
    float high;
    float low;
    int time_updated; // in seconds
} Stock;

// Function declarations
void updateStock(Stock** stocks, int num_stocks);
void displayStocks(Stock** stocks, int num_stocks);
Stock* createStock(char symbol[], float price, int volume, float high, float low);

int main()
{
    int num_stocks = 5;
    Stock** stocks = malloc(num_stocks * sizeof(Stock*));

    // Initialize the stocks
    stocks[0] = createStock("AAPL", 150.25, 1000000, 152.50, 147.75);
    stocks[1] = createStock("GOOG", 950.75, 500000, 960.00, 940.50);
    stocks[2] = createStock("AMZN", 1185.25, 750000, 1200.00, 1172.50);
    stocks[3] = createStock("FB", 175.50, 250000, 177.75, 173.25);
    stocks[4] = createStock("NFLX", 200.00, 350000, 205.50, 194.00);

    // Seed random number generator
    srand(time(NULL));

    while (1)
    {
        displayStocks(stocks, num_stocks);
        updateStock(stocks, num_stocks);
        printf("=============================================\n");
    }

    // Free allocated memory
    for (int i = 0; i < num_stocks; i++)
    {
        free(stocks[i]);
    }

    free(stocks);

    return 0;
}

// Function to update the stock details
void updateStock(Stock** stocks, int num_stocks)
{
    int index = rand() % num_stocks;

    float change = ((float)rand() / RAND_MAX) * 20.00 - 10.00; // generate random price change between -10 and 10
    stocks[index]->price += change;

    if (stocks[index]->price > stocks[index]->high)
    {
        stocks[index]->high = stocks[index]->price;
    }

    if (stocks[index]->price < stocks[index]->low)
    {
        stocks[index]->low = stocks[index]->price;
    }

    stocks[index]->volume += rand() % 5000;
    stocks[index]->time_updated = time(NULL);
}

// Function to display the stock details
void displayStocks(Stock** stocks, int num_stocks)
{
    printf("STOCK\tPRICE\tVOLUME\tHIGH\tLOW\tUPDATED\n");

    for (int i = 0; i < num_stocks; i++)
    {
        printf("%s\t%.2f\t%d\t%.2f\t%.2f\t%d\n", stocks[i]->symbol, stocks[i]->price, stocks[i]->volume, stocks[i]->high, stocks[i]->low, stocks[i]->time_updated);
    }
}

// Function to create a new stock
Stock* createStock(char symbol[], float price, int volume, float high, float low)
{
    Stock* stock = malloc(sizeof(Stock));

    strcpy(stock->symbol, symbol);
    stock->price = price;
    stock->volume = volume;
    stock->high = high;
    stock->low = low;
    stock->time_updated = time(NULL);

    return stock;
}