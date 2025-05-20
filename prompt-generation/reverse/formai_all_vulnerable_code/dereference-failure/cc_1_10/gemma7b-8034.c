//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head, char* name, int room_number) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_number = room_number;
    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        head->next = newGuest;
    }

    return head;
}

Guest* findGuest(Guest* head, char* name) {
    Guest* currentGuest = head;

    while (currentGuest) {
        if (strcmp(currentGuest->name, name) == 0) {
            return currentGuest;
        }
        currentGuest = currentGuest->next;
    }

    return NULL;
}

void deleteGuest(Guest* head, char* name) {
    Guest* previousGuest = NULL;
    Guest* currentGuest = head;

    while (currentGuest) {
        if (strcmp(currentGuest->name, name) == 0) {
            if (previousGuest) {
                previousGuest->next = currentGuest->next;
            } else {
                head = currentGuest->next;
            }
            free(currentGuest);
            currentGuest = NULL;
        } else {
            previousGuest = currentGuest;
            currentGuest = currentGuest->next;
        }
    }

    return;
}

int main() {
    Guest* head = NULL;

    insertGuest(head, "John Doe", 101);
    insertGuest(head, "Jane Doe", 102);
    insertGuest(head, "Peter Pan", 103);

    Guest* guest = findGuest(head, "Jane Doe");

    if (guest) {
        printf("Name: %s, Room Number: %d", guest->name, guest->room_number);
    } else {
        printf("Guest not found");
    }

    deleteGuest(head, "Peter Pan");

    guest = findGuest(head, "Peter Pan");

    if (guest) {
        printf("Name: %s, Room Number: %d", guest->name, guest->room_number);
    } else {
        printf("Guest not found");
    }

    return 0;
}