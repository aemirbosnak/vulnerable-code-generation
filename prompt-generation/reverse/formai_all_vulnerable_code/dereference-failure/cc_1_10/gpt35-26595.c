//FormAI DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100 // Maximum number of rooms
#define MAX_NAME_LEN 50 // Maximum length of name of guest
#define MAX_NIGHTS 14 // Maximum number of nights guest can stay
#define PRICE_PER_NIGHT 100 // Price per night for a room

// Structure to store hotel rooms
typedef struct {
    int room_num;
    char guest_name[MAX_NAME_LEN];
    int nights;
} Room;

// Function to display menu and read user input
int getMenuChoice() {
    int choice;
    printf("\n-------- Hotel Management System --------\n");
    printf("1. Check-In\n");
    printf("2. Check-Out\n");
    printf("3. Display Rooms\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to check if a room number is valid
int isValidRoom(int room_num, Room *rooms, int num_rooms) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_num == room_num) {
            return 1; // Room number exists
        }
    }
    return 0; // Room number does not exist
}

// Function to check-in a guest
void checkIn(Room *rooms, int num_rooms) {
    int room_num, nights;
    char guest_name[MAX_NAME_LEN];
    printf("\nEnter room number: ");
    scanf("%d", &room_num);
    if (!isValidRoom(room_num, rooms, num_rooms)) {
        printf("Invalid room number.\n");
        return;
    }
    if (rooms[room_num-1].guest_name[0] != '\0') {
        printf("Room is already occupied by %s.\n", rooms[room_num-1].guest_name);
        return;
    }
    printf("Enter guest name: ");
    scanf("%s", guest_name);
    printf("Enter number of nights: ");
    scanf("%d", &nights);
    if (nights > MAX_NIGHTS) {
        printf("Guest cannot stay for more than %d nights.\n", MAX_NIGHTS);
        return;
    }
    rooms[room_num-1].room_num = room_num;
    strncpy(rooms[room_num-1].guest_name, guest_name, MAX_NAME_LEN);
    rooms[room_num-1].nights = nights;
    printf("%s has checked in to room %d for %d nights.\n", guest_name, room_num, nights);
}

// Function to check-out a guest
void checkOut(Room *rooms, int num_rooms) {
    int room_num;
    printf("\nEnter room number: ");
    scanf("%d", &room_num);
    if (!isValidRoom(room_num, rooms, num_rooms)) {
        printf("Invalid room number.\n");
        return;
    }
    if (rooms[room_num-1].guest_name[0] == '\0') {
        printf("Room is already vacant.\n");
        return;
    }
    int nights = rooms[room_num-1].nights;
    int price = nights * PRICE_PER_NIGHT;
    printf("%s has checked out from room %d after staying for %d nights. The total bill is $%d.\n", rooms[room_num-1].guest_name, room_num, nights, price);
    rooms[room_num-1].room_num = room_num;
    rooms[room_num-1].guest_name[0] = '\0';
    rooms[room_num-1].nights = 0;
}

// Function to display list of filled and empty rooms
void displayRooms(Room *rooms, int num_rooms) {
    int i;
    printf("\n-------- Hotel Rooms --------\n");
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].guest_name[0] == '\0') {
            printf("%d. Empty\n", i+1);
        } else {
            printf("%d. Room #%d: %s, %d nights\n", i+1, rooms[i].room_num, rooms[i].guest_name, rooms[i].nights);
        }
    }
}

int main() {
    int num_rooms, choice;
    printf("Enter number of rooms: ");
    scanf("%d", &num_rooms);
    if (num_rooms <= 0 || num_rooms > MAX_ROOMS) {
        printf("Invalid number of rooms.\n");
        return 1;
    }
    Room *rooms = malloc(num_rooms * sizeof(Room));
    int i;
    for (i = 0; i < num_rooms; i++) {
        rooms[i].room_num = i+1; // Initialize room numbers
        rooms[i].guest_name[0] = '\0'; // Initialize guest names to empty string
        rooms[i].nights = 0; // Initialize nights stayed to 0
    }
    while (1) {
        choice = getMenuChoice();
        switch(choice) {
            case 1:
                checkIn(rooms, num_rooms);
                break;
            case 2:
                checkOut(rooms, num_rooms);
                break;
            case 3:
                displayRooms(rooms, num_rooms);
                break;
            case 4:
                printf("Exiting program...\n");
                free(rooms); // Free allocated memory
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}