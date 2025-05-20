//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 1000

typedef struct {
  char name[256];
  int value;
} item_t;

typedef struct {
  char name[256];
  int amount;
} bid_t;

item_t items[MAX_ITEMS];
bid_t bids[MAX_BIDS];

int num_items;
int num_bids;

void load_items() {
  FILE *fp = fopen("items.txt", "r");
  if (fp == NULL) {
    printf("Error opening items file.\n");
    exit(1);
  }

  char line[256];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char *name = strtok(line, ",");
    int value = atoi(strtok(NULL, ","));

    strcpy(items[num_items].name, name);
    items[num_items].value = value;

    num_items++;
  }

  fclose(fp);
}

void load_bids() {
  FILE *fp = fopen("bids.txt", "r");
  if (fp == NULL) {
    printf("Error opening bids file.\n");
    exit(1);
  }

  char line[256];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char *name = strtok(line, ",");
    int amount = atoi(strtok(NULL, ","));

    strcpy(bids[num_bids].name, name);
    bids[num_bids].amount = amount;

    num_bids++;
  }

  fclose(fp);
}

void print_items() {
  for (int i = 0; i < num_items; i++) {
    printf("%s: $%d\n", items[i].name, items[i].value);
  }
}

void print_bids() {
  for (int i = 0; i < num_bids; i++) {
    printf("%s: $%d\n", bids[i].name, bids[i].amount);
  }
}

void process_bids() {
  for (int i = 0; i < num_bids; i++) {
    for (int j = 0; j < num_items; j++) {
      if (strcmp(bids[i].name, items[j].name) == 0) {
        if (bids[i].amount >= items[j].value) {
          printf("%s won %s for $%d.\n", bids[i].name, items[j].name, bids[i].amount);
        }
      }
    }
  }
}

int main() {
  load_items();
  load_bids();

  print_items();
  print_bids();

  process_bids();

  return 0;
}