//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <string.h>

// Define a structure for a hotel room
typedef struct Room {
    char name[20];
    int number;
    double price;
    struct Room* next;
} Room;

// Define a function to insert a room into the linked list
void insertRoom(Room** head, char* name, int number, double price) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->number = number;
    newRoom->price = price;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

// Define a function to search for a room by name
Room* searchRoom(Room* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int main() {
    Room* head = NULL;

    // Insert some rooms
    insertRoom(&head, "John Doe's Room", 101, 50.0);
    insertRoom(&head, "Jane Doe's Room", 102, 60.0);
    insertRoom(&head, "Bill Smith's Room", 103, 70.0);

    // Search for a room by name
    Room* room = searchRoom(head, "Jane Doe's Room");

    // Print the room information
    if (room) {
        printf("Name: %s\n", room->name);
        printf("Number: %d\n", room->number);
        printf("Price: %.2lf\n", room->price);
    } else {
        printf("Room not found.\n");
    }

    return 0;
}