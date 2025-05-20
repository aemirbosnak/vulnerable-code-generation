//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_ROOM_SIZE 20

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point top_left;
    int width, height;
} Room;

typedef struct {
    Room *rooms;
    int num_rooms;
} Dungeon;

void generate_room(Room *room) {
    room->width = rand() % MAX_ROOM_SIZE + 1;
    room->height = rand() % MAX_ROOM_SIZE + 1;
    room->top_left.x = rand() % MAX_ROOMS;
    room->top_left.y = rand() % MAX_ROOMS;
}

int check_collision(Room *room1, Room *room2) {
    if (room1->top_left.x < room2->top_left.x + room2->width &&
        room1->top_left.x + room1->width > room2->top_left.x &&
        room1->top_left.y < room2->top_left.y + room2->height &&
        room1->top_left.y + room1->height > room2->top_left.y) {
        return 1;
    }
    return 0;
}

void generate_dungeon(Dungeon *dungeon) {
    srand(time(NULL));
    dungeon->num_rooms = rand() % MAX_ROOMS + 1;
    dungeon->rooms = malloc(dungeon->num_rooms * sizeof(Room));
    for (int i = 0; i < dungeon->num_rooms; i++) {
        generate_room(&dungeon->rooms[i]);
    }
}

int main() {
    Dungeon dungeon;
    generate_dungeon(&dungeon);
    printf("Generated Dungeon:\n");
    for (int i = 0; i < dungeon.num_rooms; i++) {
        printf("Room %d: (%d,%d) - (%d,%d)\n", i, dungeon.rooms[i].top_left.x, dungeon.rooms[i].top_left.y, dungeon.rooms[i].top_left.x + dungeon.rooms[i].width, dungeon.rooms[i].top_left.y + dungeon.rooms[i].height);
    }
    return 0;
}