//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
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

// Function to insert a bidder into the list
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

// Function to find the highest bidder
Bidder* findHighestBidder(Bidder* head) {
  Bidder* highestBidder = head;
  while (highestBidder->next) {
    if (highestBidder->bid > highestBidder->next->bid) {
      highestBidder = highestBidder->next;
    }
  }
  return highestBidder;
}

int main() {
  // Create a list of bidders
  Bidder* bidders = NULL;

  // Insert some bidders
  insertBidder(&bidders, "Romeo", 10);
  insertBidder(&bidders, "Juliet", 12);
  insertBidder(&bidders, " Mercutio", 14);
  insertBidder(&bidders, "Benvolio", 16);

  // Find the highest bidder
  Bidder* highestBidder = findHighestBidder(bidders);

  // Print the highest bidder
  printf("The highest bidder is: %s with a bid of %d\n", highestBidder->name, highestBidder->bid);

  return 0;
}