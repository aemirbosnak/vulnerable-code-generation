//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char *name;
    int start_price;
    int current_price;
    int num_bids;
    struct Auction *next;
} Auction;

Auction *auction_head = NULL;

void create_auction(char *name, int start_price) {
    Auction *new_auction = malloc(sizeof(Auction));
    new_auction->name = strdup(name);
    new_auction->start_price = start_price;
    new_auction->current_price = start_price;
    new_auction->num_bids = 0;
    new_auction->next = NULL;

    if (auction_head == NULL) {
        auction_head = new_auction;
    } else {
        auction_head->next = new_auction;
        auction_head = new_auction;
    }
}

void place_bid(char *name, int bid) {
    Auction *current_auction = auction_head;

    while (current_auction) {
        if (strcmp(current_auction->name, name) == 0) {
            current_auction->num_bids++;
            if (bid > current_auction->current_price) {
                current_auction->current_price = bid;
            }
            break;
        }
        current_auction = current_auction->next;
    }

    if (current_auction == NULL) {
        create_auction(name, bid);
    }
}

void print_auctions() {
    Auction *current_auction = auction_head;

    while (current_auction) {
        printf("Name: %s, Start Price: %d, Current Price: %d, Number of Bids: %d\n", current_auction->name, current_auction->start_price, current_auction->current_price, current_auction->num_bids);
        current_auction = current_auction->next;
    }
}

int main() {
    create_auction("Item 1", 100);
    create_auction("Item 2", 200);
    create_auction("Item 3", 300);

    place_bid("John Doe", 150);
    place_bid("Jane Doe", 220);
    place_bid("Bob Smith", 170);

    print_auctions();

    return 0;
}