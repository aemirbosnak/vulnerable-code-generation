//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[20];
    int room_no;
    struct Guest* next;
} Guest;

typedef struct Room {
    int room_no;
    int occupancy;
    struct Room* next;
} Room;

Guest* insertGuest(Guest* head, char* name, int room_no) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = room_no;
    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        Guest* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }

    return head;
}

Room* insertRoom(Room* head, int room_no, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_no = room_no;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        Room* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }

    return head;
}

int findGuest(Guest* head, char* name) {
    Guest* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp->room_no;
        }
        temp = temp->next;
    }

    return -1;
}

int findRoom(Room* head, int room_no) {
    Room* temp = head;
    while (temp) {
        if (temp->room_no == room_no) {
            return temp->occupancy;
        }
        temp = temp->next;
    }

    return -1;
}

int main() {
    Guest* guests = NULL;
    Room* rooms = NULL;

    // Insert some guests
    insertGuest(guests, "Sherlock Holmes", 1);
    insertGuest(guests, "John Watson", 2);
    insertGuest(guests, "Dr. Watson", 3);

    // Insert some rooms
    insertRoom(rooms, 1, 2);
    insertRoom(rooms, 2, 1);
    insertRoom(rooms, 3, 0);

    // Find the room number of Mr. Holmes
    int holmes_room_no = findGuest(guests, "Sherlock Holmes");

    // Find the occupancy of room number 2
    int room_occupancy = findRoom(rooms, 2);

    // Print the results
    printf("Mr. Holmes' room number: %d\n", holmes_room_no);
    printf("Occupancy of room number 2: %d\n", room_occupancy);

    return 0;
}