//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[50];
    int room_number;
    char email[50];
    int phone_number;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter your name: ");
    scanf("%s", newGuest->name);
    printf("Enter your room number: ");
    scanf("%d", &newGuest->room_number);
    printf("Enter your email address: ");
    scanf("%s", newGuest->email);
    printf("Enter your phone number: ");
    scanf("%d", &newGuest->phone_number);

    if (head == NULL) {
        head = newGuest;
    } else {
        newGuest->next = head;
        head = newGuest;
    }

    return head;
}

void printGuests(Guest* head) {
    Guest* currentGuest = head;
    while (currentGuest) {
        printf("Name: %s\n", currentGuest->name);
        printf("Room Number: %d\n", currentGuest->room_number);
        printf("Email Address: %s\n", currentGuest->email);
        printf("Phone Number: %d\n", currentGuest->phone_number);
        printf("\n");
        currentGuest = currentGuest->next;
    }
}

int main() {
    Guest* head = NULL;
    int choice;

    printf("Welcome to the Hotel Management System!\n");
    printf("1. Insert Guest\n");
    printf("2. Print Guests\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            head = insertGuest(head);
            break;
        case 2:
            printGuests(head);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}