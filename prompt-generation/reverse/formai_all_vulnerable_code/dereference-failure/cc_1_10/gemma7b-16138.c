//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100

typedef struct Room {
    int room_number;
    char room_type;
    int available_beds;
    int booked_beds;
    struct Room* next;
} Room;

Room* create_room(int room_number, char room_type, int available_beds, int booked_beds) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    new_room->room_type = room_type;
    new_room->available_beds = available_beds;
    new_room->booked_beds = booked_beds;
    new_room->next = NULL;
    return new_room;
}

void add_room(Room* head, int room_number, char room_type, int available_beds, int booked_beds) {
    Room* new_room = create_room(room_number, room_type, available_beds, booked_beds);
    if (head == NULL) {
        head = new_room;
    } else {
        new_room->next = head;
        head = new_room;
    }
}

void display_rooms(Room* head) {
    while (head) {
        printf("Room number: %d, Room type: %c, Available beds: %d, Booked beds: %d\n", head->room_number, head->room_type, head->available_beds, head->booked_beds);
        head = head->next;
    }
}

int main() {
    Room* head = NULL;
    add_room(head, 101, 'A', 50, 10);
    add_room(head, 102, 'B', 40, 20);
    add_room(head, 103, 'A', 60, 30);
    add_room(head, 104, 'B', 30, 15);

    display_rooms(head);

    return 0;
}