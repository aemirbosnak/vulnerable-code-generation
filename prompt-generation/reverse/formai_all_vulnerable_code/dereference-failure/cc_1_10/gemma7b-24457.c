//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BID 10000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
};

struct Item {
  char name[50];
  int reservePrice;
  struct Bidder* highestBidder;
  struct Item* next;
};

void insertBidder(struct Bidder** head, char* name, int bid) {
  struct Bidder* newNode = malloc(sizeof(struct Bidder));
  strcpy(newNode->name, name);
  newNode->bid = bid;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void insertItem(struct Item** head, char* name, int reservePrice) {
  struct Item* newNode = malloc(sizeof(struct Item));
  strcpy(newNode->name, name);
  newNode->reservePrice = reservePrice;
  newNode->highestBidder = NULL;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int main() {
  struct Bidder* head = NULL;
  struct Item* itemHead = NULL;

  insertBidder(&head, "John Doe", 5000);
  insertBidder(&head, "Jane Doe", 6000);
  insertBidder(&head, "Peter Pan", 7000);

  insertItem(&itemHead, "A Diamond Ring", 10000);
  insertItem(&itemHead, "A Gold Watch", 8000);

  // Bidding starts!
  printf("Enter your name: ");
  char bidderName[20];
  scanf("%s", bidderName);

  printf("Enter your bid: ");
  int bidAmount;
  scanf("%d", &bidAmount);

  struct Bidder* currentBidder = head;
  while (currentBidder) {
    if (strcmp(currentBidder->name, bidderName) == 0) {
      if (currentBidder->bid > bidAmount) {
        printf("Sorry, your bid is not high enough.\n");
      } else {
        printf("Congratulations, you have won the auction!\n");
      }
      break;
    }
    currentBidder = currentBidder->next;
  }

  return 0;
}