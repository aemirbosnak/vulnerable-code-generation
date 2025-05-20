//FormAI DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Item {
  char name[20];
  float price;
};

struct Bid {
  char bidder[20];
  float bid_amount;
  struct Bid *next;
};

struct Auction {
  char item_name[20];
  float start_price;
  struct Bid *bids;
};

void print_item(struct Item item);
void print_bid(struct Bid *bid);
void print_auction(struct Auction *auction);
int add_bid(struct Auction *auction, char *bidder_name, float bid_amount);

int main() {
  //initialize random seed
  srand(time(NULL));

  //create items
  struct Item item1 = {"Antique Vase", 100.0};
  struct Item item2 = {"Rare Baseball Card", 50.0};
  struct Item item3 = {"Signed Guitar", 500.0};

  //create auctions for each item
  struct Auction auction1 = {item1.name, item1.price, NULL};
  struct Auction auction2 = {item2.name, item2.price, NULL};
  struct Auction auction3 = {item3.name, item3.price, NULL};

  //simulate bidding process
  char bidders[5][20] = {"John", "Jane", "Mike", "Sara", "Tom"};
  float bid_amounts[5] = {150.0, 120.0, 80.0, 600.0, 450.0};

  for(int i=0; i<5; i++) {
    add_bid(&auction1, bidders[i], bid_amounts[i]);
  }

  //print results
  printf("Auction Results: \n");
  print_item(item1);
  print_auction(&auction1);

  return 0;
}

void print_item(struct Item item) {
  printf("Item: %s\n", item.name);
  printf("Starting Price: $%.2f\n", item.price);
}

void print_bid(struct Bid *bid) {
  printf("%s bids $%.2f\n", bid->bidder, bid->bid_amount);
}

void print_auction(struct Auction *auction) {
  printf("Current Bids:\n");
  struct Bid *current_bid = auction->bids;
  while(current_bid != NULL) {
    print_bid(current_bid);
    current_bid = current_bid->next;
  }
}

int add_bid(struct Auction *auction, char *bidder_name, float bid_amount) {
  //validate bid amount
  if(bid_amount <= auction->start_price) {
    printf("%s's bid for $%.2f was too low.\n", bidder_name, bid_amount);
    return 0;
  }

  //create new bid
  struct Bid *new_bid = (struct Bid*)malloc(sizeof(struct Bid));
  strcpy(new_bid->bidder, bidder_name);
  new_bid->bid_amount = bid_amount;

  //add bid to list
  struct Bid *prev_bid = NULL;
  struct Bid *current_bid = auction->bids;
  while(current_bid != NULL && current_bid->bid_amount > bid_amount) {
    prev_bid = current_bid;
    current_bid = current_bid->next;
  }

  if(prev_bid == NULL) {
    new_bid->next = auction->bids;
    auction->bids = new_bid;
  }
  else {
    prev_bid->next = new_bid;
    new_bid->next = current_bid;
  }

  printf("%s's bid for $%.2f was successful.\n", bidder_name, bid_amount);
  return 1;
}