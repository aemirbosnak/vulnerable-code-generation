//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock {
  char *symbol;
  double price;
  double change;
  double volume;
} stock_t;

// Function to create a new stock
stock_t *stock_new(char *symbol, double price, double change, double volume) {
  stock_t *stock = malloc(sizeof(stock_t));
  stock->symbol = strdup(symbol);
  stock->price = price;
  stock->change = change;
  stock->volume = volume;
  return stock;
}

// Function to free a stock
void stock_free(stock_t *stock) {
  free(stock->symbol);
  free(stock);
}

// Function to print a stock
void stock_print(stock_t *stock) {
  printf("%s: $%.2f (%.2f%%) [%ld]\n", stock->symbol, stock->price, stock->change, stock->volume);
}

// Function to compare two stocks by price
int stock_cmp_price(const void *a, const void *b) {
  stock_t *stock1 = (stock_t *)a;
  stock_t *stock2 = (stock_t *)b;
  return stock1->price - stock2->price;
}

// Function to compare two stocks by change
int stock_cmp_change(const void *a, const void *b) {
  stock_t *stock1 = (stock_t *)a;
  stock_t *stock2 = (stock_t *)b;
  return stock1->change - stock2->change;
}

// Function to compare two stocks by volume
int stock_cmp_volume(const void *a, const void *b) {
  stock_t *stock1 = (stock_t *)a;
  stock_t *stock2 = (stock_t *)b;
  return stock1->volume - stock2->volume;
}

// Function to load stocks from a file
stock_t **stock_load(const char *filename, int *nstocks) {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  // Count the number of stocks in the file
  *nstocks = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    (*nstocks)++;
  }
  rewind(fp);

  // Allocate memory for the stocks
  stock_t **stocks = malloc(*nstocks * sizeof(stock_t *));

  // Load the stocks from the file
  int i = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    char *symbol, *price, *change, *volume;
    symbol = strtok(line, ",");
    price = strtok(NULL, ",");
    change = strtok(NULL, ",");
    volume = strtok(NULL, ",");
    stocks[i] = stock_new(symbol, atof(price), atof(change), atof(volume));
    i++;
  }

  // Free the line buffer
  free(line);

  // Close the file
  fclose(fp);

  return stocks;
}

// Function to save stocks to a file
void stock_save(const char *filename, stock_t **stocks, int nstocks) {
  FILE *fp;

  fp = fopen(filename, "w");
  if (fp == NULL) {
    return;
  }

  // Save the stocks to the file
  for (int i = 0; i < nstocks; i++) {
    fprintf(fp, "%s,%.2f,%.2f,%.2f\n", stocks[i]->symbol, stocks[i]->price, stocks[i]->change, stocks[i]->volume);
  }

  // Close the file
  fclose(fp);
}

// Function to print the menu
void menu() {
  printf("\n");
  printf("1. Load stocks from a file\n");
  printf("2. Save stocks to a file\n");
  printf("3. Print stocks\n");
  printf("4. Sort stocks by price\n");
  printf("5. Sort stocks by change\n");
  printf("6. Sort stocks by volume\n");
  printf("7. Quit\n");
  printf("\nEnter your choice: ");
}

// Function to get the user's choice
int get_choice() {
  int choice;
  scanf("%d", &choice);
  return choice;
}

// Function to execute the user's choice
void execute_choice(int choice, stock_t **stocks, int nstocks) {
  switch (choice) {
  case 1:
    stocks = stock_load("stocks.txt", &nstocks);
    break;
  case 2:
    stock_save("stocks.txt", stocks, nstocks);
    break;
  case 3:
    for (int i = 0; i < nstocks; i++) {
      stock_print(stocks[i]);
    }
    break;
  case 4:
    qsort(stocks, nstocks, sizeof(stock_t *), stock_cmp_price);
    break;
  case 5:
    qsort(stocks, nstocks, sizeof(stock_t *), stock_cmp_change);
    break;
  case 6:
    qsort(stocks, nstocks, sizeof(stock_t *), stock_cmp_volume);
    break;
  case 7:
    exit(0);
  default:
    printf("Invalid choice!\n");
    break;
  }
}

// Main function
int main() {
  stock_t **stocks = NULL;
  int nstocks = 0;

  while (1) {
    menu();
    int choice = get_choice();
    execute_choice(choice, stocks, nstocks);
  }

  return 0;
}