//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

typedef struct Bid {
    char bidder[50];
    int bid_amount;
    struct Bid* next;
} Bid;

Bid* insert_bid(Bid* head, char* bidder, int bid_amount) {
    Bid* new_bid = (Bid*)malloc(sizeof(Bid));
    strcpy(new_bid->bidder, bidder);
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (head == NULL) {
        head = new_bid;
    } else {
        head->next = new_bid;
    }

    return head;
}

int main() {

    // Create two rival factions
    Bid* faction_a = NULL;
    Bid* faction_b = NULL;

    // Auction item
    char item_name[] = "Diamond Ring";
    int reserve_price = 5000;

    // Bidding begins
    printf("The auction for the %s begins!\n", item_name);

    // Loop until the reserve price is met or a bidding war occurs
    while (faction_a->bid_amount < reserve_price && faction_b->bid_amount < reserve_price) {
        // Get the bidder's name and bid amount
        char bidder_name[50];
        int bid_amount;

        printf("Enter your name: ");
        scanf("%s", bidder_name);

        printf("Enter your bid amount: ");
        scanf("%d", &bid_amount);

        // Insert the bid into the respective faction
        insert_bid(faction_a, bidder_name, bid_amount);
        insert_bid(faction_b, bidder_name, bid_amount);

        // Update the highest bid
        if (faction_a->bid_amount > faction_b->bid_amount) {
            printf("Faction A has the highest bid!\n");
        } else if (faction_b->bid_amount > faction_a->bid_amount) {
            printf("Faction B has the highest bid!\n");
        } else {
            printf("The bids are equal.\n");
        }
    }

    // The auction ends
    printf("The auction for the %s has ended. The winning bidder is: ", item_name);

    // Print the winner's name and the final price
    if (faction_a->bid_amount > faction_b->bid_amount) {
        printf("%s with a bid of %d.\n", faction_a->bidder, faction_a->bid_amount);
        printf("The final price is %d.\n", faction_a->bid_amount);
    } else if (faction_b->bid_amount > faction_a->bid_amount) {
        printf("%s with a bid of %d.\n", faction_b->bidder, faction_b->bid_amount);
        printf("The final price is %d.\n", faction_b->bid_amount);
    } else {
        printf("There was no winner.\n");
    }

    return 0;
}