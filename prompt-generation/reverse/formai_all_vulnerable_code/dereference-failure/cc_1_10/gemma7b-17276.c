//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct Room {
    char name[20];
    int number;
    struct Room* next;
} Room;

Room* createRoom(char* name, int number) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->number = number;
    newRoom->next = NULL;
    return newRoom;
}

void addRoom(Room* head, char* name, int number) {
    Room* newRoom = createRoom(name, number);
    if (head == NULL) {
        head = newRoom;
    } else {
        head->next = newRoom;
    }
}

int findRoom(Room* head, int number) {
    while (head) {
        if (head->number == number) {
            return 1;
        } else {
            head = head->next;
        }
    }
    return 0;
}

void listRooms(Room* head) {
    while (head) {
        printf("Name: %s, Number: %d\n", head->name, head->number);
        head = head->next;
    }
}

int main() {
    Room* head = NULL;
    addRoom(head, "Room 1", 1);
    addRoom(head, "Room 2", 2);
    addRoom(head, "Room 3", 3);
    listRooms(head);
    if (findRoom(head, 2)) {
        printf("Room 2 found!\n");
    }
    return 0;
}