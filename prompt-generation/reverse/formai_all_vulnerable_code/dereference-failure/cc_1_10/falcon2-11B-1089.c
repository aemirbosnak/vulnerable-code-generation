//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a new guest
void addGuest(char *name, int roomType, char *dateIn, char *dateOut, int *numGuests) {
    char *room = (char *)malloc(sizeof(char) * 10);
    strcpy(room, "Room 1");
    printf("Added guest: %s\n", name);
    printf("Room: %s\n", room);
    printf("Date In: %s\n", dateIn);
    printf("Date Out: %s\n", dateOut);
    printf("Number of Guests: %d\n", *numGuests);
}

// Function to remove a guest
void removeGuest(char *name, int *numGuests) {
    printf("Removed guest: %s\n", name);
    printf("Number of Guests: %d\n", *numGuests);
}

// Function to update a guest's room
void updateRoom(char *name, int roomType, char *dateIn, char *dateOut, int *numGuests) {
    char *room = (char *)malloc(sizeof(char) * 10);
    strcpy(room, "Room 2");
    printf("Updated room: %s\n", name);
    printf("Room: %s\n", room);
    printf("Date In: %s\n", dateIn);
    printf("Date Out: %s\n", dateOut);
    printf("Number of Guests: %d\n", *numGuests);
}

// Function to display all guests
void displayGuests(int numGuests) {
    printf("Number of Guests: %d\n", numGuests);
}

int main() {
    int numGuests = 0;
    char name[50], room[50], dateIn[20], dateOut[20];

    // Add a new guest
    printf("Enter guest's name: ");
    fgets(name, sizeof(name), stdin);
    addGuest(name, 1, dateIn, dateOut, &numGuests);

    // Update the guest's room
    printf("Enter guest's name: ");
    fgets(name, sizeof(name), stdin);
    updateRoom(name, 2, dateIn, dateOut, &numGuests);

    // Remove a guest
    printf("Enter guest's name: ");
    fgets(name, sizeof(name), stdin);
    removeGuest(name, &numGuests);

    // Display all guests
    displayGuests(numGuests);

    return 0;
}