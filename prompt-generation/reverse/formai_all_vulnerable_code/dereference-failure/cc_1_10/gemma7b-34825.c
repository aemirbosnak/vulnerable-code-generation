//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
} Bidder;

void addBidder(Bidder** head) {
    Bidder* newBidder = (Bidder*)malloc(sizeof(Bidder));
    printf("Enter your name: ");
    scanf("%s", newBidder->name);
    printf("Enter your bid: ");
    scanf("%d", &newBidder->bid);
    newBidder->next = NULL;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
    }
}

void showBids(Bidder* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->bid);
        head = head->next;
    }
}

int main() {
    Bidder* head = NULL;

    // Bidding loop
    while (1) {
        printf("Enter 'add' to add a bidder or 'show' to see bids: ");
        char command;
        scanf("%c", &command);

        switch (command) {
            case 'a':
                addBidder(&head);
                break;
            case 'show':
                showBids(head);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        // Exit condition
        if (command == 'q') {
            break;
        }
    }

    return 0;
}