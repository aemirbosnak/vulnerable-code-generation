//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 10
#define AVG_STAY 2

typedef struct {
    int guest_id;
    char name[50];
    char email[50];
    int check_in_date;
    int check_out_date;
    int num_nights;
} guest_t;

typedef struct {
    int room_id;
    char name[50];
    int capacity;
    int num_guests;
} room_t;

// Global variables
guest_t guests[MAX_GUESTS];
room_t rooms[MAX_ROOMS];
int num_guests = 0;
int num_rooms = 0;

// Function to read data from a file
void read_data() {
    FILE *file = fopen("data.txt", "r");
    char line[100];
    int i = 0;

    while (fgets(line, 100, file)) {
        // Ignore empty lines and comments
        if (strcmp(line, "") != 0 && line[0] != '#') {
            // Parse guest data
            sscanf(line, "%d %s %s %d %d", &guests[i].guest_id, guests[i].name, guests[i].email, &guests[i].check_in_date, &guests[i].num_nights);
            i++;
        }
    }
    fclose(file);
}

// Function to write data to a file
void write_data() {
    FILE *file = fopen("data.txt", "w");
    int i = 0;

    for (i = 0; i < num_guests; i++) {
        fprintf(file, "%d %s %s %d %d\n", guests[i].guest_id, guests[i].name, guests[i].email, guests[i].check_in_date, guests[i].num_nights);
    }
    fclose(file);
}

// Function to check availability of rooms
int check_availability(int room_id) {
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_id == room_id) {
            return rooms[i].capacity - rooms[i].num_guests;
        }
    }
    return -1;
}

// Function to book a room
void book_room(int room_id) {
    int availability = check_availability(room_id);

    if (availability > 0) {
        rooms[availability].num_guests++;
        printf("Room %d is booked by guest %d\n", room_id, rooms[availability].num_guests);
    } else {
        printf("No rooms available\n");
    }
}

// Function to check if a guest has checked out
int check_checkout(int guest_id) {
    for (int i = 0; i < num_guests; i++) {
        if (guests[i].guest_id == guest_id) {
            return guests[i].check_out_date;
        }
    }
    return -1;
}

// Function to check if a guest has overstayed
int check_overstay(int guest_id) {
    int checkout_date = check_checkout(guest_id);

    if (checkout_date != -1) {
        return (clock() - checkout_date) / 3600 / 24;
    }
    return -1;
}

int main() {
    // Read data from file
    read_data();

    // Print list of guests and their information
    for (int i = 0; i < num_guests; i++) {
        printf("%d - %s %s %d %d\n", guests[i].guest_id, guests[i].name, guests[i].email, guests[i].check_in_date, guests[i].num_nights);
    }

    // Print list of rooms and their information
    for (int i = 0; i < num_rooms; i++) {
        printf("%d - %s %d\n", rooms[i].room_id, rooms[i].name, rooms[i].capacity);
    }

    // Print available rooms
    for (int i = 0; i < num_rooms; i++) {
        printf("%d is available\n", rooms[i].room_id);
    }

    // Book a room
    int room_id = 1;
    book_room(room_id);

    // Check if a guest has overstayed
    int guest_id = 2;
    int overstay = check_overstay(guest_id);

    if (overstay > 0) {
        printf("Guest %d has overstayed by %d days\n", guest_id, overstay);
    }

    return 0;
}