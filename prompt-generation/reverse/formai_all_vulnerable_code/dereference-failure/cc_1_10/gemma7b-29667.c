//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

struct Bid {
    char name[20];
    int amount;
    struct Bid* next;
};

struct Auction {
    struct Bid* head;
    int current_price;
    int reserve_price;
    char item_name[50];
    struct Auction* next;
};

void add_bid(struct Auction* auction, char* name, int amount) {
    struct Bid* new_bid = malloc(sizeof(struct Bid));
    strcpy(new_bid->name, name);
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
}

void start_auction(struct Auction* auction) {
    printf("Auction for item: %s\n", auction->item_name);
    printf("Current price: $%d\n", auction->current_price);
    printf("Reserve price: $%d\n", auction->reserve_price);

    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    printf("Enter your bid: $");
    int amount;
    scanf("%d", &amount);

    add_bid(auction, name, amount);

    printf("Your bid has been added. The current highest bid is $%d.\n", auction->head->amount);
}

int main() {
    struct Auction* auction = malloc(sizeof(struct Auction));
    auction->head = NULL;
    auction->current_price = 0;
    auction->reserve_price = 100;
    strcpy(auction->item_name, "A rare painting");

    start_auction(auction);

    return 0;
}