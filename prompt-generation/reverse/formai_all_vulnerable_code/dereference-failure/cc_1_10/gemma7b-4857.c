//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bid {
    char name[255];
    int amount;
    struct Bid* next;
} Bid;

void insertBid(Bid* head, char* name, int amount) {
    Bid* newBid = malloc(sizeof(Bid));
    strcpy(newBid->name, name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (head == NULL) {
        head = newBid;
    } else {
        head->next = newBid;
    }
}

void printBids(Bid* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main() {
    Bid* head = NULL;
    char name[255];
    int amount;

    // Simulate some bids
    insertBid(head, "John Doe", 500);
    insertBid(head, "Jane Doe", 600);
    insertBid(head, "Bill Smith", 700);

    // Print the bids
    printBids(head);

    // Get the user's name and amount
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your bid: ");
    scanf("%d", &amount);

    // Insert the user's bid
    insertBid(head, name, amount);

    // Print the updated bids
    printBids(head);

    return 0;
}