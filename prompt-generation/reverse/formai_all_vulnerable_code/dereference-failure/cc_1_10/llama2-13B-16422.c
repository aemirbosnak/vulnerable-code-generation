//LLAMA2-13B DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_GUESTS 10

typedef struct guest {
    char name[MAX_NAME_LEN];
    int arrival_time;
    int departure_time;
} guest_t;

typedef struct room {
    char name[MAX_NAME_LEN];
    int capacity;
    int num_guests;
} room_t;

void add_guest(room_t *room, char *name) {
    if (room->num_guests < room->capacity) {
        strcpy(room->name, name);
        room->num_guests++;
    }
}

void remove_guest(room_t *room) {
    if (room->num_guests > 0) {
        room->num_guests--;
    }
}

void print_room(room_t *room) {
    printf("%s (%d guests)\n", room->name, room->num_guests);
}

int main() {
    srand(time(NULL));

    // Create a list of rooms
    room_t rooms[MAX_GUESTS];
    for (int i = 0; i < MAX_GUESTS; i++) {
        rooms[i].name[0] = '\0';
        rooms[i].capacity = rand() % 5 + 1;
        rooms[i].num_guests = 0;
    }

    // Add guests to rooms
    char guest_names[MAX_GUESTS][MAX_NAME_LEN];
    for (int i = 0; i < MAX_GUESTS; i++) {
        sprintf(guest_names[i], "Guest %d", i + 1);
        add_guest(&rooms[i], guest_names[i]);
    }

    // Print rooms
    for (int i = 0; i < MAX_GUESTS; i++) {
        print_room(&rooms[i]);
    }

    // Remove guests
    for (int i = 0; i < MAX_GUESTS; i++) {
        remove_guest(&rooms[i]);
    }

    // Print final rooms
    for (int i = 0; i < MAX_GUESTS; i++) {
        print_room(&rooms[i]);
    }

    return 0;
}