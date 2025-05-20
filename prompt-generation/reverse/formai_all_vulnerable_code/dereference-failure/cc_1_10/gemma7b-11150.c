//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUMBER 5

typedef struct Room {
    char name[20];
    struct Room* next;
    int room_number;
    int items_taken;
} Room;

void create_room(int room_number, char* name, Room** head) {
    *head = malloc(sizeof(Room));
    (*head)->room_number = room_number;
    strcpy((*head)->name, name);
    (*head)->next = NULL;
    (*head)->items_taken = 0;
}

void explore_room(Room* current_room) {
    printf("You are in the %s.\n", current_room->name);
    printf("Items taken: %d\n", current_room->items_taken);
    printf("Available exits: ");
    for (Room* exit_room = current_room->next; exit_room; exit_room = exit_room->next) {
        printf("%s, ", exit_room->name);
    }
    printf("\n");
}

int main() {
    Room* head = NULL;
    create_room(1, "The Hallway", &head);
    create_room(2, "The Living Room", &head);
    create_room(3, "The Kitchen", &head);
    create_room(4, "The Bedroom", &head);
    create_room(5, "The Bathroom", &head);

    Room* current_room = head;
    explore_room(current_room);

    // Player's turn to explore the rooms
    char command[20];
    printf("Enter your command: ");
    scanf("%s", command);

    // Check if the player wants to go to a specific room
    for (Room* exit_room = current_room->next; exit_room; exit_room = exit_room->next) {
        if (strcmp(command, exit_room->name) == 0) {
            current_room = exit_room;
            explore_room(current_room);
        }
    }

    return 0;
}