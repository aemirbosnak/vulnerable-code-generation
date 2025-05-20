//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

typedef struct Room {
    int room_no;
    char type;
    int occupancy;
    struct Room* next;
} Room;

Room* insertRoom(Room* head, int room_no, char type, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_no = room_no;
    newRoom->type = type;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        head->next = newRoom;
    }

    return head;
}

int findRoom(Room* head, int room_no) {
    while (head) {
        if (head->room_no == room_no) {
            return 1;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    Room* head = NULL;

    insertRoom(head, 101, 'D', 2);
    insertRoom(head, 102, 'S', 1);
    insertRoom(head, 103, 'D', 3);

    if (findRoom(head, 102) == 1) {
        printf("Room 102 found.\n");
    } else {
        printf("Room 102 not found.\n");
    }

    return 0;
}