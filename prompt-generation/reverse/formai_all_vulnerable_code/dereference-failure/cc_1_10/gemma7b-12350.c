//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100

typedef struct Room {
    int room_no;
    char status;
    float rate;
    struct Room *next;
} Room;

Room *create_room(int room_no, float rate) {
    Room *new_room = (Room *)malloc(sizeof(Room));
    new_room->room_no = room_no;
    new_room->status = 'O';
    new_room->rate = rate;
    new_room->next = NULL;
    return new_room;
}

void insert_room(Room **head, int room_no, float rate) {
    Room *new_room = create_room(room_no, rate);
    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
    }
}

void display_rooms(Room *head) {
    while (head) {
        printf("Room No: %d, Status: %c, Rate: %.2f\n", head->room_no, head->status, head->rate);
        head = head->next;
    }
}

int main() {
    Room *head = NULL;

    insert_room(&head, 101, 5000);
    insert_room(&head, 102, 6000);
    insert_room(&head, 103, 7000);
    insert_room(&head, 104, 8000);
    insert_room(&head, 105, 9000);

    display_rooms(head);

    return 0;
}