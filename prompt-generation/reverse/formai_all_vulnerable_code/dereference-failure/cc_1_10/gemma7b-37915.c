//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

struct Bid {
    char name[50];
    int bid;
    struct Bid *next;
};

void insertBid(struct Bid **head, char *name, int bid) {
    struct Bid *newBid = malloc(sizeof(struct Bid));
    strcpy(newBid->name, name);
    newBid->bid = bid;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

int findHighestBid(struct Bid *head) {
    int highestBid = 0;
    struct Bid *currentBid = head;

    while (currentBid) {
        if (currentBid->bid > highestBid) {
            highestBid = currentBid->bid;
        }
        currentBid = currentBid->next;
    }

    return highestBid;
}

int main() {
    struct Bid *head = NULL;

    insertBid(&head, "John Doe", 500);
    insertBid(&head, "Jane Doe", 600);
    insertBid(&head, "Peter Pan", 700);

    int highestBid = findHighestBid(head);

    printf("The highest bid is: %d\n", highestBid);

    return 0;
}