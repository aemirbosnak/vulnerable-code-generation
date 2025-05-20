//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

struct room {
    int number;
    char status;
    int price;
    struct room* next;
};

struct room* insert_room(struct room* head, int number, char status, int price) {
    struct room* new_room = (struct room*)malloc(sizeof(struct room));
    new_room->number = number;
    new_room->status = status;
    new_room->price = price;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
    }

    return head;
}

struct room* find_room(struct room* head, int number) {
    struct room* current_room = head;

    while (current_room) {
        if (current_room->number == number) {
            return current_room;
        }

        current_room = current_room->next;
    }

    return NULL;
}

int main() {
    struct room* head = NULL;

    head = insert_room(head, 1, 'O', 100);
    head = insert_room(head, 2, 'A', 200);
    head = insert_room(head, 3, 'A', 300);
    head = insert_room(head, 4, 'O', 400);
    head = insert_room(head, 5, 'A', 500);

    struct room* found_room = find_room(head, 2);

    if (found_room) {
        printf("Room number: %d\n", found_room->number);
        printf("Status: %c\n", found_room->status);
        printf("Price: %d\n", found_room->price);
    } else {
        printf("Room not found.\n");
    }

    return 0;
}