//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000

struct Bid {
    char name[20];
    int amount;
    struct Bid* next;
};

struct Auction {
    char item_name[50];
    int reserve_price;
    struct Bid* head;
    struct Bid* tail;
    time_t start_time;
    time_t end_time;
};

void create_auction(struct Auction* auction) {
    auction->head = NULL;
    auction->tail = NULL;
    auction->item_name[0] = '\0';
    auction->reserve_price = 0;
    auction->start_time = 0;
    auction->end_time = 0;
}

void add_bid(struct Auction* auction, char* name, int amount) {
    struct Bid* new_bid = malloc(sizeof(struct Bid));
    strcpy(new_bid->name, name);
    new_bid->amount = amount;
    new_bid->next = NULL;

    if (auction->head == NULL) {
        auction->head = new_bid;
        auction->tail = new_bid;
    } else {
        auction->tail->next = new_bid;
        auction->tail = new_bid;
    }
}

void print_bids(struct Auction* auction) {
    struct Bid* current_bid = auction->head;
    printf("Bids for item: %s\n", auction->item_name);
    while (current_bid) {
        printf("%s bidded %d\n", current_bid->name, current_bid->amount);
        current_bid = current_bid->next;
    }
}

int main() {
    struct Auction* auction = malloc(sizeof(struct Auction));
    create_auction(auction);

    // Add some bids
    add_bid(auction, "John Doe", 500);
    add_bid(auction, "Jane Doe", 600);
    add_bid(auction, "Peter Pan", 700);

    // Print the bids
    print_bids(auction);

    return 0;
}