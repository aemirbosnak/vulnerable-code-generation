//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

struct room {
    int room_no;
    char status;
    int occupancy;
    struct room* next;
};

struct room* insert_room(struct room* head, int room_no) {
    struct room* new_node = (struct room*)malloc(sizeof(struct room));
    new_node->room_no = room_no;
    new_node->status = 'O';
    new_node->occupancy = 0;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct room* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return head;
}

void display_rooms(struct room* head) {
    struct room* temp = head;
    while (temp) {
        printf("Room No: %d, Status: %c, Occupancy: %d\n", temp->room_no, temp->status, temp->occupancy);
        temp = temp->next;
    }
}

int main() {
    struct room* head = NULL;

    insert_room(head, 101);
    insert_room(head, 102);
    insert_room(head, 103);
    insert_room(head, 104);

    display_rooms(head);

    return 0;
}