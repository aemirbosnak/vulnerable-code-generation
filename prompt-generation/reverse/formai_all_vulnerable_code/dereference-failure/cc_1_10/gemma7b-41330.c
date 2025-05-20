//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

typedef struct Room {
    int number;
    char type;
    int occupancy;
    struct Room* next;
} Room;

Room* CreateRoom(int number, char type, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;
    return newRoom;
}

void InsertRoom(Room* head, int number, char type, int occupancy) {
    Room* newRoom = CreateRoom(number, type, occupancy);
    if (head == NULL) {
        head = newRoom;
    } else {
        Room* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newRoom;
    }
}

void PrintRooms(Room* head) {
    Room* current = head;
    while (current) {
        printf("Room number: %d, Type: %c, Occupancy: %d\n", current->number, current->type, current->occupancy);
        current = current->next;
    }
}

int main() {
    Room* head = NULL;
    InsertRoom(head, 101, 'A', 2);
    InsertRoom(head, 102, 'B', 1);
    InsertRoom(head, 103, 'A', 0);
    InsertRoom(head, 104, 'B', 2);
    PrintRooms(head);
    return 0;
}