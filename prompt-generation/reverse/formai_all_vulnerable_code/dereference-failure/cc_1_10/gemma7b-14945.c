//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char name[20];
    int start_price;
    int reserve_price;
    int current_bid;
    struct Auction* next;
} Auction;

void create_auction(Auction** head) {
    *head = malloc(sizeof(Auction));
    (*head)->next = NULL;
}

void add_auction(Auction** head, char* name, int start_price, int reserve_price) {
    Auction* new_auction = malloc(sizeof(Auction));
    strcpy(new_auction->name, name);
    new_auction->start_price = start_price;
    new_auction->reserve_price = reserve_price;
    new_auction->current_bid = 0;
    new_auction->next = NULL;

    if (*head == NULL) {
        *head = new_auction;
    } else {
        (*head)->next = new_auction;
    }
}

void start_auction(Auction* auction) {
    printf("Auction: %s\n", auction->name);
    printf("Start Price: $%d\n", auction->start_price);
    printf("Reserve Price: $%d\n", auction->reserve_price);
    printf("Current Bid: $%d\n", auction->current_bid);

    int bid_amount;
    printf("Enter your bid: ");
    scanf("%d", &bid_amount);

    if (bid_amount > auction->current_bid) {
        auction->current_bid = bid_amount;
        printf("Your bid has been accepted. Current bid: $%d\n", auction->current_bid);
    } else {
        printf("Your bid is not high enough. Current bid: $%d\n", auction->current_bid);
    }
}

int main() {
    Auction* auctions = NULL;
    create_auction(&auctions);

    add_auction(&auctions, "Painting", 50, 75);
    add_auction(&auctions, "Sculpture", 25, 40);
    add_auction(&auctions, "Jewelry", 75, 100);

    start_auction(auctions);

    return 0;
}