//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: brave
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

typedef struct Room {
    int x;
    int y;
    int type;
    struct Room* next;
} Room;

Room* generate_room(int x, int y) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->type = rand() % 3;
    room->next = NULL;
    return room;
}

void draw_map(Room* room) {
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            if (room->x == x && room->y == y) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Room* first_room = generate_room(0, 0);
    Room* current_room = first_room;

    draw_map(current_room);

    // Move right
    current_room = current_room->next;
    draw_map(current_room);

    // Move down
    current_room = current_room->next->next;
    draw_map(current_room);

    return 0;
}