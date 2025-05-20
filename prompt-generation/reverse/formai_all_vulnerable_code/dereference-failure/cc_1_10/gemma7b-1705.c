//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_number;
    struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    printf("Enter your name: ");
    scanf("%s", new_guest->name);
    printf("Enter your room number: ");
    scanf("%d", &new_guest->room_number);
    new_guest->next = head;
    head = new_guest;
    return head;
}

void print_guests(Guest* head) {
    Guest* current_guest = head;
    while (current_guest) {
        printf("%s is staying in room %d\n", current_guest->name, current_guest->room_number);
        current_guest = current_guest->next;
    }
}

int main() {
    Guest* head = NULL;
    char command;

    printf("Welcome to the Hotel Management System!\n");
    printf("Please enter 'i' to insert a guest, 'p' to print guests, or 'q' to quit: ");
    scanf("%c", &command);

    while (command != 'q') {
        switch (command) {
            case 'i':
                head = insert_guest(head);
                break;
            case 'p':
                print_guests(head);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        printf("Please enter 'i' to insert a guest, 'p' to print guests, or 'q' to quit: ");
        scanf("%c", &command);
    }

    printf("Thank you for using the Hotel Management System!\n");

    return 0;
}