//FormAI DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stockPrice {
    char * symbol;
    double price;
} StockPrice;

StockPrice* createStock(char * name, double price) {
    StockPrice* stock = (StockPrice*)malloc(sizeof(StockPrice));
    stock->symbol = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(stock->symbol, name);
    stock->price = price;
    return stock;
}

void displayStockPrice(StockPrice* stock) {
    printf("Symbol: %s Price: %.2lf\n", stock->symbol, stock->price);
}

void updateStockPrice(StockPrice* stock, double price) {
    stock->price = price;
}

int main() {
    char input[20];
    StockPrice* apple = createStock("AAPL", 134.14);
    StockPrice* google = createStock("GOOGL", 2439.67);
    StockPrice* microsoft = createStock("MSFT", 244.99);
    printf("\nWelcome to the Stock Market Tracker\n\n");
    while (1) {
        printf("Which stock would you like to check? (AAPL, GOOGL, MSFT, or QUIT)");
        scanf("%s", input);
        for (int i = 0; i < strlen(input); i++) {
            input[i] = toupper(input[i]);
        }
        if (strcmp(input, "AAPL") == 0) {
            displayStockPrice(apple);
        }
        else if (strcmp(input, "GOOGL") == 0) {
            displayStockPrice(google);
        }
        else if (strcmp(input, "MSFT") == 0) {
            displayStockPrice(microsoft);
        }
        else if (strcmp(input, "QUIT") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid input, please try again!\n");
        }
    }

    free(apple->symbol);
    free(apple);
    free(google->symbol);
    free(google);
    free(microsoft->symbol);
    free(microsoft);
    return 0;
}