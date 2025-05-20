//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a bid
typedef struct Bid {
    char name[20];
    int amount;
    struct Bid* next;
} Bid;

// Function to insert a bid into a linked list
void insertBid(Bid** head, char* name, int amount) {
    Bid* newBid = malloc(sizeof(Bid));
    strcpy(newBid->name, name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

// Function to compare bids
int compareBids(Bid* a, Bid* b) {
    return a->amount - b->amount;
}

// Function to conduct the auction
void conductAuction(Bid** head) {
    // Get the highest bid
    Bid* highestBid = head;
    while (highestBid->next) {
        highestBid = highestBid->next;
    }

    // Print the winner
    printf("The winner is: %s\n", highestBid->name);

    // Print the winning bid
    printf("The winning bid is: %d\n", highestBid->amount);
}

int main() {
    // Create a linked list of bids
    Bid* head = NULL;

    // Insert some bids
    insertBid(&head, "John Doe", 100);
    insertBid(&head, "Jane Doe", 120);
    insertBid(&head, "Bill Smith", 110);

    // Conduct the auction
    conductAuction(&head);

    return 0;
}