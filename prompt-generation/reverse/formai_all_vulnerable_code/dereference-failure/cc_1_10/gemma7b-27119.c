//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[50];
    int room_no;
    struct Guest *next;
} Guest;

Guest *insert_guest(Guest *head, char *name, int room_no) {
    Guest *new_guest = (Guest *)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_no = room_no;
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

    return head;
}

void print_guests(Guest *head) {
    Guest *temp = head;
    while (temp) {
        printf("%s - Room No: %d\n", temp->name, temp->room_no);
        temp = temp->next;
    }
}

int main() {
    Guest *head = NULL;

    insert_guest(head, "John Doe", 101);
    insert_guest(head, "Jane Doe", 102);
    insert_guest(head, "Peter Pan", 103);

    print_guests(head);

    return 0;
}