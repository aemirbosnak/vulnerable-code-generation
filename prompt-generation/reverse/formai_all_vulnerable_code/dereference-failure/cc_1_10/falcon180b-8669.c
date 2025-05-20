//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define NUM_ROOMS 10

typedef struct {
    char *description;
    int x, y;
    int num_exits;
    int *exits;
} Room;

void generate_maze(Room rooms[NUM_ROOMS]) {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < NUM_ROOMS; i++) {
        rooms[i].description = malloc(1024);
        sprintf(rooms[i].description, "You are in room %d.", i + 1);
        rooms[i].x = rand() % WIDTH;
        rooms[i].y = rand() % HEIGHT;
        rooms[i].num_exits = rand() % 4;
        rooms[i].exits = malloc(rooms[i].num_exits * sizeof(int));

        for (j = 0; j < rooms[i].num_exits; j++) {
            int k;
            do {
                k = rand() % NUM_ROOMS;
            } while (k == i);

            rooms[i].exits[j] = k;
        }
    }
}

void print_room(const Room *room) {
    printf("%s\n", room->description);
}

int main() {
    Room rooms[NUM_ROOMS];
    generate_maze(rooms);

    int player_room = 0;
    while (1) {
        print_room(&rooms[player_room]);

        char direction;
        printf("Which direction do you want to go? ");
        scanf(" %c", &direction);

        int next_room = -1;
        switch (direction) {
            case 'w':
                next_room = rooms[player_room].exits[0];
                break;
            case 'a':
                next_room = rooms[player_room].exits[1];
                break;
            case's':
                next_room = rooms[player_room].exits[2];
                break;
            case 'd':
                next_room = rooms[player_room].exits[3];
                break;
            default:
                printf("Invalid direction.\n");
                continue;
        }

        if (next_room == -1) {
            printf("There is no exit in that direction.\n");
        } else {
            player_room = next_room;
        }
    }

    return 0;
}