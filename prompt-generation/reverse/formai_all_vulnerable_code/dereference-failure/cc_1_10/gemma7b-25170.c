//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a bid
typedef struct Bid {
    char *name;
    int amount;
    struct Bid *next;
} Bid;

// Function to insert a bid into the linked list
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

// Function to print the bids
void printBids(Bid *head) {
    while (head) {
        printf("%s: %d\n", head->name, head->amount);
        head = head->next;
    }
}

// Function to find the winning bid
Bid *findWinningBid(Bid *head) {
    Bid *winner = NULL;
    int highestBid = 0;

    while (head) {
        if (head->amount > highestBid) {
            highestBid = head->amount;
            winner = head;
        }
        head = head->next;
    }

    return winner;
}

int main() {
    // Create a linked list of bids
    Bid *head = NULL;

    // Insert some bids
    insertBid(&head, "John Doe", 100);
    insertBid(&head, "Jane Doe", 120);
    insertBid(&head, "Bob Smith", 110);

    // Print the bids
    printBids(head);

    // Find the winning bid
    Bid *winner = findWinningBid(head);

    // Print the winning bid
    if (winner) {
        printf("The winning bid is: %s: %d\n", winner->name, winner->amount);
    } else {
        printf("There are no bids.\n");
    }

    return 0;
}