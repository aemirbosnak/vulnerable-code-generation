//FormAI DATASET v1.0 Category: Digital Auction System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bidder {
    char name[20];
    float max_bid; 
    float current_bid;
    int num_bids;
};

int main(int argc, char* argv[]) {
    printf("Welcome to the Digital Auction System\n");
    // initialize the auction variables
    char auction_item[30];
    float starting_bid;
    float current_bid;
    int num_bidders;
    printf("What is the item being auctioned? ");
    fgets(auction_item, sizeof(auction_item), stdin);
    auction_item[strcspn(auction_item, "\n")] = '\0'; // remove newline character

    printf("What is the starting bid? ");
    scanf("%f", &starting_bid);
    fflush(stdin); // clear input buffer

    printf("How many bidders are participating? ");
    scanf("%d", &num_bidders);

    // initialize the bidders array
    struct bidder bidders[num_bidders];
    for (int i = 0; i < num_bidders; i++) {
        printf("Bidder #%d, what is your name? ", i+1);
        fgets(bidders[i].name, sizeof(bidders[i].name), stdin);
        bidders[i].name[strcspn(bidders[i].name, "\n")] = '\0'; // remove newline character

        printf("Bidder #%d, what is your maximum bid? ", i+1);
        scanf("%f", &bidders[i].max_bid);
        bidders[i].num_bids = 0;
    }

    // start the auction
    printf("The auction for %s has started\n", auction_item);
    printf("The starting bid is $%.2f\n", starting_bid);

    int current_bidder = 0;
    current_bid = starting_bid;

    while (num_bidders > 1) {
        printf("Current bid is $%.2f\n", current_bid);
        printf("Bidder #%d, what is your bid? ", current_bidder+1);
        float next_bid;
        scanf("%f", &next_bid);
        fflush(stdin); // clear input buffer

        if (next_bid <= current_bid) {
            printf("Bid must exceed $%.2f\n", current_bid);
            continue;
        }

        if (next_bid > bidders[current_bidder].max_bid) {
            printf("Bidder #%d is out of the auction\n", current_bidder+1);
            // remove bidder from the array
            for (int i = current_bidder; i < num_bidders - 1; i++) {
                bidders[i] = bidders[i+1];
            }
            num_bidders--;
            continue;
        }

        // update the current bidder's information
        bidders[current_bidder].current_bid = next_bid;
        bidders[current_bidder].num_bids++;

        // go to the next bidder
        current_bidder = (current_bidder + 1) % num_bidders;
        current_bid = next_bid;
    }

    // print the winner
    printf("The winner of the auction for %s is %s with a bid of $%.2f\n", auction_item, bidders[0].name, bidders[0].current_bid);

    // print the bid history
    printf("Bid history:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%s placed %d bids with a maximum bid of $%.2f and a final bid of $%.2f\n", bidders[i].name, bidders[i].num_bids, bidders[i].max_bid, bidders[i].current_bid);
    }

    return 0;
}