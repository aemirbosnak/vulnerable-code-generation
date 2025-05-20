//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

struct guest {
    char name[50];
    int room_no;
    struct guest* next;
};

struct room {
    int no;
    int occupancy;
    struct room* next;
};

void insert_guest(struct guest** head, char* name, int room_no) {
    struct guest* new_guest = (struct guest*)malloc(sizeof(struct guest));
    strcpy(new_guest->name, name);
    new_guest->room_no = room_no;
    new_guest->next = NULL;

    if (*head == NULL) {
        *head = new_guest;
    } else {
        (*head)->next = new_guest;
    }
}

void insert_room(struct room** head, int no, int occupancy) {
    struct room* new_room = (struct room*)malloc(sizeof(struct room));
    new_room->no = no;
    new_room->occupancy = occupancy;
    new_room->next = NULL;

    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
    }
}

void display_guests(struct guest* head) {
    struct guest* current = head;
    while (current) {
        printf("Name: %s, Room No: %d\n", current->name, current->room_no);
        current = current->next;
    }
}

void display_rooms(struct room* head) {
    struct room* current = head;
    while (current) {
        printf("No: %d, Occupancy: %d\n", current->no, current->occupancy);
        current = current->next;
    }
}

int main() {
    struct guest* head_guest = NULL;
    struct room* head_room = NULL;

    insert_guest(&head_guest, "John Doe", 101);
    insert_guest(&head_guest, "Jane Doe", 102);
    insert_guest(&head_guest, "Peter Pan", 103);

    insert_room(&head_room, 101, 2);
    insert_room(&head_room, 102, 1);
    insert_room(&head_room, 103, 3);

    display_guests(head_guest);
    display_rooms(head_room);

    return 0;
}