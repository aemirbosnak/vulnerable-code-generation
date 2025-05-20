//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
    char symbol[10];
    float current_price;
    int volume;
};

int main() {
    int num_stocks;
    printf("Enter the number of stocks: ");
    scanf("%d", &num_stocks);

    // Allocate memory for the array of Stock structures
    struct Stock* stocks = (struct Stock*) malloc(num_stocks * sizeof(struct Stock));

    // Get input for each stock
    for(int i = 0; i < num_stocks; i++) {
        printf("\nStock %d:\n", i+1);

        // Input for stock symbol
        printf("Enter the symbol: ");
        scanf("%s", &stocks[i].symbol);

        // Input for current price
        printf("Enter the current price: ");
        scanf("%f", &stocks[i].current_price);

        // Input for volume
        printf("Enter the volume: ");
        scanf("%d", &stocks[i].volume);
    }

    // Display table with stock data
    printf("\nSymbol\tCurrent Price\tVolume\n");
    for(int i = 0; i < num_stocks; i++) {
        printf("%s\t%.2f\t\t%d\n", stocks[i].symbol, stocks[i].current_price, stocks[i].volume);
    }

    // Find the highest volume stock
    int max_volume_index = 0;
    for(int i = 0; i < num_stocks; i++) {
        if(stocks[i].volume > stocks[max_volume_index].volume) {
            max_volume_index = i;
        }
    }

    // Display highest volume stock
    printf("\nThe stock with the highest volume is %s, with a volume of %d\n", stocks[max_volume_index].symbol, stocks[max_volume_index].volume);

    // Calculate the total value of all stocks
    float total_value = 0;
    for(int i = 0; i < num_stocks; i++) {
        total_value += stocks[i].current_price * stocks[i].volume;
    }

    // Display total value of all stocks
    printf("\nThe total value of all stocks is %.2f\n", total_value);

    // Free memory allocated for stocks array
    free(stocks);

    return 0;
}