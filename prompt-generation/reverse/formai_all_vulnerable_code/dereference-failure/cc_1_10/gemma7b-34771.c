//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void update_stock_price(char *symbol, int price) {
  FILE *fp = fopen("stocks.txt", "r");
  char *data = NULL;
  int i = 0;

  if (fp) {
    data = (char *)malloc(MAX);
    fread(data, MAX, 1, fp);

    for (i = 0; i < MAX && data[i] != '\0'; i++) {
      if (strcmp(symbol, data + i * 4) == 0) {
        data[i * 4] = (char)price;
      }
    }

    fclose(fp);
  } else {
    printf("Error opening file");
  }

  fp = fopen("stocks.txt", "w");
  fprintf(fp, "%s", data);
  fclose(fp);
}

int main() {
  update_stock_price("AAPL", 150);
  update_stock_price("TSLA", 120);

  FILE *fp = fopen("stocks.txt", "r");
  char *data = NULL;
  int i = 0;

  if (fp) {
    data = (char *)malloc(MAX);
    fread(data, MAX, 1, fp);

    for (i = 0; i < MAX && data[i] != '\0'; i++) {
      printf("%s: %d\n", data + i * 4, data[i * 4]);
    }

    fclose(fp);
  } else {
    printf("Error opening file");
  }

  return 0;
}