//FormAI DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *company;   // name of the company
    double price;    // current price of the stock
    char *sector;    // sector the company belongs to
} stock;

int main() {
    int num_companies;
    printf("Enter the number of companies to track: ");
    scanf("%d", &num_companies);

    stock *stocks = malloc(num_companies * sizeof(stock)); // allocate memory for array of stocks

    // loop to get inputs for each stock
    for(int i=0; i<num_companies; i++) {
        stocks[i].company = malloc(50 * sizeof(char));
        stocks[i].sector = malloc(50 * sizeof(char));

        printf("Enter the name of company %d: ", i+1);
        scanf("%s", stocks[i].company);

        printf("Enter the current price of %s's stock: ", stocks[i].company);
        scanf("%lf", &stocks[i].price);

        printf("Enter the sector %s belongs to: ", stocks[i].company);
        scanf("%s", stocks[i].sector);
    }

    // infinite loop to continuously track stocks
    while(1) {
        system("clear");  // clear the console screen

        printf("Company\t\tPrice\tSector\n");
        for(int i=0; i<num_companies; i++) {
            printf("%s\t\t%.2lf\t%s\n", stocks[i].company, stocks[i].price, stocks[i].sector);
            stocks[i].price += (double)rand()/RAND_MAX - 0.5;   // randomize the price up or down
        }

        printf("\nPress any key to continue or 'q' to quit: ");
        char choice[2];
        scanf("%s", choice);

        if(choice[0] == 'q') break; // if user wants to quit, break the loop
    }

    // free dynamically allocated memory
    for(int i=0; i<num_companies; i++) {
        free(stocks[i].company);
        free(stocks[i].sector);
    }
    free(stocks);

    return 0;
}