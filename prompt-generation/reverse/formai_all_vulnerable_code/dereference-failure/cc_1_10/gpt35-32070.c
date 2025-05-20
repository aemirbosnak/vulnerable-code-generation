//FormAI DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Auction_item {
  char name[50];
  char description[100];
  int current_bid;
  int num_bids;
  int *bids;
} Auction_item;

Auction_item* create_item(char *name, char *description, int starting_bid, int num_bids) {
  Auction_item *new_item = (Auction_item*)malloc(sizeof(Auction_item));
  strcpy(new_item->name, name);
  strcpy(new_item->description, description);
  new_item->current_bid = starting_bid;
  new_item->num_bids = num_bids;
  new_item->bids = (int*)calloc(num_bids, sizeof(int));
  return new_item;
}

void print_item(Auction_item *item) {
  printf("Item Name: %s\n", item->name);
  printf("Description: %s\n", item->description);
  printf("Current Bid: $%d\n", item->current_bid);
  printf("Number of Bids: %d\n", item->num_bids);
  printf("Bids:\n");
  for(int i = 0; i < item->num_bids; i++) {
    printf("$%d\n", item->bids[i]);
  }
}

void bid_on_item(Auction_item *item, int bid) {
  if(bid > item->current_bid) {
    item->bids[item->num_bids] = bid;
    item->num_bids++;
    item->current_bid = bid;
    printf("You have successfully placed a bid of $%d on %s!\n", bid, item->name);
  } else {
    printf("Sorry, your bid of $%d is too low. The current high bid is $%d.\n", bid, item->current_bid);
  }
}

int main() {
  Auction_item *item1 = create_item("Antique Vase", "Beautiful handcrafted vase from the Ming Dynasty", 500, 0);
  Auction_item *item2 = create_item("Vintage Sports Car", "Rare classic car from the 1970s", 10000, 0);

  printf("Welcome to our digital auction system!\n\n");
  printf("Here are the items currently up for bid:\n");
  print_item(item1);
  printf("\n");
  print_item(item2);
  printf("\n");

  printf("Please enter your bid for the Antique Vase (minimum bid is $500):\n");
  int bid1;
  scanf("%d", &bid1);
  bid_on_item(item1, bid1);

  printf("Please enter your bid for the Vintage Sports Car (minimum bid is $10000):\n");
  int bid2;
  scanf("%d", &bid2);
  bid_on_item(item2, bid2);

  printf("\nThank you for using our digital auction system. Here are the final bids:\n");
  print_item(item1);
  printf("\n");
  print_item(item2);

  free(item1->bids);
  free(item1);
  free(item2->bids);
  free(item2);

  return 0;
}