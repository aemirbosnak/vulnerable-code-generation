//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dance_with_the_spaceship(char **ship, int size) {
  for (int i = 0; i < size; i++) {
    printf("%c", ship[i]);
  }
  printf("\n");
}

int main() {
  char **ship = malloc(5 * sizeof(char *));
  for (int i = 0; i < 5; i++) {
    ship[i] = malloc(10 * sizeof(char));
  }

  ship[0][0] = 'S';
  ship[0][1] = 'P';
  ship[0][2] = 'A';
  ship[0][3] = 'C';
  ship[0][4] = 'E';

  ship[1][0] = 'R';
  ship[1][1] = 'O';
  ship[1][2] = 'W';
  ship[1][3] = 'T';
  ship[1][4] = 'A';

  ship[2][0] = 'E';
  ship[2][1] = 'F';
  ship[2][2] = 'R';
  ship[2][3] = 'T';
  ship[2][4] = 'A';

  ship[3][0] = 'T';
  ship[3][1] = 'H';
  ship[3][2] = 'A';
  ship[3][3] = 'C';
  ship[3][4] = 'H';

  ship[4][0] = 'O';
  ship[4][1] = 'U';
  ship[4][2] = 'T';
  ship[4][3] = 'R';
  ship[4][4] = 'A';

  dance_with_the_spaceship(ship, 5);

  for (int i = 0; i < 5; i++) {
    free(ship[i]);
  }
  free(ship);

  return 0;
}