//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STOCK_COUNT 5
#define MAX_STOCK_NAME_LEN 20
#define MAX_STOCK_PRICE_LEN 10
#define MAX_DATE_LEN 10

typedef struct {
    char name[MAX_STOCK_NAME_LEN + 1];
    double price;
    char date[MAX_DATE_LEN + 1];
} Stock;

void print_stock(Stock stock) {
    printf("%s: $%.2f (%s)\n", stock.name, stock.price, stock.date);
}

void print_stocks(Stock stocks[], int count) {
    for (int i = 0; i < count; i++) {
        print_stock(stocks[i]);
    }
}

int main() {
    // Create an array of stocks
    Stock stocks[STOCK_COUNT];

    // Initialize the stocks
    strcpy(stocks[0].name, "Apple");
    stocks[0].price = 120.00;
    strcpy(stocks[0].date, "2023-03-08");

    strcpy(stocks[1].name, "Microsoft");
    stocks[1].price = 250.00;
    strcpy(stocks[1].date, "2023-03-08");

    strcpy(stocks[2].name, "Google");
    stocks[2].price = 140.00;
    strcpy(stocks[2].date, "2023-03-08");

    strcpy(stocks[3].name, "Amazon");
    stocks[3].price = 110.00;
    strcpy(stocks[3].date, "2023-03-08");

    strcpy(stocks[4].name, "Tesla");
    stocks[4].price = 100.00;
    strcpy(stocks[4].date, "2023-03-08");

    // Print the stocks
    printf("Current stock prices:\n");
    print_stocks(stocks, STOCK_COUNT);

    // Get the current time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Get the user input
    char input[20];
    printf("\nWhat would you like to do? (buy, sell, or quit): ");
    scanf("%s", input);

    // Process the user input
    if (strcmp(input, "buy") == 0) {
        // Get the stock name
        char stock_name[MAX_STOCK_NAME_LEN + 1];
        printf("Enter the stock name: ");
        scanf("%s", stock_name);

        // Get the number of shares
        int shares;
        printf("Enter the number of shares: ");
        scanf("%d", &shares);

        // Find the stock in the array
        int index = -1;
        for (int i = 0; i < STOCK_COUNT; i++) {
            if (strcmp(stocks[i].name, stock_name) == 0) {
                index = i;
                break;
            }
        }

        // Check if the stock was found
        if (index == -1) {
            printf("Stock not found.\n");
        } else {
            // Calculate the total cost of the purchase
            double total_cost = stocks[index].price * shares;

            // Print the confirmation message
            printf("You have purchased %d shares of %s for a total cost of $%.2f.\n", shares, stock_name, total_cost);
        }
    } else if (strcmp(input, "sell") == 0) {
        // Get the stock name
        char stock_name[MAX_STOCK_NAME_LEN + 1];
        printf("Enter the stock name: ");
        scanf("%s", stock_name);

        // Get the number of shares
        int shares;
        printf("Enter the number of shares: ");
        scanf("%d", &shares);

        // Find the stock in the array
        int index = -1;
        for (int i = 0; i < STOCK_COUNT; i++) {
            if (strcmp(stocks[i].name, stock_name) == 0) {
                index = i;
                break;
            }
        }

        // Check if the stock was found
        if (index == -1) {
            printf("Stock not found.\n");
        } else {
            // Calculate the total value of the sale
            double total_value = stocks[index].price * shares;

            // Print the confirmation message
            printf("You have sold %d shares of %s for a total value of $%.2f.\n", shares, stock_name, total_value);
        }
    } else if (strcmp(input, "quit") == 0) {
        // Exit the program
        printf("Goodbye.\n");
        return 0;
    } else {
        // Invalid input
        printf("Invalid input.\n");
    }

    return 0;
}