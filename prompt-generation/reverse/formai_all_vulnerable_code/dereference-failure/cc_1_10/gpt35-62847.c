//FormAI DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure for representing hotel rooms */
typedef struct {
    int room_number;
    int num_beds;
    float price;
    char *availability;
} Room;

/* Define a structure for representing hotel guests */
typedef struct {
    char *name;
    int room_number;
} Guest;

/* Define a function for adding a new guest */
void add_guest(Guest *guest, Room *rooms, int num_rooms) {
    int room_num;
    char guest_name[50];
    printf("Enter guest name: ");
    scanf("%s", guest_name);
    guest->name = malloc(strlen(guest_name) * sizeof(char));
    strcpy(guest->name, guest_name);
    printf("Enter room number (1-%d): ", num_rooms);
    scanf("%d", &room_num);
    if (room_num < 1 || room_num > num_rooms) {
        printf("Invalid room number. Please try again.\n");
        add_guest(guest, rooms, num_rooms);
    } else if (strcmp(rooms[room_num-1].availability, "occupied") == 0) {
        printf("Room %d is already occupied. Please choose another room.\n", room_num);
        add_guest(guest, rooms, num_rooms);
    } else {
        guest->room_number = room_num;
        rooms[room_num-1].availability = "occupied";
        printf("Guest %s added to room %d.\n", guest->name, guest->room_number);
    }
}

/* Define a function for displaying a list of available rooms */
void display_available_rooms(Room *rooms, int num_rooms) {
    printf("List of available rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        if (strcmp(rooms[i].availability, "available") == 0) {
            printf("Room %d - %d beds - $%.2f per night\n", rooms[i].room_number, rooms[i].num_beds, rooms[i].price);
        }
    }
}

/* Define a function for checking out a guest and marking their room as available */
void checkout_guest(Guest *guest, Room *rooms) {
    if (guest->name == NULL) {
        printf("No guest is currently checked in.\n");
    } else {
        int room_num = guest->room_number;
        printf("Checking out %s from room %d.\n", guest->name, room_num);
        guest->name = NULL;
        rooms[room_num-1].availability = "available";
    }
}

int main() {
    int choice;
    int num_rooms = 5; // Change this as needed
    Room *rooms = malloc(num_rooms * sizeof(Room));
    for (int i = 0; i < num_rooms; i++) {
        rooms[i].room_number = i+1;
        rooms[i].num_beds = 2;
        rooms[i].price = 50.00;
        rooms[i].availability = "available";
    }
    Guest *current_guest = malloc(sizeof(Guest));
    current_guest->name = NULL;
    current_guest->room_number = 0;
    do {
        printf("\nC Hotel Management System\n");
        printf("1. Add guest\n");
        printf("2. Display available rooms\n");
        printf("3. Check out guest\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_guest(current_guest, rooms, num_rooms);
                break;
            case 2:
                display_available_rooms(rooms, num_rooms);
                break;
            case 3:
                checkout_guest(current_guest, rooms);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    free(rooms);
    free(current_guest->name);
    free(current_guest);
    return 0;
}