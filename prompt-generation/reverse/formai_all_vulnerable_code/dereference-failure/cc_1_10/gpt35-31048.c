//FormAI DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct stock_data {
    char stock_name[20];
    float curr_price;
    float prev_price;
    float change_percent;
};

void get_data(struct stock_data* stock, int count) {
    if (count > 0) {
        printf("\nEnter the name of the stock: ");
        scanf("%s", stock->stock_name);
        printf("Enter the current price of the stock: ");
        scanf("%f", &stock->curr_price);
        printf("Enter the previous price of the stock: ");
        scanf("%f", &stock->prev_price);
        stock->change_percent = ((stock->curr_price - stock->prev_price) / stock->prev_price) * 100;

        get_data(stock + 1, count - 1);
    }
}

void display_data(struct stock_data* stock, int count) {
    if (count > 0) {
        printf("\nStock Name: %s\n", stock->stock_name);
        printf("Current Price: %.2f\n", stock->curr_price);
        printf("Previous Price: %.2f\n", stock->prev_price);
        printf("Change Percentage: %.2f %%\n", stock->change_percent);

        display_data(stock + 1, count - 1);
    }
}

int main() {
    int num_of_stocks;
    printf("Enter the total number of stocks you want to track: ");
    scanf("%d", &num_of_stocks);

    struct stock_data* stocks = (struct stock_data*)malloc(num_of_stocks * sizeof(struct stock_data));

    get_data(stocks, num_of_stocks);

    printf("\n-- STOCK REPORT --\n");

    display_data(stocks, num_of_stocks);

    free(stocks);

    return 0;
}