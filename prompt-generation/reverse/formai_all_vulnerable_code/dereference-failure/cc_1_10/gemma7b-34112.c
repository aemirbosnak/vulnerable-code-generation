//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROOMS 100

typedef struct Room {
    char name[20];
    int number;
    double price;
    struct Room* next;
} Room;

Room* createRoom(char* name, int number, double price) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->number = number;
    newRoom->price = price;
    newRoom->next = NULL;
    return newRoom;
}

void addRoom(Room* head, char* name, int number, double price) {
    Room* newRoom = createRoom(name, number, price);
    if (head == NULL) {
        head = newRoom;
    } else {
        head->next = newRoom;
    }
    head = newRoom;
}

int searchRoom(Room* head, int number) {
    while (head) {
        if (head->number == number) {
            return 1;
        } else {
            head = head->next;
        }
    }
    return 0;
}

void printRooms(Room* head) {
    while (head) {
        printf("Name: %s, Number: %d, Price: %.2lf\n", head->name, head->number, head->price);
        head = head->next;
    }
}

int main() {
    Room* head = NULL;
    addRoom(head, "Room 1", 101, 50.0);
    addRoom(head, "Room 2", 102, 60.0);
    addRoom(head, "Room 3", 103, 70.0);

    printRooms(head);

    if (searchRoom(head, 102) == 1) {
        printf("Room 102 found!\n");
    } else {
        printf("Room 102 not found.\n");
    }

    return 0;
}