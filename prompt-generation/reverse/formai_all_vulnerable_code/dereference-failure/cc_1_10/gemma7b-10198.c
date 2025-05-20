//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_number;
    struct Guest *next;
} Guest;

Guest *head = NULL;

void add_guest(char *name, int room_number) {
    Guest *new_guest = (Guest *)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->next = NULL;

    if (head == NULL) {
        head = new_guest;
    } else {
        Guest *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_guest;
    }
}

void check_in(char *name) {
    Guest *guest = head;
    while (guest) {
        if (strcmp(guest->name, name) == 0) {
            printf("Welcome, %s, to your room %d!\n", guest->name, guest->room_number);
            return;
        }
        guest = guest->next;
    }
    printf("Sorry, %s, we don't have you registered.\n", name);
}

void check_out(char *name) {
    Guest *guest = head;
    Guest *previous = NULL;
    while (guest) {
        if (strcmp(guest->name, name) == 0) {
            if (previous) {
                previous->next = guest->next;
            } else {
                head = guest->next;
            }
            free(guest);
            printf("Goodbye, %s!\n", guest->name);
            return;
        }
        previous = guest;
        guest = guest->next;
    }
    printf("Sorry, %s, we don't have you registered.\n", name);
}

int main() {
    add_guest("John Doe", 101);
    add_guest("Jane Doe", 102);
    add_guest("Bill Smith", 103);
    add_guest("Mary Johnson", 104);

    check_in("John Doe");
    check_out("Jane Doe");
    check_in("Bill Smith");
    check_out("Mary Johnson");

    return 0;
}