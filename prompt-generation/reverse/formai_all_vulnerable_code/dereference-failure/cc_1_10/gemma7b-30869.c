//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10

typedef struct Bid {
  char name[50];
  int amount;
  struct Bid* next;
} Bid;

Bid* createBid(char* name, int amount) {
  Bid* newBid = malloc(sizeof(Bid));
  strcpy(newBid->name, name);
  newBid->amount = amount;
  newBid->next = NULL;
  return newBid;
}

void addBid(Bid* head, Bid* newBid) {
  if (head == NULL) {
    head = newBid;
  } else {
    newBid->next = head;
    head = newBid;
  }
}

int main() {
  Bid* head = NULL;
  char name[50];
  int amount;

  // Get the item name and number of bids
  printf("Enter item name: ");
  scanf("%s", name);

  printf("Enter number of bids: ");
  int numBids;
  scanf("%d", &numBids);

  // Create bids
  for (int i = 0; i < numBids; i++) {
    printf("Enter bidder name: ");
    scanf("%s", name);

    printf("Enter bid amount: ");
    scanf("%d", &amount);

    addBid(head, createBid(name, amount));
  }

  // Print bids
  printf("Bids for item '%s':", name);
  for (Bid* currentBid = head; currentBid != NULL; currentBid = currentBid->next) {
    printf("\n- %s: %d", currentBid->name, currentBid->amount);
  }

  return 0;
}