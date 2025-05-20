//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int price;
} Item;

typedef struct {
    Item *items;
    int num_items;
} Auction;

Auction *create_auction() {
    Auction *auction = malloc(sizeof(Auction));
    auction->items = malloc(sizeof(Item));
    auction->num_items = 0;
    return auction;
}

void add_item(Auction *auction, char *name, int price) {
    auction->items = realloc(auction->items, (auction->num_items + 1) * sizeof(Item));
    strcpy(auction->items[auction->num_items].name, name);
    auction->items[auction->num_items].price = price;
    auction->num_items++;
}

void print_auction(Auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        printf("%s: $%d\n", auction->items[i].name, auction->items[i].price);
    }
}

void start_auction(Auction *auction) {
    int highest_bid = 0;
    char *highest_bidder = NULL;
    while (1) {
        char *bidder = malloc(sizeof(char) * 255);
        int bid;
        printf("Enter your name: ");
        scanf("%s", bidder);
        printf("Enter your bid: ");
        scanf("%d", &bid);
        if (bid > highest_bid) {
            highest_bid = bid;
            highest_bidder = bidder;
        }
        printf("Current highest bid: $%d by %s\n", highest_bid, highest_bidder);
        printf("Do you want to continue bidding? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }
    printf("The auction is over! The winner is %s with a bid of $%d.\n", highest_bidder, highest_bid);
}

int main() {
    Auction *auction = create_auction();
    add_item(auction, "Mona Lisa", 1000000);
    add_item(auction, "Starry Night", 500000);
    add_item(auction, "The Scream", 750000);
    print_auction(auction);
    start_auction(auction);
    return 0;
}