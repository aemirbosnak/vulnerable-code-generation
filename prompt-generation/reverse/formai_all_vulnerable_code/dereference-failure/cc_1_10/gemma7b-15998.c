//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[20];
    int room_no;
    struct Guest* next;
} Guest;

typedef struct Room {
    int no;
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
    scanf("%d", &newRoom->no);
    printf("Enter occupancy: ");
    scanf("%d", &newRoom->occupancy);
    newRoom->next = head;
    head = newRoom;
    return head;
}

void checkIn(Guest* head, Room* headRoom) {
    printf("Enter guest name: ");
    char guestName[20];
    scanf("%s", guestName);
    Guest* guest = head;
    while (guest) {
        if (strcmp(guest->name, guestName) == 0) {
            int roomNo;
            printf("Enter room number: ");
            scanf("%d", &roomNo);
            Room* room = headRoom;
            while (room) {
                if (room->no == roomNo) {
                    if (room->occupancy == 0) {
                        room->occupancy = 1;
                        printf("Room booked!\n");
                        return;
                    } else {
                        printf("Room is full!\n");
                    }
                }
            }
            printf("Room not found!\n");
        }
        guest = guest->next;
    }
    printf("Guest not found!\n");
}

void checkOut(Guest* head, Room* headRoom) {
    printf("Enter guest name: ");
    char guestName[20];
    scanf("%s", guestName);
    Guest* guest = head;
    while (guest) {
        if (strcmp(guest->name, guestName) == 0) {
            int roomNo;
            printf("Enter room number: ");
            scanf("%d", &roomNo);
            Room* room = headRoom;
            while (room) {
                if (room->no == roomNo) {
                    room->occupancy = 0;
                    printf("Room vacated!\n");
                    return;
                }
            }
            printf("Room not found!\n");
        }
        guest = guest->next;
    }
    printf("Guest not found!\n");
}

int main() {
    Guest* headGuest = NULL;
    Room* headRoom = NULL;

    // Insert guests and rooms
    insertGuest(headGuest);
    insertGuest(headGuest);
    insertRoom(headRoom);
    insertRoom(headRoom);

    // Check in and out guests
    checkOut(headGuest, headRoom);
    checkIn(headGuest, headRoom);

    return 0;
}