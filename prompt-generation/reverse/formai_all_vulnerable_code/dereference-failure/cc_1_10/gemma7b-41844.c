//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

typedef struct invader {
  int x, y;
  char direction;
  struct invader* next;
} Invader;

Invader* createInvader(int x, int y, char direction)
{
  Invader* invader = malloc(sizeof(Invader));
  invader->x = x;
  invader->y = y;
  invader->direction = direction;
  invader->next = NULL;
  return invader;
}

void drawInvader(Invader* invader)
{
  printf("(%d, %d) ", invader->x, invader->y);
}

void moveInvader(Invader* invader)
{
  switch (invader->direction)
  {
    case 'r':
      invader->x++;
      break;
    case 'l':
      invader->x--;
      break;
    case 'u':
      invader->y--;
      break;
    case 'd':
      invader->y++;
      break;
  }
}

int main()
{
  time_t t = time(NULL);
  srand(t);

  Invader* head = createInvader(COLS / 2, ROWS - 1, 'r');
  Invader* tail = head;

  for (int i = 0; i < 10; i++)
  {
    moveInvader(tail);
    drawInvader(tail);
    printf("\n");
    tail = tail->next = createInvader(tail->x + 1, tail->y, rand() % 4 + 1);
  }

  return 0;
}