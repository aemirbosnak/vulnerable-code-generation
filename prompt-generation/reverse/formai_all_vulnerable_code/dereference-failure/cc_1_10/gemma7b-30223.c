//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int difficulty)
{
  int i, j, r, n = 10 + difficulty;
  char **map = (char**)malloc(n * sizeof(char*));
  for(i = 0; i < n; i++)
  {
    map[i] = (char*)malloc(n * sizeof(char));
    for(j = 0; j < n; j++)
    {
      map[i][j] = '.';
    }
  }

  map[5][5] = 'H';
  map[2][3] = 'T';
  map[3][2] = 'O';
  map[4][2] = 'R';
  map[4][3] = 'E';

  srand(time(NULL));
  r = rand() % n;
  int x = r / n;
  int y = r % n;

  while(map[x][y] != 'H')
  {
    r = rand() % n;
    x = r / n;
    y = r % n;
  }

  printf("You are in a haunted house. The door is locked.\n");
  printf("Suddenly, you hear a noise. It's coming from the %dth floor.\n", x + 1);
  printf("You turn around and see a ghostly figure standing there. It's %s!\n", map[x][y]);
  printf("What do you do? (Enter 'f' to fight, 'r' to run, 'p' to pray)\n");

  char action;
  scanf(" %c", &action);

  if(action == 'f')
  {
    printf("You fought the ghostly figure and managed to escape.\n");
  }
  else if(action == 'r')
  {
    printf("You ran away and escaped.\n");
  }
  else if(action == 'p')
  {
    printf("You prayed and the ghostly figure went away.\n");
  }
  else
  {
    printf("Invalid input.\n");
  }

  free(map);
}

int main()
{
  haunted_house(5);
  return 0;
}