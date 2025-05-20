//FormAI DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_AMT 10 // defines the number of rooms the hotel has
#define MAX_NAME_LEN 50 // defines the maximum length of a guest's name

// struct that defines a guest
typedef struct {
    char name[MAX_NAME_LEN];
    unsigned int room_number;
    unsigned int num_nights_staying;
} Guest;

// function to display the hotel's current occupancy and available rooms
void display_occupancy(Guest* guests) {
    int num_guests = 0;
    int occupied_rooms[ROOM_AMT];
    int num_occupied_rooms = 0;

    for (int i = 0; i < ROOM_AMT; i++) {
        if (guests[i].name[0] != '\0') {
            num_guests++;
            occupied_rooms[num_occupied_rooms] = guests[i].room_number;
            num_occupied_rooms++;
        }
    }

    printf("Current Occupancy:\n");
    printf("Number of guests: %d\n", num_guests);

    if (num_guests > 0) {
        printf("Guests in rooms: ");
        for (int i = 0; i < num_occupied_rooms; i++) {
            printf("%d ", occupied_rooms[i]);
        }
        printf("\n");
    }

    int num_avail_rooms = ROOM_AMT - num_guests;
    printf("Number of available rooms: %d\n", num_avail_rooms);
}

// function to add a guest to the hotel's guest list
void add_guest(Guest* guests) {
    int room_number;
    char guest_name[MAX_NAME_LEN];
    int num_nights_staying;

    printf("Room number: ");
    scanf("%d", &room_number);
    printf("Guest name: ");
    scanf("%s", guest_name);
    printf("Number of nights staying: ");
    scanf("%d", &num_nights_staying);

    guests[room_number-1].room_number = room_number;
    strcpy(guests[room_number-1].name, guest_name);
    guests[room_number-1].num_nights_staying = num_nights_staying;

    printf("%s has been checked into room %d for %d nights.\n", guest_name, room_number, num_nights_staying);
}

// function to remove a guest from the hotel's guest list
void remove_guest(Guest* guests) {
    int room_number;

    printf("Room number: ");
    scanf("%d", &room_number);

    if (guests[room_number-1].name[0] != '\0') {
        printf("%s has been checked out of room %d.\n", guests[room_number-1].name, room_number);
        guests[room_number-1].room_number = 0;
        guests[room_number-1].name[0] = '\0';
        guests[room_number-1].num_nights_staying = 0;
    } else {
        printf("Room %d is not currently occupied.\n", room_number);
    }
}

int main() {
    Guest guests[ROOM_AMT];
    memset(guests, 0, sizeof guests); // set all guest structs to initial values

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Display occupancy\n");
        printf("2. Check in a guest\n");
        printf("3. Check out a guest\n");
        printf("4. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_occupancy(guests);
                break;
            case 2:
                add_guest(guests);
                break;
            case 3:
                remove_guest(guests);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return EXIT_SUCCESS;
}