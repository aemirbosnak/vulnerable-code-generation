//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct Room {
    int number;
    char status;
    char type;
    int price;
    struct Room* next;
} Room;

Room* createRoom(int number, char status, char type, int price) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->status = status;
    newRoom->type = type;
    newRoom->price = price;
    newRoom->next = NULL;

    return newRoom;
}

void insertRoom(Room* head, Room* newRoom) {
    if (head == NULL) {
        head = newRoom;
    } else {
        newRoom->next = head;
        head = newRoom;
    }
}

void printRooms(Room* head) {
    while (head) {
        printf("Room Number: %d, Status: %c, Type: %c, Price: %d\n", head->number, head->status, head->type, head->price);
        head = head->next;
    }
}

int main() {
    Room* head = NULL;

    insertRoom(head, createRoom(1, 'O', 'D', 100));
    insertRoom(head, createRoom(2, 'A', 'F', 120));
    insertRoom(head, createRoom(3, 'B', 'R', 150));

    printRooms(head);

    return 0;
}