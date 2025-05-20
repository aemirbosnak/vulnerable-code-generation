//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int bid;
} Bidder;

typedef struct {
  char *name;
  int price;
  int num_bidders;
  Bidder *bidders;
} Item;

int main() {
  // Create an auction system with 3 items
  Item items[3];
  strcpy(items[0].name, "Item 1");
  items[0].price = 100;
  items[0].num_bidders = 0;
  items[0].bidders = NULL;

  strcpy(items[1].name, "Item 2");
  items[1].price = 200;
  items[1].num_bidders = 0;
  items[1].bidders = NULL;

  strcpy(items[2].name, "Item 3");
  items[2].price = 300;
  items[2].num_bidders = 0;
  items[2].bidders = NULL;

  // Create a list of bidders
  Bidder bidders[4];
  strcpy(bidders[0].name, "Bidder 1");
  bidders[0].bid = 110;

  strcpy(bidders[1].name, "Bidder 2");
  bidders[1].bid = 120;

  strcpy(bidders[2].name, "Bidder 3");
  bidders[2].bid = 130;

  strcpy(bidders[3].name, "Bidder 4");
  bidders[3].bid = 140;

  // Start the auction
  printf("Welcome to the auction!\n");
  printf("Please enter your name and bid for each item.\n");

  int i, j;
  for (i = 0; i < 3; i++) {
    printf("Item %s:\n", items[i].name);

    for (j = 0; j < 4; j++) {
      printf("  %s: %d\n", bidders[j].name, bidders[j].bid);
    }

    printf("Enter your bid: ");
    int bid;
    scanf("%d", &bid);

    // Find the highest bidder
    int highest_bid = -1;
    Bidder *highest_bidder = NULL;
    for (j = 0; j < 4; j++) {
      if (bidders[j].bid > highest_bid) {
        highest_bid = bidders[j].bid;
        highest_bidder = &bidders[j];
      }
    }

    // Update the item's price and highest bidder
    items[i].price = highest_bid;
    items[i].bidders = highest_bidder;
  }

  // Print the results of the auction
  printf("The auction is over!\n");
  for (i = 0; i < 3; i++) {
    printf("Item %s: %d\n", items[i].name, items[i].price);
    printf("  Winner: %s\n", items[i].bidders->name);
  }

  return 0;
}