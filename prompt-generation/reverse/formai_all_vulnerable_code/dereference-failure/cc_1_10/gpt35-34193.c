//FormAI DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock {
    char name[20];
    float price;
};

int main() {

    struct stock *stocks = malloc(sizeof(struct stock) * 5); // Allocate memory for 5 "Stocks" 

    // Populate the stocks array
    strcpy(stocks[0].name, "Apple");
    stocks[0].price = 150.33;
    strcpy(stocks[1].name, "Amazon");
    stocks[1].price = 3278.00;
    strcpy(stocks[2].name, "Microsoft");
    stocks[2].price = 300.24;
    strcpy(stocks[3].name, "Tesla");
    stocks[3].price = 730.32;
    strcpy(stocks[4].name, "Netflix");
    stocks[4].price = 550.50;

    // Print out the initial values of the stocks array:
    printf("Starting Prices:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }

    // Continuously update stock prices until user quits:
    while (1) {
        char input[20];
        printf("\nEnter the name of a stock to update (or QUIT to exit program): ");
        scanf("%s", input);
        if (strcmp(input, "QUIT") == 0) {
            break;
        }
        float newPrice;
        printf("Enter the new price: ");
        scanf("%f", &newPrice);

        // Update the relevant stock:
        for (int i = 0; i < 5; i++) {
            if (strcmp(stocks[i].name, input) == 0) {
                stocks[i].price = newPrice;
                printf("%s updated to $%.2f\n", stocks[i].name, stocks[i].price);
                break;
            }
        }
    }

    // Print out the final values of the stocks array:
    printf("\nFinal Prices:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }

    // Free the memory used by the stocks array:
    free(stocks);

    return 0;
}