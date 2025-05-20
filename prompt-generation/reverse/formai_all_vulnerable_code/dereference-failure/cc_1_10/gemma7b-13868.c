//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUEST_ROOM_NUM 10

typedef struct guest_room {
    int room_num;
    char guest_name[50];
    int num_of_guests;
    struct guest_room* next;
} guest_room;

guest_room* insert_guest_room(guest_room* head, int room_num, char* guest_name, int num_of_guests) {
    guest_room* new_room = (guest_room*)malloc(sizeof(guest_room));
    new_room->room_num = room_num;
    strcpy(new_room->guest_name, guest_name);
    new_room->num_of_guests = num_of_guests;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
    }

    return head;
}

void print_guest_room(guest_room* head) {
    guest_room* current = head;
    while (current) {
        printf("Room Number: %d\n", current->room_num);
        printf("Guest Name: %s\n", current->guest_name);
        printf("Number of Guests: %d\n", current->num_of_guests);
        printf("\n");
        current = current->next;
    }
}

int main() {
    guest_room* head = NULL;

    insert_guest_room(head, 101, "John Doe", 2);
    insert_guest_room(head, 102, "Jane Doe", 1);
    insert_guest_room(head, 103, "Peter Pan", 3);

    print_guest_room(head);

    return 0;
}