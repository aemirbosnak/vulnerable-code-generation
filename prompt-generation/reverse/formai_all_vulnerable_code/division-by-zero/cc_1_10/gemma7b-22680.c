//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{

    // Declare variables
    char stock_name[MAX];
    int stock_price, i, j, k, trend_direction, previous_price, average_price, current_price, change_in_price, percentage_change;

    // Initialize data
    previous_price = 0;
    average_price = 0;
    current_price = 0;
    change_in_price = 0;
    percentage_change = 0;

    // Get the stock name
    printf("Enter the name of the stock: ");
    scanf("%s", stock_name);

    // Get the stock price
    printf("Enter the current price of the stock: ");
    scanf("%d", &stock_price);

    // Calculate the previous price
    previous_price = stock_price - 1;

    // Calculate the average price
    average_price = (previous_price + stock_price) / 2;

    // Calculate the current price
    current_price = stock_price;

    // Calculate the change in price
    change_in_price = current_price - previous_price;

    // Calculate the percentage change
    percentage_change = (change_in_price / previous_price) * 100;

    // Display the results
    printf("\nStock Name: %s", stock_name);
    printf("\nCurrent Price: %d", current_price);
    printf("\nPrevious Price: %d", previous_price);
    printf("\nAverage Price: %d", average_price);
    printf("\nChange in Price: %d", change_in_price);
    printf("\nPercentage Change: %.2f%%", percentage_change);

    return 0;
}