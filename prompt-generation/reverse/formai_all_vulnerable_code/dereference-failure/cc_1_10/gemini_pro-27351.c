//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Paranoid data structures and functions...
#define PARANOIA_LEVEL_NONE          0
#define PARANOIA_LEVEL_LOW           1
#define PARANOIA_LEVEL_MEDIUM        2
#define PARANOIA_LEVEL_HIGH          3
#define PARANOIA_LEVEL_EXTREME       4

typedef struct {
  char *name;
  float price;
  int volume;
} stock_t;

typedef struct {
  int paranoia_level;
  int num_stocks;
  stock_t *stocks;
} stock_tracker_t;

stock_tracker_t *stock_tracker_create(int paranoia_level) {
  stock_tracker_t *tracker = (stock_tracker_t *)malloc(sizeof(stock_tracker_t));
  if (tracker == NULL) {
    return NULL;
  }

  tracker->paranoia_level = paranoia_level;
  tracker->num_stocks = 0;
  tracker->stocks = NULL;

  return tracker;
}

void stock_tracker_destroy(stock_tracker_t *tracker) {
  if (tracker == NULL) {
    return;
  }

  for (int i = 0; i < tracker->num_stocks; i++) {
    free(tracker->stocks[i].name);
  }

  free(tracker->stocks);
  free(tracker);
}

int stock_tracker_add_stock(stock_tracker_t *tracker, char *name, float price, int volume) {
  if (tracker == NULL) {
    return -1;
  }

  stock_t *new_stock = (stock_t *)malloc(sizeof(stock_t));
  if (new_stock == NULL) {
    return -1;
  }

  new_stock->name = strdup(name);
  new_stock->price = price;
  new_stock->volume = volume;

  tracker->stocks = (stock_t *)realloc(tracker->stocks, (tracker->num_stocks + 1) * sizeof(stock_t));
  if (tracker->stocks == NULL) {
    free(new_stock);
    return -1;
  }

  tracker->stocks[tracker->num_stocks] = *new_stock;
  tracker->num_stocks++;

  return 0;
}

int stock_tracker_remove_stock(stock_tracker_t *tracker, char *name) {
  if (tracker == NULL) {
    return -1;
  }

  for (int i = 0; i < tracker->num_stocks; i++) {
    if (strcmp(tracker->stocks[i].name, name) == 0) {
      for (int j = i + 1; j < tracker->num_stocks; j++) {
        tracker->stocks[j - 1] = tracker->stocks[j];
      }

      tracker->num_stocks--;
      return 0;
    }
  }

  return -1;
}

int stock_tracker_get_num_stocks(stock_tracker_t *tracker) {
  if (tracker == NULL) {
    return -1;
  }

  return tracker->num_stocks;
}

stock_t *stock_tracker_get_stock(stock_tracker_t *tracker, char *name) {
  if (tracker == NULL) {
    return NULL;
  }

  for (int i = 0; i < tracker->num_stocks; i++) {
    if (strcmp(tracker->stocks[i].name, name) == 0) {
      return &tracker->stocks[i];
    }
  }

  return NULL;
}

void stock_tracker_print(stock_tracker_t *tracker) {
  if (tracker == NULL) {
    return;
  }

  for (int i = 0; i < tracker->num_stocks; i++) {
    printf("%s: $%.2f (%d)\n", tracker->stocks[i].name, tracker->stocks[i].price, tracker->stocks[i].volume);
  }
}

// Paranoid stock tracking program...
int main(int argc, char **argv) {
  // Set the paranoia level...
  int paranoia_level = PARANOIA_LEVEL_NONE;

  // Parse the command line arguments...
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-p") == 0) {
      paranoia_level = PARANOIA_LEVEL_LOW;
    } else if (strcmp(argv[i], "-m") == 0) {
      paranoia_level = PARANOIA_LEVEL_MEDIUM;
    } else if (strcmp(argv[i], "-h") == 0) {
      paranoia_level = PARANOIA_LEVEL_HIGH;
    } else if (strcmp(argv[i], "-e") == 0) {
      paranoia_level = PARANOIA_LEVEL_EXTREME;
    }
  }

  // Create the stock tracker...
  stock_tracker_t *tracker = stock_tracker_create(paranoia_level);

  // Add some stocks to the tracker...
  stock_tracker_add_stock(tracker, "AAPL", 100.00, 1000);
  stock_tracker_add_stock(tracker, "GOOG", 50.00, 2000);
  stock_tracker_add_stock(tracker, "MSFT", 25.00, 3000);

  // Print the stocks in the tracker...
  stock_tracker_print(tracker);

  // Destroy the stock tracker...
  stock_tracker_destroy(tracker);

  return 0;
}