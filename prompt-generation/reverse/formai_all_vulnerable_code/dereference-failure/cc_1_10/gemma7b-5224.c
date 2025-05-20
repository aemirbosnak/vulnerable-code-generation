//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 50

typedef struct Guest {
    char name[50];
    int room_no;
    char status[20];
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head, char* name, int room_no, char* status) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = room_no;
    strcpy(newGuest->status, status);
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

    return head;
}

void printGuests(Guest* head) {
    Guest* temp = head;
    while (temp) {
        printf("%s - Room No: %d, Status: %s\n", temp->name, temp->room_no, temp->status);
        temp = temp->next;
    }
}

int main() {
    Guest* head = NULL;

    insertGuest(head, "John Doe", 101, "Occupied");
    insertGuest(head, "Jane Doe", 102, "Available");
    insertGuest(head, "Peter Pan", 103, "Occupied");
    insertGuest(head, "Mary Poppins", 104, "Available");

    printGuests(head);

    return 0;
}