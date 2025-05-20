//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOM_SIZE 20
#define MAX_ROOM_COUNT 100

typedef struct {
    char name[100];
    char desc[100];
    int x;
    int y;
} room_t;

void print_room(room_t* room);
void create_room(room_t* room);
void create_rooms(room_t** rooms, int count);
void fill_rooms(room_t** rooms, int count);
void print_rooms(room_t** rooms, int count);

int main() {
    srand(time(NULL));

    int room_count = 0;
    room_t* rooms[MAX_ROOM_COUNT];
    create_rooms(rooms, MAX_ROOM_COUNT);

    for (int i = 0; i < room_count; i++) {
        print_room(rooms[i]);
        printf("\n");
    }

    return 0;
}

void create_rooms(room_t** rooms, int count) {
    for (int i = 0; i < count; i++) {
        room_t* room = (room_t*)malloc(sizeof(room_t));
        create_room(room);
        rooms[i] = room;
    }
}

void create_room(room_t* room) {
    strcpy(room->name, "Room ");
    strcat(room->name, (char*)room);
    room->desc[0] = '\0';
    room->x = rand() % 20;
    room->y = rand() % 20;
}

void print_room(room_t* room) {
    printf("You are in the %s room.\n", room->name);
    printf("This room is %s.\n", room->desc);
    printf("You see a %s in the %s corner.\n", "big", "red");
    printf("There is a %s in the %s corner.\n", "small", "blue");
}

void fill_rooms(room_t** rooms, int count) {
    for (int i = 0; i < count; i++) {
        create_room(rooms[i]);
    }
}

void print_rooms(room_t** rooms, int count) {
    for (int i = 0; i < count; i++) {
        print_room(rooms[i]);
    }
}