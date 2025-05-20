//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_number;
    int days_staying;
    struct Guest* next;
} Guest;

Guest* create_guest(char* name, int room_number, int days_staying) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->days_staying = days_staying;
    new_guest->next = NULL;
    return new_guest;
}

void check_in(Guest* guest) {
    printf("Welcome, %s, to the Hotel Acme! Please enjoy your stay in room %d.\n", guest->name, guest->room_number);
}

void check_out(Guest* guest) {
    printf("Goodbye, %s. We hope you enjoyed your stay at the Hotel Acme.\n", guest->name);
}

int main() {
    Guest* head = NULL;

    // Create a few guests
    Guest* guest1 = create_guest("John Doe", 101, 3);
    Guest* guest2 = create_guest("Jane Doe", 102, 2);
    Guest* guest3 = create_guest("Mr. Fluff", 103, 4);

    // Check in the guests
    check_in(guest1);
    check_in(guest2);
    check_in(guest3);

    // Check out the guests
    check_out(guest2);
    check_out(guest3);

    // Print the remaining guests
    Guest* current_guest = head;
    while (current_guest) {
        printf("Current guest: %s, room number: %d, days staying: %d\n", current_guest->name, current_guest->room_number, current_guest->days_staying);
        current_guest = current_guest->next;
    }

    return 0;
}