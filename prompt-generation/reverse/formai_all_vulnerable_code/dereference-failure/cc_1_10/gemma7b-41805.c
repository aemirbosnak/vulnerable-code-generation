//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    double checkin_time;
    double checkout_time;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter your name: ");
    scanf("%s", newGuest->name);
    printf("Enter your room number: ");
    scanf("%d", &newGuest->room_number);
    printf("Enter your checkin time: ");
    scanf("%lf", &newGuest->checkin_time);
    printf("Enter your checkout time: ");
    scanf("%lf", &newGuest->checkout_time);

    newGuest->next = head;
    head = newGuest;

    return head;
}

void displayGuests(Guest* head) {
    Guest* currentGuest = head;
    printf("List of guests:\n");
    while (currentGuest) {
        printf("Name: %s, Room Number: %d, Checkin Time: %.2lf, Checkout Time: %.2lf\n", currentGuest->name, currentGuest->room_number, currentGuest->checkin_time, currentGuest->checkout_time);
        currentGuest = currentGuest->next;
    }
}

int main() {
    Guest* head = NULL;

    while (1) {
        printf("Enter '1' to insert a guest, '2' to display guests, or '3' to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertGuest(head);
                break;
            case 2:
                displayGuests(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}