//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Item {
	char *name;
	int price;
};

struct Bidder {
	char *name;
	int balance;
};

struct Auction {
	struct Item *item;
	struct Bidder *current_bidder;
	int current_price;
	int num_bidders;
};

void create_auction(struct Auction *auction, char *item_name, int item_price, char *bidder_name, int bidder_balance) {
	auction->item = malloc(sizeof(struct Item));
	auction->item->name = strdup(item_name);
	auction->item->price = item_price;
	auction->current_bidder = malloc(sizeof(struct Bidder));
	auction->current_bidder->name = strdup(bidder_name);
	auction->current_bidder->balance = bidder_balance;
	auction->current_price = item_price;
	auction->num_bidders = 1;
}

void destroy_auction(struct Auction *auction) {
	free(auction->item->name);
	free(auction->item);
	free(auction->current_bidder->name);
	free(auction->current_bidder);
}

void add_bidder(struct Auction *auction, char *bidder_name, int bidder_balance) {
	struct Bidder *new_bidder = malloc(sizeof(struct Bidder));
	new_bidder->name = strdup(bidder_name);
	new_bidder->balance = bidder_balance;
	auction->current_bidder = new_bidder;
	auction->num_bidders++;
}

void remove_bidder(struct Auction *auction, char *bidder_name) {
	if (strcmp(auction->current_bidder->name, bidder_name) == 0) {
		auction->current_bidder = NULL;
		auction->num_bidders--;
	}
}

int place_bid(struct Auction *auction, int bid_amount) {
	if (bid_amount > auction->current_bidder->balance) {
		return -1;
	}
	auction->current_bidder->balance -= bid_amount;
	auction->current_price += bid_amount;
	return 0;
}

int main() {
	struct Auction auction;
	create_auction(&auction, "Mona Lisa", 1000, "John", 10000);
	add_bidder(&auction, "Mary", 5000);
	add_bidder(&auction, "Bob", 2000);
	while (auction.num_bidders > 1) {
		int bid_amount = rand() % 1000;
		if (place_bid(&auction, bid_amount) == 0) {
			printf("%s bid %d\n", auction.current_bidder->name, bid_amount);
		} else {
			printf("%s ran out of money\n", auction.current_bidder->name);
			remove_bidder(&auction, auction.current_bidder->name);
		}
	}
	printf("The winner is %s with a bid of %d\n", auction.current_bidder->name, auction.current_price);
	destroy_auction(&auction);
	return 0;
}