//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct auction {
    char* title;
    char* description;
    int starting_price;
    int min_bid;
    int current_bid;
    char* winner;
};

void auction_init(struct auction* auction) {
    auction->title = malloc(100);
    auction->description = malloc(100);
    auction->starting_price = 0;
    auction->min_bid = 0;
    auction->current_bid = 0;
    auction->winner = NULL;
}

void place_bid(struct auction* auction, int bid) {
    if (bid < auction->current_bid) {
        printf("Invalid bid! The current bid is %d.\n", auction->current_bid);
    } else if (bid > auction->current_bid) {
        auction->current_bid = bid;
        printf("Bid placed! The current bid is %d.\n", auction->current_bid);
    }
}

void handle_bid(struct auction* auction) {
    int highest_bid = auction->current_bid;
    char* highest_bidder = auction->winner;
    int i;

    for (i = 1; i <= auction->current_bid; i++) {
        if (i > highest_bid) {
            highest_bid = i;
            highest_bidder = auction->winner;
        }
    }

    if (highest_bid == auction->current_bid) {
        printf("No winner!\n");
    } else {
        printf("The winner is %s with a bid of %d!\n", highest_bidder, highest_bid);
    }
}

void end_auction(struct auction* auction) {
    printf("-----------------------------\n");
    printf("| Auction Details: |\n");
    printf("-----------------------------\n");
    printf("| Title: %s |\n", auction->title);
    printf("| Description: %s |\n", auction->description);
    printf("| Starting Price: %d |\n", auction->starting_price);
    printf("| Minimum Bid: %d |\n", auction->min_bid);
    printf("| Current Bid: %d |\n", auction->current_bid);
    printf("-----------------------------\n");
    printf("| Winner: %s |\n", auction->winner);
    printf("-----------------------------\n");
}

int main() {
    struct auction auction;
    auction_init(&auction);
    place_bid(&auction, 10);
    place_bid(&auction, 20);
    place_bid(&auction, 30);
    place_bid(&auction, 40);
    handle_bid(&auction);
    end_auction(&auction);
    return 0;
}