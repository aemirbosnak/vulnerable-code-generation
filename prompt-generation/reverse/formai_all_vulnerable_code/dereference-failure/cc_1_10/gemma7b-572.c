//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Room {
    char name[20];
    int number;
    double rate;
    struct Room* next;
} Room;

typedef struct Guest {
    char name[20];
    char address[100];
    int room_number;
    struct Guest* next;
} Guest;

Room* insertRoom(Room* head, char* name, int number, double rate) {
    Room* newNode = malloc(sizeof(Room));
    strcpy(newNode->name, name);
    newNode->number = number;
    newNode->rate = rate;
    newNode->next = head;
    return newNode;
}

Guest* insertGuest(Guest* head, char* name, char* address, int room_number) {
    Guest* newNode = malloc(sizeof(Guest));
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    newNode->room_number = room_number;
    newNode->next = head;
    return newNode;
}

int main() {
    Room* head = NULL;
    Guest* guestHead = NULL;

    // Insert some rooms
    insertRoom(&head, "Suite 1", 101, 200.0);
    insertRoom(&head, "Suite 2", 102, 150.0);
    insertRoom(&head, "Deluxe Room", 103, 120.0);

    // Insert some guests
    insertGuest(&guestHead, "John Doe", "123 Main St.", 101);
    insertGuest(&guestHead, "Jane Doe", "456 Oak Ave.", 102);
    insertGuest(&guestHead, "Peter Pan", "Neverland", 103);

    // Print the room and guest information
    printf("Rooms:");
    for (Room* currentRoom = head; currentRoom; currentRoom = currentRoom->next) {
        printf("\nName: %s, Number: %d, Rate: %.2lf", currentRoom->name, currentRoom->number, currentRoom->rate);
    }

    printf("\nGuests:");
    for (Guest* currentGuest = guestHead; currentGuest; currentGuest = currentGuest->next) {
        printf("\nName: %s, Address: %s, Room Number: %d", currentGuest->name, currentGuest->address, currentGuest->room_number);
    }

    return 0;
}