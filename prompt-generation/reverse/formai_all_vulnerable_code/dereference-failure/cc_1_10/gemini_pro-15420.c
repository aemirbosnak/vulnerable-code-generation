//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
  char *name;
  float price;
  float change;
};

typedef struct Stock Stock;

int main() {
  // Get the number of stocks to track
  int num_stocks;
  printf("Enter the number of stocks to track: ");
  scanf("%d", &num_stocks);

  // Allocate memory for the stocks
  Stock *stocks = malloc(sizeof(Stock) * num_stocks);

  // Get the stock data
  for (int i = 0; i < num_stocks; i++) {
    // Get the stock name
    char name[256];
    printf("Enter the name of stock %d: ", i + 1);
    scanf("%s", name);

    // Allocate memory for the stock name
    stocks[i].name = malloc(strlen(name) + 1);
    strcpy(stocks[i].name, name);

    // Get the stock price
    float price;
    printf("Enter the price of stock %d: ", i + 1);
    scanf("%f", &price);

    // Set the stock price
    stocks[i].price = price;

    // Get the stock change
    float change;
    printf("Enter the change in stock %d: ", i + 1);
    scanf("%f", &change);

    // Set the stock change
    stocks[i].change = change;
  }

  // Print the stock data
  printf("\nStock data\n\n");
  for (int i = 0; i < num_stocks; i++) {
    printf("Name: %s\n", stocks[i].name);
    printf("Price: %.2f\n", stocks[i].price);
    printf("Change: %.2f\n\n", stocks[i].change);
  }

  // Free the memory allocated for the stocks
  for (int i = 0; i < num_stocks; i++) {
    free(stocks[i].name);
  }
  free(stocks);

  return 0;
}