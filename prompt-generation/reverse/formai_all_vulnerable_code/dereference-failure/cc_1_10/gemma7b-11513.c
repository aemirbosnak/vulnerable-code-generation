//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 5
#define MAX_ITEM_NUM 10

typedef struct Room {
    int num;
    char name[20];
    struct Room* next;
} Room;

typedef struct Item {
    int num;
    char name[20];
    struct Item* next;
} Item;

Room* CreateRoom(int num, char* name, Room* next) {
    Room* room = (Room*)malloc(sizeof(Room));
    room->num = num;
    strcpy(room->name, name);
    room->next = next;
    return room;
}

Item* CreateItem(int num, char* name, Item* next) {
    Item* item = (Item*)malloc(sizeof(Item));
    item->num = num;
    strcpy(item->name, name);
    item->next = next;
    return item;
}

int main() {
    // Create a list of rooms
    Room* head = CreateRoom(1, "The Grand Hall", NULL);
    CreateRoom(2, "The Library", head);
    CreateRoom(3, "The Dining Hall", head->next);
    CreateRoom(4, "The Bedroom", head->next->next);
    CreateRoom(5, "The Secret Room", head->next->next->next);

    // Create a list of items
    Item* inventory = CreateItem(1, "Sword", NULL);
    CreateItem(2, "Shield", inventory);
    CreateItem(3, "Key", inventory);
    CreateItem(4, "Potion", inventory);

    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    int current_room = 1;
    while (current_room) {
        // Display the current room
        printf("You are in %s.\n", head->next->name);

        // List the items in the room
        printf("Items in the room:");
        for (Item* item = inventory; item; item = item->next) {
            printf(" %s", item->name);
        }

        // Get the player's input
        char input[20];
        printf("Enter your command: ");
        scanf("%s", input);

        // Process the player's input
        switch (input[0]) {
            case 'n':
                // Go north
                if (head->next) {
                    current_room = head->next->num;
                } else {
                    printf("There is no north exit.\n");
                }
                break;
            case 's':
                // Go south
                if (head->next->next) {
                    current_room = head->next->next->num;
                } else {
                    printf("There is no south exit.\n");
                }
                break;
            case 'e':
                // Go east
                if (head->next->next->next) {
                    current_room = head->next->next->next->num;
                } else {
                    printf("There is no east exit.\n");
                }
                break;
            case 'w':
                // Go west
                if (head->next->next) {
                    current_room = head->next->next->num;
                } else {
                    printf("There is no west exit.\n");
                }
                break;
            case 'i':
                // Inventory
                printf("Your inventory:");
                for (Item* item = inventory; item; item = item->next) {
                    printf(" %s", item->name);
                }
                break;
            case 'q':
                // Quit
                current_room = 0;
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}