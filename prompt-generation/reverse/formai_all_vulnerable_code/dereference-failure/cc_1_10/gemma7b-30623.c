//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Guests 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_no;
    struct Guest* next;
} Guest;

typedef struct Room {
    int no;
    int capacity;
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

Room* insertRoom(Room* head, int no, int capacity) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->no = no;
    newRoom->capacity = capacity;
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

void checkIn(Guest* head) {
    printf("Welcome, %s! Please proceed to your room: ", head->name);
    printf("%d\n", head->room_no);
}

void checkOut(Guest* head) {
    printf("Thank you for your stay, %s. Have a pleasant day!", head->name);
}

int main() {
    Guest* head = NULL;
    Room* headRoom = NULL;

    // Insert guests
    insertGuest(head, "John Doe", 101);
    insertGuest(head, "Jane Doe", 102);
    insertGuest(head, "Peter Pan", 103);

    // Insert rooms
    insertRoom(headRoom, 101, 2);
    insertRoom(headRoom, 102, 3);
    insertRoom(headRoom, 103, 4);

    // Check in a guest
    checkOut(head);

    // Check out a guest
    checkOut(head);

    return 0;
}