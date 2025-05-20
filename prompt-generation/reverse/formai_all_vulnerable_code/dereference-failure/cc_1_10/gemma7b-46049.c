//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
    char name[50];
    int bid;
    struct Bidder *next;
};

struct Auction {
    char item_name[50];
    int reserve_price;
    struct Bidder *highest_bidder;
    struct Auction *next;
};

void insert_bidder(struct Bidder **head, char *name, int bid) {
    struct Bidder *new_bidder = malloc(sizeof(struct Bidder));
    strcpy(new_bidder->name, name);
    new_bidder->bid = bid;
    new_bidder->next = NULL;

    if (*head == NULL) {
        *head = new_bidder;
    } else {
        (*head)->next = new_bidder;
    }
}

void insert_auction(struct Auction **head, char *item_name, int reserve_price) {
    struct Auction *new_auction = malloc(sizeof(struct Auction));
    strcpy(new_auction->item_name, item_name);
    new_auction->reserve_price = reserve_price;
    new_auction->highest_bidder = NULL;
    new_auction->next = NULL;

    if (*head == NULL) {
        *head = new_auction;
    } else {
        (*head)->next = new_auction;
    }
}

int main() {
    struct Bidder *head = NULL;
    struct Auction *head_auction = NULL;

    insert_bidder(&head, "John Doe", 5000);
    insert_bidder(&head, "Jane Doe", 6000);
    insert_bidder(&head, "Mike Smith", 7000);

    insert_auction(&head_auction, "Laptop", 8000);
    insert_auction(&head_auction, "Smartphone", 9000);

    srand(time(NULL));

    // Bidding starts
    for (int i = 0; i < 10; i++) {
        int random_bid = rand() % MAX_BID;
        char *random_bidder = head->name;

        insert_bidder(&head, random_bidder, random_bid);
    }

    // Highest bidder wins
    struct Bidder *winner = head_auction->highest_bidder;

    // Auction results
    printf("Congratulations, %s, you won the auction for %s with a bid of %d.\n", winner->name, head_auction->item_name, winner->bid);

    return 0;
}