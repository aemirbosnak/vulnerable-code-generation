//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a guest
typedef struct guest {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int room_number;
    int days_stayed;
    float bill_amount;
} guest;

// Structure to represent the hotel
typedef struct hotel {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int num_rooms;
    int num_guests;
    guest *guests;
} hotel;

// Function to create a new guest
guest *create_guest(char *name, char *address, char *phone, char *email, int room_number, int days_stayed, float bill_amount) {
    guest *new_guest = (guest *)malloc(sizeof(guest));
    strcpy(new_guest->name, name);
    strcpy(new_guest->address, address);
    strcpy(new_guest->phone, phone);
    strcpy(new_guest->email, email);
    new_guest->room_number = room_number;
    new_guest->days_stayed = days_stayed;
    new_guest->bill_amount = bill_amount;
    return new_guest;
}

// Function to create a new hotel
hotel *create_hotel(char *name, char *address, char *phone, char *email, int num_rooms) {
    hotel *new_hotel = (hotel *)malloc(sizeof(hotel));
    strcpy(new_hotel->name, name);
    strcpy(new_hotel->address, address);
    strcpy(new_hotel->phone, phone);
    strcpy(new_hotel->email, email);
    new_hotel->num_rooms = num_rooms;
    new_hotel->num_guests = 0;
    new_hotel->guests = NULL;
    return new_hotel;
}

// Function to add a guest to the hotel
void add_guest(hotel *h, guest *g) {
    h->guests = (guest *)realloc(h->guests, (h->num_guests + 1) * sizeof(guest));
    h->guests[h->num_guests] = *g;
    h->num_guests++;
}

// Function to find a guest by name
guest *find_guest_by_name(hotel *h, char *name) {
    for (int i = 0; i < h->num_guests; i++) {
        if (strcmp(h->guests[i].name, name) == 0) {
            return &h->guests[i];
        }
    }
    return NULL;
}

// Function to find a guest by room number
guest *find_guest_by_room_number(hotel *h, int room_number) {
    for (int i = 0; i < h->num_guests; i++) {
        if (h->guests[i].room_number == room_number) {
            return &h->guests[i];
        }
    }
    return NULL;
}

// Function to print the details of a guest
void print_guest(guest *g) {
    printf("Name: %s\n", g->name);
    printf("Address: %s\n", g->address);
    printf("Phone: %s\n", g->phone);
    printf("Email: %s\n", g->email);
    printf("Room Number: %d\n", g->room_number);
    printf("Days Stayed: %d\n", g->days_stayed);
    printf("Bill Amount: %.2f\n", g->bill_amount);
}

// Function to print the details of a hotel
void print_hotel(hotel *h) {
    printf("Name: %s\n", h->name);
    printf("Address: %s\n", h->address);
    printf("Phone: %s\n", h->phone);
    printf("Email: %s\n", h->email);
    printf("Number of Rooms: %d\n", h->num_rooms);
    printf("Number of Guests: %d\n", h->num_guests);
    for (int i = 0; i < h->num_guests; i++) {
        print_guest(&h->guests[i]);
    }
}

// Main function
int main() {
    // Create a new hotel
    hotel *h = create_hotel("The Grand Hotel", "123 Main Street", "555-1212", "info@thegrandhotel.com", 100);

    // Create a few guests
    guest *g1 = create_guest("John Doe", "123 Elm Street", "555-1213", "john.doe@email.com", 101, 3, 100.00);
    guest *g2 = create_guest("Jane Doe", "456 Oak Street", "555-1214", "jane.doe@email.com", 102, 2, 150.00);
    guest *g3 = create_guest("Jack Doe", "789 Pine Street", "555-1215", "jack.doe@email.com", 103, 1, 200.00);

    // Add the guests to the hotel
    add_guest(h, g1);
    add_guest(h, g2);
    add_guest(h, g3);

    // Print the details of the hotel
    print_hotel(h);

    return 0;
}