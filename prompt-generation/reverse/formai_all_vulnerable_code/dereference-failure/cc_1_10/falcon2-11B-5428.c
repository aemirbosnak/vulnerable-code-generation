//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_NIGHT_STAY 7

typedef struct {
    char name[50];
    int room_number;
    int price_per_night;
    int nights_stayed;
} Guest;

typedef struct {
    Guest guests[MAX_ROOMS];
    int num_guests;
} Hotel;

void create_guest(Guest* guest) {
    srand(time(0));
    int random_room = rand() % MAX_ROOMS;
    guest->room_number = random_room;
    guest->price_per_night = rand() % 100 + 1;
    guest->nights_stayed = rand() % MAX_NIGHT_STAY + 1;
}

void print_guest(Guest* guest) {
    printf("Guest: %s\n", guest->name);
    printf("Room Number: %d\n", guest->room_number);
    printf("Price Per Night: %d\n", guest->price_per_night);
    printf("Nights Stayed: %d\n", guest->nights_stayed);
    printf("\n");
}

void create_hotel() {
    Hotel hotel;
    hotel.num_guests = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        Guest* guest = malloc(sizeof(Guest));
        create_guest(guest);
        hotel.guests[i] = *guest;
        hotel.num_guests++;
    }
}

void print_hotel(Hotel* hotel) {
    printf("Hotel: %d Guests\n", hotel->num_guests);
    for (int i = 0; i < hotel->num_guests; i++) {
        printf("Guest %d: ", i + 1);
        print_guest(&hotel->guests[i]);
        printf("\n");
    }
}

int main() {
    Hotel hotel;
    create_hotel();
    print_hotel(&hotel);
    return 0;
}