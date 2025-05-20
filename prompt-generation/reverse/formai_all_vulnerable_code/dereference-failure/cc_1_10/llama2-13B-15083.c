//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

typedef struct {
    int guest_id;
    char name[50];
    char email[50];
    int check_in_time;
    int check_out_time;
    int room_num;
} guest_t;

typedef struct {
    int room_id;
    char name[50];
    int capacity;
    int num_guests;
} room_t;

void init_guests(guest_t** guests);
void init_rooms(room_t** rooms);
void check_in(guest_t* guest, room_t* room);
void check_out(guest_t* guest, room_t* room);
void assign_room(guest_t* guest, room_t* room);
void display_guests(guest_t* guests);
void display_rooms(room_t* rooms);

int main() {
    srand(time(NULL));

    // Initialize guests
    guest_t* guests = (guest_t*)calloc(MAX_GUESTS, sizeof(guest_t));
    init_guests(guests);

    // Initialize rooms
    room_t* rooms = (room_t*)calloc(MAX_ROOMS, sizeof(room_t));
    init_rooms(rooms);

    // Check-in guests
    for (int i = 0; i < MAX_GUESTS; i++) {
        guest_t* guest = guests + i;
        room_t* room = rooms + (rand() % MAX_ROOMS);
        check_in(guest, room);
    }

    // Check-out guests
    for (int i = 0; i < MAX_GUESTS; i++) {
        guest_t* guest = guests + i;
        room_t* room = guests[i].room_num;
        check_out(guest, room);
    }

    // Display guests
    display_guests(guests);

    // Display rooms
    display_rooms(rooms);

    return 0;
}

void init_guests(guest_t** guests) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        guest_t* guest = guests + i;
        guest->guest_id = i + 1;
        strcpy(guest->name, "Guest");
        strcpy(guest->email, "guest");
        guest->check_in_time = 0;
        guest->check_out_time = 0;
        guest->room_num = 0;
    }
}

void init_rooms(room_t** rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        room_t* room = rooms + i;
        room->room_id = i + 1;
        strcpy(room->name, "Room");
        room->capacity = 2;
        room->num_guests = 0;
    }
}

void check_in(guest_t* guest, room_t* room) {
    guest->check_in_time = time(NULL);
    guest->room_num = room->room_id;
    room->num_guests++;
}

void check_out(guest_t* guest, room_t* room) {
    guest->check_out_time = time(NULL);
    room->num_guests--;
}

void assign_room(guest_t* guest, room_t* room) {
    guest->room_num = room->room_id;
}

void display_guests(guest_t* guests) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        guest_t* guest = guests + i;
        printf("%d: %s %s %d %d\n",
               guest->guest_id,
               guest->name,
               guest->email,
               guest->check_in_time,
               guest->check_out_time);
    }
}

void display_rooms(room_t* rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        room_t* room = rooms + i;
        printf("%d: %s %d\n",
               room->room_id,
               room->name,
               room->num_guests);
    }
}