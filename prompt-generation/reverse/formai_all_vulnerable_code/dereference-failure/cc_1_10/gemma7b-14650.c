//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100

typedef struct Room {
    int room_no;
    char status;
    int occupancy;
    struct Room* next;
} Room;

Room* create_room(int room_no) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_no = room_no;
    new_room->status = 'O';
    new_room->occupancy = 0;
    new_room->next = NULL;
    return new_room;
}

void insert_room(Room* head, int room_no) {
    Room* new_room = create_room(room_no);
    if (head == NULL) {
        head = new_room;
    } else {
        Room* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_room;
    }
}

void check_room_status(Room* head, int room_no) {
    Room* temp = head;
    while (temp) {
        if (temp->room_no == room_no) {
            printf("Room status: %c\n", temp->status);
            break;
        }
        temp = temp->next;
    }
}

int main() {
    Room* head = NULL;

    insert_room(head, 101);
    insert_room(head, 102);
    insert_room(head, 103);

    check_room_status(head, 102);

    return 0;
}