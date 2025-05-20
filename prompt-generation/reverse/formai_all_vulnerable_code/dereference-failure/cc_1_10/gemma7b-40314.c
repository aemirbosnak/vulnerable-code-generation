//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

struct guest {
    char name[50];
    int room_no;
    struct guest* next;
};

struct room {
    int room_no;
    int occupancy;
    struct room* next;
};

struct hotel {
    struct room* rooms;
    struct guest* guests;
    int num_rooms;
    int num_guests;
};

void add_guest(struct hotel* h) {
    struct guest* new_guest = (struct guest*)malloc(sizeof(struct guest));
    new_guest->next = NULL;

    printf("Enter guest name: ");
    scanf("%s", new_guest->name);

    printf("Enter room number: ");
    scanf("%d", &new_guest->room_no);

    h->num_guests++;

    if (h->guests == NULL) {
        h->guests = new_guest;
    } else {
        struct guest* temp = h->guests;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_guest;
    }
}

void add_room(struct hotel* h) {
    struct room* new_room = (struct room*)malloc(sizeof(struct room));
    new_room->next = NULL;

    printf("Enter room number: ");
    scanf("%d", &new_room->room_no);

    printf("Enter occupancy: ");
    scanf("%d", &new_room->occupancy);

    h->num_rooms++;

    if (h->rooms == NULL) {
        h->rooms = new_room;
    } else {
        struct room* temp = h->rooms;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_room;
    }
}

void check_in(struct hotel* h) {
    struct guest* new_guest = (struct guest*)malloc(sizeof(struct guest));
    new_guest->next = NULL;

    printf("Enter guest name: ");
    scanf("%s", new_guest->name);

    printf("Enter room number: ");
    scanf("%d", &new_guest->room_no);

    h->num_guests++;

    if (h->guests == NULL) {
        h->guests = new_guest;
    } else {
        struct guest* temp = h->guests;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_guest;
    }
}

void check_out(struct hotel* h) {
    struct guest* temp_guest = h->guests;
    struct guest* prev_guest = NULL;

    printf("Enter guest name: ");
    scanf("%s", temp_guest->name);

    while (temp_guest) {
        if (strcmp(temp_guest->name, h->guests->name) == 0) {
            h->num_guests--;

            if (prev_guest) {
                prev_guest->next = temp_guest->next;
            } else {
                h->guests = temp_guest->next;
            }

            free(temp_guest);
            temp_guest = NULL;
            break;
        }

        prev_guest = temp_guest;
        temp_guest = temp_guest->next;
    }

    if (temp_guest == NULL) {
        printf("Guest not found.\n");
    }
}

int main() {
    struct hotel* h = (struct hotel*)malloc(sizeof(struct hotel));
    h->rooms = NULL;
    h->guests = NULL;
    h->num_rooms = 0;
    h->num_guests = 0;

    int choice;

    printf("Welcome to the Hotel Management System.\n");
    printf("Please select an option:\n");
    printf("1. Add Guest\n");
    printf("2. Add Room\n");
    printf("3. Check In\n");
    printf("4. Check Out\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_guest(h);
            break;
        case 2:
            add_room(h);
            break;
        case 3:
            check_in(h);
            break;
        case 4:
            check_out(h);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}