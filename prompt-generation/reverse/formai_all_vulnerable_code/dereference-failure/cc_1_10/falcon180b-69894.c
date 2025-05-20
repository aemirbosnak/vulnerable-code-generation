//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int roomNumber;
    char guestName[50];
    int checkInDate;
    int checkOutDate;
    int daysStayed;
    int totalCost;
} Guest;

typedef struct {
    Guest* guests;
    int capacity;
    int numGuests;
} Hotel;

void initializeHotel(Hotel* hotel, int capacity) {
    hotel->guests = (Guest*)malloc(capacity * sizeof(Guest));
    hotel->capacity = capacity;
    hotel->numGuests = 0;
}

void addGuest(Hotel* hotel, Guest guest) {
    if (hotel->numGuests >= hotel->capacity) {
        printf("Hotel is full.\n");
        return;
    }
    hotel->guests[hotel->numGuests] = guest;
    hotel->numGuests++;
}

void removeGuest(Hotel* hotel, int roomNumber) {
    for (int i = 0; i < hotel->numGuests; i++) {
        if (hotel->guests[i].roomNumber == roomNumber) {
            free(hotel->guests[i].guestName);
            hotel->numGuests--;
            for (int j = i; j < hotel->numGuests; j++) {
                hotel->guests[j] = hotel->guests[j+1];
            }
            break;
        }
    }
}

void displayGuests(Hotel* hotel) {
    printf("Guests:\n");
    for (int i = 0; i < hotel->numGuests; i++) {
        printf("Room %d: %s\n", hotel->guests[i].roomNumber, hotel->guests[i].guestName);
        printf("Check-in date: %d\n", hotel->guests[i].checkInDate);
        printf("Check-out date: %d\n", hotel->guests[i].checkOutDate);
        printf("Days stayed: %d\n", hotel->guests[i].daysStayed);
        printf("Total cost: $%d\n\n", hotel->guests[i].totalCost);
    }
}

int main() {
    Hotel hotel;
    initializeHotel(&hotel, 10);

    addGuest(&hotel, (Guest){1, "John Doe", 20220101, 20220105, 4, 200});
    addGuest(&hotel, (Guest){2, "Jane Doe", 20220102, 20220106, 4, 250});

    displayGuests(&hotel);

    removeGuest(&hotel, 1);

    displayGuests(&hotel);

    return 0;
}