//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 5

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

Item* item_list = NULL;

void add_item(char* name, int quantity) {
  Item* new_item = malloc(sizeof(Item));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->next = item_list;
  item_list = new_item;
}

void use_item(char* name) {
  Item* current_item = item_list;
  while (current_item) {
    if (strcmp(current_item->name, name) == 0) {
      current_item->quantity--;
      if (current_item->quantity == 0) {
        item_list = current_item->next;
        free(current_item);
      }
      printf("You used %s.\n", name);
      return;
    }
    current_item = current_item->next;
  }
  printf("You do not have that item.\n");
}

int main() {
  add_item("Water", 10);
  add_item("Food", 5);
  add_item("Medkit", 2);
  add_item("Gun", 1);
  add_item("Grenades", 3);

  char command[20];

  printf("Welcome to the post-apocalyptic world. You are scavenging for supplies.\n");

  while (1) {
    printf("Enter a command: ");
    scanf("%s", command);

    if (strcmp(command, "quit") == 0) {
      break;
    } else if (strcmp(command, "use") == 0) {
      char item_name[20];
      printf("Enter the name of the item you want to use: ");
      scanf("%s", item_name);
      use_item(item_name);
    } else if (strcmp(command, "list") == 0) {
      Item* current_item = item_list;
      printf("Your items:\n");
      while (current_item) {
        printf("%s (%d) ", current_item->name, current_item->quantity);
        current_item = current_item->next;
      }
      printf("\n");
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}