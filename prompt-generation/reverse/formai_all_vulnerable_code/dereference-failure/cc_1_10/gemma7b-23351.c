//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder *next;
};

struct Item {
  char name[20];
  int starting_price;
  struct Bidder *highest_bidder;
  struct Item *next;
};

void insert_bidder(struct Bidder **head, char *name, int bid) {
  struct Bidder *new_bidder = malloc(sizeof(struct Bidder));
  strcpy(new_bidder->name, name);
  new_bidder->bid = bid;
  new_bidder->next = NULL;

  if (*head == NULL) {
    *head = new_bidder;
  } else {
    (*head)->next = new_bidder;
  }
}

void insert_item(struct Item **head, char *name, int starting_price) {
  struct Item *new_item = malloc(sizeof(struct Item));
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

int main() {
  struct Bidder *head_bidder = NULL;
  struct Item *head_item = NULL;

  insert_bidder(&head_bidder, "John Doe", 5000);
  insert_bidder(&head_bidder, "Jane Doe", 4000);
  insert_bidder(&head_bidder, "Bill Smith", 3000);

  insert_item(&head_item, "Car", 10000);
  insert_item(&head_item, "House", 20000);
  insert_item(&head_item, "Electronics", 30000);

  // Start the auction
  time_t start_time = time(NULL);
  time_t end_time = start_time + 300;

  while (time(NULL) < end_time) {
    // Get the highest bid for each item
    for (struct Item *item = head_item; item; item++) {
      struct Bidder *highest_bidder = item->highest_bidder;

      // If there is no highest bidder, or the current bid is higher than the highest bid, update the highest bidder
      if (highest_bidder == NULL || item->highest_bidder->bid < head_bidder->bid) {
        item->highest_bidder = head_bidder;
      }
    }

    // Sleep for 1 second
    sleep(1);
  }

  // End the auction

  // Print the winner of each item
  for (struct Item *item = head_item; item; item++) {
    printf("Winner of item: %s is %s\n", item->name, item->highest_bidder->name);
  }

  return 0;
}