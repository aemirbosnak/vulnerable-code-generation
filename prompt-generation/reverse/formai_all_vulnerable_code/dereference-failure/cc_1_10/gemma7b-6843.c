//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

typedef struct Room {
    int number;
    char type;
    int occupancy;
    struct Room* next;
} Room;

Room* createRoom(int number, char type, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;
    return newRoom;
}

void insertRoom(Room* head, int number, char type, int occupancy) {
    Room* newRoom = createRoom(number, type, occupancy);
    if (head == NULL) {
        head = newRoom;
    } else {
        Room* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }
}

int searchRoom(Room* head, int number) {
    Room* temp = head;
    while (temp) {
        if (temp->number == number) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    Room* head = NULL;
    insertRoom(head, 101, 'A', 2);
    insertRoom(head, 102, 'B', 1);
    insertRoom(head, 103, 'A', 3);
    insertRoom(head, 104, 'B', 2);

    if (searchRoom(head, 102) == 1) {
        printf("Room 102 is found.\n");
    }

    return 0;
}