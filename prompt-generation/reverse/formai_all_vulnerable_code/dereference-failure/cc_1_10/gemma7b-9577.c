//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
};

struct AuctionItem {
  char name[50];
  int startingPrice;
  int reservePrice;
  struct Bidder* highestBidder;
  struct AuctionItem* next;
};

void insertBidder(struct Bidder** head, char* name, int bid) {
  struct Bidder* newBidder = (struct Bidder*)malloc(sizeof(struct Bidder));
  strcpy(newBidder->name, name);
  newBidder->bid = bid;
  newBidder->next = NULL;

  if (*head == NULL) {
    *head = newBidder;
  } else {
    (*head)->next = newBidder;
  }
}

void insertAuctionItem(struct AuctionItem** head, char* name, int startingPrice, int reservePrice) {
  struct AuctionItem* newItem = (struct AuctionItem*)malloc(sizeof(struct AuctionItem));
  strcpy(newItem->name, name);
  newItem->startingPrice = startingPrice;
  newItem->reservePrice = reservePrice;
  newItem->highestBidder = NULL;
  newItem->next = NULL;

  if (*head == NULL) {
    *head = newItem;
  } else {
    (*head)->next = newItem;
  }
}

void startAuction(struct AuctionItem* item) {
  printf("Auction for item: %s\n", item->name);
  printf("Starting price: $%d\n", item->startingPrice);

  struct Bidder* bidder = item->highestBidder;
  if (bidder) {
    printf("Current highest bid: $%d by %s\n", bidder->bid, bidder->name);
  } else {
    printf("No bids yet.\n");
  }

  printf("Enter your bid: ");
  int bid = atoi(stdin);

  if (bid > MAX_BID) {
    printf("Error: bid too high.\n");
  } else if (bid < item->startingPrice) {
    printf("Error: bid too low.\n");
  } else {
    insertBidder(&item->highestBidder, "John Doe", bid);
    printf("Your bid has been placed. Current highest bid: $%d by %s\n", item->highestBidder->bid, item->highestBidder->name);
  }
}

int main() {
  struct AuctionItem* itemHead = NULL;
  insertAuctionItem(&itemHead, "Gold Ring", 100, 50);
  insertAuctionItem(&itemHead, "Diamond Necklace", 200, 75);

  startAuction(itemHead->next);

  return 0;
}