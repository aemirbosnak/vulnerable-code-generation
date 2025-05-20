//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
};

struct Item {
  char name[50];
  int starting_price;
  struct Bidder* highest_bidder;
  struct Item* next;
};

void add_bidder(struct Bidder** head, char* name, int bid) {
  struct Bidder* new_bidder = malloc(sizeof(struct Bidder));
  strcpy(new_bidder->name, name);
  new_bidder->bid = bid;
  new_bidder->next = NULL;

  if (*head == NULL) {
    *head = new_bidder;
  } else {
    (*head)->next = new_bidder;
  }
}

void add_item(struct Item** head, char* name, int starting_price) {
  struct Item* new_item = malloc(sizeof(struct Item));
  strcpy(new_item->name, name);
  new_item->starting_price = starting_price;
  new_item->highest_bidder = NULL;
  new_item->next = NULL;

  if (*head == NULL) {
    *head = new_item;
  } else {
    (*head)->next = new_item;
  }
}

void bid(struct Item* item, struct Bidder* bidder) {
  if (bidder->bid > item->starting_price && bidder->bid < MAX_BID) {
    item->highest_bidder = bidder;
  }
}

int main() {
  struct Bidder* head_bidder = NULL;
  struct Item* head_item = NULL;

  add_bidder(&head_bidder, "John Doe", 500);
  add_bidder(&head_bidder, "Jane Doe", 400);
  add_bidder(&head_bidder, "Peter Pan", 600);

  add_item(&head_item, "iPhone", 800);
  add_item(&head_item, "Laptop", 700);
  add_item(&head_item, "Car", 900);

  time_t t = time(NULL);
  srand(t);

  for (int i = 0; i < 10; i++) {
    int rand_bid = rand() % MAX_BID;
    struct Bidder* rand_bidder = head_bidder;

    for (int j = 0; j < 3; j++) {
      bid(head_item, rand_bidder);
      rand_bidder = rand_bidder->next;
    }
  }

  for (struct Item* item = head_item; item; item = item->next) {
    printf("Item: %s, Highest Bid: %d, Bidder: %s\n", item->name, item->highest_bidder->bid, item->highest_bidder->name);
  }

  return 0;
}