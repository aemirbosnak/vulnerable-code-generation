//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 10

// Define the structure of a bidder
typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
} Bidder;

// Function to create a new bidder
Bidder* create_bidder(char* name, int bid) {
    Bidder* new_bidder = (Bidder*)malloc(sizeof(Bidder));
    strcpy(new_bidder->name, name);
    new_bidder->bid = bid;
    new_bidder->next = NULL;
    return new_bidder;
}

// Function to add a bidder to the list
void add_bidder(Bidder* head, Bidder* new_bidder) {
    if (head == NULL) {
        head = new_bidder;
    } else {
        new_bidder->next = head;
        head = new_bidder;
    }
}

// Function to find the winner of the auction
Bidder* find_winner(Bidder* head) {
    Bidder* winner = NULL;
    for (Bidder* current_bidder = head; current_bidder; current_bidder = current_bidder->next) {
        if (winner == NULL || current_bidder->bid > winner->bid) {
            winner = current_bidder;
        }
    }
    return winner;
}

// Main function
int main() {
    // Create a list of bidders
    Bidder* head = NULL;

    // Add some bidders to the list
    add_bidder(head, create_bidder("John Doe", 100));
    add_bidder(head, create_bidder("Jane Doe", 120));
    add_bidder(head, create_bidder("Bill Smith", 130));

    // Find the winner of the auction
    Bidder* winner = find_winner(head);

    // Print the winner of the auction
    printf("The winner of the auction is: %s\n", winner->name);
    printf("The winning bid is: %d\n", winner->bid);

    return 0;
}