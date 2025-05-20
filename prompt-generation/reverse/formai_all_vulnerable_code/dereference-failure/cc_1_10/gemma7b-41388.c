//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure of a bid
typedef struct Bid {
    char name[20];
    int amount;
    struct Bid* next;
} Bid;

// Function to insert a bid into the list
void insertBid(Bid** head, char* name, int amount) {
    Bid* newBid = (Bid*)malloc(sizeof(Bid));
    strcpy(newBid->name, name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

// Function to print the bids
void printBids(Bid* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->amount);
        head = head->next;
    }
}

// Function to start the auction
void startAuction(Bid** head) {
    // Get the current time
    time_t now = time(NULL);

    // Set the auction start time
    time_t startTime = now - 60 * 5;

    // Wait for the auction start time
    while (now < startTime) {
        sleep(1);
        now = time(NULL);
    }

    // Print the bids
    printBids(*head);

    // Find the winner of the auction
    Bid* winner = *head;
    for (Bid* currentBid = *head; currentBid; currentBid = currentBid->next) {
        if (currentBid->amount > winner->amount) {
            winner = currentBid;
        }
    }

    // Announce the winner
    printf("The winner of the auction is: %s\n", winner->name);
    printf("The winning bid is: %d\n", winner->amount);
}

int main() {
    Bid* head = NULL;

    // Insert some bids
    insertBid(&head, "John Doe", 100);
    insertBid(&head, "Jane Doe", 120);
    insertBid(&head, "Bill Smith", 110);

    // Start the auction
    startAuction(&head);

    return 0;
}