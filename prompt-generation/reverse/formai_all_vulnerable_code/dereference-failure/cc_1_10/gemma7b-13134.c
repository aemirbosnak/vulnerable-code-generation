//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AuctionItem {
  char name[20];
  int startingBid;
  int currentBid;
  struct AuctionItem* nextItem;
};

struct Auction {
  struct AuctionItem* head;
  int numItems;
  struct Auction* nextAuction;
};

void addItem(struct Auction* auction, char* name, int startingBid) {
  struct AuctionItem* item = (struct AuctionItem*)malloc(sizeof(struct AuctionItem));
  strcpy(item->name, name);
  item->startingBid = startingBid;
  item->currentBid = startingBid;
  item->nextItem = NULL;

  if (auction->head == NULL) {
    auction->head = item;
  } else {
    auction->head->nextItem = item;
  }

  auction->numItems++;
}

void bid(struct Auction* auction, char* bidder, int amount) {
  struct AuctionItem* item = auction->head;
  while (item) {
    if (strcmp(item->name, bidder) == 0) {
      if (amount > item->currentBid) {
        item->currentBid = amount;
      }
    }
    item = item->nextItem;
  }
}

void printAuction(struct Auction* auction) {
  struct AuctionItem* item = auction->head;
  while (item) {
    printf("%s: %d\n", item->name, item->currentBid);
    item = item->nextItem;
  }
}

int main() {
  struct Auction* auction = (struct Auction*)malloc(sizeof(struct Auction));
  auction->head = NULL;
  auction->numItems = 0;
  auction->nextAuction = NULL;

  addItem(auction, "Painting", 100);
  addItem(auction, "Sculpture", 200);
  addItem(auction, "Jewelry", 300);

  bid(auction, "John Doe", 150);
  bid(auction, "Jane Doe", 220);

  printAuction(auction);

  return 0;
}