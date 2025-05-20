//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct _item {
  char *name;
  int price;
} item;

typedef struct _bid {
  char *name;
  int price;
} bid;

item items[MAX_ITEMS];
int num_items = 0;

bid bids[MAX_ITEMS];
int num_bids = 0;

void add_item(char *name, int price)
{
  if (num_items >= MAX_ITEMS) {
    printf("Error: Too many items.\n");
    return;
  }

  items[num_items].name = strdup(name);
  items[num_items].price = price;
  num_items++;
}

void add_bid(char *name, int price)
{
  if (num_bids >= MAX_ITEMS) {
    printf("Error: Too many bids.\n");
    return;
  }

  bids[num_bids].name = strdup(name);
  bids[num_bids].price = price;
  num_bids++;
}

void print_items()
{
  for (int i = 0; i < num_items; i++) {
    printf("%s %d\n", items[i].name, items[i].price);
  }
}

void print_bids()
{
  for (int i = 0; i < num_bids; i++) {
    printf("%s %d\n", bids[i].name, bids[i].price);
  }
}

int main()
{
  add_item("Item 1", 10);
  add_item("Item 2", 20);
  add_item("Item 3", 30);

  add_bid("Bidder 1", 15);
  add_bid("Bidder 2", 25);
  add_bid("Bidder 3", 35);

  print_items();
  printf("\n");
  print_bids();

  return 0;
}