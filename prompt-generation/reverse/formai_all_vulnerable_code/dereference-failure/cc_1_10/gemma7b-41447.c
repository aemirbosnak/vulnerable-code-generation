//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
};

struct Item {
  char name[20];
  int startingPrice;
  struct Bidder* highestBidder;
  struct Item* next;
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

void insertItem(struct Item** head, char* name, int startingPrice) {
  struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
  strcpy(newItem->name, name);
  newItem->startingPrice = startingPrice;
  newItem->highestBidder = NULL;
  newItem->next = NULL;

  if (*head == NULL) {
    *head = newItem;
  } else {
    (*head)->next = newItem;
  }
}

void auction(struct Item* item) {
  struct Bidder* highestBidder = item->highestBidder;
  int highestBid = highestBidder->bid;
  int currentBid = highestBid;

  printf("Auction for item: %s\n", item->name);
  printf("Current highest bid: $%d\n", highestBid);

  while (currentBid < MAX_BID) {
    printf("Enter your bid: $");
    int newBid = atoi(fgets(NULL, 20, stdin));

    if (newBid > currentBid) {
      currentBid = newBid;
      highestBidder = NULL;
    }

    insertBidder(&highestBidder, "John Doe", newBid);

    printf("New highest bid: $%d\n", currentBid);
  }

  printf("Congratulations, %s, you won the auction!\n", highestBidder->name);
  printf("Your total cost: $%d\n", currentBid);
}

int main() {
  struct Item* items = NULL;
  insertItem(&items, "Gold necklace", 500);
  insertItem(&items, "Diamond ring", 1000);
  insertItem(&items, "Silver bracelet", 200);

  auction(items->next);

  return 0;
}