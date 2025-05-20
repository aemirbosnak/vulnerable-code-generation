//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// The hotel has 100 rooms, each with a capacity of 2 guests.
#define NUM_ROOMS 100
#define ROOM_CAPACITY 2

// The hotel's guests are represented by a struct.
typedef struct guest {
    char name[50];
    int age;
} guest;

// The hotel's rooms are represented by a struct.
typedef struct room {
    guest guests[ROOM_CAPACITY];
    int num_guests;
} room;

// The hotel is represented by a struct.
typedef struct hotel {
    room rooms[NUM_ROOMS];
    int num_rooms;
} hotel;

// Create a new hotel.
hotel* create_hotel() {
    hotel* h = malloc(sizeof(hotel));
    h->num_rooms = NUM_ROOMS;
    for (int i = 0; i < NUM_ROOMS; i++) {
        h->rooms[i].num_guests = 0;
    }
    return h;
}

// Check in a guest to a room.
void check_in(hotel* h, guest* g, int room_number) {
    if (room_number < 0 || room_number >= NUM_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }
    if (h->rooms[room_number].num_guests >= ROOM_CAPACITY) {
        printf("Room is full.\n");
        return;
    }
    h->rooms[room_number].guests[h->rooms[room_number].num_guests] = *g;
    h->rooms[room_number].num_guests++;
}

// Check out a guest from a room.
void check_out(hotel* h, guest* g, int room_number) {
    if (room_number < 0 || room_number >= NUM_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }
    for (int i = 0; i < h->rooms[room_number].num_guests; i++) {
        if (strcmp(h->rooms[room_number].guests[i].name, g->name) == 0) {
            h->rooms[room_number].guests[i] = h->rooms[room_number].guests[h->rooms[room_number].num_guests - 1];
            h->rooms[room_number].num_guests--;
            return;
        }
    }
    printf("Guest not found.\n");
}

// Print the hotel's guest list.
void print_guest_list(hotel* h) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("Room %d:\n", i + 1);
        for (int j = 0; j < h->rooms[i].num_guests; j++) {
            printf("    %s, %d\n", h->rooms[i].guests[j].name, h->rooms[i].guests[j].age);
        }
    }
}

// Free the memory allocated for the hotel.
void destroy_hotel(hotel* h) {
    free(h);
}

int main() {
    // Create a new hotel.
    hotel* h = create_hotel();

    // Check in some guests.
    guest g1 = {"Alice", 20};
    check_in(h, &g1, 0);
    guest g2 = {"Bob", 21};
    check_in(h, &g2, 1);
    guest g3 = {"Charlie", 22};
    check_in(h, &g3, 2);

    // Print the hotel's guest list.
    print_guest_list(h);

    // Check out a guest.
    check_out(h, &g2, 1);

    // Print the hotel's guest list again.
    print_guest_list(h);

    // Free the memory allocated for the hotel.
    destroy_hotel(h);

    return 0;
}