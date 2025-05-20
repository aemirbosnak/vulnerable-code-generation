//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
};

struct Item {
    char name[20];
    int reservePrice;
    struct Bidder* highestBidder;
    struct Item* next;
};

void insertBidder(struct Bidder** head, char* name, int bid) {
    struct Bidder* newNode = (struct Bidder*)malloc(sizeof(struct Bidder));
    strcpy(newNode->name, name);
    newNode->bid = bid;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertItem(struct Item** head, char* name, int reservePrice) {
    struct Item* newNode = (struct Item*)malloc(sizeof(struct Item));
    strcpy(newNode->name, name);
    newNode->reservePrice = reservePrice;
    newNode->highestBidder = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {
    struct Bidder* headBidder = NULL;
    struct Item* headItem = NULL;

    insertBidder(&headBidder, "John Doe", 5000);
    insertBidder(&headBidder, "Jane Doe", 4000);
    insertBidder(&headBidder, "Peter Pan", 3000);

    insertItem(&headItem, "Diamond Ring", 10000);
    insertItem(&headItem, "Gold Watch", 8000);
    insertItem(&headItem, "Silver Necklace", 6000);

    // Start the auction
    time_t start = time(NULL);
    time_t end = start + 60;

    while (time(NULL) < end) {
        // Get the current highest bid for each item
        for (struct Item* item = headItem; item; item) {
            int highestBid = 0;
            for (struct Bidder* bidder = headBidder; bidder; bidder) {
                if (bidder->bid > highestBid && bidder->name != item->highestBidder) {
                    highestBid = bidder->bid;
                    item->highestBidder = bidder;
                }
            }

            // If the highest bid is greater than the reserve price, the item is sold
            if (highestBid > item->reservePrice) {
                printf("Item: %s sold to %s for %d\n", item->name, item->highestBidder->name, highestBid);
            }
        }

        // Sleep for 1 second
        sleep(1);
    }

    // End the auction
    printf("The auction is complete.\n");

    return 0;
}