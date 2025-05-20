//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

typedef struct Cell {
  int x;
  int y;
  struct Cell* next;
} Cell;

Cell* CreateCell(int x, int y) {
  Cell* cell = (Cell*)malloc(sizeof(Cell));
  cell->x = x;
  cell->y = y;
  cell->next = NULL;
  return cell;
}

void DrawMap(Cell* cell) {
  system("cls");
  for (int y = 0; y < MAX_HEIGHT; y++) {
    for (int x = 0; x < MAX_WIDTH; x++) {
      if (cell->x == x && cell->y == y) {
        printf("X ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  time_t t = time(NULL);
  srand(t);

  Cell* head = CreateCell(rand() % MAX_WIDTH, rand() % MAX_HEIGHT);
  DrawMap(head);

  char input;
  printf("Enter 'w', 'a', 's', or 'd' to move: ");
  scanf("%c", &input);

  switch (input) {
    case 'w':
      head->y--;
      break;
    case 'a':
      head->x--;
      break;
    case 's':
      head->y++;
      break;
    case 'd':
      head->x++;
      break;
  }

  DrawMap(head);

  return 0;
}