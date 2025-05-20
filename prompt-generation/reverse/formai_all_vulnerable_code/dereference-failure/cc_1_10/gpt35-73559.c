//FormAI DATASET v1.0 Category: Hotel Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int room_no;
    int capacity;
    float price;
    int booked;
};

struct Guest {
    int id;
    char name[50];
    int room_no;
    int duration;
};

void display_menu() {
    printf("Welcome to C Hotel Management System!\n");
    printf("1. Display available rooms\n");
    printf("2. Book a room\n");
    printf("3. Check out\n");
    printf("4. Display all guests\n");
    printf("5. Exit\n");
}

struct Room* create_room(int room_no, int capacity, float price) {
    struct Room* room = (struct Room*) malloc(sizeof(struct Room));
    room->room_no = room_no;
    room->capacity = capacity;
    room->price = price;
    room->booked = 0;
    return room;
}

struct Room** create_rooms() {
    struct Room** rooms = (struct Room**) malloc(sizeof(struct Room*) * 5);

    rooms[0] = create_room(101, 2, 100.0);
    rooms[1] = create_room(102, 2, 120.0);
    rooms[2] = create_room(103, 3, 150.0);
    rooms[3] = create_room(104, 3, 170.0);
    rooms[4] = create_room(105, 4, 200.0);

    return rooms;
}

void display_rooms(struct Room** rooms, int len) {
    printf("Rooms available:\n");
    for (int i = 0; i < len; i++) {
        struct Room* room = rooms[i];
        if (!room->booked) {
            printf("Room %d - %d people - $%.2f per night\n", room->room_no, room->capacity, room->price);
        }
    }
}

int find_available_room(struct Room** rooms, int len, int capacity) {
    for (int i = 0; i < len; i++) {
        struct Room* room = rooms[i];
        if (!room->booked && room->capacity >= capacity) {
            return room->room_no;
        }
    }
    return -1;
}

struct Guest* create_guest(int id, char* name, int room_no, int duration) {
    struct Guest* guest = (struct Guest*) malloc(sizeof(struct Guest));
    guest->id = id;
    strcpy(guest->name, name);
    guest->room_no = room_no;
    guest->duration = duration;
    return guest;
}

struct Guest** create_guests() {
    struct Guest** guests = (struct Guest**) malloc(sizeof(struct Guest*) * 5);

    guests[0] = create_guest(1001, "John Doe", 101, 3);
    guests[1] = create_guest(1002, "Jane Smith", 102, 4);
    guests[2] = create_guest(1003, "Bob Johnson", 104, 2);
    guests[3] = create_guest(1004, "Mary Lee", 105, 5);
    guests[4] = create_guest(1005, "David Kim", 103, 3);

    return guests;
}

void book_room(struct Guest** guests, int len, struct Room** rooms, int room_no, char* name, int duration) {
    int id = guests[len - 1]->id + 1;
    struct Guest* guest = create_guest(id, name, room_no, duration);
    guests[len] = guest;
    for (int i = 0; i < 5; i++) {
        if (rooms[i]->room_no == room_no) {
            rooms[i]->booked = 1;
            break;
        }
    }
    printf("Room %d has been booked, confirmation ID is %d\n", room_no, id);
}

void check_out(struct Guest** guests, int len, struct Room** rooms, int room_no) {
    for (int i = 0; i < len; i++) {
        struct Guest* guest = guests[i];
        if (guest->room_no == room_no) {
            float price = 0.0;
            for (int j = 0; j < 5; j++) {
                if (rooms[j]->room_no == room_no) {
                    price = rooms[j]->price;
                    rooms[j]->booked = 0;
                    break;
                }
            }
            printf("%s has checked out of room %d, total price is $%.2f\n", guest->name, room_no, (float) guest->duration * price);
            free(guests[i]);
            guests[i] = guests[len - 1];
            break;
        }
    }
}

void display_guests(struct Guest** guests, int len) {
    printf("Guests:\n");
    for (int i = 0; i < len; i++) {
        struct Guest* guest = guests[i];
        printf("%d - %s - Room %d - Duration %d\n", guest->id, guest->name, guest->room_no, guest->duration);
    }
}

int main() {
    struct Room** rooms = create_rooms();
    struct Guest** guests = create_guests();
    int guest_len = 5;
    int room_len = 5;
    int choice = 0;

    while (choice != 5) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_rooms(rooms, room_len);
                break;
            case 2:
                printf("Enter your name: ");
                char name[50];
                scanf("%s", name);
                int capacity;
                printf("Enter the number of people: ");
                scanf("%d", &capacity);
                int room_no = find_available_room(rooms, room_len, capacity);
                if (room_no == -1) {
                    printf("Sorry, there are no available rooms for %d people\n", capacity);
                } else {
                    int duration;
                    printf("Enter the duration of your stay: ");
                    scanf("%d", &duration);
                    book_room(guests, guest_len, rooms, room_no, name, duration);
                    guest_len++;
                }
                break;
            case 3:
                printf("Enter your room number: ");
                int room_no_check;
                scanf("%d", &room_no_check);
                check_out(guests, guest_len, rooms, room_no_check);
                guest_len--;
                break;
            case 4:
                display_guests(guests, guest_len);
                break;
            case 5:
                printf("Thank you for using C Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    for (int i = 0; i < room_len; i++) {
        free(rooms[i]);
    }
    for (int i = 0; i < guest_len; i++) {
        free(guests[i]);
    }
    free(rooms);
    free(guests);

    return 0;
}