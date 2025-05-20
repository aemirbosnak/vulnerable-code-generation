//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[50];
    int room_no;
    char status;
    struct Guest *next;
} Guest;

Guest *head = NULL;

void insertGuest(char *name, int room_no, char status) {
    Guest *newGuest = (Guest *)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = room_no;
    newGuest->status = status;
    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        Guest *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }
}

void printGuests() {
    Guest *temp = head;
    while (temp) {
        printf("Name: %s, Room No: %d, Status: %c\n", temp->name, temp->room_no, temp->status);
        temp = temp->next;
    }
}

void updateGuestStatus(int room_no, char new_status) {
    Guest *temp = head;
    while (temp) {
        if (temp->room_no == room_no) {
            temp->status = new_status;
            break;
        }
        temp = temp->next;
    }
}

int main() {
    insertGuest("John Doe", 101, 'A');
    insertGuest("Jane Doe", 102, 'B');
    insertGuest("Peter Pan", 103, 'C');

    printGuests();

    updateGuestStatus(102, 'C');

    printGuests();

    return 0;
}