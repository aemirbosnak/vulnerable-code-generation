//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Bid
typedef struct Bid {
    char bidder_name[20];
    int bid_amount;
    struct Bid* next;
} Bid;

// Function to insert a bid into a linked list
void insert_bid(Bid** head, char* bidder_name, int bid_amount) {
    Bid* new_bid = (Bid*)malloc(sizeof(Bid));
    strcpy(new_bid->bidder_name, bidder_name);
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (*head == NULL) {
        *head = new_bid;
    } else {
        (*head)->next = new_bid;
    }
}

// Function to find the highest bid
int find_highest_bid(Bid* head) {
    int highest_bid = 0;
    Bid* current_bid = head;

    while (current_bid) {
        if (current_bid->bid_amount > highest_bid) {
            highest_bid = current_bid->bid_amount;
        }
        current_bid = current_bid->next;
    }

    return highest_bid;
}

// Function to display the bids
void display_bids(Bid* head) {
    Bid* current_bid = head;

    while (current_bid) {
        printf("Bidder: %s, Bid Amount: %d\n", current_bid->bidder_name, current_bid->bid_amount);
        current_bid = current_bid->next;
    }
}

int main() {
    // Create a linked list of bids
    Bid* head = NULL;

    // Insert some bids
    insert_bid(&head, "John Doe", 100);
    insert_bid(&head, "Jane Doe", 120);
    insert_bid(&head, "Bill Smith", 110);

    // Find the highest bid
    int highest_bid = find_highest_bid(head);

    // Display the bids
    display_bids(head);

    // Print the highest bid
    printf("The highest bid is: %d\n", highest_bid);

    return 0;
}