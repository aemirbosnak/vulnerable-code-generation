//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_no;
    char status;
    struct Guest* next;
} Guest;

Guest* head = NULL;

void insertGuest(char* name, int room_no) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = room_no;
    newGuest->status = 'O';
    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        Guest* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }
}

void checkGuestStatus(int room_no) {
    Guest* temp = head;
    while (temp) {
        if (temp->room_no == room_no) {
            printf("Guest status: %c\n", temp->status);
        }
        temp = temp->next;
    }
}

int main() {
    insertGuest("John Doe", 101);
    insertGuest("Jane Doe", 102);
    insertGuest("Peter Pan", 103);

    checkGuestStatus(101);
    checkGuestStatus(102);

    return 0;
}