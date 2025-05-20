//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Room {
    int number;
    char type;
    int available;
    struct Room* next;
} Room;

Room* insertRoom(Room* head, int number, char type, int available);
void displayRooms(Room* head);

int main() {
    Room* head = NULL;
    head = insertRoom(head, 101, 'A', 1);
    head = insertRoom(head, 102, 'B', 0);
    head = insertRoom(head, 103, 'A', 1);
    head = insertRoom(head, 104, 'B', 1);
    displayRooms(head);

    return 0;
}

Room* insertRoom(Room* head, int number, char type, int available) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->available = available;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        Room* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }

    return head;
}

void displayRooms(Room* head) {
    printf("Rooms:\n");
    while (head) {
        printf("Number: %d, Type: %c, Available: %d\n", head->number, head->type, head->available);
        head = head->next;
    }
}