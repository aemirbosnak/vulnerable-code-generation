//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10

struct stock {
    char symbol[6];
    float price;
};

struct stock stocks[MAX_STOCKS];
int num_stocks = 0;

int main(void) {
    // Read stocks from the command line
    char buffer[MAX_STOCKS*6];
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        perror("Could not open file");
        return 1;
    }
    while (fgets(buffer, MAX_STOCKS*6, fp)!= NULL) {
        if (num_stocks == MAX_STOCKS) {
            fprintf(stderr, "Error: Too many stocks\n");
            return 1;
        }
        int len = strlen(buffer);
        if (len!= 6) {
            fprintf(stderr, "Error: Invalid stock symbol\n");
            return 1;
        }
        for (int i = 0; i < len; i++) {
            if (buffer[i] < 'A' || buffer[i] > 'Z') {
                fprintf(stderr, "Error: Invalid stock symbol\n");
                return 1;
            }
        }
        stocks[num_stocks].symbol[0] = buffer[0];
        stocks[num_stocks].symbol[1] = buffer[1];
        stocks[num_stocks].symbol[2] = buffer[2];
        stocks[num_stocks].symbol[3] = buffer[3];
        stocks[num_stocks].symbol[4] = buffer[4];
        stocks[num_stocks].symbol[5] = '\0';
        stocks[num_stocks].price = atof(buffer+6);
        num_stocks++;
    }
    fclose(fp);
    
    // Calculate the total value of the portfolio
    float total_value = 0;
    for (int i = 0; i < num_stocks; i++) {
        total_value += stocks[i].price;
    }
    
    // Display the portfolio
    printf("Portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: %f\n", stocks[i].symbol, stocks[i].price);
    }
    
    // Calculate the gain/loss
    float gain_loss = (total_value - 1000000) / 1000000;
    printf("Gain/Loss: %.2f%%\n", gain_loss);
    
    return 0;
}