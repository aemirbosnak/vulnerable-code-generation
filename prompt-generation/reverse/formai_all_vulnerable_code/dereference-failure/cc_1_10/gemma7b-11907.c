//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

// Structure to store a bidder's information
struct Bidder {
    char name[50];
    int bid;
    struct Bidder *next;
};

// Function to insert a bidder into the bid list
void insertBidder(struct Bidder **head, char *name, int bid) {
    struct Bidder *newBidder = (struct Bidder *)malloc(sizeof(struct Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
    }
}

// Function to find the highest bidder
struct Bidder *findHighestBidder(struct Bidder *head) {
    struct Bidder *highestBidder = NULL;
    int highestBid = 0;

    for (struct Bidder *bidder = head; bidder; bidder = bidder->next) {
        if (bidder->bid > highestBid) {
            highestBidder = bidder;
            highestBid = bidder->bid;
        }
    }

    return highestBidder;
}

// Function to conduct the digital auction
void conductAuction(struct Bidder *head) {
    // Get the current time
    time_t now = time(NULL);

    // Set the auction end time
    time_t endTime = now + 60;

    // Wait for the auction to end
    while (now < endTime) {
        sleep(1);
        now = time(NULL);
    }

    // Find the highest bidder
    struct Bidder *highestBidder = findHighestBidder(head);

    // Announce the highest bidder
    printf("The highest bidder is: %s with a bid of %d.\n", highestBidder->name, highestBidder->bid);
}

int main() {
    // Create a list of bidders
    struct Bidder *head = NULL;

    // Insert bidders
    insertBidder(&head, "John Doe", 5000);
    insertBidder(&head, "Jane Doe", 6000);
    insertBidder(&head, "Peter Pan", 7000);
    insertBidder(&head, "Mary Poppins", 8000);

    // Conduct the auction
    conductAuction(head);

    return 0;
}