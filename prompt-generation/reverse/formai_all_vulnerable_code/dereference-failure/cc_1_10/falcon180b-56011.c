//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

struct Room {
    int roomNumber;
    int isAvailable;
};

struct Guest {
    char name[50];
    int roomNumber;
    int daysStayed;
};

void initializeHotel() {
    struct Room *rooms = (struct Room*) malloc(MAX_ROOMS * sizeof(struct Room));

    // Initialize all rooms as available
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isAvailable = 1;
    }
}

int getAvailableRoom() {
    struct Room *rooms = (struct Room*) malloc(MAX_ROOMS * sizeof(struct Room));
    int availableRoom = -1;

    // Find the first available room
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].isAvailable == 1) {
            availableRoom = i + 1;
            rooms[i].isAvailable = 0;
            break;
        }
    }

    free(rooms);
    return availableRoom;
}

void checkIn(struct Guest *guest, struct Room *rooms) {
    int roomNumber = getAvailableRoom();

    if (roomNumber!= -1) {
        guest->roomNumber = roomNumber;
        rooms[roomNumber - 1].isAvailable = 0;
        printf("Welcome to our hotel! Your room number is %d.\n", roomNumber);
    } else {
        printf("Sorry, we are fully booked.\n");
    }
}

void checkOut(struct Guest *guest, struct Room *rooms) {
    rooms[guest->roomNumber - 1].isAvailable = 1;
    printf("Thank you for staying with us. Have a nice day!\n");
}

int main() {
    initializeHotel();

    struct Guest guest;
    printf("What is your name? ");
    scanf("%s", guest.name);

    int roomNumber = getAvailableRoom();

    if (roomNumber!= -1) {
        guest.roomNumber = roomNumber;
        printf("Welcome to our hotel! Your room number is %d.\n", roomNumber);

        int daysStayed;
        printf("How many days will you be staying? ");
        scanf("%d", &daysStayed);

        printf("Enjoy your stay at our hotel!\n");
    } else {
        printf("Sorry, we are fully booked.\n");
    }

    return 0;
}