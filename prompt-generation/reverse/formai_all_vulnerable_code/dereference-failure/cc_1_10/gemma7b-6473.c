//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 100

struct Guest {
    char name[50];
    int room_no;
    struct Guest* next;
};

struct Room {
    int no;
    int occupancy;
    struct Room* next;
};

void insertGuest(struct Guest** head, char* name, int room_no) {
    struct Guest* newGuest = (struct Guest*)malloc(sizeof(struct Guest));
    strcpy(newGuest->name, name);
    newGuest->room_no = room_no;
    newGuest->next = NULL;

    if (*head == NULL) {
        *head = newGuest;
    } else {
        (*head)->next = newGuest;
    }
}

void insertRoom(struct Room** head, int no, int occupancy) {
    struct Room* newRoom = (struct Room*)malloc(sizeof(struct Room));
    newRoom->no = no;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

int searchGuest(struct Guest* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int searchRoom(struct Room* head, int no) {
    while (head) {
        if (head->no == no) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    struct Guest* guests = NULL;
    struct Room* rooms = NULL;

    insertGuest(&guests, "John Doe", 101);
    insertGuest(&guests, "Jane Doe", 102);
    insertGuest(&guests, "Peter Pan", 103);

    insertRoom(&rooms, 101, 2);
    insertRoom(&rooms, 102, 1);
    insertRoom(&rooms, 103, 0);

    if (searchGuest(guests, "John Doe")) {
        printf("John Doe is a guest.\n");
    }

    if (searchRoom(rooms, 102)) {
        printf("Room 102 is occupied by Jane Doe.\n");
    }

    return 0;
}