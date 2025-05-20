//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    struct Guest* next;
} Guest;

Guest* head = NULL;

void add_guest(char* name, int room_number) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    strcpy(new_guest->name, name);
    new_guest->room_number = room_number;
    new_guest->next = NULL;

    if (head == NULL) {
        head = new_guest;
    } else {
        Guest* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_guest;
    }
}

void check_in(char* name) {
    Guest* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Welcome, %s! Your room number is %d.\n", temp->name, temp->room_number);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("No guest found with that name.\n");
    }
}

void check_out(char* name) {
    Guest* temp = head;
    Guest* prev = NULL;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            printf("Goodbye, %s. We hope you enjoyed your stay.\n", temp->name);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("No guest found with that name.\n");
    }
}

int main() {
    add_guest("John Doe", 101);
    add_guest("Jane Doe", 102);
    add_guest("Peter Pan", 103);

    check_in("John Doe");
    check_out("Jane Doe");

    check_in("John Doe");
    check_out("Peter Pan");

    check_in("Jack Sparrow");

    return 0;
}