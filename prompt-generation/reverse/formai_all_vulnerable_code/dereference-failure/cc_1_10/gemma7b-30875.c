//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char *name;
    int starting_bid;
    int current_bid;
    struct Auction *next;
} Auction;

void create_auction(Auction **head, char *name, int starting_bid) {
    Auction *new_auction = malloc(sizeof(Auction));
    new_auction->name = strdup(name);
    new_auction->starting_bid = starting_bid;
    new_auction->current_bid = starting_bid;
    new_auction->next = NULL;

    if (*head == NULL) {
        *head = new_auction;
    } else {
        (*head)->next = new_auction;
    }
}

void place_bid(Auction *auction, int bid) {
    if (bid > auction->current_bid) {
        auction->current_bid = bid;
    }
}

void print_auctions(Auction *head) {
    while (head) {
        printf("%s: %d, Current Bid: %d\n", head->name, head->starting_bid, head->current_bid);
        head = head->next;
    }
}

int main() {
    Auction *head = NULL;

    create_auction(&head, "Laptop", 1000);
    create_auction(&head, "Phone", 800);
    create_auction(&head, "TV", 600);

    place_bid(head->next, 1200);
    place_bid(head, 1100);

    print_auctions(head);

    return 0;
}