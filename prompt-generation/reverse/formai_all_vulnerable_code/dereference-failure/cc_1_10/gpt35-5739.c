//FormAI DATASET v1.0 Category: Digital Auction System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 100

typedef struct item {
  char name[50];
  double start_price;
  int bids_count;
  double *bids;
  int bidder_index;
} item;

typedef struct bidder {
  char name[50];
  double balance;
  int items_count;
  item *items[MAX_ITEMS];
} bidder;

item *items[MAX_ITEMS];
bidder *bidders[MAX_BIDDERS];
int bidders_count = 0;
int items_count = 0;

// Add the given bidder to the list of bidders
void add_bidder(bidder *b) {
  if (bidders_count < MAX_BIDDERS) {
    bidders[bidders_count++] = b;
    printf("%s added as a bidder.\n", b->name);
  } else {
    printf("Max bidder limit reached!\n");
  }
}

// Add the given item to the list of items
void add_item(item *i) {
  if (items_count < MAX_ITEMS) {
    items[items_count++] = i;
    printf("%s added for auction. Starting price is %.2lf\n", i->name, i->start_price);
  } else {
    printf("Max item limit reached!\n");
  }
}

// Function to get the current highest bidder for an item
bidder *get_highest_bidder(item *i) {
  int j, index = 0;
  double max_bid = i->start_price;
  for (j = 0; j < i->bids_count; j++) {
    if (i->bids[j] > max_bid) {
      index = j+1;
      max_bid = i->bids[j];
    }
  }
  return i->bidder_index ? i->bidder_index : bidders[index];
}

// Function to place a bid on an item
void place_bid(bidder *b, item *i, double amount) {
  if (i->start_price >= amount) {
    printf("Bid amount must be greater than the starting price.\n");
    return;
  }
  if (b->balance < amount) {
   printf("%s does not have sufficient balance to place the bid.\n", b->name);
   return;
  }
  bidder *highest_bidder = get_highest_bidder(i);
  if (highest_bidder == b) {
    printf("%s is already the highest bidder.\n", b->name);
    return;
  }
  highest_bidder->balance += i->bidder_index ? i->bids[i->bidder_index-1] : i->start_price;
  i->bidder_index = 0;
  i->bids[i->bids_count++] = amount;
  b->balance -= amount;
  printf("%s has placed the bid of %.2lf on %s.\n", b->name, amount, i->name);
}

// Function to print the current status of the auction
void print_status() {
  int i, j;
  for (i = 0; i < items_count; i++) {
    printf("==============================\n");
    printf("Item: %s\n", items[i]->name);
    printf("Starting price: %.2lf\n", items[i]->start_price);
    printf("Bids:\n");
    if (items[i]->bids_count == 0) {
      printf("No bids placed yet.\n");
    }
    else {
      bidder *highest_bidder = get_highest_bidder(items[i]);
      for (j = 0; j < items[i]->bids_count; j++) {
        printf("%.2lf - %s\n", items[i]->bids[j], highest_bidder->name);
        highest_bidder = bidders[j+1];
      }
    }
  }
}

int main() {
  bidder *b1 = (bidder *)malloc(sizeof(bidder));
  strcpy(b1->name, "Alice");
  b1->balance = 1000;
  add_bidder(b1);

  bidder *b2 = (bidder *)malloc(sizeof(bidder));
  strcpy(b2->name, "Bob");
  b2->balance = 2000;
  add_bidder(b2);

  item *i1 = (item *)malloc(sizeof(item));
  strcpy(i1->name, "Painting");
  i1->start_price = 100;
  i1->bids_count = 0;
  i1->bids = (double *)malloc(sizeof(double) * MAX_BIDDERS);
  i1->bidder_index = 0;
  add_item(i1);

  item *i2 = (item *)malloc(sizeof(item));
  strcpy(i2->name, "Watch");
  i2->start_price = 50;
  i2->bids_count = 0;
  i2->bids = (double *)malloc(sizeof(double) * MAX_BIDDERS);
  i2->bidder_index = 0;
  add_item(i2);

  place_bid(b1, i1, 150);
  place_bid(b2, i1, 200);
  place_bid(b1, i2, 70);
  place_bid(b2, i2, 80);

  print_status();

  return 0;
}