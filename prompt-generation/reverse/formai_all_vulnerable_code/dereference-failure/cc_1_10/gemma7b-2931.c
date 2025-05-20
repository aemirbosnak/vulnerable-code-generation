//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Bid {
  int bidder_id;
  int amount;
  struct Bid* next;
} Bid;

Bid* insert_bid(Bid* head, int bidder_id, int amount) {
  Bid* new_bid = (Bid*)malloc(sizeof(Bid));
  new_bid->bidder_id = bidder_id;
  new_bid->amount = amount;
  new_bid->next = NULL;

  if (head == NULL) {
    head = new_bid;
  } else {
    Bid* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_bid;
  }

  return head;
}

void print_bids(Bid* head) {
  printf("Bids:\n");
  while (head) {
    printf("  - bidder_id: %d, amount: %d\n", head->bidder_id, head->amount);
    head = head->next;
  }
}

int main() {
  Bid* head = NULL;

  // Insert bids
  insert_bid(head, 1, 10);
  insert_bid(head, 2, 12);
  insert_bid(head, 3, 14);
  insert_bid(head, 4, 16);

  // Print bids
  print_bids(head);

  return 0;
}