//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_num;
    char status;
    struct Guest *next;
} Guest;

Guest *head = NULL;

void add_guest(char *name, int room_num) {
    Guest *new_guest = (Guest *)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_num = room_num;
    new_guest->status = 'A';
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
}

void check_guest_status(char *name) {
    Guest *temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Guest status: %c\n", temp->status);
        }
        temp = temp->next;
    }
}

int main() {
    add_guest("John Doe", 101);
    add_guest("Jane Doe", 102);
    add_guest("Peter Pan", 103);

    check_guest_status("John Doe");

    return 0;
}