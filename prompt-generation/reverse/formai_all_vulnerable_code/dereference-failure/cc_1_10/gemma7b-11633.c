//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID_AMOUNT 10000

typedef struct Bidder {
    char name[256];
    int bid_amount;
    struct Bidder* next;
} Bidder;

typedef struct AuctionItem {
    char item_name[256];
    int reserve_price;
    Bidder* highest_bidder;
    struct AuctionItem* next;
} AuctionItem;

void insertBidder(Bidder** head, char* name, int bid_amount) {
    Bidder* new_bidder = malloc(sizeof(Bidder));
    strcpy(new_bidder->name, name);
    new_bidder->bid_amount = bid_amount;
    new_bidder->next = NULL;

    if (*head == NULL) {
        *head = new_bidder;
    } else {
        (*head)->next = new_bidder;
    }
}

void insertAuctionItem(AuctionItem** head, char* item_name, int reserve_price) {
    AuctionItem* new_item = malloc(sizeof(AuctionItem));
    strcpy(new_item->item_name, item_name);
    new_item->reserve_price = reserve_price;
    new_item->highest_bidder = NULL;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

void auction_process(AuctionItem* item) {
    int current_bid = 0;
    Bidder* highest_bidder = NULL;

    printf("Auction for item: %s\n", item->item_name);
    printf("Reserve price: $%d\n", item->reserve_price);

    while (current_bid < item->reserve_price) {
        printf("Enter your bid: $");
        int bid_amount = atoi(fgets(NULL, 256, stdin));

        insertBidder(&highest_bidder, "John Doe", bid_amount);

        current_bid = bid_amount;
    }

    printf("Congratulations, %s, you won the auction for item: %s!\n", highest_bidder->name, item->item_name);
    printf("Your total bid amount is: $%d\n", highest_bidder->bid_amount);
}

int main() {
    AuctionItem* head = NULL;
    insertAuctionItem(&head, "Laptop", 1000);
    insertAuctionItem(&head, "Smartphone", 800);
    insertAuctionItem(&head, "Watch", 1200);

    auction_process(head->next);

    return 0;
}