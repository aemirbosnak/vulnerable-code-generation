//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_AUCTIONS 10
#define MAX_BIDDERS 5

struct Auction {
  char name[20];
  int startPrice;
  int reservePrice;
  int currentBid;
  struct Bidder *bidders;
};

struct Bidder {
  char name[20];
  int bid;
  struct Bidder *next;
};

void createAuction(struct Auction **auction) {
  *auction = (struct Auction *)malloc(sizeof(struct Auction));
  (*auction)->name[0] = '\0';
  (*auction)->startPrice = 0;
  (*auction)->reservePrice = 0;
  (*auction)->currentBid = 0;
  (*auction)->bidders = NULL;
}

void addBidder(struct Auction *auction, struct Bidder **bidder) {
  *bidder = (struct Bidder *)malloc(sizeof(struct Bidder));
  (*bidder)->name[0] = '\0';
  (*bidder)->bid = 0;
  (*bidder)->next = NULL;

  if (auction->bidders == NULL) {
    auction->bidders = *bidder;
  } else {
    auction->bidders->next = *bidder;
  }
}

void bid(struct Auction *auction, struct Bidder *bidder, int amount) {
  if (amount > auction->currentBid) {
    auction->currentBid = amount;
    bidder->bid = amount;
  }
}

void auctionEnd(struct Auction *auction) {
  free(auction->bidders);
  free(auction);
}

int main() {
  struct Auction *auction = NULL;
  struct Bidder *bidder = NULL;

  createAuction(&auction);
  addBidder(auction, &bidder);
  addBidder(auction, &bidder);
  addBidder(auction, &bidder);

  bid(auction, bidder, 10);
  bid(auction, bidder, 12);
  bid(auction, bidder, 14);

  auctionEnd(auction);

  return 0;
}