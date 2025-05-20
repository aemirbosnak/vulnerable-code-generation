//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: authentic
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

Auction* create_auction(char* name, int starting_bid, int reserve_price) {
    Auction* new_auction = (Auction*)malloc(sizeof(Auction));
    strcpy(new_auction->name, name);
    new_auction->starting_bid = starting_bid;
    new_auction->reserve_price = reserve_price;
    new_auction->current_bid = starting_bid;
    new_auction->next = NULL;
    return new_auction;
}

void add_auction(Auction** head, char* name, int starting_bid, int reserve_price) {
    Auction* new_auction = create_auction(name, starting_bid, reserve_price);
    if (*head == NULL) {
        *head = new_auction;
    } else {
        (*head)->next = new_auction;
        *head = new_auction;
    }
}

void print_auctions(Auction* head) {
    while (head) {
        printf("%s: Starting Bid %d, Reserve Price %d, Current Bid %d\n", head->name, head->starting_bid, head->reserve_price, head->current_bid);
        head = head->next;
    }
}

int main() {
    Auction* auctions = NULL;
    add_auction(&auctions, "Painting", 50, 100);
    add_auction(&auctions, "Sculpture", 20, 50);
    add_auction(&auctions, "Jewelry", 30, 70);

    print_auctions(auctions);

    return 0;
}