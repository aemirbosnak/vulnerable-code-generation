//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _room {
    int id;
    char *name;
    int capacity;
    int status;
} room;

typedef struct _hotel {
    char *name;
    int num_rooms;
    room *rooms;
} hotel;

void check_in(hotel *hotel, int room_id, char *guest_name) {
    if (room_id < 0 || room_id >= hotel->num_rooms) {
        printf("Invalid room number.\n");
        return;
    }
    if (hotel->rooms[room_id].status == 1) {
        printf("Room is already occupied.\n");
        return;
    }
    hotel->rooms[room_id].status = 1;
    hotel->rooms[room_id].name = guest_name;
    printf("Guest %s checked in to room %d.\n", guest_name, room_id);
}

void check_out(hotel *hotel, int room_id) {
    if (room_id < 0 || room_id >= hotel->num_rooms) {
        printf("Invalid room number.\n");
        return;
    }
    if (hotel->rooms[room_id].status == 0) {
        printf("Room is already empty.\n");
        return;
    }
    hotel->rooms[room_id].status = 0;
    hotel->rooms[room_id].name = NULL;
    printf("Guest checked out of room %d.\n", room_id);
}

void list_rooms(hotel *hotel) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        printf("Room %d: %s, capacity %d, status %d\n", hotel->rooms[i].id, hotel->rooms[i].name, hotel->rooms[i].capacity, hotel->rooms[i].status);
    }
}

int main() {
    hotel hotel1 = {
        .name = "Hotel 1",
        .num_rooms = 10,
        .rooms = malloc(sizeof(room) * 10)
    };

    for (int i = 0; i < hotel1.num_rooms; i++) {
        hotel1.rooms[i].id = i;
        hotel1.rooms[i].name = NULL;
        hotel1.rooms[i].capacity = 2;
        hotel1.rooms[i].status = 0;
    }

    check_in(&hotel1, 0, "John Doe");
    check_in(&hotel1, 1, "Jane Doe");
    check_out(&hotel1, 1);
    list_rooms(&hotel1);

    return 0;
}