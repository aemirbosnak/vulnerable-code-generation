//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter guest name: ");
    scanf("%s", newGuest->name);
    printf("Enter room number: ");
    scanf("%d", &newGuest->room_number);
    newGuest->next = head;
    head = newGuest;
    return head;
}

void printGuests(Guest* head) {
    Guest* currentGuest = head;
    while (currentGuest) {
        printf("Name: %s, Room Number: %d\n", currentGuest->name, currentGuest->room_number);
        currentGuest = currentGuest->next;
    }
}

void searchGuest(Guest* head, char* name) {
    Guest* currentGuest = head;
    while (currentGuest) {
        if (strcmp(currentGuest->name, name) == 0) {
            printf("Name: %s, Room Number: %d\n", currentGuest->name, currentGuest->room_number);
            return;
        }
        currentGuest = currentGuest->next;
    }
    printf("Guest not found.\n");
}

int main() {
    Guest* head = NULL;
    head = insertGuest(head);
    head = insertGuest(head);
    printGuests(head);
    searchGuest(head, "John Doe");
    return 0;
}