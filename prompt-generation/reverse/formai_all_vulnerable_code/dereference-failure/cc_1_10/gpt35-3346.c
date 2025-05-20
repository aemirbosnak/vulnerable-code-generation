//FormAI DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_STOCKS 10
#define API_KEY "your_api_key_here"

struct MemoryStruct {
  char *memory;
  size_t size;
};

typedef struct {
  char name[50];
  char symbol[10];
  float price;
} Stock;

void *my_realloc(void *ptr, size_t size) {
  if (size == 0) {
    free(ptr);
    return NULL;
  }

  void *new_ptr = realloc(ptr, size);

  if (!new_ptr) {
    free(ptr);
    return NULL;
  }

  return new_ptr;
}

void *my_calloc(size_t count, size_t size) {
  void *ptr = malloc(count * size);

  if (!ptr) {
    return NULL;
  }

  memset(ptr, 0, count * size);

  return ptr;
}

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  mem->memory = my_realloc(mem->memory, mem->size + realsize + 1);

  if (mem->memory) {
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = '\0';
  }

  return realsize;
}

float get_stock_price(char *symbol) {
  CURL *curl;
  CURLcode res;

  struct MemoryStruct chunk;

  chunk.memory = NULL;
  chunk.size = 0;

  char *url_fmt = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=%s&apikey=%s";
  int url_len = strlen(url_fmt) + strlen(symbol) + strlen(API_KEY) - 3;
  char url[url_len];
  sprintf(url, url_fmt, symbol, API_KEY);

  curl = curl_easy_init();

  if (!curl) {
    printf("Error initializing curl\n");
    return -1;
  }

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

  res = curl_easy_perform(curl);

  if (res != CURLE_OK) {
    printf("Error fetching stock price for %s (%d): %s\n", symbol, res, curl_easy_strerror(res));
    curl_easy_cleanup(curl);
    return -1;
  }

  curl_easy_cleanup(curl);

  char *start = strstr(chunk.memory, "price\": \"") + 9;
  char *end = strstr(start, "\"");

  float price = -1;

  if (start && end) {
    char price_str[end - start + 1];
    memcpy(price_str, start, end - start);
    price_str[end - start] = '\0';
    sscanf(price_str, "%f", &price);
  } else {
    printf("Error parsing stock price for %s\n", symbol);
  }

  free(chunk.memory);

  return price;
}

void print_portfolio(Stock *portfolio, int n_stocks) {
  printf("\n**** STOCK PORTFOLIO ****\n");

  for (int i = 0; i < n_stocks; ++i) {
    printf("%s: $%.2f\n", portfolio[i].name, portfolio[i].price);
  }
}

void update_portfolio(Stock *portfolio, int n_stocks) {
  printf("Updating portfolio...\n");

  for (int i = 0; i < n_stocks; ++i) {
    portfolio[i].price = get_stock_price(portfolio[i].symbol);

    if (portfolio[i].price == -1) {
      printf("Error updating price for %s (%s)\n", portfolio[i].name, portfolio[i].symbol);
    }
  }
}

void add_stock(Stock *portfolio, int *n_stocks) {
  if (*n_stocks >= MAX_STOCKS) {
    printf("Maximum number of stocks reached (%d)\n", MAX_STOCKS);
    return;
  }

  printf("Enter stock name: ");
  scanf("%s", portfolio[*n_stocks].name);
  printf("Enter stock symbol: ");
  scanf("%s", portfolio[*n_stocks].symbol);
  portfolio[*n_stocks].price = get_stock_price(portfolio[*n_stocks].symbol);

  if (portfolio[*n_stocks].price == -1) {
    printf("Error getting stock price for %s (%s)\n", portfolio[*n_stocks].name, portfolio[*n_stocks].symbol);
  }

  *n_stocks += 1;

  printf("Added stock %s (%s)\n", portfolio[*n_stocks - 1].name, portfolio[*n_stocks - 1].symbol);
}

void remove_stock(Stock *portfolio, int *n_stocks) {
  printf("Enter stock symbol to remove: ");
  char symbol[10];
  scanf("%s", symbol);

  for (int i = 0; i < *n_stocks; ++i) {
    if (strcmp(portfolio[i].symbol, symbol) == 0) {
      printf("Removed stock %s (%s)\n", portfolio[i].name, portfolio[i].symbol);

      // Shift remaining stocks left
      for (int j = i + 1; j < *n_stocks; ++j) {
        portfolio[j - 1] = portfolio[j];
      }

      *n_stocks -= 1;

      return;
    }
  }

  printf("Unable to find stock %s in portfolio\n", symbol);
}

void print_menu() {
  printf("\n**** MAIN MENU ****\n");
  printf("1. Show portfolio\n");
  printf("2. Add stock\n");
  printf("3. Remove stock\n");
  printf("4. Update portfolio\n");
  printf("5. Quit\n");
  printf("Enter option number: ");
}

int main() {
  curl_global_init(CURL_GLOBAL_ALL);

  int choice = 0;
  Stock *portfolio = my_calloc(MAX_STOCKS, sizeof(Stock));
  int n_stocks = 0;

  while (choice != 5) {
    print_menu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        print_portfolio(portfolio, n_stocks);
        break;
      case 2:
        add_stock(portfolio, &n_stocks);
        break;
      case 3:
        remove_stock(portfolio, &n_stocks);
        break;
      case 4:
        update_portfolio(portfolio, n_stocks);
        break;
      case 5:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice, please try again\n");
        break;
    }
  }

  curl_global_cleanup();
  free(portfolio);

  return 0;
}