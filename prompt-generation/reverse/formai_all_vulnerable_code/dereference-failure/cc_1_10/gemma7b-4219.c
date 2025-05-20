//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    char status;
    struct Guest* next;
} Guest;

Guest* create_guest(char* name, int room_number, char status) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->status = status;
    new_guest->next = NULL;
    return new_guest;
}

void check_in(Guest* guest) {
    guest->status = 'O';
}

void check_out(Guest* guest) {
    guest->status = 'X';
}

int main() {
    Guest* head = NULL;

    // Create a few guests
    Guest* guest1 = create_guest("John Doe", 101, 'N');
    Guest* guest2 = create_guest("Jane Doe", 102, 'O');
    Guest* guest3 = create_guest("Peter Pan", 103, 'X');

    // Link the guests together
    guest1->next = guest2;
    guest2->next = guest3;

    // Check in and out guests
    check_in(guest2);
    check_out(guest3);

    // Print the guest list
    Guest* current_guest = head;
    while (current_guest) {
        printf("%s, room %d, status %c\n", current_guest->name, current_guest->room_number, current_guest->status);
        current_guest = current_guest->next;
    }

    return 0;
}