//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: surrealist
// A surrealist stock market tracker

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defines a stock quote in our surreal world.
typedef struct {
  char name[20]; // The name of the stock.
  float price; // The price of the stock.
  char* description; // A surreal description of the stock.
} StockQuote;

// Create a new stock quote.
StockQuote* newStockQuote(char *name, float price, char *description) {
  StockQuote* quote = malloc(sizeof(StockQuote));
  strcpy(quote->name, name);
  quote->price = price;
  quote->description = description;
  return quote;
}

// Compare two stock quotes.
int compareStockQuotes(StockQuote *a, StockQuote *b) {
  return strcmp(a->name, b->name);
}

// Sort an array of stock quotes.
void sortStockQuotes(StockQuote** quotes, int length) {
  qsort(quotes, length, sizeof(StockQuote*), compareStockQuotes);
}

// Print a stock quote.
void printStockQuote(StockQuote *quote) {
  printf("%s: $%.2f - %s\n", quote->name, quote->price, quote->description);
}

// Main function.
int main() {
  // Create some stock quotes.
  StockQuote* quotes[] = {
    newStockQuote("The Laughing Cow", 10.00, "A cheese that makes you laugh!"),
    newStockQuote("The Crying Onion", 5.00, "An onion that makes you cry!"),
    newStockQuote("The Flying Saucer", 100.00, "A flying saucer that takes you to the moon!"),
    newStockQuote("The Invisible Man", 0.00, "A man who is invisible!"),
    newStockQuote("The Loch Ness Monster", 50.00, "A monster that lives in a lake!"),
  };

  // Sort the stock quotes by name.
  sortStockQuotes(quotes, 5);

  // Print the stock quotes.
  printf("Welcome to the Surreal Stock Market!\n");
  for (int i = 0; i < 5; i++) {
    printStockQuote(quotes[i]);
  }
  printf("\nHave a surreal day!\n");

  // Free the stock quotes.
  for (int i = 0; i < 5; i++) {
    free(quotes[i]);
  }
  return 0;
}