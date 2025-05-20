//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    int room_number;
    char name[50];
    char address[100];
    char phone_number[20];
    char email[50];
    int num_nights;
    float total_cost;
};

struct hotel {
    int num_rooms;
    struct guest *guests;
};

struct hotel *create_hotel(int num_rooms) {
    struct hotel *hotel = malloc(sizeof(struct hotel));
    hotel->num_rooms = num_rooms;
    hotel->guests = malloc(num_rooms * sizeof(struct guest));
    return hotel;
}

void free_hotel(struct hotel *hotel) {
    free(hotel->guests);
    free(hotel);
}

int check_in_guest(struct hotel *hotel, struct guest *guest) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        if (hotel->guests[i].room_number == 0) {
            hotel->guests[i] = *guest;
            return 1;
        }
    }
    return 0;
}

int check_out_guest(struct hotel *hotel, int room_number) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        if (hotel->guests[i].room_number == room_number) {
            hotel->guests[i].room_number = 0;
            return 1;
        }
    }
    return 0;
}

void print_guest_info(struct hotel *hotel, int room_number) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        if (hotel->guests[i].room_number == room_number) {
            printf("Room number: %d\n", hotel->guests[i].room_number);
            printf("Name: %s\n", hotel->guests[i].name);
            printf("Address: %s\n", hotel->guests[i].address);
            printf("Phone number: %s\n", hotel->guests[i].phone_number);
            printf("Email: %s\n", hotel->guests[i].email);
            printf("Number of nights: %d\n", hotel->guests[i].num_nights);
            printf("Total cost: %.2f\n", hotel->guests[i].total_cost);
        }
    }
}

int main() {
    struct hotel *hotel = create_hotel(10);

    struct guest guest1 = {
        .room_number = 101,
        .name = "John Smith",
        .address = "123 Main Street",
        .phone_number = "555-123-4567",
        .email = "john.smith@example.com",
        .num_nights = 3,
        .total_cost = 1000.00
    };

    check_in_guest(hotel, &guest1);

    struct guest guest2 = {
        .room_number = 102,
        .name = "Jane Doe",
        .address = "456 Elm Street",
        .phone_number = "555-234-5678",
        .email = "jane.doe@example.com",
        .num_nights = 4,
        .total_cost = 1200.00
    };

    check_in_guest(hotel, &guest2);

    print_guest_info(hotel, 101);
    print_guest_info(hotel, 102);

    check_out_guest(hotel, 101);

    free_hotel(hotel);

    return 0;
}