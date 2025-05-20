//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: recursive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define DUNGEON_WIDTH 80
#define DUNGEON_HEIGHT 21
#define MAX_ROOMS 10

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

typedef struct {
    Room *rooms;
    int num_rooms;
} Dungeon;

Dungeon *generate_dungeon();
void print_dungeon(Dungeon *dungeon);
void free_dungeon(Dungeon *dungeon);

int main() {
    srand(time(NULL));

    Dungeon *dungeon = generate_dungeon();
    print_dungeon(dungeon);
    free_dungeon(dungeon);

    return 0;
}

Dungeon *generate_dungeon() {
    Dungeon *dungeon = malloc(sizeof(Dungeon));
    dungeon->rooms = malloc(sizeof(Room) * MAX_ROOMS);
    dungeon->num_rooms = 0;

    for (int i = 0; i < MAX_ROOMS; i++) {
        Room room;
        room.x = rand() % DUNGEON_WIDTH;
        room.y = rand() % DUNGEON_HEIGHT;
        room.width = rand() % (DUNGEON_WIDTH / 2) + 1;
        room.height = rand() % (DUNGEON_HEIGHT / 2) + 1;

        if (dungeon->num_rooms == 0) {
            dungeon->rooms[dungeon->num_rooms] = room;
            dungeon->num_rooms++;
            continue;
        }

        int overlap = 0;
        for (int j = 0; j < dungeon->num_rooms; j++) {
            if (room.x + room.width > dungeon->rooms[j].x &&
                room.x < dungeon->rooms[j].x + dungeon->rooms[j].width &&
                room.y + room.height > dungeon->rooms[j].y &&
                room.y < dungeon->rooms[j].y + dungeon->rooms[j].height) {
                overlap = 1;
                break;
            }
        }

        if (!overlap) {
            dungeon->rooms[dungeon->num_rooms] = room;
            dungeon->num_rooms++;
        }
    }

    return dungeon;
}

void print_dungeon(Dungeon *dungeon) {
    for (int i = 0; i < DUNGEON_HEIGHT; i++) {
        for (int j = 0; j < DUNGEON_WIDTH; j++) {
            int in_room = 0;
            for (int k = 0; k < dungeon->num_rooms; k++) {
                if (j >= dungeon->rooms[k].x &&
                    j < dungeon->rooms[k].x + dungeon->rooms[k].width &&
                    i >= dungeon->rooms[k].y &&
                    i < dungeon->rooms[k].y + dungeon->rooms[k].height) {
                    in_room = 1;
                    break;
                }
            }

            if (in_room) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void free_dungeon(Dungeon *dungeon) {
    free(dungeon->rooms);
    free(dungeon);
}