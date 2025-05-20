//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

struct Bid {
    char name[50];
    int amount;
    struct Bid* next;
};

void addBid(struct Bid** head, char* name, int amount) {
    struct Bid* newBid = malloc(sizeof(struct Bid));
    strcpy(newBid->name, name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

void printBids(struct Bid* head) {
    struct Bid* current = head;
    while (current) {
        printf("%s: %d\n", current->name, current->amount);
        current = current->next;
    }
}

int main() {
    struct Bid* head = NULL;

    // Add bids
    addBid(&head, "John Doe", 500);
    addBid(&head, "Jane Doe", 600);
    addBid(&head, "Bob Smith", 700);

    // Print bids
    printBids(head);

    // Get the highest bid
    struct Bid* highestBid = head;
    while (highestBid->next) {
        highestBid = highestBid->next;
    }

    // Print the highest bid
    printf("The highest bid is: %s: %d\n", highestBid->name, highestBid->amount);

    return 0;
}