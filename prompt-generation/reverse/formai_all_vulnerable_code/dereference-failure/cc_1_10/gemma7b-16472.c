//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a hotel room
typedef struct room {
    char name[20];
    int number;
    double price;
    struct room* next;
} room;

// Define the function to insert a room into the linked list
void insert_room(room** head, char* name, int number, double price) {
    room* new_room = (room*)malloc(sizeof(room));
    strcpy(new_room->name, name);
    new_room->number = number;
    new_room->price = price;
    new_room->next = NULL;

    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
    }
}

// Define the function to search for a room
room* search_room(room* head, int number) {
    while (head) {
        if (head->number == number) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Define the function to update the price of a room
void update_price(room* head, int number, double new_price) {
    room* room = search_room(head, number);
    if (room) {
        room->price = new_price;
    }
}

// Define the function to delete a room
void delete_room(room* head, int number) {
    room* previous = NULL;
    room* current = head;

    while (current) {
        if (current->number == number) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

// Main function
int main() {
    room* head = NULL;

    insert_room(&head, "John Doe", 101, 50.0);
    insert_room(&head, "Jane Doe", 102, 60.0);
    insert_room(&head, "Peter Pan", 103, 70.0);

    room* room = search_room(head, 102);
    if (room) {
        printf("Name: %s\n", room->name);
        printf("Number: %d\n", room->number);
        printf("Price: %.2lf\n", room->price);
    }

    update_price(head, 101, 60.0);

    room = search_room(head, 101);
    if (room) {
        printf("Name: %s\n", room->name);
        printf("Number: %d\n", room->number);
        printf("Price: %.2lf\n", room->price);
    }

    delete_room(head, 103);

    room = search_room(head, 103);
    if (room) {
        printf("Error: Room not found.\n");
    }

    return 0;
}