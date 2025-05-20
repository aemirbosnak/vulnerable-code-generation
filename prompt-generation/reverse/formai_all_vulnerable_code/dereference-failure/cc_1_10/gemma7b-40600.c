//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_number;
    struct Guest* next;
} Guest;

Guest* create_guest(char* name, int room_number) {
    Guest* guest = (Guest*)malloc(sizeof(Guest));
    strcpy(guest->name, name);
    guest->room_number = room_number;
    guest->next = NULL;
    return guest;
}

Guest* insert_guest(Guest* head, char* name, int room_number) {
    Guest* new_guest = create_guest(name, room_number);
    if (head == NULL) {
        head = new_guest;
    } else {
        Guest* current = head;
        Guest* previous = NULL;
        while (current) {
            if (strcmp(current->name, name) == 0) {
                return current;
            } else if (previous == NULL) {
                previous = current;
            }
            current = current->next;
        }
        previous->next = new_guest;
    }
    return head;
}

void print_guests(Guest* head) {
    Guest* current = head;
    while (current) {
        printf("Name: %s, Room Number: %d\n", current->name, current->room_number);
        current = current->next;
    }
}

int main() {
    Guest* head = NULL;
    insert_guest(head, "John Doe", 101);
    insert_guest(head, "Jane Doe", 102);
    insert_guest(head, "Peter Pan", 103);
    print_guests(head);

    return 0;
}