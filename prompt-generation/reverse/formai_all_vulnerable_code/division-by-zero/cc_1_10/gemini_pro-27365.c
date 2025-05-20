//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int item_id;
  char *item_name;
  int current_bid;
  int reserve_price;
} Item;

typedef struct {
  int bidder_id;
  char *bidder_name;
  int balance;
} Bidder;

typedef struct {
  Item *items;
  int num_items;
  Bidder *bidders;
  int num_bidders;
  int current_time;
} Auction;

Auction *create_auction(int num_items, int num_bidders) {
  Auction *auction = malloc(sizeof(Auction));
  auction->items = malloc(sizeof(Item) * num_items);
  auction->num_items = num_items;
  auction->bidders = malloc(sizeof(Bidder) * num_bidders);
  auction->num_bidders = num_bidders;
  auction->current_time = 0;
  return auction;
}

void destroy_auction(Auction *auction) {
  free(auction->items);
  free(auction->bidders);
  free(auction);
}

void add_item(Auction *auction, Item item) {
  auction->items[auction->num_items++] = item;
}

void add_bidder(Auction *auction, Bidder bidder) {
  auction->bidders[auction->num_bidders++] = bidder;
}

void start_auction(Auction *auction) {
  while (auction->current_time < 100) {
    for (int i = 0; i < auction->num_items; i++) {
      Item *item = &auction->items[i];
      if (item->current_bid < item->reserve_price) {
        continue;
      }
      for (int j = 0; j < auction->num_bidders; j++) {
        Bidder *bidder = &auction->bidders[j];
        if (bidder->balance < item->current_bid) {
          continue;
        }
        int bid = (rand() % (item->reserve_price - item->current_bid)) + item->current_bid;
        if (bid > bidder->balance) {
          continue;
        }
        bidder->balance -= bid;
        item->current_bid = bid;
        printf("Bidder %d bids %d on item %d\n", bidder->bidder_id, bid, item->item_id);
      }
    }
    auction->current_time++;
  }
}

int main() {
  srand(time(NULL));

  Auction *auction = create_auction(10, 10);

  Item item1 = {1, "iPhone 13", 1000, 1200};
  Item item2 = {2, "MacBook Air", 1500, 1800};
  Item item3 = {3, "Apple Watch", 500, 600};
  Item item4 = {4, "iPad Pro", 1200, 1500};
  Item item5 = {5, "AirPods Pro", 250, 300};
  Item item6 = {6, "HomePod mini", 100, 150};
  Item item7 = {7, "Apple TV 4K", 200, 250};
  Item item8 = {8, "Beats Solo Pro", 300, 350};
  Item item9 = {9, "Powerbeats Pro", 250, 300};
  Item item10 = {10, "MagSafe Charger", 50, 75};

  add_item(auction, item1);
  add_item(auction, item2);
  add_item(auction, item3);
  add_item(auction, item4);
  add_item(auction, item5);
  add_item(auction, item6);
  add_item(auction, item7);
  add_item(auction, item8);
  add_item(auction, item9);
  add_item(auction, item10);

  Bidder bidder1 = {1, "Alice", 2000};
  Bidder bidder2 = {2, "Bob", 3000};
  Bidder bidder3 = {3, "Carol", 4000};
  Bidder bidder4 = {4, "Dave", 5000};
  Bidder bidder5 = {5, "Eve", 6000};
  Bidder bidder6 = {6, "Frank", 7000};
  Bidder bidder7 = {7, "George", 8000};
  Bidder bidder8 = {8, "Helen", 9000};
  Bidder bidder9 = {9, "Ian", 10000};
  Bidder bidder10 = {10, "Jack", 11000};

  add_bidder(auction, bidder1);
  add_bidder(auction, bidder2);
  add_bidder(auction, bidder3);
  add_bidder(auction, bidder4);
  add_bidder(auction, bidder5);
  add_bidder(auction, bidder6);
  add_bidder(auction, bidder7);
  add_bidder(auction, bidder8);
  add_bidder(auction, bidder9);
  add_bidder(auction, bidder10);

  start_auction(auction);

  destroy_auction(auction);

  return 0;
}