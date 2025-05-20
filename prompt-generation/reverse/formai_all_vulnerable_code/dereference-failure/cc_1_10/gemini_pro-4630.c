//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_LINE_LENGTH 1024

struct stock {
  char *symbol;
  double price;
  double change;
  double percent_change;
};

struct stock stocks[MAX_STOCKS];
int num_stocks;

void parse_line(char *line) {
  char *symbol = strtok(line, ",");
  char *price = strtok(NULL, ",");
  char *change = strtok(NULL, ",");
  char *percent_change = strtok(NULL, ",");

  stocks[num_stocks].symbol = strdup(symbol);
  stocks[num_stocks].price = atof(price);
  stocks[num_stocks].change = atof(change);
  stocks[num_stocks].percent_change = atof(percent_change);

  num_stocks++;
}

void read_file(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    parse_line(line);
  }

  fclose(fp);
}

void print_stocks() {
  printf("%-10s %-10s %-10s %-10s\n", "Symbol", "Price", "Change", "% Change");
  for (int i = 0; i < num_stocks; i++) {
    printf("%-10s %-10.2f %-10.2f %-10.2f\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].percent_change);
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s filename\n", argv[0]);
    exit(1);
  }

  read_file(argv[1]);
  print_stocks();

  return 0;
}