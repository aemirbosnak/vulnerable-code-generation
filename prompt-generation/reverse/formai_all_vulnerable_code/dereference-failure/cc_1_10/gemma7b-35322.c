//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room {
    char type;
    int number;
    struct room *next;
} room_t;

room_t *insert_room(room_t *head, char type, int number) {
    room_t *new_room = malloc(sizeof(room_t));
    new_room->type = type;
    new_room->number = number;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
    }

    return head;
}

void check_room(room_t *head, int number) {
    room_t *current = head;

    while (current) {
        if (current->number == number) {
            printf("Room %d is available.\n", number);
            return;
        }

        current = current->next;
    }

    printf("Room %d is not available.\n", number);
}

int main() {
    room_t *head = NULL;

    insert_room(head, 'A', 1);
    insert_room(head, 'B', 2);
    insert_room(head, 'A', 3);
    insert_room(head, 'B', 4);

    check_room(head, 3);
    check_room(head, 5);

    return 0;
}