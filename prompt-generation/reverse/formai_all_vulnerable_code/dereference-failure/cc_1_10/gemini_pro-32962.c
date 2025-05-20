//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int bid;
} Bidder;

int compare_bids(const void *a, const void *b) {
  Bidder *bidder1 = (Bidder *)a;
  Bidder *bidder2 = (Bidder *)b;
  return bidder2->bid - bidder1->bid;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <item> <starting bid>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *item = argv[1];
  int starting_bid = atoi(argv[2]);

  Bidder *bidders = NULL;
  int num_bidders = 0;

  while (1) {
    char name[256];
    int bid;
    printf("Enter your name and bid (or q to quit): ");
    if (scanf("%s %d", name, &bid) != 2) {
      break;
    }
    if (strcmp(name, "q") == 0) {
      break;
    }
    Bidder *new_bidder = malloc(sizeof(Bidder));
    new_bidder->name = strdup(name);
    new_bidder->bid = bid;
    bidders = realloc(bidders, sizeof(Bidder) * (num_bidders + 1));
    bidders[num_bidders++] = *new_bidder;
  }

  qsort(bidders, num_bidders, sizeof(Bidder), compare_bids);

  if (num_bidders == 0) {
    printf("No bids received.\n");
  } else {
    printf("The winner is %s with a bid of %d.\n", bidders[0].name, bidders[0].bid);
  }

  for (int i = 0; i < num_bidders; i++) {
    free(bidders[i].name);
  }
  free(bidders);

  return EXIT_SUCCESS;
}