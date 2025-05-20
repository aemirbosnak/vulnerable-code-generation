//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int find_guest(Guest *head, char *name) {
    Guest *temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp->room_no;
        }
        temp = temp->next;
    }

    return -1;
}

void delete_guest(Guest *head, char *name) {
    Guest *prev = NULL;
    Guest *temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    return;
}

int main() {
    Guest *head = NULL;

    insert_guest(head, "John Doe", 101);
    insert_guest(head, "Jane Doe", 102);
    insert_guest(head, "Peter Pan", 103);

    int room_no = find_guest(head, "John Doe");
    printf("Room no: %d\n", room_no);

    delete_guest(head, "Jane Doe");

    room_no = find_guest(head, "Peter Pan");
    printf("Room no: %d\n", room_no);

    return 0;
}