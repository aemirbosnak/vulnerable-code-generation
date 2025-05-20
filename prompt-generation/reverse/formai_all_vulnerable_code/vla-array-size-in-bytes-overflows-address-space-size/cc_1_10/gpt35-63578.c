//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct item {
  char name[50];
  int starting_bid;
  int current_bid;
  char highest_bidder[50];
};

int main() {
  int num_items;
  char input[50];

  printf("Welcome to the Digital Auction System\n");
  printf("Please enter the number of items to auction: ");
  fgets(input, 50, stdin);
  num_items = atoi(input);

  struct item items[num_items];

  for (int i = 0; i < num_items; i++) {
    printf("\n");
    printf("Please enter the name of item number %d: ", i+1);
    fgets(items[i].name, 50, stdin);

    printf("Please enter the starting bid for %s: ", items[i].name);
    fgets(input, 50, stdin);
    items[i].starting_bid = atoi(input);

    items[i].current_bid = items[i].starting_bid;
    strcpy(items[i].highest_bidder, "No one");
  }

  printf("\n");
  printf("The auction has begun!\n");

  while (1) {
    for (int i = 0; i < num_items; i++) {
      printf("\n");
      printf("Item: %s\n", items[i].name);
      printf("Current highest bid: %d\n", items[i].current_bid);
      printf("Highest bidder: %s\n", items[i].highest_bidder);

      printf("Enter your bid for %s or type 'pass': ", items[i].name);
      fgets(input, 50, stdin);

      if (strcmp(input, "pass\n") == 0) {
        printf("No bid was made for %s\n", items[i].name);
      } else {
        int bid = atoi(input);

        if (bid > items[i].current_bid) {
          printf("Congratulations! You are now the highest bidder for %s with a bid of %d\n", items[i].name, bid);
          items[i].current_bid = bid;

          printf("Please enter your name: ");
          fgets(items[i].highest_bidder, 50, stdin);
        } else {
          printf("Sorry, your bid is not high enough.\n");
        }
      }
    }
  }

  return 0;
}