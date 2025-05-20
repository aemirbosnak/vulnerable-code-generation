//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  int price;
} Item;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <item_file>\n", argv[0]);
    return 1;
  }

  FILE* file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Could not open file '%s'\n", argv[1]);
    return 2;
  }

  Item* items = malloc(sizeof(Item) * 100);
  if (items == NULL) {
    printf("Memory allocation failed\n");
    return 3;
  }

  int num_items = 0;
  char line[100];
  while (fgets(line, sizeof(line), file)) {
    sscanf(line, "%s %d", items[num_items].name, &items[num_items].price);
    num_items++;
  }
  fclose(file);

  Item* item = items;
  int bid = 0;
  int i = 0;
  while (item!= NULL && bid <= 100) {
    printf("%s: $%d\n", item->name, item->price);
    if (i == num_items) {
      i = 0;
    } else {
      i++;
    }
    item = items + i;
  }

  free(items);
  return 0;
}