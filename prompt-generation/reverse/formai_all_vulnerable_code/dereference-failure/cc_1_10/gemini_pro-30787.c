//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char room_id[10];
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int num_guests;
    int num_nights;
    float price;
} Guest;

Guest* create_guest(char* room_id, char* name, char* address, char* phone, char* email, int num_guests, int num_nights, float price) {
    Guest* guest = (Guest*)malloc(sizeof(Guest));
    strcpy(guest->room_id, room_id);
    strcpy(guest->name, name);
    strcpy(guest->address, address);
    strcpy(guest->phone, phone);
    strcpy(guest->email, email);
    guest->num_guests = num_guests;
    guest->num_nights = num_nights;
    guest->price = price;
    return guest;
}

void print_guest(Guest* guest) {
    printf("Room: %s\n", guest->room_id);
    printf("Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Phone: %s\n", guest->phone);
    printf("Email: %s\n", guest->email);
    printf("Number of guests: %d\n", guest->num_guests);
    printf("Number of nights: %d\n", guest->num_nights);
    printf("Price: %.2f\n", guest->price);
}

int main() {
    // Create an array of guests
    Guest* guests[100];

    // Add some guests to the array
    guests[0] = create_guest("101", "John Smith", "123 Main Street", "555-1212", "john.smith@example.com", 2, 3, 120.00);
    guests[1] = create_guest("102", "Jane Doe", "456 Elm Street", "555-1213", "jane.doe@example.com", 1, 2, 80.00);
    guests[2] = create_guest("103", "Bill Jones", "789 Oak Street", "555-1214", "bill.jones@example.com", 3, 4, 160.00);

    // Print the guests
    for (int i = 0; i < 3; i++) {
        print_guest(guests[i]);
        printf("\n");
    }

    return 0;
}