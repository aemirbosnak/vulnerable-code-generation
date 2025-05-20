//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room {
    int room_number;
    char room_type;
    int room_capacity;
    float room_price;
    int room_availability;
} room;

typedef struct reservation {
    int reservation_id;
    int room_number;
    char guest_name[50];
    char check_in_date[20];
    char check_out_date[20];
    int num_guests;
    float total_price;
} reservation;

void add_room(room *rooms, int *num_rooms) {
    printf("Enter room number: ");
    scanf("%d", &rooms[*num_rooms].room_number);

    printf("Enter room type (S/D/T): ");
    scanf(" %c", &rooms[*num_rooms].room_type);

    printf("Enter room capacity: ");
    scanf("%d", &rooms[*num_rooms].room_capacity);

    printf("Enter room price: ");
    scanf("%f", &rooms[*num_rooms].room_price);

    rooms[*num_rooms].room_availability = 1;

    (*num_rooms)++;
}

void display_rooms(room *rooms, int num_rooms) {
    printf("\nRooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("Room %d: ", rooms[i].room_number);
        printf("Type: %c, ", rooms[i].room_type);
        printf("Capacity: %d, ", rooms[i].room_capacity);
        printf("Price: %0.2f, ", rooms[i].room_price);
        printf("Availability: %d\n", rooms[i].room_availability);
    }
}

void add_reservation(reservation *reservations, int *num_reservations, room *rooms, int num_rooms) {
    printf("Enter reservation ID: ");
    scanf("%d", &reservations[*num_reservations].reservation_id);

    printf("Enter room number: ");
    scanf("%d", &reservations[*num_reservations].room_number);

    printf("Enter guest name: ");
    scanf(" %[^\n]s", reservations[*num_reservations].guest_name);

    printf("Enter check-in date (YYYY-MM-DD): ");
    scanf(" %s", reservations[*num_reservations].check_in_date);

    printf("Enter check-out date (YYYY-MM-DD): ");
    scanf(" %s", reservations[*num_reservations].check_out_date);

    printf("Enter number of guests: ");
    scanf("%d", &reservations[*num_reservations].num_guests);

    // Calculate total price
    int num_days = (reservations[*num_reservations].check_out_date - reservations[*num_reservations].check_in_date) / 86400;
    reservations[*num_reservations].total_price = num_days * rooms[reservations[*num_reservations].room_number - 1].room_price;

    // Check if room is available
    if (rooms[reservations[*num_reservations].room_number - 1].room_availability == 0) {
        printf("Room is not available for the selected dates.\n");
        return;
    }

    // Mark room as unavailable
    rooms[reservations[*num_reservations].room_number - 1].room_availability = 0;

    (*num_reservations)++;
}

void display_reservations(reservation *reservations, int num_reservations) {
    printf("\nReservations:\n");
    for (int i = 0; i < num_reservations; i++) {
        printf("Reservation %d: ", reservations[i].reservation_id);
        printf("Room: %d, ", reservations[i].room_number);
        printf("Guest: %s, ", reservations[i].guest_name);
        printf("Check-in: %s, ", reservations[i].check_in_date);
        printf("Check-out: %s, ", reservations[i].check_out_date);
        printf("Guests: %d, ", reservations[i].num_guests);
        printf("Total price: %d\n", reservations[i].total_price);
    }
}

int main() {
    // Initialize arrays
    room rooms[100];
    reservation reservations[100];

    int num_rooms = 0;
    int num_reservations = 0;

    // Main loop
    while (1) {
        // Display menu
        printf("\nHotel Management System\n");
        printf("1. Add room\n");
        printf("2. Display rooms\n");
        printf("3. Add reservation\n");
        printf("4. Display reservations\n");
        printf("5. Exit\n");

        // Get user choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_room(rooms, &num_rooms);
                break;
            case 2:
                display_rooms(rooms, num_rooms);
                break;
            case 3:
                add_reservation(reservations, &num_reservations, rooms, num_rooms);
                break;
            case 4:
                display_reservations(reservations, num_reservations);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}