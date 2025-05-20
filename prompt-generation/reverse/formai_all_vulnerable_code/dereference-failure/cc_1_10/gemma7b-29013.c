//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int starting_bid;
  int current_bid;
  struct Item *next;
} Item;

Item *auction_head = NULL;

void add_item(char *name, int starting_bid) {
  Item *new_item = malloc(sizeof(Item));
  strcpy(new_item->name, name);
  new_item->starting_bid = starting_bid;
  new_item->current_bid = starting_bid;
  new_item->next = auction_head;
  auction_head = new_item;
}

void bid(char *name, int amount) {
  Item *current_item = auction_head;
  while (current_item) {
    if (strcmp(current_item->name, name) == 0) {
      if (amount > current_item->current_bid) {
        current_item->current_bid = amount;
        printf("Thank you, %s, your bid of %d has been accepted.\n", name, amount);
      } else {
        printf("Sorry, your bid of %d is not higher than the current bid of %d.\n", amount, current_item->current_bid);
      }
    }
    current_item = current_item->next;
  }
}

void close_auction() {
  Item *current_item = auction_head;
  while (current_item) {
    printf("Item: %s, Final Bid: %d\n", current_item->name, current_item->current_bid);
    current_item = current_item->next;
  }
}

int main() {
  add_item("Painting", 50);
  add_item("Sculpture", 20);
  add_item("Antique clock", 100);

  bid("John Doe", 60);
  bid("Jane Doe", 40);
  bid("John Doe", 70);

  close_auction();

  return 0;
}