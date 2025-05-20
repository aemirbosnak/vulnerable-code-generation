//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Ship {
  char name[MAX_SIZE];
  int x, y;
  int health;
} Ship;

void initializeShips(Ship **ships, int numShips) {
  for (int i = 0; i < numShips; i++) {
    ships[i] = malloc(sizeof(Ship));
    ships[i]->name[0] = '\0';
    ships[i]->x = 0;
    ships[i]->y = 0;
    ships[i]->health = 100;
  }
}

void moveShips(Ship **ships, int numShips) {
  for (int i = 0; i < numShips; i++) {
    printf("Enter the direction of ship %s (N/S/E/W): ", ships[i]->name);
    char direction;
    scanf(" %c", &direction);

    switch (direction) {
      case 'N':
        ships[i]->y--;
        break;
      case 'S':
        ships[i]->y++;
        break;
      case 'E':
        ships[i]->x++;
        break;
      case 'W':
        ships[i]->x--;
        break;
      default:
        printf("Invalid direction.\n");
    }
  }
}

void battleShips(Ship **ships, int numShips) {
  for (int i = 0; i < numShips; i++) {
    for (int j = 0; j < numShips; j++) {
      if (i != j) {
        if (ships[i]->x == ships[j]->x && ships[i]->y == ships[j]->y) {
          ships[j]->health--;
          printf("BOOM! Ship %s has sunk Ship %s!\n", ships[i]->name, ships[j]->name);
        }
      }
    }
  }
}

int main() {
  int numShips;
  printf("Enter the number of ships: ");
  scanf(" %d", &numShips);

  Ship **ships = NULL;
  initializeShips(&ships, numShips);

  moveShips(ships, numShips);

  battleShips(ships, numShips);

  for (int i = 0; i < numShips; i++) {
    free(ships[i]);
  }
  free(ships);

  return 0;
}