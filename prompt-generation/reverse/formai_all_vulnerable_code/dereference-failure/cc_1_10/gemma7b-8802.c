//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct Room {
    int number;
    char type;
    int available;
    char guest_name[50];
    struct Room* next;
} Room;

Room* insert_room(Room* head) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->number = MAX_ROOMS + 1;
    new_room->type = 'A';
    new_room->available = 1;
    new_room->guest_name[0] = '\0';
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
    }

    return head;
}

void print_rooms(Room* head) {
    Room* current = head;

    while (current) {
        printf("Room No: %d, Type: %c, Available: %d, Guest Name: %s\n", current->number, current->type, current->available, current->guest_name);
        current = current->next;
    }
}

int main() {
    Room* head = NULL;

    head = insert_room(head);
    head = insert_room(head);
    head = insert_room(head);

    print_rooms(head);

    return 0;
}