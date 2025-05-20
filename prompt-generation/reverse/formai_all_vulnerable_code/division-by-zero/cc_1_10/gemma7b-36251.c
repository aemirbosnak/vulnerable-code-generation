//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int main()
{
    int i, j, k, n, m, index, price, average_price, total_price = 0, total_shares = 0;
    char symbol[20];

    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &n);

    // Create an array of structures to store stock information
    struct stock
    {
        char symbol[20];
        int shares;
        int price;
        int average_price;
    } stocks[n];

    // Get the stock information for each stock
    for (i = 0; i < n; i++)
    {
        printf("Enter the symbol of the stock: ");
        scanf("%s", stocks[i].symbol);

        printf("Enter the number of shares you own: ");
        scanf("%d", &stocks[i].shares);

        printf("Enter the current price of the stock: ");
        scanf("%d", &stocks[i].price);

        stocks[i].average_price = (stocks[i].shares * stocks[i].price) / total_shares;
    }

    // Calculate the total price and total shares
    for (i = 0; i < n; i++)
    {
        total_price += stocks[i].shares * stocks[i].price;
        total_shares += stocks[i].shares;
    }

    // Print the total price and total shares
    printf("Total price: $%d", total_price);

    printf("Total shares: %d", total_shares);

    // Calculate the average price per share
    average_price = (total_price) / total_shares;

    // Print the average price per share
    printf("Average price per share: $%d", average_price);

    return 0;
}