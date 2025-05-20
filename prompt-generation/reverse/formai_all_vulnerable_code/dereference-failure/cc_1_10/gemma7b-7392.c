//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_NUM 10

typedef struct Room {
    char name[20];
    struct Room* next;
    int has_visited;
    int items[MAX_ROOM_NUM];
} Room;

Room* create_room(char* name) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    new_room->has_visited = 0;
    for (int i = 0; i < MAX_ROOM_NUM; i++) {
        new_room->items[i] = 0;
    }
    return new_room;
}

void add_item(Room* room, int item_num) {
    room->items[item_num] = 1;
}

void play_game() {
    Room* start_room = create_room("The Foyer");
    Room* current_room = start_room;

    // Game loop
    while (!current_room->has_visited) {
        // Display room description
        printf("%s\n", current_room->name);

        // Get user input
        char input[20];
        printf("Enter command: ");
        scanf("%s", input);

        // Process user input
        if (strcmp(input, "look") == 0) {
            // Describe room items
            printf("Items in the room: ");
            for (int i = 0; i < MAX_ROOM_NUM; i++) {
                if (current_room->items[i] == 1) {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
        } else if (strcmp(input, "go") == 0) {
            // Go to a different room
            char direction[20];
            printf("Enter direction: ");
            scanf("%s", direction);

            // Check if the direction is valid
            if (direction[0] == 'N' || direction[0] == 'S' || direction[0] == 'E' || direction[0] == 'W') {
                // Move to the next room
                switch (direction[0]) {
                    case 'N':
                        current_room = current_room->next;
                        break;
                    case 'S':
                        current_room = current_room->next->next;
                        break;
                    case 'E':
                        current_room = current_room->next->next->next;
                        break;
                    case 'W':
                        current_room = current_room->next->next->next->next;
                        break;
                }

                // Mark the room as visited
                current_room->has_visited = 1;
            } else {
                printf("Invalid direction.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    // Game over
    printf("You have completed the game!\n");
}

int main() {
    play_game();
    return 0;
}