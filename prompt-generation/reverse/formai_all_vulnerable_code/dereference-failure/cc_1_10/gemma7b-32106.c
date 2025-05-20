//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
};

struct Item {
    char name[50];
    int starting_price;
    int current_price;
    struct Bidder* bidders;
};

void place_bid(struct Item* item, struct Bidder* bidder) {
    struct Bidder* new_bidder = malloc(sizeof(struct Bidder));
    strcpy(new_bidder->name, bidder->name);
    new_bidder->bid = bidder->bid;
    new_bidder->next = item->bidders;
    item->bidders = new_bidder;

    if (new_bidder->bid > item->current_price) {
        item->current_price = new_bidder->bid;
    }
}

void print_auction(struct Item* item) {
    printf("Item: %s\n", item->name);
    printf("Starting Price: %d\n", item->starting_price);
    printf("Current Price: %d\n", item->current_price);
    printf("Bidders:\n");

    struct Bidder* bidder = item->bidders;
    while (bidder) {
        printf("%s: %d\n", bidder->name, bidder->bid);
        bidder = bidder->next;
    }
}

int main() {
    struct Item* item = malloc(sizeof(struct Item));
    strcpy(item->name, "Jet-powered motorcycle");
    item->starting_price = 10000;
    item->current_price = 10000;
    item->bidders = NULL;

    struct Bidder* bidder = malloc(sizeof(struct Bidder));
    strcpy(bidder->name, "John Doe");
    bidder->bid = 8000;

    place_bid(item, bidder);

    print_auction(item);

    return 0;
}