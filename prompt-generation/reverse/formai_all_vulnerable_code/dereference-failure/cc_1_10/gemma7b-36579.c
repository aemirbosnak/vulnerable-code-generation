//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_no;
    struct Guest* next;
} Guest;

typedef struct Room {
    int room_no;
    int occupancy;
    struct Room* next;
} Room;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter guest name: ");
    scanf("%s", newGuest->name);
    printf("Enter room number: ");
    scanf("%d", &newGuest->room_no);

    newGuest->next = head;
    head = newGuest;

    return head;
}

Room* insertRoom(Room* head) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    printf("Enter room number: ");
    scanf("%d", &newRoom->room_no);
    printf("Enter occupancy: ");
    scanf("%d", &newRoom->occupancy);

    newRoom->next = head;
    head = newRoom;

    return head;
}

void checkIn(Guest* head, Room* headRoom) {
    char guestName[50];
    printf("Enter guest name: ");
    scanf("%s", guestName);

    Guest* currentGuest = head;
    Room* currentRoom = headRoom;

    while (currentGuest) {
        if (strcmp(currentGuest->name, guestName) == 0) {
            currentRoom = headRoom;

            while (currentRoom) {
                if (currentRoom->occupancy == 0) {
                    currentRoom->occupancy = 1;
                    currentGuest->room_no = currentRoom->room_no;
                    printf("Room assigned: %d\n", currentRoom->room_no);
                    break;
                }
                currentRoom = currentRoom->next;
            }

            if (currentRoom == NULL) {
                printf("No rooms available for this guest.\n");
            }
            break;
        }
        currentGuest = currentGuest->next;
    }

    if (currentGuest == NULL) {
        printf("Guest not found.\n");
    }
}

void checkOut(Guest* head, Room* headRoom) {
    char guestName[50];
    printf("Enter guest name: ");
    scanf("%s", guestName);

    Guest* currentGuest = head;
    Room* currentRoom = headRoom;

    while (currentGuest) {
        if (strcmp(currentGuest->name, guestName) == 0) {
            currentGuest->room_no = 0;
            currentRoom = headRoom;

            while (currentRoom) {
                if (currentRoom->occupancy == 1 && currentRoom->room_no == currentGuest->room_no) {
                    currentRoom->occupancy = 0;
                    printf("Room released: %d\n", currentRoom->room_no);
                    break;
                }
                currentRoom = currentRoom->next;
            }

            if (currentRoom == NULL) {
                printf("Guest not found or room not occupied.\n");
            }
            break;
        }
        currentGuest = currentGuest->next;
    }

    if (currentGuest == NULL) {
        printf("Guest not found.\n");
    }
}

int main() {
    Guest* headGuest = NULL;
    Room* headRoom = NULL;

    insertGuest(headGuest);
    insertGuest(headGuest);
    insertRoom(headRoom);
    insertRoom(headRoom);

    checkOut(headGuest, headRoom);
    checkIn(headGuest, headRoom);

    return 0;
}