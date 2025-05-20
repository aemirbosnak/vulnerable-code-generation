//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel room details
typedef struct room {
    int room_number;
    char room_type;  // 'S' for single, 'D' for double, 'F' for family
    int num_beds;
    float price;
    int booked;  // 0 for available, 1 for booked
} room;

// Structure to store guest details
typedef struct guest {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int num_days;
    room *room_booked;  // Pointer to the room booked by the guest
} guest;

// Function to create a new room
room *create_room(int room_number, char room_type, int num_beds, float price) {
    room *new_room = (room *)malloc(sizeof(room));
    new_room->room_number = room_number;
    new_room->room_type = room_type;
    new_room->num_beds = num_beds;
    new_room->price = price;
    new_room->booked = 0;
    return new_room;
}

// Function to create a new guest
guest *create_guest(char *name, char *address, char *phone, char *email, int num_days, room *room_booked) {
    guest *new_guest = (guest *)malloc(sizeof(guest));
    strcpy(new_guest->name, name);
    strcpy(new_guest->address, address);
    strcpy(new_guest->phone, phone);
    strcpy(new_guest->email, email);
    new_guest->num_days = num_days;
    new_guest->room_booked = room_booked;
    return new_guest;
}

// Function to check availability of a room
int is_room_available(room *room, int date) {
    // Check if the room is already booked for the given date
    if (room->booked == 1) {
        return 0;
    }
    return 1;
}

// Function to book a room
int book_room(room *room, guest *guest, int date) {
    // Check if the room is available for the given date
    if (!is_room_available(room, date)) {
        return 0;
    }

    // Book the room
    room->booked = 1;
    guest->room_booked = room;
    return 1;
}

// Function to cancel a room booking
int cancel_room_booking(room *room, guest *guest) {
    // Check if the room is booked by the guest
    if (room->booked == 0 || room->booked != guest->room_booked->room_number) {
        return 0;
    }

    // Cancel the room booking
    room->booked = 0;
    guest->room_booked = NULL;
    return 1;
}

// Function to print the details of a room
void print_room_details(room *room) {
    printf("Room Number: %d\n", room->room_number);
    printf("Room Type: %c\n", room->room_type);
    printf("Number of Beds: %d\n", room->num_beds);
    printf("Price: %f\n", room->price);
    printf("Booked: %d\n", room->booked);
    printf("\n");
}

// Function to print the details of a guest
void print_guest_details(guest *guest) {
    printf("Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Phone: %s\n", guest->phone);
    printf("Email: %s\n", guest->email);
    printf("Number of Days: %d\n", guest->num_days);
    printf("Room Booked: %d\n", guest->room_booked->room_number);
    printf("\n");
}

// Main function
int main() {
    // Create a few sample rooms
    room *room1 = create_room(101, 'S', 1, 1000.0);
    room *room2 = create_room(102, 'D', 2, 1500.0);
    room *room3 = create_room(103, 'F', 4, 2000.0);

    // Create a few sample guests
    guest *guest1 = create_guest("John Doe", "123 Main Street", "555-1212", "john.doe@email.com", 3, NULL);
    guest *guest2 = create_guest("Jane Smith", "456 Elm Street", "555-2323", "jane.smith@email.com", 5, NULL);
    guest *guest3 = create_guest("Bill Jones", "789 Oak Street", "555-3434", "bill.jones@email.com", 7, NULL);

    // Book a room for the first guest
    book_room(room1, guest1, 1);

    // Print the details of the first guest
    print_guest_details(guest1);

    // Cancel the room booking for the first guest
    cancel_room_booking(room1, guest1);

    // Book a room for the second guest
    book_room(room2, guest2, 3);

    // Print the details of the second guest
    print_guest_details(guest2);

    // Free the memory allocated for the rooms and guests
    free(room1);
    free(room2);
    free(room3);
    free(guest1);
    free(guest2);
    free(guest3);

    return 0;
}