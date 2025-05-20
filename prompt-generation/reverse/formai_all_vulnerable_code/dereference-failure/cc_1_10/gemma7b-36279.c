//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char name[20];
    int starting_bid;
    int reserve_price;
    int current_bid;
    struct Auction* next;
} Auction;

void create_auction(Auction** head) {
    *head = malloc(sizeof(Auction));
    (*head)->next = NULL;
}

void add_auction(Auction** head, char* name, int starting_bid, int reserve_price) {
    Auction* new_auction = malloc(sizeof(Auction));
    strcpy(new_auction->name, name);
    new_auction->starting_bid = starting_bid;
    new_auction->reserve_price = reserve_price;
    new_auction->current_bid = starting_bid;
    new_auction->next = NULL;

    if (*head == NULL) {
        *head = new_auction;
    } else {
        (*head)->next = new_auction;
    }
}

void bid(Auction* auction, int bid) {
    if (bid > auction->current_bid) {
        auction->current_bid = bid;
    }
}

void print_auctions(Auction* head) {
    while (head) {
        printf("Name: %s, Starting Bid: %d, Reserve Price: %d, Current Bid: %d\n", head->name, head->starting_bid, head->reserve_price, head->current_bid);
        head = head->next;
    }
}

int main() {
    Auction* auctions = NULL;

    create_auction(&auctions);
    add_auction(&auctions, "Phone", 500, 700);
    add_auction(&auctions, "Laptop", 700, 1000);
    add_auction(&auctions, "Watch", 300, 500);

    print_auctions(auctions);

    bid(auctions->next, 800);
    bid(auctions->next->next, 900);

    print_auctions(auctions);

    return 0;
}