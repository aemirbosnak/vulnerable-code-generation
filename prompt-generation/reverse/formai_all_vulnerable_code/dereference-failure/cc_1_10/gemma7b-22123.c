//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct Room {
    int x, y;
    struct Room* next;
} Room;

Room* generate_map() {
    srand(time(NULL));
    Room* head = NULL;
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            int rand_num = rand() % 3;
            Room* new_room = malloc(sizeof(Room));
            new_room->x = x;
            new_room->y = y;
            new_room->next = NULL;
            if (head == NULL) {
                head = new_room;
            } else {
                head->next = new_room;
                head = new_room;
            }
        }
    }
    return head;
}

void draw_map(Room* room) {
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            if (room->x == x && room->y == y) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

int main() {
    Room* room = generate_map();
    draw_map(room);
    return 0;
}