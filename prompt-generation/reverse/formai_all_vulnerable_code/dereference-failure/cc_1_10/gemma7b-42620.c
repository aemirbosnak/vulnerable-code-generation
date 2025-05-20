//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_no;
    struct Guest* next;
} Guest;

Guest* createGuest(char* name, int room_no) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = room_no;
    newGuest->next = NULL;
    return newGuest;
}

void insertGuest(Guest* head, char* name, int room_no) {
    Guest* newGuest = createGuest(name, room_no);
    if (head == NULL) {
        head = newGuest;
    } else {
        Guest* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }
}

void searchGuest(Guest* head, char* name) {
    Guest* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Guest name: %s, Room number: %d\n", temp->name, temp->room_no);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Guest not found.\n");
    }
}

int main() {
    Guest* head = NULL;
    insertGuest(head, "John Doe", 101);
    insertGuest(head, "Jane Doe", 102);
    insertGuest(head, "Peter Pan", 103);
    searchGuest(head, "Jane Doe");
    searchGuest(head, "Non-existent Guest");
    return 0;
}