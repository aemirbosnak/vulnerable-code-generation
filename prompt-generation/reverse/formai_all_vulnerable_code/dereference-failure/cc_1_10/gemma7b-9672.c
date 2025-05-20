//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5
#define MAX_MISSILES 20

typedef struct Ship {
    int x, y, health, direction, speed;
    char name[20];
} Ship;

void initializeShips(Ship **ships, int numShips) {
    for (int i = 0; i < numShips; i++) {
        ships[i] = malloc(sizeof(Ship));
        ships[i]->x = rand() % 10;
        ships[i]->y = rand() % 10;
        ships[i]->health = 100;
        ships[i]->direction = rand() % 4;
        ships[i]->speed = rand() % 3;
        strcpy(ships[i]->name, "Ship " + i);
    }
}

void moveShips(Ship **ships, int numShips) {
    for (int i = 0; i < numShips; i++) {
        switch (ships[i]->direction) {
            case 0:
                ships[i]->x++;
                break;
            case 1:
                ships[i]->x--;
                break;
            case 2:
                ships[i]->y++;
                break;
            case 3:
                ships[i]->y--;
                break;
        }

        ships[i]->x = (ships[i]->x < 0) ? 0 : ships[i]->x;
        ships[i]->x = (ships[i]->x > 9) ? 9 : ships[i]->x;
        ships[i]->y = (ships[i]->y < 0) ? 0 : ships[i]->y;
        ships[i]->y = (ships[i]->y > 9) ? 9 : ships[i]->y;
    }
}

void battle(Ship **ships, int numShips) {
    for (int i = 0; i < numShips; i++) {
        for (int j = 0; j < numShips; j++) {
            if (i != j) {
                if (ships[i]->x == ships[j]->x && ships[i]->y == ships[j]->y) {
                    ships[j]->health--;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Ship **ships = malloc(MAX_ENEMIES * sizeof(Ship));
    initializeShips(ships, MAX_ENEMIES);

    moveShips(ships, MAX_ENEMIES);

    battle(ships, MAX_ENEMIES);

    for (int i = 0; i < MAX_ENEMIES; i++) {
        printf("%s health: %d\n", ships[i]->name, ships[i]->health);
    }

    free(ships);

    return 0;
}