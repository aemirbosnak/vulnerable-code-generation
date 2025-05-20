//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define ROOM_MAX 10

struct room {
    int number;
    char status;
    int occupied_by;
    struct room* next;
};

struct room* create_room(int number) {
    struct room* new_room = (struct room*)malloc(sizeof(struct room));
    new_room->number = number;
    new_room->status = 'O';
    new_room->occupied_by = -1;
    new_room->next = NULL;
    return new_room;
}

struct room* insert_room(struct room* head, int number) {
    struct room* new_room = create_room(number);
    if (head == NULL) {
        head = new_room;
    } else {
        struct room* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_room;
    }
    return head;
}

void print_rooms(struct room* head) {
    struct room* current = head;
    while (current) {
        printf("Room number: %d, Status: %c, Occupied by: %d\n", current->number, current->status, current->occupied_by);
        current = current->next;
    }
}

int main() {
    struct room* head = NULL;
    head = insert_room(head, 1);
    head = insert_room(head, 2);
    head = insert_room(head, 3);
    head = insert_room(head, 4);
    head = insert_room(head, 5);
    print_rooms(head);
    return 0;
}