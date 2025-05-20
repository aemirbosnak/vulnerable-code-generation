//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char stock_name[MAX];
    int stock_price;
    float stock_change;
    FILE *fp;

    // Open file for reading and writing
    fp = fopen("stocks.txt", "r");

    // Check if file is open
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Get the stock name
    printf("Enter the name of the stock: ");
    scanf("%s", stock_name);

    // Get the stock price
    printf("Enter the current price of the stock: ");
    scanf("%d", &stock_price);

    // Calculate the stock change
    stock_change = (stock_price - get_stock_price(stock_name, fp)) / get_stock_price(stock_name, fp);

    // Display the stock change
    printf("The stock change is: %.2f%%", stock_change * 100);

    // Close the file
    fclose(fp);

    return 0;
}

int get_stock_price(char *stock_name, FILE *fp)
{
    char line[MAX];
    int price;

    // Iterate over the file line by line
    while (fgets(line, MAX, fp) != NULL)
    {
        // Check if the line contains the stock name
        if (strstr(line, stock_name) != NULL)
        {
            // Extract the price from the line
            price = atoi(strtok(line, ","));

            // Return the price
            return price;
        }
    }

    // Return -1 if the stock name is not found
    return -1;
}