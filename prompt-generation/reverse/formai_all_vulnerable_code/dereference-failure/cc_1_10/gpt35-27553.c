//FormAI DATASET v1.0 Category: Hotel Management System ; Style: authentic
#include <stdio.h>

/* Struct to represent a single room in the hotel */
typedef struct Room {
    int room_number;
    int occupancy;
    float price;
} Room;

/* Helper function to print a single room's details */
void print_room(Room room) {
    printf("Room #%d -- $%.2f per night -- ", 
            room.room_number, room.price);

    if (room.occupancy == 0) {
        printf("Vacant\n");
    } else {
        printf("Occupied\n");
    }
}

/* Initializes an array of rooms with the provided number of rooms */
Room* init_hotel(int num_rooms) {
    Room* hotel = (Room*) malloc(sizeof(Room) * num_rooms);

    for (int i = 0; i < num_rooms; i++) {
        hotel[i].room_number = i + 1;
        hotel[i].occupancy = 0;
        hotel[i].price = (i % 3 == 0) ? 150.00 : 100.00;
    }

    return hotel;
}

/* Books a room in the hotel given a room number, returns a success/failure flag */
_Bool book_room(Room* hotel, int room_num) {
    if (hotel[room_num - 1].occupancy == 0) {
        hotel[room_num - 1].occupancy = 1;
        return 1;
    } else {
        return 0;
    }
}

/* Prints all the rooms in the hotel */
void list_rooms(Room* hotel, int num_rooms) {
    for (int i = 0; i < num_rooms; i++) {
        print_room(hotel[i]);
    }
}

int main() {
    Room* hotel = init_hotel(10);

    printf("Welcome to the Hotel Management System!\n\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. List rooms\n");
        printf("2. Book a room\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            list_rooms(hotel, 10);
        } else if (choice == 2) {
            printf("Which room would you like to book?\n");
            int room_num;
            scanf("%d", &room_num);

            if (book_room(hotel, room_num)) {
                printf("Room %d successfully booked!\n", room_num);
            } else {
                printf("Room %d is already occupied. Please try again.\n", room_num);
            }
        } else if (choice == 3) {
            printf("Thank you for using the Hotel Management System. Have a nice day!\n");
            break;
        } else {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

        printf("\n");
    }

    free(hotel);

    return 0;
}