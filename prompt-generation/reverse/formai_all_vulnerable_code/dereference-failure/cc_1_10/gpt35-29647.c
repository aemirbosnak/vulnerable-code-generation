//FormAI DATASET v1.0 Category: Digital Auction System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  char item_name[20];
  double min_bid;
  int num_bids;
  double* bids;
} item_t;

int main(int argc, char const *argv[]) {
  int num_items = 5;
  item_t* items = malloc(num_items * sizeof(item_t));

  // Populate items
  strcpy(items[0].item_name, "Football");
  items[0].min_bid = 10.00;
  items[0].num_bids = 0;
  items[0].bids = malloc(sizeof(double));

  strcpy(items[1].item_name, "Guitar");
  items[1].min_bid = 50.00;
  items[1].num_bids = 0;
  items[1].bids = malloc(sizeof(double));

  strcpy(items[2].item_name, "Book");
  items[2].min_bid = 5.00;
  items[2].num_bids = 0;
  items[2].bids = malloc(sizeof(double));

  strcpy(items[3].item_name, "Soccer Ball");
  items[3].min_bid = 15.00;
  items[3].num_bids = 0;
  items[3].bids = malloc(sizeof(double));

  strcpy(items[4].item_name, "Camera");
  items[4].min_bid = 100.00;
  items[4].num_bids = 0;
  items[4].bids = malloc(sizeof(double));

  int item_choice;

  // Display items
  printf("Welcome to the Digital Auction System \n\n");
  printf("Items available for bidding: \n");
  for (int i = 0; i < num_items; ++i) {
    printf("[%d] %s (minimum bid: %.2f)\n", i+1, items[i].item_name, items[i].min_bid);
  }

  // Prompt user to choose an item to bid on
  printf("\nWhich item would you like to bid on? (Enter item number): ");
  scanf("%d", &item_choice);
  getchar(); // Remove newline character

  // Check if item number is valid
  if (item_choice < 1 || item_choice > num_items) {
    printf("\nInvalid item number. Exiting program.\n");
    return 1;
  }

  // Display chosen item and current highest bid (if any)
  item_t chosen_item = items[item_choice-1];
  printf("\nYou have chosen item [%d] %s\n", item_choice, chosen_item.item_name);
  if (chosen_item.num_bids > 0) {
    printf("The current highest bid is %.2f\n", chosen_item.bids[chosen_item.num_bids-1]);
  } else {
    printf("There are no current bids on this item\n");
  }

  // Prompt user to enter their bid
  printf("Enter your bid (minimum bid: %.2f): ", chosen_item.min_bid);
  double bid;
  scanf("%lf", &bid);

  // Check if bid is valid
  if (bid < chosen_item.min_bid) {
    printf("\nYour bid is lower than the minimum bid. Exiting program.\n");
    return 1;
  }

  // Add bid to list of bids for chosen item
  chosen_item.num_bids++;
  chosen_item.bids = realloc(chosen_item.bids, chosen_item.num_bids * sizeof(double));
  chosen_item.bids[chosen_item.num_bids-1] = bid;
  items[item_choice-1] = chosen_item;

  // Display bid information and end program
  printf("\nCongratulations, you are currently the highest bidder on item [%d] %s with a bid of %.2f\n", item_choice, chosen_item.item_name, bid);
  printf("Thank you for using the Digital Auction System\n");

  return 0;
}