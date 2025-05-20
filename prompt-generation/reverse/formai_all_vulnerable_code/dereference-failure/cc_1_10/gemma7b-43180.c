//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the auction item structure
typedef struct Item {
  char name[20];
  int starting_bid;
  int reserve_price;
  int current_bid;
  struct Item* next;
} Item;

// Create a linked list of auction items
Item* head = NULL;

// Function to add an item to the auction list
void addItem(char* name, int starting_bid, int reserve_price) {
  Item* new_item = (Item*)malloc(sizeof(Item));
  strcpy(new_item->name, name);
  new_item->starting_bid = starting_bid;
  new_item->reserve_price = reserve_price;
  new_item->current_bid = starting_bid;
  new_item->next = NULL;

  if (head == NULL) {
    head = new_item;
  } else {
    Item* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_item;
  }
}

// Function to bid on an item
void bid(char* item_name, int bid_amount) {
  Item* item = head;
  while (item) {
    if (strcmp(item->name, item_name) == 0) {
      if (bid_amount > item->current_bid) {
        item->current_bid = bid_amount;
      }
    }
    item = item->next;
  }
}

// Function to start the auction
void startAuction() {
  time_t start_time = time(NULL);
  time_t end_time = start_time + 60;

  while (time(NULL) < end_time) {
    printf("Current time: %s\n",ctime(time(NULL)));
    printf("Auction is ongoing... Please wait...\n");
    sleep(1);
  }

  Item* item = head;
  while (item) {
    if (item->current_bid == item->reserve_price) {
      printf("Congratulations! You won the auction for %s at %d.\n", item->name, item->current_bid);
    } else {
      printf("Sorry, you did not win the auction for %s. The winning bid was %d.\n", item->name, item->current_bid);
    }
    item = item->next;
  }
}

int main() {
  addItem("Gold necklace", 100, 150);
  addItem("Diamond ring", 200, 250);
  addItem("Luxury watch", 300, 350);

  startAuction();

  return 0;
}