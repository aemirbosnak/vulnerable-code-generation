//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char name[50];
    int starting_price;
    int reserve_price;
    int current_price;
    int bids_received;
    struct Auction* next;
} Auction;

void create_auction(Auction** head) {
    *head = malloc(sizeof(Auction));
    (*head)->next = NULL;
    (*head)->name[0] = '\0';
    (*head)->starting_price = 0;
    (*head)->reserve_price = 0;
    (*head)->current_price = 0;
    (*head)->bids_received = 0;
}

void add_bid(Auction* auction, int bid) {
    auction->bids_received++;
    auction->current_price = bid > auction->current_price ? bid : auction->current_price;
}

void close_auction(Auction* auction) {
    free(auction);
}

int main() {
    Auction* head = NULL;
    create_auction(&head);

    // Add auctions
    create_auction(&head);
    strcpy(head->name, "Painting");
    head->starting_price = 100;
    head->reserve_price = 150;

    create_auction(&head);
    strcpy(head->name, "Sculpture");
    head->starting_price = 50;
    head->reserve_price = 75;

    // Place bids
    add_bid(head->next, 120);
    add_bid(head, 130);
    add_bid(head->next, 140);

    // Print auction results
    for (Auction* auction = head; auction; auction = auction->next) {
        printf("Auction: %s\n", auction->name);
        printf("Starting Price: %d\n", auction->starting_price);
        printf("Reserve Price: %d\n", auction->reserve_price);
        printf("Current Price: %d\n", auction->current_price);
        printf("Number of Bids Received: %d\n", auction->bids_received);
        printf("\n");
    }

    // Close auctions
    close_auction(head->next);
    close_auction(head);

    return 0;
}