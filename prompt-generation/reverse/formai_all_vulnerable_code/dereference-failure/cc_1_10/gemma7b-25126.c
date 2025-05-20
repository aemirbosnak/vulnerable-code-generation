//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder *next;
};

struct Auction {
    char item_name[50];
    int starting_price;
    struct Bidder *highest_bidder;
    struct Auction *next;
};

void add_bidder(struct Auction *auction, char *name, int bid) {
    struct Bidder *new_bidder = (struct Bidder *)malloc(sizeof(struct Bidder));
    strcpy(new_bidder->name, name);
    new_bidder->bid = bid;
    new_bidder->next = NULL;

    if (auction->highest_bidder == NULL) {
        auction->highest_bidder = new_bidder;
    } else {
        auction->highest_bidder->next = new_bidder;
    }
}

void start_auction(struct Auction *auction) {
    printf("Auction for item: %s\n", auction->item_name);
    printf("Starting price: %d\n", auction->starting_price);

    int current_price = auction->starting_price;
    struct Bidder *current_bidder = auction->highest_bidder;

    while (current_price < MAX_BID) {
        printf("Current price: %d\n", current_price);

        char bidder_name[20];
        int new_bid;

        printf("Enter your name: ");
        scanf("%s", bidder_name);

        printf("Enter your bid: ");
        scanf("%d", &new_bid);

        add_bidder(auction, bidder_name, new_bid);

        current_price = new_bid;
        current_bidder = auction->highest_bidder;
    }

    printf("Congratulations, %s, you won the auction!\n", current_bidder->name);
    printf("The final price is: %d\n", current_price);
}

int main() {
    struct Auction *auction = (struct Auction *)malloc(sizeof(struct Auction));
    strcpy(auction->item_name, "iPhone");
    auction->starting_price = 500;
    auction->highest_bidder = NULL;

    start_auction(auction);

    return 0;
}