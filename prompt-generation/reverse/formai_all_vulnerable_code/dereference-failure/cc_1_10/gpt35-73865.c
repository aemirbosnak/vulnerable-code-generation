//FormAI DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define MAX_STOCKS 10

typedef struct {
    char name[MAX_LENGTH];
    double price;
    int quantity;
} Stock;

/*
 * Function to create a new stock
 */
Stock *create_stock(char name[], double price, int quantity) {
    Stock *new_stock = malloc(sizeof(Stock));
    strcpy(new_stock->name, name);
    new_stock->price = price;
    new_stock->quantity = quantity;
    return new_stock;
}

/*
 * Function to print the information of a stock
 */
void display_stock(Stock *stock) {
    printf("Stock Name: %s\n", stock->name);
    printf("Price: $%.2lf\n", stock->price);
    printf("Quantity: %d\n", stock->quantity);
}

/*
 * Function to update the price of a stock
 */
void update_price(Stock *stock, double new_price) {
    stock->price = new_price;
}

/*
 * Function to update the quantity of a stock
 */
void update_quantity(Stock *stock, int new_quantity) {
    stock->quantity = new_quantity;
}

int main() {
    // create some sample stocks
    Stock *stock1 = create_stock("Apple", 142.7, 500);
    Stock *stock2 = create_stock("Microsoft", 245.4, 300);
    Stock *stock3 = create_stock("Amazon", 3186.6, 100);
    Stock *stock4 = create_stock("Tesla", 670.0, 200);
    Stock *stock5 = create_stock("Facebook", 313.09, 400);

    // put the stocks in an array
    Stock *stocks[MAX_STOCKS];
    stocks[0] = stock1;
    stocks[1] = stock2;
    stocks[2] = stock3;
    stocks[3] = stock4;
    stocks[4] = stock5;

    // print the information of all the stocks
    for (int i = 0; i < MAX_STOCKS; i++) {
        display_stock(stocks[i]);
        printf("\n");
    }

    // update the price of a stock
    update_price(stock2, 248.5);

    // update the quantity of a stock
    update_quantity(stock4, 250);

    // print the updated information of all the stocks
    for (int i = 0; i < MAX_STOCKS; i++) {
        display_stock(stocks[i]);
        printf("\n");
    }

    // free the memory allocated for the stocks
    free(stock1);
    free(stock2);
    free(stock3);
    free(stock4);
    free(stock5);

    return 0;
}