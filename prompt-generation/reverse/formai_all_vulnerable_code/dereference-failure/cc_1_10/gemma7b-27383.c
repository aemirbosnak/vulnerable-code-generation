//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

typedef struct Room {
    int room_no;
    char room_type[20];
    int available;
    float rate;
    struct Room* next;
} Room;

Room* insertRoom(Room* head, int room_no, char* room_type, int available, float rate) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_no = room_no;
    strcpy(new_room->room_type, room_type);
    new_room->available = available;
    new_room->rate = rate;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
    }

    return head;
}

void searchRooms(Room* head, char* room_type, int available) {
    while (head) {
        if (strcmp(head->room_type, room_type) == 0 && head->available == available) {
            printf("Room No: %d, Rate: %.2f\n", head->room_no, head->rate);
        }
        head = head->next;
    }
}

int main() {
    Room* head = NULL;

    insertRoom(head, 101, "Luxury", 1, 500.0);
    insertRoom(head, 102, "Standard", 2, 300.0);
    insertRoom(head, 103, "Deluxe", 0, 400.0);

    searchRooms(head, "Standard", 2);

    return 0;
}