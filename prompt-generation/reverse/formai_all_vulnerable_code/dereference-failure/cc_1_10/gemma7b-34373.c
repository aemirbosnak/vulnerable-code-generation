//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_number;
    int status;
    struct Guest* next;
} Guest;

Guest* head = NULL;

void add_guest(char* name, int room_number) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->status = 0;
    new_guest->next = NULL;

    if (head == NULL) {
        head = new_guest;
    } else {
        Guest* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_guest;
    }
}

void check_guest_status(int room_number) {
    Guest* temp = head;
    while (temp) {
        if (temp->room_number == room_number) {
            printf("Guest status: %d\n", temp->status);
        }
        temp = temp->next;
    }
}

void update_guest_status(int room_number, int new_status) {
    Guest* temp = head;
    while (temp) {
        if (temp->room_number == room_number) {
            temp->status = new_status;
        }
        temp = temp->next;
    }
}

int main() {
    add_guest("John Doe", 101);
    add_guest("Jane Doe", 102);
    add_guest("Mike Smith", 103);

    check_guest_status(101);
    update_guest_status(102, 1);

    check_guest_status(101);
    check_guest_status(102);

    return 0;
}