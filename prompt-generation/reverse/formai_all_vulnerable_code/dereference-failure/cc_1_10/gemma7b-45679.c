//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_num;
    struct Guest* next;
} Guest;

typedef struct Room {
    int room_num;
    int occupancy;
    struct Room* next;
} Room;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter guest name: ");
    scanf("%s", newGuest->name);
    printf("Enter room number: ");
    scanf("%d", &newGuest->room_num);
    newGuest->next = head;
    return newGuest;
}

Room* insertRoom(Room* head) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    printf("Enter room number: ");
    scanf("%d", &newRoom->room_num);
    printf("Enter occupancy: ");
    scanf("%d", &newRoom->occupancy);
    newRoom->next = head;
    return newRoom;
}

void checkIn(Guest* head, Room* headRoom) {
    char guestName[50];
    printf("Enter guest name: ");
    scanf("%s", guestName);
    Guest* currentGuest = head;
    while (currentGuest) {
        if (strcmp(guestName, currentGuest->name) == 0) {
            int roomNum;
            printf("Enter room number: ");
            scanf("%d", &roomNum);
            Room* currentRoom = headRoom;
            while (currentRoom) {
                if (currentRoom->room_num == roomNum) {
                    if (currentRoom->occupancy == 0) {
                        currentRoom->occupancy = 1;
                        printf("Check-in successful!\n");
                        return;
                    } else {
                        printf("Room is occupied!\n");
                        return;
                    }
                }
            }
            printf("Room not found!\n");
            return;
        }
        currentGuest = currentGuest->next;
    }
    printf("Guest not found!\n");
    return;
}

void checkOut(Guest* head, Room* headRoom) {
    char guestName[50];
    printf("Enter guest name: ");
    scanf("%s", guestName);
    Guest* currentGuest = head;
    while (currentGuest) {
        if (strcmp(guestName, currentGuest->name) == 0) {
            int roomNum;
            printf("Enter room number: ");
            scanf("%d", &roomNum);
            Room* currentRoom = headRoom;
            while (currentRoom) {
                if (currentRoom->room_num == roomNum) {
                    currentRoom->occupancy = 0;
                    printf("Check-out successful!\n");
                    return;
                }
            }
            printf("Room not found!\n");
            return;
        }
        currentGuest = currentGuest->next;
    }
    printf("Guest not found!\n");
    return;
}

int main() {
    Guest* headGuest = NULL;
    Room* headRoom = NULL;

    int choice;
    while (1) {
        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertGuest(headGuest);
                break;
            case 2:
                checkOut(headGuest, headRoom);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    return 0;
}