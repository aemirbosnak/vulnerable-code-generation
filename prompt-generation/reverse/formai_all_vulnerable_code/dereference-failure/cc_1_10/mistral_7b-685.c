//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int room_number;
    bool is_checked_in;
} Guest;

typedef struct {
    int room_number;
    Guest guest;
} Room;

#define NUM_ROOMS 100

Room rooms[NUM_ROOMS];
int num_guests = 0;

void print_menu() {
    printf("\n\n~~~~~~~ HOTEL MAGIC ~~~~~~~\n");
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. List all guests\n");
    printf("4. Search for a guest\n");
    printf("5. Quit\n");
}

void check_in(int room_number) {
    Room *room = &rooms[room_number];
    Guest *guest = &room->guest;

    printf("Enter guest name: ");
    scanf("%s", guest->name);
    guest->is_checked_in = true;

    printf("Welcome, %s! Your room number is %d.\n", guest->name, room_number);
}

void check_out(int room_number) {
    Room *room = &rooms[room_number];
    Guest *guest = &room->guest;

    printf("Checking out, %s...\n", guest->name);
    guest->is_checked_in = false;
}

void list_all_guests() {
    int i;

    printf("\nCurrent guests:\n");
    for (i = 0; i < NUM_ROOMS; i++) {
        Room *room = &rooms[i];
        if (room->guest.is_checked_in) {
            printf("Room %d: %s\n", i, room->guest.name);
        }
    }
}

void search_for_guest(char name[50]) {
    int i;

    printf("\nSearching for %s...\n", name);
    for (i = 0; i < NUM_ROOMS; i++) {
        Room *room = &rooms[i];
        if (room->guest.is_checked_in && strcmp(room->guest.name, name) == 0) {
            printf("Found! %s is in room %d.\n", name, i);
            return;
        }
    }

    printf("Sorry, %s not found.\n", name);
}

int main() {
    int choice;
    char name[50];
    int room_number;

    while (true) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                check_in(room_number);
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                check_out(room_number);
                break;
            case 3:
                list_all_guests();
                break;
            case 4:
                printf("Enter guest name: ");
                scanf("%s", name);
                search_for_guest(name);
                break;
            case 5:
                printf("Thank you for staying with us! Have a magical day!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}