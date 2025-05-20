//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    char name[50];
    int number;
};

struct Room* rooms[100];
int roomCount = 0;

int addRoom(char* name, int number) {
    struct Room* newRoom = (struct Room*)malloc(sizeof(struct Room));
    if (newRoom == NULL) {
        return -1;
    }
    strcpy(newRoom->name, name);
    newRoom->number = number;
    rooms[roomCount++] = newRoom;
    return 0;
}

int removeRoom(int number) {
    if (number < 1 || number > roomCount) {
        return -1;
    }
    struct Room* room = rooms[number - 1];
    free(room);
    memmove(room, room + 1, (roomCount - 1) * sizeof(struct Room));
    roomCount--;
    return 0;
}

int checkRoomAvailability(int number) {
    if (number < 1 || number > roomCount) {
        return -1;
    }
    struct Room* room = rooms[number - 1];
    if (strcmp(room->name, "Available") == 0) {
        return 0;
    }
    return -1;
}

int bookRoom(int number, char* name) {
    if (number < 1 || number > roomCount) {
        return -1;
    }
    struct Room* room = rooms[number - 1];
    if (strcmp(room->name, "Available")!= 0) {
        return -1;
    }
    strcpy(room->name, name);
    return 0;
}

int checkInGuest(int number) {
    if (number < 1 || number > roomCount) {
        return -1;
    }
    struct Room* room = rooms[number - 1];
    if (strcmp(room->name, "Available")!= 0) {
        return -1;
    }
    strcpy(room->name, "Occupied");
    return 0;
}

int checkOutGuest(int number) {
    if (number < 1 || number > roomCount) {
        return -1;
    }
    struct Room* room = rooms[number - 1];
    if (strcmp(room->name, "Occupied")!= 0) {
        return -1;
    }
    strcpy(room->name, "Available");
    return 0;
}

int getRoomCount() {
    return roomCount;
}

int main() {
    struct Room* room1 = (struct Room*)malloc(sizeof(struct Room));
    strcpy(room1->name, "Room 1");
    room1->number = 1;
    rooms[0] = room1;

    struct Room* room2 = (struct Room*)malloc(sizeof(struct Room));
    strcpy(room2->name, "Room 2");
    room2->number = 2;
    rooms[1] = room2;

    struct Room* room3 = (struct Room*)malloc(sizeof(struct Room));
    strcpy(room3->name, "Room 3");
    room3->number = 3;
    rooms[2] = room3;

    int guest1 = bookRoom(1, "John Doe");
    int guest2 = bookRoom(2, "Jane Doe");
    int guest3 = bookRoom(3, "Mike Smith");

    checkInGuest(1);
    checkInGuest(2);
    checkInGuest(3);

    int guest4 = checkRoomAvailability(1);
    int guest5 = checkRoomAvailability(2);
    int guest6 = checkRoomAvailability(3);

    checkOutGuest(1);
    checkOutGuest(2);
    checkOutGuest(3);

    removeRoom(1);
    removeRoom(2);
    removeRoom(3);

    free(room1);
    free(room2);
    free(room3);

    printf("Room count: %d\n", getRoomCount());

    return 0;
}