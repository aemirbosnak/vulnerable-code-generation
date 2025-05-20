//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ROOM_SIZE 20
#define MAX_ROOMS 100

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef struct {
    int x;
    int y;
    char name[20];
    bool visited;
    int direction;
} Room;

int main() {
    srand(time(NULL));

    printf("Welcome to the Rogue-like Game!\n");
    printf("Generating a dungeon...\n");

    Room* rooms = (Room*) malloc(MAX_ROOMS * sizeof(Room));

    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].visited = false;
    }

    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].x = rand() % MAX_ROOM_SIZE;
        rooms[i].y = rand() % MAX_ROOM_SIZE;
        rooms[i].name[0] = '.';
        rooms[i].direction = rand() % 4;
    }

    int current_room = 0;
    bool game_over = false;

    while (!game_over) {
        printf("Current room: %s\n", rooms[current_room].name);

        if (rooms[current_room].visited) {
            printf("You have already been here!\n");
        } else {
            printf("What direction do you want to go? (UP, DOWN, LEFT, RIGHT): ");
            char direction_input[3];
            scanf("%s", direction_input);

            int direction = atoi(direction_input);

            if (direction == UP) {
                current_room -= rooms[current_room].direction;
            } else if (direction == DOWN) {
                current_room += rooms[current_room].direction;
            } else if (direction == LEFT) {
                current_room -= MAX_ROOM_SIZE - rooms[current_room].direction;
            } else if (direction == RIGHT) {
                current_room += MAX_ROOM_SIZE - rooms[current_room].direction;
            }

            rooms[current_room].visited = true;

            if (rooms[current_room].name[0] == 'E') {
                game_over = true;
            }
        }

        printf("-----------------------------\n");
    }

    free(rooms);
    return 0;
}