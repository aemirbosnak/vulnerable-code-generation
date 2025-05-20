//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_BID 1000

struct Bid {
  char name[50];
  int amount;
  struct Bid* next;
};

struct Item {
  char name[50];
  int reservePrice;
  struct Bid* highestBid;
  struct Item* next;
};

void insertBid(struct Bid** head, char* name, int amount) {
  struct Bid* newBid = malloc(sizeof(struct Bid));
  strcpy(newBid->name, name);
  newBid->amount = amount;
  newBid->next = NULL;

  if (*head == NULL) {
    *head = newBid;
  } else {
    (*head)->next = newBid;
  }
}

void insertItem(struct Item** head, char* name, int reservePrice) {
  struct Item* newItem = malloc(sizeof(struct Item));
  strcpy(newItem->name, name);
  newItem->reservePrice = reservePrice;
  newItem->highestBid = NULL;
  newItem->next = NULL;

  if (*head == NULL) {
    *head = newItem;
  } else {
    (*head)->next = newItem;
  }
}

void auction(struct Item* item) {
  printf("Auction for item: %s\n", item->name);
  printf("Reserve price: $%d\n", item->reservePrice);

  struct Bid* highestBid = item->highestBid;
  if (highestBid) {
    printf("Current highest bid: $%d, by %s\n", highestBid->amount, highestBid->name);
  } else {
    printf("No bids yet.\n");
  }

  printf("Enter your bid: $");
  int bidAmount = atoi(fgets(NULL, 10, stdin));

  if (bidAmount > item->reservePrice) {
    printf("Your bid is too high.\n");
  } else if (highestBid && bidAmount < highestBid->amount) {
    printf("Your bid is too low.\n");
  } else {
    insertBid(&highestBid, "John Doe", bidAmount);
    item->highestBid = highestBid;
    printf("Your bid has been placed. Thank you!\n");
  }
}

int main() {
  struct Item* itemHead = NULL;
  insertItem(&itemHead, "Gold ring", 500);
  insertItem(&itemHead, "Diamond necklace", 1000);
  insertItem(&itemHead, "Platinum watch", 2000);

  auction(itemHead->next);

  return 0;
}