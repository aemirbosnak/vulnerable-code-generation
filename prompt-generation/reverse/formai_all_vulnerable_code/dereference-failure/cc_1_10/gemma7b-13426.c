//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        Guest* currentGuest = head;
        while (currentGuest->next != NULL) {
            currentGuest = currentGuest->next;
        }
        currentGuest->next = newGuest;
    }

    return head;
}

int validateGuest(Guest* head, char* name) {
    Guest* currentGuest = head;

    while (currentGuest) {
        if (strcmp(currentGuest->name, name) == 0) {
            return 1;
        }
        currentGuest = currentGuest->next;
    }

    return 0;
}

int main() {
    Guest* head = NULL;

    insertGuest(head, "John Doe", 101);
    insertGuest(head, "Jane Doe", 102);
    insertGuest(head, "Bob Smith", 103);

    if (validateGuest(head, "John Doe") == 1) {
        printf("Guest John Doe is valid.\n");
    } else {
        printf("Guest John Doe is not valid.\n");
    }

    if (validateGuest(head, "Bob Smith") == 1) {
        printf("Guest Bob Smith is valid.\n");
    } else {
        printf("Guest Bob Smith is not valid.\n");
    }

    return 0;
}