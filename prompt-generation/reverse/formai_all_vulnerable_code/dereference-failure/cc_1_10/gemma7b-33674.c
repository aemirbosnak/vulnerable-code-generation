//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

struct Bid {
    int bidder_id;
    int amount;
    struct Bid* next;
};

struct Auction {
    struct Bid* head;
    int current_bid;
    int reserve_price;
    time_t start_time;
    time_t end_time;
    int status;
};

void place_bid(struct Auction* auction, int bidder_id, int amount)
{
    struct Bid* new_bid = malloc(sizeof(struct Bid));
    new_bid->bidder_id = bidder_id;
    new_bid->amount = amount;
    new_bid->next = NULL;

    if (auction->head == NULL) {
        auction->head = new_bid;
    } else {
        struct Bid* current_bid = auction->head;
        while (current_bid->next) {
            current_bid = current_bid->next;
        }
        current_bid->next = new_bid;
    }

    auction->current_bid = amount;
}

void check_auction_status(struct Auction* auction)
{
    time_t current_time = time(NULL);

    if (auction->start_time > current_time || current_time > auction->end_time) {
        auction->status = 2;
    } else if (auction->current_bid >= auction->reserve_price) {
        auction->status = 1;
    } else {
        auction->status = 0;
    }
}

int main()
{
    struct Auction* auction = malloc(sizeof(struct Auction));
    auction->head = NULL;
    auction->current_bid = 0;
    auction->reserve_price = 5000;
    auction->start_time = time(NULL) + 60;
    auction->end_time = time(NULL) + 120;
    auction->status = 0;

    place_bid(auction, 1, 6000);
    place_bid(auction, 2, 4000);
    place_bid(auction, 3, 3000);

    check_auction_status(auction);

    switch (auction->status) {
        case 0:
            printf("Auction has not started.\n");
            break;
        case 1:
            printf("Auction completed.\n");
            break;
        case 2:
            printf("Auction ended prematurely.\n");
            break;
    }

    return 0;
}