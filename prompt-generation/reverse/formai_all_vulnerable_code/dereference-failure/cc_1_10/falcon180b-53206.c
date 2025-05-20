//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    double price;
    int quantity;
} Stock;

Stock *create_stock(char *name, double price, int quantity) {
    Stock *stock = malloc(sizeof(Stock));
    stock->name = strdup(name);
    stock->price = price;
    stock->quantity = quantity;
    return stock;
}

void print_stock(Stock *stock) {
    printf("Name: %s\n", stock->name);
    printf("Price: $%.2f\n", stock->price);
    printf("Quantity: %d\n", stock->quantity);
}

int main() {
    char input[100];
    Stock *stocks[10];
    int num_stocks = 0;

    while (num_stocks < 10) {
        printf("Enter name of stock (or 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        printf("Enter price of %s: ", input);
        double price;
        if (scanf("%lf", &price)!= 1) {
            printf("Invalid input\n");
            continue;
        }

        printf("Enter quantity of %s: ", input);
        int quantity;
        if (scanf("%d", &quantity)!= 1) {
            printf("Invalid input\n");
            continue;
        }

        stocks[num_stocks] = create_stock(input, price, quantity);
        num_stocks++;
    }

    printf("\nStock Market Tracker\n");
    printf("=====================\n");

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}