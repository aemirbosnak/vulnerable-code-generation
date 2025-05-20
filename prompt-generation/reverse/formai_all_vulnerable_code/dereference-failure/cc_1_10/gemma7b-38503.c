//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bid {
  char name[256];
  int amount;
  struct Bid* next;
};

struct Item {
  char name[256];
  int startingPrice;
  struct Bid* bids;
  struct Item* next;
};

void addBid(struct Item* item, char* name, int amount) {
  struct Bid* newBid = malloc(sizeof(struct Bid));
  strcpy(newBid->name, name);
  newBid->amount = amount;
  newBid->next = item->bids;
  item->bids = newBid;
}

void printBids(struct Item* item) {
  struct Bid* currentBid = item->bids;
  printf("Bids for item '%s':\n", item->name);
  while (currentBid) {
    printf("%s bidded %d\n", currentBid->name, currentBid->amount);
    currentBid = currentBid->next;
  }
}

int main() {
  struct Item* items = NULL;
  struct Bid* bids = NULL;

  // Create a few items
  struct Item* item1 = malloc(sizeof(struct Item));
  strcpy(item1->name, "Laptop");
  item1->startingPrice = 500;
  item1->bids = NULL;
  items = item1;

  struct Item* item2 = malloc(sizeof(struct Item));
  strcpy(item2->name, "Smartphone");
  item2->startingPrice = 300;
  item2->bids = NULL;
  items->next = item2;

  // Add some bids
  addBid(item1, "John Doe", 1200);
  addBid(item1, "Jane Doe", 800);
  addBid(item2, "Bill Smith", 200);
  addBid(item2, "Mary Johnson", 150);

  // Print the bids
  printBids(item1);
  printBids(item2);

  return 0;
}