//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 32
#define MAX_DATA_LEN 1024

typedef struct {
  char name[MAX_NAME_LEN];
  float price;
  float change;
  char data[MAX_DATA_LEN];
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void load_stocks(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  char line[MAX_DATA_LEN];
  while (fgets(line, MAX_DATA_LEN, fp) != NULL) {
    if (num_stocks >= MAX_STOCKS) {
      fprintf(stderr, "Error: Too many stocks\n");
      exit(EXIT_FAILURE);
    }

    char *name = strtok(line, ",");
    if (name == NULL) {
      fprintf(stderr, "Error: Invalid stock data\n");
      exit(EXIT_FAILURE);
    }

    char *price = strtok(NULL, ",");
    if (price == NULL) {
      fprintf(stderr, "Error: Invalid stock data\n");
      exit(EXIT_FAILURE);
    }

    char *change = strtok(NULL, ",");
    if (change == NULL) {
      fprintf(stderr, "Error: Invalid stock data\n");
      exit(EXIT_FAILURE);
    }

    char *data = strtok(NULL, "\n");
    if (data == NULL) {
      fprintf(stderr, "Error: Invalid stock data\n");
    exit(EXIT_FAILURE);
    }

    strcpy(stocks[num_stocks].name, name);
    stocks[num_stocks].price = atof(price);
    stocks[num_stocks].change = atof(change);
    strcpy(stocks[num_stocks].data, data);
    num_stocks++;
  }

  fclose(fp);
}

void print_stocks() {
  printf("-------------------------------------------------------------------------------------------------------------------\n");
  printf("| Name              | Price           | Change          | Data                                                            |\n");
  printf("-------------------------------------------------------------------------------------------------------------------\n");
  for (int i = 0; i < num_stocks; i++) {
    printf("| %-16s | %-13.2f | %-13.2f | %s |\n", stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].data);
  }
  printf("-------------------------------------------------------------------------------------------------------------------\n");
}

int main() {
  load_stocks("stocks.csv");
  print_stocks();

  return 0;
}