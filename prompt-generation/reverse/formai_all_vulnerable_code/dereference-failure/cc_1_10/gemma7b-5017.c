//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_STOCK_NUM 10

typedef struct Stock {
  char name[20];
  double price;
  double last_price;
  double change;
  int volatality;
} Stock;

Stock stocks[MAX_STOCK_NUM];

void update_stock_prices() {
  FILE *fp;
  char line[256];
  int i = 0;

  fp = fopen("stock_prices.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  while (fgets(line, 256, fp) != NULL) {
    char *stock_name = strtok(line, ",");
    double stock_price = atof(strtok(NULL, ","));

    for (i = 0; i < MAX_STOCK_NUM; i++) {
      if (strcmp(stocks[i].name, stock_name) == 0) {
        stocks[i].price = stock_price;
      }
    }
  }

  fclose(fp);
}

void calculate_stock_changes() {
  int i = 0;

  for (i = 0; i < MAX_STOCK_NUM; i++) {
    stocks[i].change = (stocks[i].price - stocks[i].last_price) / stocks[i].last_price * 100;
  }
}

void display_stock_changes() {
  int i = 0;

  printf("Stock changes:\n");
  for (i = 0; i < MAX_STOCK_NUM; i++) {
    printf("%s: %.2f%% (%.2f)\n", stocks[i].name, stocks[i].change, stocks[i].price);
  }
}

int main() {
  update_stock_prices();
  calculate_stock_changes();
  display_stock_changes();

  return 0;
}