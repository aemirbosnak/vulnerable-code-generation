//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
    char name[20];
    struct Room* next;
    int is_visited;
    int items[10];
} Room;

Room* create_room(char* name, int items_num) {
    Room* room = malloc(sizeof(Room));
    strcpy(room->name, name);
    room->next = NULL;
    room->is_visited = 0;
    room->items[0] = items_num;

    return room;
}

void connect_rooms(Room* room1, Room* room2) {
    room1->next = room2;
}

void play_game() {
    Room* current_room = create_room("The Entrance", 0);
    Room* room_list = current_room;

    for (int i = 1; i < MAX_ROOM_NUM; i++) {
        room_list = create_room(NULL, i);
        connect_rooms(current_room, room_list);
        current_room = room_list;
    }

    current_room = room_list;

    // Game loop
    while (1) {
        // Display current room information
        printf("You are in: %s\n", current_room->name);

        // List items in the room
        printf("Items in the room: ");
        for (int i = 0; i < current_room->items[0]; i++) {
            printf("%d ", current_room->items[i]);
        }

        // Get user input
        char input[20];
        printf("\nEnter a command: ");
        scanf("%s", input);

        // Process user input
        if (strcmp(input, "exit") == 0) {
            printf("Thank you for playing!\n");
            exit(0);
        } else if (strcmp(input, "look") == 0) {
            // Display room description
            printf("You look around and see...\n");
            printf("%s\n", current_room->name);
        } else if (strcmp(input, "take") == 0) {
            // Take item from the room
            int item_num = atoi(input);
            if (item_num > current_room->items[0] || item_num <= 0) {
                printf("Invalid item number.\n");
            } else {
                current_room->items[0]--;
                printf("You took the item: %d.\n", current_room->items[0]);
            }
        } else {
            printf("Invalid command.\n");
        }
    }
}

int main() {
    play_game();

    return 0;
}