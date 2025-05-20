//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mind-bending macros
#define ROOM_BOOKED    (1 << 0)    // Binary flag for room booked
#define ROOM_AVAILABLE (1 << 1)    // Binary flag for room available
#define ROOM_CLEAN     (1 << 2)    // Binary flag for room clean

// Trippy room status codes
typedef enum {
    ROOM_VACANT    = 0,
    ROOM_OCCUPIED  = 1,
    ROOM_IN_FLUX   = 2,
    ROOM_OUT_OF_IT = 3
} RoomStatus;

// Freaky room types
typedef enum {
    ROOM_SINGLE    = 0,
    ROOM_DOUBLE    = 1,
    ROOM_SUITE     = 2,
    ROOM_PRESIDENTIAL = 3
} RoomType;

// Mesmerizing hotel structure
typedef struct {
    int room_number;
    RoomStatus room_status;
    RoomType room_type;
    char *guest_name;
    long check_in_date;
    long check_out_date;
} HotelRoom;

// Initialize the hotel with some trippy rooms
HotelRoom *init_hotel(int num_rooms) {
    HotelRoom *hotel = calloc(num_rooms, sizeof(HotelRoom));
    for (int i = 0; i < num_rooms; i++) {
        hotel[i].room_number = i + 1;
        hotel[i].room_status = ROOM_VACANT;
        hotel[i].room_type = ROOM_SINGLE;
        hotel[i].guest_name = NULL;
        hotel[i].check_in_date = 0;
        hotel[i].check_out_date = 0;
    }
    return hotel;
}

// Book a room with some psychedelic effects
int book_room(HotelRoom *hotel, int num_rooms, char *guest_name, int room_type) {
    for (int i = 0; i < num_rooms; i++) {
        if (hotel[i].room_status == ROOM_VACANT && hotel[i].room_type == room_type) {
            hotel[i].room_status = ROOM_BOOKED;
            hotel[i].guest_name = strdup(guest_name);
            hotel[i].check_in_date = time(NULL);
            hotel[i].check_out_date = 0;
            return hotel[i].room_number;
        }
    }
    return -1;
}

// Check out of a room and enter a new dimension
int check_out(HotelRoom *hotel, int num_rooms, int room_number) {
    for (int i = 0; i < num_rooms; i++) {
        if (hotel[i].room_number == room_number) {
            hotel[i].room_status = ROOM_VACANT;
            hotel[i].guest_name = NULL;
            hotel[i].check_in_date = 0;
            hotel[i].check_out_date = time(NULL);
            return 0;
        }
    }
    return -1;
}

// Print the hotel status in a mind-altering way
void print_hotel_status(HotelRoom *hotel, int num_rooms) {
    printf("---------------------------------------------------------------\n");
    printf("| Room | Status | Type | Guest Name | Check-In Date | Check-Out Date |\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("| %4d | ", hotel[i].room_number);
        switch (hotel[i].room_status) {
            case ROOM_VACANT:    printf("VACANT    | "); break;
            case ROOM_OCCUPIED:  printf("OCCUPIED  | "); break;
            case ROOM_IN_FLUX:   printf("IN_FLUX   | "); break;
            case ROOM_OUT_OF_IT: printf("OUT_OF_IT | "); break;
        }
        switch (hotel[i].room_type) {
            case ROOM_SINGLE:    printf("SINGLE    | "); break;
            case ROOM_DOUBLE:    printf("DOUBLE    | "); break;
            case ROOM_SUITE:     printf("SUITE     | "); break;
            case ROOM_PRESIDENTIAL: printf("PRESIDENTIAL | "); break;
        }
        printf("%10s | ", hotel[i].guest_name);
        printf("%16ld | ", hotel[i].check_in_date);
        printf("%16ld |\n", hotel[i].check_out_date);
    }
    printf("---------------------------------------------------------------\n");
}

int main() {
    // Create a hotel with 10 trippy rooms
    HotelRoom *hotel = init_hotel(10);

    // Book some rooms with psychedelic guest names
    int room_num1 = book_room(hotel, 10, "Alice", ROOM_SINGLE);
    int room_num2 = book_room(hotel, 10, "Bob", ROOM_DOUBLE);
    int room_num3 = book_room(hotel, 10, "Charlie", ROOM_SUITE);

    // Check out of some rooms and enter a new dimension
    check_out(hotel, 10, room_num1);
    check_out(hotel, 10, room_num2);

    // Print the hotel status in a mind-altering way
    print_hotel_status(hotel, 10);

    // Free the hotel rooms from the ether
    for (int i = 0; i < 10; i++) {
        free(hotel[i].guest_name);
    }
    free(hotel);

    return 0;
}