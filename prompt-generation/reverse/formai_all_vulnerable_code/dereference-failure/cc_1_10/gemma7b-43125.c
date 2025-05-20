//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECOVERY_SIZE 1024

typedef struct Item {
  char name[50];
  int quantity;
  struct Item* next;
} Item;

Item* recoverItems(char* filename) {
  FILE* file = fopen(filename, "r");
  Item* head = NULL;
  char line[MAX_RECOVERY_SIZE];

  if (file) {
    while (fgets(line, MAX_RECOVERY_SIZE, file) != NULL) {
      Item* item = malloc(sizeof(Item));
      item->quantity = atoi(line);
      strcpy(item->name, line);

      if (head == NULL) {
        head = item;
      } else {
        item->next = head;
        head = item;
      }
    }

    fclose(file);
  }

  return head;
}

int main() {
  Item* items = recoverItems("treasure.txt");

  if (items) {
    printf("Your treasures:\n");
    for (Item* item = items; item; item = item->next) {
      printf("%s: %d\n", item->name, item->quantity);
    }
  } else {
    printf("No treasures found.\n");
  }

  return 0;
}