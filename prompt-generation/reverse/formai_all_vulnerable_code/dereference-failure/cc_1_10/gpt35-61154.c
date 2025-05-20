//FormAI DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int room_number;
    int capacity;
    char* guest_name;
    int is_available;
};

struct room rooms[10];

void add_room(int room_number, int capacity, int is_available) {
    struct room new_room;
    new_room.room_number = room_number;
    new_room.capacity = capacity;
    new_room.is_available = is_available;
    rooms[room_number - 1] = new_room;
}

void check_in(int room_number, char* guest_name) {
    if (!rooms[room_number - 1].is_available) {
        printf("Room is not available.\n");
        return;
    }
    rooms[room_number - 1].is_available = 0;
    rooms[room_number - 1].guest_name = strdup(guest_name);
    printf("%s checked into room %d.\n", guest_name, room_number);
}

void check_out(int room_number) {
    if (rooms[room_number - 1].is_available) {
        printf("Room is not checked in.\n");
        return;
    }
    printf("%s checked out of room %d.\n", rooms[room_number - 1].guest_name, room_number);
    rooms[room_number - 1].is_available = 1;
    rooms[room_number - 1].guest_name = NULL;
}

void list_rooms() {
    printf("Room\tCapacity\tAvailable\tGuest Name\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t%d\t\t%d\t\t", rooms[i].room_number, rooms[i].capacity, rooms[i].is_available);
        if (rooms[i].is_available) {
            printf("N/A\n");
        } else {
            printf("%s\n", rooms[i].guest_name);
        }
    }
}

int main() {
    for (int i = 1; i <= 10; i++) {
        add_room(i, i * 2, 1);
    }
    list_rooms();
    check_in(5, "John Doe");
    check_out(5);
    check_in(10, "Jane Doe");
    check_in(5, "Jack Doe");
    list_rooms();
    return 0;
}