//FormAI DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 50 //Maximum number of stocks
#define MAX_NAME_LENGTH 20 //Maximum length of a stock name

struct Stock {
    char name[MAX_NAME_LENGTH];
    double price;
};

int main() {
    struct Stock stocks[MAX_STOCKS]; //Array of stocks
    int numStocks = 0; //Number of stocks in the array
    char input[100];
    char *token;

    //Ask the user to enter the stock information
    do {
        printf("Enter the stock name and price (e.g. AAPL 123.45), or enter 'stop' to finish:\n");
        fgets(input, 100, stdin);

        if (strcmp(input, "stop\n") != 0) { //If the user didn't input 'stop'
            token = strtok(input, " "); //Get the stock name
            strcpy(stocks[numStocks].name, token);

            token = strtok(NULL, " "); //Get the stock price
            stocks[numStocks].price = atof(token);

            numStocks++; //Increment the number of stocks
        }
    } while(strcmp(input, "stop\n") != 0 && numStocks < MAX_STOCKS); //Stop when the user enters 'stop' or we have too many stocks

    printf("\nStocks:\n");

    //Print the list of stocks
    for(int i = 0; i < numStocks; i++) {
        printf("%s: %.2lf\n", stocks[i].name, stocks[i].price);
    }

    //Find the highest-priced stock
    double highestPrice = 0;
    char *highestName;
    for(int i = 0; i < numStocks; i++) {
        if(stocks[i].price > highestPrice) {
            highestPrice = stocks[i].price;
            highestName = stocks[i].name;
        }
    }
    printf("\n%s has the highest price of %.2lf\n", highestName, highestPrice);

    //Find the lowest-priced stock
    double lowestPrice = stocks[0].price;
    char *lowestName;
    for(int i = 1; i < numStocks; i++) {
        if(stocks[i].price < lowestPrice) {
            lowestPrice = stocks[i].price;
            lowestName = stocks[i].name;
        }
    }
    printf("\n%s has the loweset price of %.2lf\n", lowestName, lowestPrice);

    return 0;
}