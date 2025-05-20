//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    float price;
    int volume;
} Stock;

Stock *create_stock(char *name, float price, int volume) {
    Stock *stock = (Stock *) malloc(sizeof(Stock));
    stock->name = strdup(name);
    stock->price = price;
    stock->volume = volume;
    return stock;
}

void print_stock(Stock *stock) {
    printf("Name: %s\n", stock->name);
    printf("Price: $%.2f\n", stock->price);
    printf("Volume: %d\n\n", stock->volume);
}

int main() {
    Stock *stocks[10];
    int num_stocks = 0;

    char input[100];
    printf("Enter the name of the stock (or type 'exit' to quit): ");
    scanf("%s", input);

    while (strcmp(input, "exit")!= 0) {
        if (num_stocks >= 10) {
            printf("Error: Maximum number of stocks reached.\n");
            break;
        }

        printf("Enter the price of the stock: ");
        scanf("%f", &stocks[num_stocks]->price);

        printf("Enter the volume of the stock: ");
        scanf("%d", &stocks[num_stocks]->volume);

        stocks[num_stocks] = create_stock(input, stocks[num_stocks]->price, stocks[num_stocks]->volume);
        num_stocks++;

        printf("\nStock added successfully!\n\n");

        printf("Enter the name of the stock (or type 'exit' to quit): ");
        scanf("%s", input);
    }

    printf("\nStock Market Tracker\n");
    printf("====================\n");

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}