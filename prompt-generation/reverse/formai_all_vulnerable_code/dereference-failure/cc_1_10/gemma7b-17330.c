//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TREASURE_NUM 10

typedef struct Treasure {
  int x;
  int y;
  int type;
  struct Treasure* next;
} Treasure;

void createTreasure(Treasure** head) {
  *head = (Treasure*)malloc(sizeof(Treasure));
  (*head)->x = rand() % 10;
  (*head)->y = rand() % 10;
  (*head)->type = rand() % MAX_TREASURE_NUM;
  (*head)->next = NULL;
}

void searchTreasure(Treasure* head) {
  int x, y;
  printf("Enter your coordinates (x, y): ");
  scanf("%d %d", &x, &y);

  if (head->x == x && head->y == y) {
    switch (head->type) {
      case 0:
        printf("You found a gold coin!\n");
        break;
      case 1:
        printf("You found a silver coin!\n");
        break;
      case 2:
        printf("You found a diamond!\n");
        break;
      default:
        printf("You found a mystery item!\n");
    }
  } else {
    printf("Coordinates are incorrect.\n");
  }
}

int main() {
  Treasure* head = NULL;
  createTreasure(&head);
  searchTreasure(head);

  return 0;
}