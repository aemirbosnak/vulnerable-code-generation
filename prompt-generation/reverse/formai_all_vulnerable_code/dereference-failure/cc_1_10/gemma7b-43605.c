//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    char status;
    struct Guest *next;
} Guest;

Guest *head = NULL;

void insert_guest(char *name, int room_number) {
    Guest *new_guest = (Guest *)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->status = 'O';
    new_guest->next = NULL;

    if (head == NULL) {
        head = new_guest;
    } else {
        Guest *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_guest;
    }
}

void check_guest(char *name) {
    Guest *temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Guest name: %s\n", temp->name);
            printf("Room number: %d\n", temp->room_number);
            printf("Status: %c\n", temp->status);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Guest not found.\n");
    }
}

int main() {
    insert_guest("John Doe", 101);
    insert_guest("Jane Doe", 102);
    insert_guest("Peter Pan", 103);

    check_guest("John Doe");

    return 0;
}