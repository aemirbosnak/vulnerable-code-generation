//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Auction {
    int item_id;
    int bid_amount;
    int highest_bid;
    int time_left;
};

int main() {
    struct Auction auction;
    auction.item_id = 1;
    auction.bid_amount = 0;
    auction.highest_bid = 0;
    auction.time_left = 60;

    struct Auction* auctions = malloc(10 * sizeof(struct Auction));

    srand(time(NULL));

    int winner_index = rand() % 10;

    printf("Welcome to the Digital Auction System!\n");
    printf("Auctions:\n");

    for (int i = 0; i < 10; i++) {
        auctions[i].item_id = i + 1;
        auctions[i].bid_amount = rand() % 100;
        auctions[i].highest_bid = auctions[i].bid_amount;
        auctions[i].time_left = rand() % 60 + 1;

        printf("Auction %d: Item ID - %d, Bid Amount - %d, Time Left - %d\n", i + 1, auctions[i].item_id, auctions[i].bid_amount, auctions[i].time_left);
    }

    printf("Bidding has started!\n");
    printf("Enter the auction number you want to bid on: ");
    int auction_number;
    scanf("%d", &auction_number);

    if (auction_number >= 1 && auction_number <= 10) {
        int new_bid;
        printf("Enter your bid: ");
        scanf("%d", &new_bid);

        if (new_bid > auctions[auction_number - 1].highest_bid) {
            auctions[auction_number - 1].highest_bid = new_bid;
            auctions[auction_number - 1].time_left = rand() % 60 + 1;
            printf("You have won the auction!\n");
        } else {
            printf("Sorry, you have been outbid.\n");
        }
    } else {
        printf("Invalid auction number.\n");
    }

    printf("Auction %d: Item ID - %d, Bid Amount - %d, Time Left - %d\n", auction_number, auctions[auction_number - 1].item_id, auctions[auction_number - 1].bid_amount, auctions[auction_number - 1].time_left);

    free(auctions);

    return 0;
}