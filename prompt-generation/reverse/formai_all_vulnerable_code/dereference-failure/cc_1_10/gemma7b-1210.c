//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bid {
    int bidder_id;
    int bid_amount;
    struct Bid* next;
};

struct Item {
    char item_name[20];
    int reserve_price;
    struct Bid* highest_bid;
};

int main() {
    struct Item item1 = {"Laptop", 500, NULL};
    struct Item item2 = {"Smartphone", 300, NULL};
    struct Item item3 = {"Watch", 700, NULL};

    struct Bid* head = NULL;

    // Bidding starts
    int bid_amount;
    char bidder_name[20];

    printf("Enter bidder name: ");
    scanf("%s", bidder_name);

    printf("Enter bid amount: ");
    scanf("%d", &bid_amount);

    struct Bid* new_bid = malloc(sizeof(struct Bid));
    new_bid->bidder_id = 1;
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (head == NULL) {
        head = new_bid;
    } else {
        struct Bid* current_bid = head;
        while (current_bid->next != NULL) {
            current_bid = current_bid->next;
        }
        current_bid->next = new_bid;
    }

    // Auction ends

    // Print highest bid
    printf("Highest bid for item1: %d", item1.highest_bid->bid_amount);

    // Print highest bid for item2:
    printf("Highest bid for item2: %d", item2.highest_bid->bid_amount);

    // Print highest bid for item3:
    printf("Highest bid for item3: %d", item3.highest_bid->bid_amount);

    return 0;
}