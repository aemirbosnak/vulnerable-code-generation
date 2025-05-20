//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

#define STOCK_COUNT 5

typedef struct Stock {
    char *name;
    float price;
    float volatility;
} Stock;

Stock *create_stock(char *name, float price, float volatility) {
    Stock *stock = malloc(sizeof(Stock));
    stock->name = name;
    stock->price = price;
    stock->volatility = volatility;
    return stock;
}

void update_stock_price(Stock *stock) {
    float rand_num = (float)rand()/(float)RAND_MAX; 
    stock->price += stock->price * (rand_num - 0.5) * (2*stock->volatility);
}

void create_portfolio(Stock **portfolio) {
    portfolio[0] = create_stock("AAPL", 139.07, 0.1);
    portfolio[1] = create_stock("GOOG", 2106.50, 0.05);
    portfolio[2] = create_stock("MSFT", 243.79, 0.08);
    portfolio[3] = create_stock("AMZN", 3245.00, 0.12);
    portfolio[4] = create_stock("TSLA", 659.58, 0.2);
}

void print_portfolio(Stock **portfolio) {
    printf("Your portfolio:\n");
    for(int i = 0; i < STOCK_COUNT; i++) {
        printf("%s - $%.2f\n", portfolio[i]->name, portfolio[i]->price);
    }
}

int main() {
    srand(time(NULL));
    Stock *portfolio[STOCK_COUNT];
    create_portfolio(portfolio);
    print_portfolio(portfolio);
    
    for(int i = 1; i <= 10; i++) {
        printf("Day %d:\n", i);
        for(int j = 0; j < STOCK_COUNT; j++) {
            update_stock_price(portfolio[j]);
            printf("%s - $%.2f\n", portfolio[j]->name, portfolio[j]->price);
        }
        printf("\n");
    }
    
    return 0;
}