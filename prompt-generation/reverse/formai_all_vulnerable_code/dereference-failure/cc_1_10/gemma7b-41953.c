//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct Room {
    int room_no;
    char status;
    char occupancy;
    struct Room* next;
} Room;

Room* create_room(int room_no) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_no = room_no;
    new_room->status = 'O';
    new_room->occupancy = 'N';
    new_room->next = NULL;
    return new_room;
}

void insert_room(Room** head, int room_no) {
    Room* new_room = create_room(room_no);
    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
        *head = new_room;
    }
}

void check_room_status(Room* head, int room_no) {
    while (head) {
        if (head->room_no == room_no) {
            printf("Room status: %c", head->status);
            break;
        } else {
            head = head->next;
        }
    }
}

int main() {
    Room* head = NULL;
    insert_room(&head, 101);
    insert_room(&head, 102);
    insert_room(&head, 103);
    check_room_status(head, 102);
    return 0;
}