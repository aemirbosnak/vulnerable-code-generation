//FormAI DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock {
    char symbol[10];
    float price;
};

typedef struct stock Stock;

void printStocks(Stock **portfolio, int size) {
    printf("Stock Portfolio:\n");
    for(int i=0; i<size; i++) {
        printf("Symbol: %s\tPrice: $%0.2f\n", portfolio[i]->symbol, portfolio[i]->price);
    }
    printf("\n");
}

void updatePrices(Stock **portfolio, int size) {
    for(int i=0; i<size; i++) {
        float randNum = ((float) rand()) / RAND_MAX;
        float newPrice = portfolio[i]->price * (randNum + 0.5);
        portfolio[i]->price = newPrice;
    }
    printf("Stock prices updated.\n\n");
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. View Portfolio\n");
    printf("2. Update Prices\n");
    printf("3. Exit\n");
}

int main() {

    srand(time(NULL));

    Stock **portfolio;
    int portfolioSize = 5;
    portfolio = (Stock **) malloc(sizeof(Stock *) * portfolioSize);

    // Initialize portfolio
    for(int i=0; i<portfolioSize; i++) {
        portfolio[i] = (Stock *) malloc(sizeof(Stock));
        strcpy(portfolio[i]->symbol, "SYMBOL");
        portfolio[i]->price = 10.0;
    }

    int choice = 0;
    do {
        displayMenu();
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printStocks(portfolio, portfolioSize);
                break;
            case 2:
                updatePrices(portfolio, portfolioSize);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(choice != 3);

    // Free portfolio memory
    for(int i=0; i<portfolioSize; i++) {
        free(portfolio[i]);
    }
    free(portfolio);

    return 0;
}