//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AuctionSeller {
    char name[50];
    float minimum_price;
    float current_price;
    int num_bids;
} AuctionSeller;

typedef struct AuctionBuyer {
    char name[50];
    float max_price;
    float current_bid;
} AuctionBuyer;

int main() {
    int num_sellers;
    printf("Welcome to the Mind-Bending Digital Auction System!\n");
    printf("Please enter the number of sellers: ");
    scanf("%d", &num_sellers);

    AuctionSeller sellers[num_sellers];

    for (int i = 0; i < num_sellers; i++) {
        printf("Seller %d, please enter your name: ", i+1);
        scanf("%s", sellers[i].name);
        printf("Please enter your minimum price: ");
        scanf("%f", &sellers[i].minimum_price);
        sellers[i].current_price = sellers[i].minimum_price;
        sellers[i].num_bids = 0;
    }

    int num_buyers;
    printf("\nHow many buyers do we have today? ");
    scanf("%d", &num_buyers);

    AuctionBuyer buyers[num_buyers];

    for (int i = 0; i < num_buyers; i++) {
        printf("Buyer %d, please enter your name: ", i+1);
        scanf("%s", buyers[i].name);
        printf("Please enter your maximum bid: ");
        scanf("%f", &buyers[i].max_price);
        buyers[i].current_bid = 0;
    }

    printf("\nLet the bidding commence!\n");
    printf("**************************\n");

    while (1) {
        int num_bids = 0;

        for (int i = 0; i < num_buyers; i++) {
            if (buyers[i].max_price <= buyers[i].current_bid) {
                continue;
            }
            printf("%s, please enter your bid for the current item(s): ", buyers[i].name);
            float bid_amount;
            scanf("%f", &bid_amount);
            if (bid_amount <= buyers[i].current_bid) {
                printf("Sorry %s, your current bid is lower than your previous bid. Please try again.\n", buyers[i].name);
                continue;
            }
            int winner = -1;
            float winning_bid = 0;
            for (int j = 0; j < num_sellers; j++) {
                if (sellers[j].num_bids >= i+1) {
                    continue;
                }
                if (bid_amount >= sellers[j].current_price && bid_amount >= sellers[j].minimum_price) {
                    if (sellers[j].current_price > winning_bid) {
                        winner = j;
                        winning_bid = sellers[j].current_price;
                    }
                }
            }
            if (winner == -1) {
                printf("Sorry %s, your bid is not high enough for any item(s) currently on auction.\n", buyers[i].name);
                continue;
            }
            buyers[i].current_bid = bid_amount;
            sellers[winner].current_price = bid_amount;
            sellers[winner].num_bids = i+1;
            num_bids++;
            printf("Congratulations %s, you are the current highest bidder for %s's item(s) with a bid of $%.2f!\n", buyers[i].name, sellers[winner].name, bid_amount);
        }

        if (num_bids == 0) {
            break;
        }
    }

    printf("\n\n\nAll auctions have finished!\n");

    for (int i = 0; i < num_sellers; i++) {
        printf("\n\n\nCongratulations %s,\n", sellers[i].name);
        printf("You sold your item(s) for $%.2f to the following buyers:\n", sellers[i].current_price);
        for (int j = 0; j < num_buyers; j++) {
            if (sellers[i].num_bids == j+1) {
                printf("- %s for $%.2f\n", buyers[j].name, buyers[j].current_bid);
            } else {
                printf("- No buyer found for bid #%d\n", j+1);
            }
        }
    }

    printf("\n\n\nThank you for using Mind-Bending Digital Auction System!\n");

    return 0;
}