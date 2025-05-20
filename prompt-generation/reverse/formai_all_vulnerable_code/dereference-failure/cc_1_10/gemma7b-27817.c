//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head, char* name, int room_number) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
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

    return head;
}

void check_in(Guest* head) {
    printf("Welcome, %s, to the Hotel!\n", head->name);
    printf("Your room number is: %d\n", head->room_number);
}

void check_out(Guest* head) {
    printf("Thank you for staying at the Hotel, %s.\n", head->name);
}

int main() {
    Guest* head = NULL;

    head = insert_guest(head, "John Doe", 101);
    head = insert_guest(head, "Jane Doe", 102);
    head = insert_guest(head, "Peter Pan", 103);

    check_in(head);
    check_out(head);

    return 0;
}