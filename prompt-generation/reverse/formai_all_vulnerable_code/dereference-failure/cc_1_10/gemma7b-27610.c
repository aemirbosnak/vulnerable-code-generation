//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

typedef struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
} Bidder;

void insertBidder(Bidder** head, char* name, int bid) {
  Bidder* newBidder = (Bidder*)malloc(sizeof(Bidder));
  strcpy(newBidder->name, name);
  newBidder->bid = bid;
  newBidder->next = NULL;

  if (*head == NULL) {
    *head = newBidder;
  } else {
    (*head)->next = newBidder;
  }
}

int main() {
  Bidder* head = NULL;

  // Auction items and their starting bids
  char* items[] = {"Painting", "Sculpture", "Jewelry"};
  int startBids[] = {500, 200, 700};

  // Simulate bidders
  insertBidder(&head, "John Doe", 600);
  insertBidder(&head, "Jane Doe", 400);
  insertBidder(&head, "Mike Smith", 800);

  // Start the auction
  for (int i = 0; i < 3; i++) {
    printf("Auction for item: %s\n", items[i]);
    printf("Current highest bid: %d\n", startBids[i]);

    // Bidding loop
    int currentBid = startBids[i];
    while (1) {
      char bidderName[20];
      int newBid;

      printf("Enter your name: ");
      scanf("%s", bidderName);

      printf("Enter your bid: ");
      scanf("%d", &newBid);

      // Validate bid
      if (newBid < currentBid || newBid > MAX_BID) {
        printf("Invalid bid.\n");
      } else {
        insertBidder(&head, bidderName, newBid);

        // Update current highest bid
        currentBid = newBid;

        // Break out of bidding loop
        break;
      }
    }

    // Print the winner
    printf("Congratulations, %s! You won the auction for item: %s for %d.\n", head->name, items[i], currentBid);
  }

  return 0;
}