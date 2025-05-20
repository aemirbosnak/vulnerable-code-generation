//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure of a bid
typedef struct Bid {
    char *name;
    int amount;
    struct Bid *next;
} Bid;

// Function to insert a bid into a linked list
void insertBid(Bid **head, char *name, int amount) {
    Bid *newBid = malloc(sizeof(Bid));
    newBid->name = strdup(name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

// Function to compare two bids
int compareBids(Bid *bid1, Bid *bid2) {
    return bid1->amount - bid2->amount;
}

// Function to auction an item
void auctionItem(Bid **head) {
    // Get the highest bid
    Bid *highestBid = head;
    while (highestBid->next) {
        highestBid = highestBid->next;
    }

    // Print the highest bid
    printf("The highest bid is: %s for %d\n", highestBid->name, highestBid->amount);
}

int main() {
    // Create a linked list of bids
    Bid *head = NULL;

    // Insert some bids
    insertBid(&head, "John Doe", 100);
    insertBid(&head, "Jane Doe", 120);
    insertBid(&head, "Bill Smith", 110);

    // Auction the item
    auctionItem(&head);

    return 0;
}