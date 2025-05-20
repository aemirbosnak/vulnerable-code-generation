//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

typedef struct Room {
    int room_number;
    char status;
    char type;
    int price;
    struct Room* next;
} Room;

Room* insert_room(Room* head, int room_number, char status, char type, int price) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    new_room->status = status;
    new_room->type = type;
    new_room->price = price;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
    }

    return head;
}

void display_rooms(Room* head) {
    while (head) {
        printf("Room Number: %d, Status: %c, Type: %c, Price: %d\n", head->room_number, head->status, head->type, head->price);
        head = head->next;
    }
}

int main() {
    Room* head = NULL;

    insert_room(head, 101, 'A', 'D', 1000);
    insert_room(head, 102, 'O', 'C', 800);
    insert_room(head, 103, 'A', 'B', 700);
    insert_room(head, 104, 'O', 'A', 600);
    insert_room(head, 105, 'A', 'D', 900);

    display_rooms(head);

    return 0;
}