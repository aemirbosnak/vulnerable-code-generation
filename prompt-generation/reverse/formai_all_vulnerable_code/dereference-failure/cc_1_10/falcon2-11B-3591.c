//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char company[50];
    float price;
    float volume;
} stock;

stock stocks[100];

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number of stocks>\n", argv[0]);
        return 1;
    }

    int num_stocks = atoi(argv[1]);

    if (num_stocks < 1 || num_stocks > 100) {
        printf("Invalid number of stocks.\n");
        return 1;
    }

    for (int i = 0; i < num_stocks; i++) {
        stocks[i].company[0] = '\0';
        stocks[i].price = 0.0;
        stocks[i].volume = 0.0;
    }

    srand(time(NULL));

    for (int i = 0; i < num_stocks; i++) {
        sprintf(stocks[i].company, "Stock %d", i+1);
        stocks[i].price = (float)rand() / (float)RAND_MAX;
        stocks[i].volume = (float)rand() / (float)RAND_MAX;
    }

    printf("Stock Market Tracker\n");
    printf("------------------------------------\n");
    printf("Company    Price    Volume\n");
    printf("------------------------------------\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("%s %.2f %.2f\n", stocks[i].company, stocks[i].price, stocks[i].volume);
    }

    return 0;
}