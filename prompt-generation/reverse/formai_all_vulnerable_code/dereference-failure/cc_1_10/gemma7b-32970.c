//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

void initialize_game(Cell **cells, int size)
{
  for (int i = 0; i < size; i++)
  {
    cells[i] = malloc(sizeof(Cell));
    cells[i]->x = i % size;
    cells[i]->y = i / size;
    cells[i]->state = rand() % 2;
  }
}

void update_cells(Cell **cells, int size)
{
  for (int i = 0; i < size; i++)
  {
    int neighbors = 0;
    for (int dx = -1; dx <= 1; dx++)
    {
      for (int dy = -1; dy <= 1; dy++)
      {
        if (dx == 0 && dy == 0)
          continue;

        int x = cells[i]->x + dx;
        int y = cells[i]->y + dy;

        if (x >= 0 && x < size && y >= 0 && y < size)
          neighbors++;
      }
    }

    if (cells[i]->state == 0 && neighbors >= 3)
      cells[i]->state = 1;
    else if (cells[i]->state == 1 && neighbors <= 1)
      cells[i]->state = 0;
  }
}

int main()
{
  srand(time(NULL));

  Cell **cells = NULL;
  initialize_game(cells, MAX_SIZE);

  for (int t = 0; t < 10; t++)
  {
    update_cells(cells, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++)
    {
      switch (cells[i]->state)
      {
        case 0:
          printf("O ");
          break;
        case 1:
          printf("X ");
          break;
      }
    }

    printf("\n");
  }

  return 0;
}