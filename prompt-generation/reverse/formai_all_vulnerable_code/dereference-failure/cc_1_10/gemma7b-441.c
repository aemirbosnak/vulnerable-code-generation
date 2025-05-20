//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bid {
  int user_id;
  int amount;
  struct Bid* next;
} Bid;

void insert_bid(Bid* head, int user_id, int amount) {
  Bid* new_bid = malloc(sizeof(Bid));
  new_bid->user_id = user_id;
  new_bid->amount = amount;
  new_bid->next = NULL;

  if (head == NULL) {
    head = new_bid;
  } else {
    new_bid->next = head;
    head = new_bid;
  }
}

int get_highest_bid(Bid* head) {
  if (head == NULL) {
    return 0;
  }

  Bid* current_bid = head;
  int highest_bid = current_bid->amount;

  while (current_bid->next) {
    current_bid = current_bid->next;
    if (current_bid->amount > highest_bid) {
      highest_bid = current_bid->amount;
    }
  }

  return highest_bid;
}

int main() {
  Bid* head = NULL;

  // Insert some bids
  insert_bid(head, 1, 500);
  insert_bid(head, 2, 600);
  insert_bid(head, 3, 700);
  insert_bid(head, 4, 800);

  // Get the highest bid
  int highest_bid = get_highest_bid(head);

  // Print the highest bid
  printf("The highest bid is: %d\n", highest_bid);

  return 0;
}